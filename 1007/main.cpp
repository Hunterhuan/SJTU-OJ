#include <iostream>

using namespace std;

int main()
{
    char a[250];
    char b[250];
    cin>>a>>b;
    int end1,end2;
    for(int i=0;i<250;++i)
        if(a[i]=='\0')
        {
            end1 = i-1;
            break;
        }

    for(int i=0;i<250;++i)
        if(b[i]=='\0')
        {
            end2 = i-1;
            break;
        }
    char result[250];
    result[2]='.';
    int count = 0;
    char flag = '0';
    while(true)
    {
        if(count == 2)
        {
            end1--;
            end2--;
            ++count;
            continue;
        }
        if(end1==(-1) && end2==(-1) )
        {
            if(flag=='1')
            {
                result[count] = '1';
                result[count+1]='\0';
                ++count;
            }
            result[count]='\0';
            break;
        }
        if(end1==(-1))
            {
                result[count] = b[end2] + flag -'0';
                flag = '0';
                if(result[count]-'0' >=10)
                {
                    result[count] = result[count]-10;

                    flag = '1';
                }
                ++count;
                end2--;
                continue;
            }
        else if(end2==(-1))
            {
                result[count] = a[end1] + flag -'0';
                flag = '0';
                if(result[count]-'0' >=10)
                {
                    result[count] = result[count]-10;

                    flag = '1';
                }
                ++count;
                end1--;
                continue;
            }
        result[count] = a[end1] -'0' + b[end2] + flag - '0';
        flag = '0';
        if(result[count]-'0' >=10)
        {
            result[count] = result[count]-10;

            flag = '1';
        }
        end1--;
        end2--;
        ++count;
    }
    for(int j=count-1;j>=0;--j)
        cout<<result[j];
    return 0;
}
