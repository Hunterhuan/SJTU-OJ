#include <iostream>

using namespace std;
class linklist
{
public:
    struct Node
    {
        int data;
        Node *next;
        Node():next(NULL){}
        Node(int i,Node *n=NULL):data(i),next(n){}
    };
    Node *head;
    linklist()
    {
        head = new Node();
    }
    ~linklist(){delete head;}
    void add(int n)
    {
        Node *p=head;
        Node *newnode = new Node(n);
        while(p->next!=NULL)
            p = p->next;
        p->next = newnode;
    }

    int search(int obj)
    {
        Node *p=head;
        int count = 0;
        while(p->next!=NULL)
        {
            if(p->next->data!=obj)
            {
                p=p->next;
                ++count;
            }
            else
            {
                Node *tmp = p->next;
                p->next = p->next->next;
                tmp->next = head->next;
                head->next = tmp;
                return ++count;
            }
        }
        return count;
    }
};
int main()
{
    int n,tmp;
    cin>>n;
    linklist *link = new linklist();
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        link->add(tmp);
    }
    int m;
    cin>>m;
    int count=0;
    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        count = count+link->search(tmp);
    }
    cout <<count;
    return 0;
}
