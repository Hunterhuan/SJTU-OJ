//#include <iostream>
//
//using namespace std;
//int r,m,n;
//int getstep()
//{
//    int count = 0;
//    for(int i=1;i<=r/2;++i)
//    {
//        if(i==m || i==n || r-i+1==m || r-i+1==n)
//        {
//            int start = i,length = r-2*(i-1);
//            for(int i=0;i<length;++i)
//            {
//                if(start==m && start+i==n)
//                {
//                    cout<<count<<endl;
//                    return 0;
//                }
//                ++count;
//            }
//            for(int i=1;i<length;++i)
//            {
//                if(start+i==m && start+length-1==n)
//                {
//                    cout<<count<<endl;
//                    return 0;
//                }
//                ++count;
//            }
//            for(int i=1;i<length;++i)
//            {
//                if(start+length-1 ==m && start +length-1-i==n)
//                {
//                    cout<<count<<endl;
//                    return 0;
//                }
//                ++count;
//            }
//            for(int i=1;i<length;++i)
//            {
//                if(start+length-1-i==m &&start ==n)
//                {
//                    cout<<count<<endl;
//                    return 0;
//                }
//                ++count;
//            }
//        }
//        else
//        {
//            count += ((r-2*(i-1)-1)*4);
//        }
//    }
//}
//int main()
//{
//    r = 5;
//    while(true)
//    {
//        cin>>m>>n;
//        getstep();
//    }
//    return 0;
//}

#include <iostream>
#include <iomanip>

using namespace std;
int l,m,n;
int mountain[1001][1001];
void getMatrix(int begin ,int l,int count)
{
    if(l<=0)
        return;
    for(int i=0;i<l;++i)
    {
        mountain[count][count+i] = begin;
        ++begin;
    }
    for(int i=0;i<l-1;++i)
    {
        mountain[count+i+1][count+l-1] = begin;
        ++begin;
    }
    for(int i=0;i<l-1;++i)
    {
        mountain[count+l-1][count+l-2-i] = begin;
        ++begin;
    }
    for(int i=0;i<l-2;++i)
    {
        mountain[count+l-2-i][count] = begin;
        ++begin;
    }
    if(count+l-1==m || count+l-1==n ||count ==n ||count==m)
        return;
    l = l - 2;
    getMatrix(begin,l,count+1);
}
int main()
{
    cin>>l>>m>>n;
    getMatrix(0,l,1);
    cout<<mountain[m][n];
//    for(int i=1 ; i<=l;++i)
//    {
//        for(int j=1;j<=l;++j)
//            cout<<setw(6)<<mountain[i][j];
//        cout<<endl;
//    }
    return 0;
}
