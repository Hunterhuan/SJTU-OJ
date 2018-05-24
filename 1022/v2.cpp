#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > cheng(vector<vector<int> > matrix1,vector<vector<int> > matrix2)
{
    vector<vector<int> > res;
    vector<int> p1;
    p1.push_back(matrix1[0][0]*matrix2[0][0]+matrix1[0][1]*matrix2[1][0]);
    p1.push_back(matrix1[0][0]*matrix2[0][1]+matrix1[0][1]*matrix2[1][1]);
    res.push_back(p1);
    vector<int> p2;
    p2.push_back(matrix1[1][0]*matrix2[0][0]+matrix1[1][1]*matrix2[1][0]);
    p1.push_back(matrix1[1][0]*matrix2[0][1]+matrix1[1][1]*matrix2[1][1]);
    res.push_back(p2);
    return res;
}
int main()
{

}
