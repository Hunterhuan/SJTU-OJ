#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int tree[100005][3] = {0};
int a,b;

template<class T>
class seqstack
{
private:
    T *data;
    int top_p;
    int maxSize;
    void doubleSpace()
    {
        T *tmp = data;
        data = new T[2*maxSize];
        for(int i=0;i<maxSize;++i)
            data[i] = tmp[i];
        maxSize *=2;
        delete [] tmp;
    }
public:
    seqstack(int initSize = 10)
    {
        data = new T[initSize];
        maxSize = initSize;
        top_p = -1;
    }
    ~seqstack(){
    delete [] data;
    }
    bool isempty()const
    {
        return top_p==-1;
    }
    void push(const T &x)
    {
        if(top_p==maxSize-1)
            doubleSpace();
        data[++top_p] = x;
    }
    T pop()
    {
        return data[top_p--];
    }
    T top()
    {
        return data[top_p];
    }
};

template <class elemType>
class seqQueue
{
private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();
public:
    seqQueue(int size = 10)
    {
        elem = new elemType[size];
        maxSize = size; front = rear = 0;
    }
    ~seqQueue() {}
    bool isEmpty() {return front == rear;}
    void enQueue(const elemType &x) ;
    elemType deQueue();
    elemType getHead()
    {return elem[(front + 1) % maxSize];}
};

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp =elem;
 	elem = new elemType[2 * maxSize];
 	for (int i = 1; i < maxSize; ++i)
	 	elem[i] = tmp[(front + i) % maxSize];

 	front = 0; rear = maxSize - 1;
 	maxSize *= 2;
 	delete tmp;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if ((rear + 1) % maxSize == front) doubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}

template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front + 1) % maxSize;
    return elem[front];
}

    struct node{
        node *left,*right,*parent;
        int data;
        node():left(NULL),right(NULL),parent(NULL){}
        node(int n,node *L = NULL,node *R = NULL,node *P=NULL)
        {
            data = n;
            left = L;
            right = R;
            parent = P;
        }
        ~node(){}
    };

class Binary_tree{
public:
    node *root;
    void clear(node *t)
    {
        if(t->left !=NULL)
            clear(t->left);
        if(t->right!=NULL)
            clear(t->right);
        delete t;
    }
    Binary_tree(){
        int n;
        cin>>n>>a>>b;
        for(int i=1;i<=n;++i)
        {
            scanf("%d %d", &tree[i][0] ,&tree[i][1]);
            tree[tree[i][0]][2] = i;
            tree[tree[i][1]][2] = i;
        }
        int root_index;
        for(int i=1;i<=n;++i)
        {
            if(tree[i][2])
            {
                root_index = i;
                break;
            }
        }
        while(tree[root_index][2])
        {
            root_index = tree[root_index][2];
        }

        node *tmp;
        root = new node(root_index);
        seqQueue<node *> que;
        que.enQueue(root);
        while(!que.isEmpty())
        {
            tmp = que.getHead();
            que.deQueue();
            if(tree[tmp->data][0]!=0)
            {
                tmp->left = new node(tree[tmp->data][0],NULL,NULL,tmp);
                que.enQueue(tmp->left);
            }
            if(tree[tmp->data][1]!=0)
            {
                tmp->right = new node(tree[tmp->data][1],NULL,NULL,tmp);
                que.enQueue(tmp->right);
            }
        }
    }
    ~Binary_tree()
    {
        clear(root);
    }
    void display()
    {
        seqQueue<node *> a;
        a.enQueue(root);
        while(!a.isEmpty())
        {
            node *p = a.getHead();
            a.deQueue();
            cout<<p->data<<' ';
            if(p->parent)
                cout<<p->parent->data<<' ';
            else
                cout<<0<<' ';
            if(p->left)
                a.enQueue(p->left);
            if(p->right)
                a.enQueue(p->right);
        }
    }
    int find_lca(int r1,int r2)
    {
        bool trace[1000];
        for(int i=0;i<1000;++i)
            trace[i]=false;
        seqQueue<node *> q1;
        q1.enQueue(root);
        while(!q1.isEmpty())
        {
            node *temp = q1.deQueue();
            if(temp->data==r1)
            {
                temp=temp->parent;
                while(temp!=NULL)
                {
                    trace[temp->data]=true;
                    temp = temp->parent;
                }
                break;
            }
            else
            {
                if(temp->right!=NULL)
                    q1.enQueue(temp->right);
                if(temp->left!=NULL)
                    q1.enQueue(temp->left);
            }
        }

        seqQueue<node *> q2;
        q2.enQueue(root);
        while(!q2.isEmpty())
        {
            node *temp = q2.deQueue();
            if(temp->data==r2)
            {
                temp=temp->parent;
                while(temp!=NULL)
                {
                    if(trace[temp->data]==true)
                        return temp->data;
                    temp = temp->parent;
                }
                break;
            }
            else
            {
                if(temp->right!=NULL)
                    q2.enQueue(temp->right);
                if(temp->left!=NULL)
                    q2.enQueue(temp->left);
            }
        }
    }
};
int main()
{
    Binary_tree t;
    //t.display();
    cout<<t.find_lca(a,b);
    return 0;
}
