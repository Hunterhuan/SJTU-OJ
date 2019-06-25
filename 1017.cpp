#include <iostream>
#include "string.h"
using namespace std;
 
class bigInt
{
    friend bigInt operator+(bigInt a,bigInt b);
    friend bigInt operator-(bigInt a,bigInt b);
    friend bigInt operator*(bigInt a,bigInt b);
public:
    int ans[3000];
    int length;
    bigInt()
    {
        memset(ans,0,sizeof(int)*1000);
        length=0;
    }
    bigInt(int a)
    {
        memset(ans,0,sizeof(int)*1000);
        int i=0;
        while(a!=0)
        {
            ans[i++]=a%10;
            a=a/10;
        }
        length=i;
    }
    bigInt(const bigInt& a)
    {
        length=a.length;
        for(int i=0;i<length;i++)
        {
            ans[i]=a.ans[i];
        }
    }
    bigInt& operator=(const bigInt &a)
    {
        if(&a==this) return (*this);
        length=a.length;
        for(int i=0;i<length;i++)
        {
            ans[i]=a.ans[i];
        }
        return (*this);
    }
    void print()
    {
        for(int i=length-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
 
 
};
bigInt operator*(bigInt a,int b)
{
    bigInt c;
    int carry=0;
    for(int i=0;i<a.length;i++)
    {
        int tp=a.ans[i]*b+carry;
        carry=tp/10;
        c.ans[i]=tp%10;
    }
    int j=a.length;
    while(carry!=0)
    {
        c.ans[j++]=carry%10;
        carry=carry/10;
    }
    c.length=j;
    return c;
}
bigInt operator-(bigInt a,bigInt b)
{
    bigInt c;
    int carry=0;
    int length_small=(a.length>b.length)?b.length:a.length;
    for(int i=0;i<length_small;i++)
    {
        if(a.ans[i]<(b.ans[i]+carry))
        {
            c.ans[i]=10+a.ans[i]-b.ans[i]-carry;
            carry=1;
        }
        else
        {
            c.ans[i]=a.ans[i]-b.ans[i]-carry;
            carry=0;
        }
    }
    if(a.length>b.length)
    {
        for(int i=b.length;i<a.length;i++)
        {
            if(a.ans[i]<carry)
            {
                c.ans[i]=10+a.ans[i]-carry;
                carry=1;
            }
            else
            {
                c.ans[i]=a.ans[i]-carry;
                carry=0;
            }
        }
    }
    else if(a.length<b.length)
    {
        for(int i=a.length;i<b.length;i++)
        {
            if(a.ans[i]<carry)
            {
                c.ans[i]=10+b.ans[i]-carry;
                carry=1;
            }
            else
            {
                c.ans[i]=b.ans[i]-carry;
                carry=0;
            }
        }
    }
    for(int i=max(a.length,b.length);i>=0;i--)
    {
        if(c.ans[i]!=0)
        {
            c.length=i+1;
            break;
        }
    }
    return c;
}
 
bigInt operator+(bigInt a,bigInt b)
{
    bigInt c;
    int carry=0;
    int length_small=(a.length>b.length)?b.length:a.length;
    for(int i=0;i<length_small;i++)
    {
        int tp=a.ans[i]+b.ans[i]+carry;
        c.ans[i]=tp%10;
        carry=tp/10;
    }
    if(a.length>b.length)
    {
        for(int i=b.length;i<a.length;i++)
        {
            int tp=a.ans[i]+carry;
            c.ans[i]=tp%10;
            carry=tp/10;
        }
        if(carry==1)
        {
            c.ans[a.length]=carry;
            c.length=a.length+1;
        }
        else
        {
            c.length=a.length;
        }
    }
    else if(a.length<b.length)
    {
        for(int i=a.length;i<b.length;i++)
        {
            int tp=b.ans[i]+carry;
            c.ans[i]=tp%10;
            carry=tp/10;
        }
        if(carry==1)
        {
            c.ans[b.length]=carry;
            c.length=b.length+1;
        }
        else
        {
            c.length=b.length;
        }
    }
    else
    {
        if(carry==1)
        {
            c.ans[a.length]=1;
            c.length=a.length+1;
        }
        else
        {
            c.length=a.length;
        }
    }
    return c;
}
 
 
int main()
{
    int a,b,c;
    int N;
    cin>>a>>b>>c>>N;
    bigInt *res=new bigInt[N+1];
    res[0]=1;
    res[1]=a+1;
    res[2]=b+a+a*a+1;
    for(int i=3;i<=N;i++)
    {
        res[i]=res[i-3]*c+(res[i-2]-res[i-3])*b+(res[i-1]-res[i-2])*a+res[i-1];
    }
    res[N].print();
    return 0;
}