#include <iostream>
#include <stdio.h>
using namespace std;
int S[1000001] = {0};

int main(){
    //freopen("1.txt","r",stdin);
    int n;
    int num;
    cin >> n;
    cin >> S[0];
    for (int i = 1 ; i < n; i++){
        cin >> num;
        S[i] = S[i-1] + num;
    }

    int min = S[0];
    int min_flag = 0;
    int max = S[1];
    for (int i = 1; i < n; i++){
        if (min > S[i]){
            min = S[i];
            min_flag = i;
        }
        if (i - min_flag > 1 && S[i] - min > max)
            max = S[i]-min;
    }
    if(max <= 0)
        cout << "Game Over";
    else
        cout << max;
    return 0;

}
