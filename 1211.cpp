#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int tree[100005][3] = {0};

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



class Binary_tree{
private:
    struct node{
        node *left,*right;
        int data;
        node():left(NULL),right(NULL){}
        node(int n,node *L = NULL,node *R = NULL)
        {
            data = n;
            left = L;
            right = R;
        }
        ~node(){}
    };
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
        cin>>n;
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
                tmp->left = new node(tree[tmp->data][0]);
                que.enQueue(tmp->left);
            }
            if(tree[tmp->data][1]!=0)
            {
                tmp->right = new node(tree[tmp->data][1]);
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
            if(p->left)
                a.enQueue(p->left);
            if(p->right)
                a.enQueue(p->right);
        }
    }
    bool isCBT()
    {
        if(root==NULL)
            return false;
        seqQueue<node *> q;
        q.enQueue(root);
        while(!q.isEmpty())
        {
            node * top = q.getHead();
            if(top->left && top->right)
            {
                q.deQueue();
                q.enQueue(top->left);
                q.enQueue(top->right);
            }
            if(top->left==NULL &&top->right)
            {
                return false;
            }
            if((top->left &&top->right==NULL)||(top->left==NULL&&top->right==NULL))
            {
                q.deQueue();
                while(!q.isEmpty())
                {
                    top = q.getHead();
                    if(top->left==NULL &&top->right==NULL)
                        q.deQueue();
                    else
                        return false;
                }
                return true;
            }
        }
        return true;
    }
};
int main()
{
    Binary_tree t;
    //t.display();
    bool res = t.isCBT();
    if(res)
        cout<<'Y';
    else
        cout<<'N';
    return 0;
}
