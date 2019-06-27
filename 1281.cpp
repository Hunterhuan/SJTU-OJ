#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
using namespace std;


int M, N, M1, M2;
vector<vector<int>> graph;
int main()
{
    cin>>M>>N>>M1>>M2;
    pair<int,int> s_p;
    graph.assign(M, vector<int>(N, 0));
    for(int i=0;i<M; ++i){
        for(int j=0; j<N;++j){
            cin>>graph[i][j];
            if(graph[i][j]==3){
                s_p.first = i;
                s_p.second = j;
            }
        }
    }
    vector<int> matric={M1,-M1, M2, -M2};
    queue<pair<int,int>> q;
    q.push(s_p);
    int res = 1;
    while(!q.empty()){
        int len = q.size();
        for(int i=0;i<len;++i){
            auto p = q.front();
            q.pop();
            for(auto col:matric){
                for(auto row:matric){
                    if(abs(col)==abs(row))
                        continue;
                    int left = p.first + col;
                    int right = p.second + row;
                    if(left>=M || left<0 || right>=N || right<0){
                        continue;
                    }
                    if(graph[left][right]==4){
                        cout<<res<<endl;
                        return 0;
                    }
                    if(graph[left][right]!=1)
                        continue;
                    q.push(make_pair(left, right));
                    graph[left][right] = 0;
                }
            }
        }
        ++res;
    }
    return 0;
}
