#include <iostream>
#include <algorithm>
using namespace std;
string name[1050];

bool cmp(int *a,int *b)
{
    if(a[4]<b[4])
        return false;
    else if(a[4]>b[4])
        return true;
    else
    {
        if(a[1]<b[1])
            return false;
        else if(a[1]>b[1])
            return true;
        else
        {
            if(a[2]<b[2])
                return false;
            else if(a[2]>b[2])
                return true;
            else
            {
                return name[a[0]]<name[b[0]];
            }
        }
    }
}
int main()
{
    int n,s1,s2,s3,s4,k;
    cin>>n;
    int **score = new int *[n];
    for(int i=0;i<n;++i)
    {
        score[i] = new int[5];
    }
    for(int i=0;i<n;++i)
    {
        cin>>name[i];
        score[i][0] = i;
        cin>>score[i][1]>>score[i][2]>>score[i][3];
        score[i][4] = score[i][1]+score[i][2]+score[i][3];
    }

    sort(score,score+n,cmp);
    cin>>k;
    cout<<name[score[k-1][0]]<<' '<<score[k-1][4];
    return 0;
}
