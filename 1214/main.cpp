#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int tree[100005][4] = {0};
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
        int data,index;
        node():left(NULL),right(NULL){}
        node(int n,int m,node *L = NULL,node *R = NULL)
        {
            data = n;
            index = m;
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
            scanf("%d%d%d",&tree[i][0],&tree[i][1],&tree[i][3]);
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
        seqQueue<node *> que;
        node *tmp;
        root = new node(tree[root_index][3],root_index);
        que.enQueue(root);
        while(!que.isEmpty())
        {
            tmp = que.getHead();
            que.deQueue();
            int left_index = tree[tmp->index][0];
            int right_index = tree[tmp->index][1];
            if(left_index!=0)
            {
                tmp->left = new node(tree[left_index][3],left_index);
                que.enQueue(tmp->left);
            }
            if(right_index!=0)
            {
                tmp->right = new node(tree[right_index][3],right_index);
                que.enQueue(tmp->right);
            }
        }
    }
    ~Binary_tree()
    {
        clear(root);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void preOrder(node *t)
    {
        if(t==NULL)
            return;
        printf("%d ",t->data);
        node * p = t->left;
        while(p!=NULL)
        {
            preOrder(p);
            p = p->right;
        }
    }
    void postOrder()
    {
        postOrder(root);
    }
    void postOrder(node *t)
    {
        if(t==NULL)
            return ;
        node *p = t->left;
        while(p!=NULL)
        {
            postOrder(p);
            p = p->right;
        }
        printf("%d ",t->data);
    }
    void levelOrder()
    {
        seqQueue<node *> que;
        node *tmp;
        if(root==NULL)
            return ;
        que.enQueue(root);
        while(!que.isEmpty())
        {
            tmp = que.getHead();
            que.deQueue();
            printf("%d ",tmp->data);
            tmp = tmp->left;
            while(tmp!=NULL)
            {
                que.enQueue(tmp);
                tmp = tmp->right;
            }
        }
    }
};
int main()
{
    Binary_tree t;
    t.preOrder();
    cout<<endl;
    t.postOrder();
    cout<<endl;
    t.levelOrder();
    cout<<endl;
    //bool res = t.isCBT();
//    if(res)
//        cout<<'Y';
//    else
//        cout<<'N';
    return 0;
}

