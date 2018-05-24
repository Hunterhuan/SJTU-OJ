#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int data;
    node * son;
    node * bro;
    node(int n=0, node *a = NULL, node *b = NULL)
    {
        data = n;
        son = a;
        bro = b;
    }

};

node *root;
void create_tree()
{
    stack<node *> s;
    char tmp;
    cin>>tmp;
    cin>>tmp;
    root = new node(tmp-'0');
    s.push(root);
    while(true)
    {
        cin>>tmp;
        if(tmp=='(')
        {
            cin>>tmp;
            node * tmp2 = s.top();
            s.pop();
            if(tmp2->son == NULL)
            {
                tmp2->son = new node(tmp-'0');
                s.push(tmp2);
                s.push(tmp2->son);
            }
            else
            {
                node *tmp3 = tmp2->son;
                while(tmp3->bro!=NULL)
                    tmp3 = tmp3->bro;
                tmp3->bro = new node(tmp-'0');
                s.push(tmp2);
                s.push(tmp3->bro);
            }
        }
        else if(tmp==')')
        {
            s.pop();
            if(s.empty())
                break;
        }
    }
}

int main()
{
    create_tree();

    return 0;
}
