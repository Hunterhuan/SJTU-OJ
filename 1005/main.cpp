#include <iostream>

using namespace std;
int matrix[10][10];
int legal[10];
void clear()
{
    for(int i=0;i<=9;++i)
        legal[i]=0;
}
bool islegal()
{
    for(int i=1;i<=9;++i)
    {
        clear();
        for(int j=1;j<=9;++j)
        {
            if(legal[matrix[i][j]]==1)
                return false;
            else
                legal[matrix[i][j]]=1;
        }
    }
    for(int i=1;i<=9;++i)
    {
        clear();
        for(int j=1;j<=9;++j)
        {
            if(legal[matrix[j][i]]==1)
                return false;
            else
                legal[matrix[j][i]]=1;
        }
    }
    for(int i=1;i<9;i=i+3)
    {
        for(int j=1;j<9;j=j+3)
        {
            clear();
            for(int k=0;k<3;++k)
            {
                for(int l=0;l<3;++l)
                {
                    if(legal[matrix[i+k][j+l]]==1)
                        return false;
                    else
                        legal[matrix[i+k][j+l]]=1;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=9;++j)
            for(int k=1;k<=9;++k)
            {
                cin>>matrix[j][k];
            }
        if(islegal())
            cout<<"Right"<<endl;
        else
            cout<<"Wrong"<<endl;
    }
    return 0;
}
