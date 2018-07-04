#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int cubes[1000000][4]={};

class disjointset{
private:
    int size;
    int *parent;
public:
    disjointset(int s){
        size=s;
        parent = new int[size];
        for(int i=0;i<size;++i)
            parent[i]=-1;
    }
    ~disjointset(){
        delete [] parent;
    }
    void Union(int root1, int root2){
        if(root1==root2){
            return;
        }
        if(parent[root1]>parent[root2]){
            parent[root1] = root2;
        }
        else if(parent[root1]<parent[root2]){
            parent[root2]=root1;
        }
        else{
            parent[root2] = root1;
            --parent[root1];
        }
    }

    int Find(int x){
//        int start = x,tmp;
//        while(!(parent[x]<0))
//            x = parent[x];
//        while(start != x){
//            tmp = parent[start];
//            parent[start] = x;
//            start = tmp;
//        }
//        return x;
        if(parent[x]<0)
            return x;
        return parent[x]=Find(parent[x]);
    }
};


void transfer(int index, int &row, int &col){
    row = 1;
    int tmp = 0;
    while(tmp<index){
        tmp += row;
        row++;
    }
    --row;
    col = index - (row-1)*row/2;
}


void add(int pos1,int pos2, int direction){
    cubes[pos1][direction]=pos2;
    if(direction==0)
        cubes[pos2][3] = pos1;
    else if(direction==1)
        cubes[pos2][2] = pos1;
    else if(direction==2)
        cubes[pos2][1] = pos1;
    else
        cubes[pos2][0] = pos1;
}

void Puzzle(int n, int start_index, int end_index){

    int sum_index = n*(n+1)/2;
    disjointset ds(sum_index);
    //int startrow = int(sqrt((start_index)*2));
    //int startcol = start_index-(startrow*(startrow-1)/2);

    //int endrow = int(sqrt((end_index)*2));
    //int endcol = end_index-(endrow*(endrow-1)/2);

    int pos1,pos2,direction;
    while(ds.Find(start_index)!=ds.Find(end_index)){
            //int pos1,pos2,direction;
            cin>>pos1>>direction;
            int row,col,row2,col2;
            transfer(pos1, row, col);
            if(direction==0){
                row2 = row-1;
                col2 = col-1;
            }
            else if(direction==1){
                row2 = row-1;
                col2 = col;
            }
            else if(direction==2){
                row2 = row+1;
                col2 = col;
            }
            else{
                row2 = row+1;
                col2 = col+1;
            }
            if(row2<=0 || row2 >n || col2 >row2 || col2<=0 )
                continue;
            pos2 = (row2-1)*row2/2 + col2;
            add(pos1,pos2,direction);
            ds.Union(ds.Find(pos1),ds.Find(pos2));
    }
}

void find_path(int begin_index, int end_index){
    vector<int> path;
    if(begin_index==end_index)
    {
        cout<<begin_index;
        return;}
    path.push_back(begin_index);
    while(true){
        int top = path.back();
        int i=0;
        while(i<=3 && cubes[top][i]==0)
            ++i;
        if(i==4)
        {
            path.pop_back();
            continue;
        }
        else{
            path.push_back(cubes[top][i]);
            cubes[top][i]=0;
            if(path.back()==end_index)
                break;
        }
    }
    for(int j=0;j<path.size();++j)
        cout<<path[j]<<' ';
}
int main()
{
    int n,_start, _end;
    for(int i=0;i<1000000;++i){
        for(int j=0;j<4;++j){
            cubes[i][j] = 0;
        }
    }
    cin>>n>>_start>>_end;
    Puzzle(n,_start,_end);
    find_path(_start,_end);
    return 0;
}
