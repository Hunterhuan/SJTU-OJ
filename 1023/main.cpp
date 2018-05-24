#include <iostream>

using namespace std;

void getresult(int method,int length,int matrix[700][700])
{
    if(method==0)
    {
        int tmp;
        for(int i=1;i<=length;++i)
        {
            for(int j=1;j<=(length/2);++j)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][length-j+1];
                matrix[i][length-j+1] = tmp;
            }
        }
    }
    else if(method ==1)
    {
        int tmp;
        for(int i=1;i<=length;++i)
        {
            for(int j=1;j<=(length/2);++j)
            {
                tmp = matrix[j][i];
                matrix[j][i] = matrix[length-j+1][i];
                matrix[length-j+1][i] = tmp;
            }
        }
    }
}

int main()
{
    int matrix[700][700];
    int n,method,length;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>length>>method;

        for(int j=1;j<=length;++j)
        {
            for(int k=1;k<=length;++k)
            {
                cin>>matrix[j][k];
            }
        }
        if(method==2)
        {
            for(int j=1;j<=length;++j)
            {
                for(int k=1;k<=length;++k)
                {
                    cout<<matrix[k][j]<<' ';
                }
                cout<<endl;
            }
            continue;
        }
        getresult(method,length,matrix);
        for(int j=1;j<=length;++j)
        {
            for(int k=1;k<=length;++k)
            {
                cout<<matrix[j][k]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
