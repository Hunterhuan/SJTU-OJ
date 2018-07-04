#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int tmp;
    scanf("%d",&tmp);
    while(tmp)
    {
        if(tmp>=101)
            printf("%d\n",tmp-10);
        else
            printf("%d\n",91);
        scanf("%d",&tmp);
    }
    return 0;
}
