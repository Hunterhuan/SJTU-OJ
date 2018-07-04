#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<string> book;
int main()
{
    cin>>n;
    string tmp;
    cin.get();
    for(int i=1;i<=n;++i)
    {
        getline(cin,tmp);
        book.push_back(tmp);
    }
    int x,y;
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        book[y-1] = book[y-1] + " " + book[x-1];
        book[x-1] = "";
    }
    int it = book.size()-1;
    while(true)
    {
        if(book[it]!="")
        {
            cout<<book[it];
            break;
        }
        --it;
    }
    return 0;
}
