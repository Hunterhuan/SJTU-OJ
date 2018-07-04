#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int start, end ,index;
    int maxlength = 1;
    cin>>start>>end;
    long long int times_maxlen = end-start+1;
    vector<int> length(end-start+1,1);
    vector<long long int> times(end-start+1,1);
    int i,j,tmp;
    for(i = start;i<=end;++i){
        for(j = 1;j<=100;++j){
            if((i*j)%100!=0)
                continue;
            tmp = i+(i*j)/100;
            index = tmp-start;
            if(tmp>end)
                break;
            if(length[index]==length[i-start]+1)
                times[index] +=times[i-start];
            else if(length[index]<length[i-start]+1){
                times[index] = times[i-start];
                length[index] = length[i-start]+1;
            }
            else
                continue;
            if(maxlength <length[index]){
                maxlength = length[index];
                times_maxlen = times[index];
            }
            else if(maxlength==length[index]){
                times_maxlen += times[i-start];
            }
        }
    }
    cout <<maxlength<<endl<<times_maxlen;
    return 0;
}
