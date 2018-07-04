#include <iostream>
#include <algorithm>
using namespace std;
bool comp(char *a,char *b)
{
    int count = 0;
    while(true)
    {
        if(a[count]>b[count])
            return true;
        else if(a[count]==b[count])
        {
            count++;
            continue;
        }
        else
            return false;
    }
}

int main()
{
    char **str = new char*[10000];
    for(int i=0;i<10000;++i)
        str[i] = new char[40];
    char ch;
    cin>>ch;
    cin.get();
    int count = 0;
    while(true)
    {
        char tmp;
        int count1 = 0;
        while(true)
        {
            cin.get(tmp);
            if(tmp==ch)
                continue;
            str[count][count1] = tmp;
            if(tmp=='\n')
            {
                str[count][count1]='\0';
                break;
            }
            ++count1;
        }
        if(str[count][0]=='@')
            break;
        ++count;
    }
    sort(str,str+count,comp);
    for(int i=0;i<count;++i)
    {
        cout<<str[i]<<endl;
    }
    return 0;
}
