#include <iostream>

using namespace std;

template<class T>
class linklist
{
private:
    struct node{
        T value;
        node *next;
        node():next(NULL){}
        node(const T &v,node *n = NULL):value(v),next(n){}
    };
    node *head;
    int size;
public:
    node *get(int i)const{
        if(i<0) return head;
        node *p = head->next;
        for(int j=0;j<i;++j)
            p = p->next;
        return p;
        }
    linklist():size(0)
    {
        head = new node;
    }
    ~linklist(){
        clear();
        delete head;
    }
    void clear()
    {
        while(length()>0)
            remove(0);
    }
    int length()const
    {
        return size;
    }
    void insert(int i,const T &x)
    {
        node *p = get(i-1);
        p->next = new node(x,p->next);
        ++size;
    }
    void remove(int i)
    {
        node *p =get(i-1);
        node *q = p->next;
        p->next = q->next;
        delete q;
        --size;
    }
    int search(const T &x)const
    {
        node *p=head->next;
        for(int i=0;p;++i)
        {
            if(x==p->value)return i;
            p = p->next;
        }
        return -1;
    }
    T visit(int i)const
    {
        return get(i)->value;
    }
    void traverse()const
    {
        node *p = head->next;
        while(p){
            cout<<p->value<<' ';
            p = p->next;
        }
    }
};
int main()
{
    linklist<int> q;
    q.insert(0,10);
    q.traverse();
    return 0;
}
