#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;

int ne[1000005];
void GetNext(char *a)
{
     int len = strlen(a);
     int i = 0, j = -1;
     ne[0] = -1;
     while(i < len)
     {
          if(j == -1 || a[i] == a[j])
          {
               ne[++i] = ++j;
          }
          else j = ne[j];
     }
}
int KMP(char *a, char *b)
{
     int lena = strlen(a);
     int lenb = strlen(b);
     int i = 0, j = 0;
     while (i < lena && j < lenb)
     {
          if(j == -1 || a[i] == b[j])
          {
               j++;
               i++;
          }
          else
               j = ne[j];
     }
     if(j == lenb)
          return i-j+1;
     else
          return -1;
}


int main()
{
    char s[1000005];
    char p[100005];
    scanf("%s", &s);
    scanf("%s", &p);
    GetNext(p);
    cout<<KMP(s,p)-1<<endl;
}
