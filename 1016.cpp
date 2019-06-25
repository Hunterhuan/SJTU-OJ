// 比大小之后再连减
#include <stdio.h> 
#include <string.h> 
char a[100002]; 
char b[100002]; 
char result[100002] = {0}; 
int lena = 0,lenb = 0,lenres;
 
int nolowerthan(char a[], char b[]){
    int i;
 
    if((a[-1] - '0')){
        return 1;
    }
 
    for (i = 0; i < lenb; i++){
        if(a[i] > b[i]){
            return 1;
        }
        else if(a[i] < b[i])
        {
            return 0;
        }
    }
    return 1;
}
 
void minues(char a[], char b[]){
    int i;
    for (i = lenb - 1; i >= 0; i--){
        if(a[i] < b[i]){
            a[i - 1]--;
            a[i] = a[i] + 10;
        }
        a[i] = a[i] - (b[i] - '0');
    }
}
 
int main(){
    int i = 1,j;
    int nlflag;
    char *add=a;
    char in;
    add[0] = '0';
    while(1) { 
        in = getchar(); 
        if(in == '\n'){ 
            add[i]=0; 
            if(!lena){ 
                lena = i;
                add = b; 
                i = 0; 
            } 
            else{ 
                lenb = i; 
                break; 
            } 
        } else{ 
            add[i++] = in; 
        } 
    }
    if(2 <= lena && '0' == a[1]){
        printf("0\n");
    }
    else{
        for (i = 0, lenres = 0; i < lena && lena - i >= lenb;){
            nlflag = nolowerthan(&a[i + 1], b);
            if(nlflag){
                minues(&a[i + 1], b);
                result[i] ++;
            }
            else{
                i++;
                lenres++;
            }
        }
        for (i = 0, nlflag = 0; i < lenres - 1; i++)
        {
            if(result[i]){
                nlflag = 1;
            }
            if(nlflag){
                printf("%d",result[i]);
            }
        }
        printf("\n");
    }
 
    return 0;
}