#include <iostream>
#include <queue>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

struct bigint{ // only positive number;
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> s;
    //value
    bigint(long long num=0){ *this = num;}
    bigint operator = (long long num){
        s.clear();
        do{
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;
    }
    bigint operator = (const string& str){
        s.clear() ;
        int x,len = (str.length()-1)/WIDTH + 1;
        for(int i=0;i<len;i++){
            int end = str.length() - i*WIDTH;
            int start = max(0,end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
    //input&output
    friend ostream& operator << (ostream &out, const bigint& x){
        out << x.s.back();
        for(int i=x.s.size()-2;i>=0;i--){
            char buf[20];
            sprintf(buf,"%08d",x.s[i]);
            for(int j=0;j<strlen(buf);j++) out << buf[j];
        }
        return out;
    }
    friend istream& operator >>(istream &in, bigint& x){
        string s;
        if(!(in>>s)) return in;
        x=s;
        return in;
    }
    //compare
    bool operator < (const bigint& b) const {
        if(s.size()!=b.s.size()) return s.size() < b.s.size();
        for(int i=s.size()-1;i>=0;i++) if(s[i]!=b.s[i]) return s[i] < b.s[i];
        return false;//equal
    }
    bool operator > (const bigint& b) const {return b < *this;}
    bool operator <= (const bigint& b) const {return !(b < *this);}
    bool operator >= (const bigint& b) const {return !(*this < b);}
    bool operator != (const bigint& b) const {return b < *this || *this < b;}
    bool operator == (const bigint& b) const {return !(b < *this) && !(*this < b);}
    //calculate
    bigint operator +(const bigint& b) const {
        bigint c;
        c.s.clear();
        for(int i=0,g=0;;i++){
            if(g==0 && i>=s.size() && i>=b.s.size()) break;
            int x=g;
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x+=b.s[i];
            c.s.push_back(x%BASE);
            g = x/BASE;
        }
        return c;
    }
    bigint operator +=(const bigint& b){
        *this = *this + b;
        return *this;
    }
    bigint operator -(const bigint& b) const {
        bigint c;
        c.s.clear();
        for(int i=0,g=0;;i++){
            if(g==0 && i>=s.size() && i>=b.s.size()) break;
            int x=g;
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x-=b.s[i];
            x+=BASE;
            c.s.push_back(x%BASE);
            g = x/BASE - 1;
        }
        return c;
    }
    bigint operator * (const bigint& b) const {
        bigint c;
        c.s.clear();
        bigint g=0;
        for(int i=0;;i++){
            if(g.s.size()==0 && i>=s.size()+b.s.size()-1) break;
            bigint x;
            x.s.clear() ;
            for(int j=0;j<g.s.size();j++) x.s.push_back(g.s[j]);
            if(i<s.size()+b.s.size()-1){
                for(int j = max(0 , i-(int)s.size()+1);j<=min(i,(int)b.s.size()-1);j++){
                    bigint t = (long long)b.s[j]*s[i-j];
                    x += t;
                }
            }
            c.s.push_back(x.s[0]);
            g.s.clear();
            if(x.s.size()>1) for(int j=1;j<x.s.size();j++) g.s.push_back(x.s[j]);
        }
        return c;
    }
};


int main()
{
    queue<bigint> q;
    int n;
    cin>>n;
    bigint a(1);
    q.push(a);
    q.push(a);
    q.push(a);
    for(int i=3;i<n+2;++i)
    {
        bigint tmp = q.front();
        q.pop();
        q.push(a);
        for(int j=1;j<i;++j)
        {
            q.push(tmp+q.front());
            tmp = q.front();
            q.pop();
        }
        q.push(a);
    }
    for(int i=1;i<n;++i)
    {
        q.pop();
    }
    cout<<q.front();
    return 0;
}
