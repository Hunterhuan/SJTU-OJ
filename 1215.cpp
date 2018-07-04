#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
template<class T>
class bernoulli
{
    //儿子兄弟表示法
    struct Node
    {
        T data;
        Node * son;
        Node *brother;
        Node(T n,Node * leftNode=NULL,Node * rightNode=NULL)
        {
            data = n;
            son = leftNode;
            brother = rightNode;
        }
        Node(){}
    };

    Node **forest;
    int maxSize;

    //一个树的递归删除
    void deleteTree(Node *rt)
    {
        Node *son = rt->son, *t;
        while(son!=NULL)
        {
            t = son;
            son = son->brother;
            deleteTree(t);
        }
        delete rt;
    }
    Node* merge(Node *t1, Node *t2)
    {
        Node *mi, *ma;
        if(t1->data < t2->data)
        {
            mi = t1;
            ma = t2;
        }
        else
        {
            mi = t2;
            ma = t1;
        }
        if(mi->son==NULL)
            mi->son = ma;
        else
        {
            Node *t = mi->son;
            while(t->brother !=NULL)
                t = t->brother;
            t->brother = ma;
        }
        return mi;
    }
public:
    bernoulli(int n=100)
    {
        //计算队列所需array长度
        maxSize = int(log(n)/log(2))+1;
        forest = new Node*[maxSize];
        for(int i=0;i<maxSize;++i)
            forest[i] = NULL;
    }
    ~bernoulli()
    {
        //删除每个树
        for(int i=0;i<maxSize;++i)
        {
            if(forest[i]!=NULL)
                deleteTree(forest[i]);
        }
        delete [] forest;
    }

    //找到最小值的队列中坐标
    int findmin()
    {
        int min_index;
        int i=0;
        for(;i<maxSize&&forest[i]==NULL;++i);
        min_index = i;

        for(;i<maxSize;++i)
            if(forest[i]!=NULL && forest[i]->data<forest[min_index]->data)
                min_index=i;
        return min_index;
    }

    void merge(bernoulli &other)
    {
        Node **tmp = forest, *carry;
        int tmpSize = maxSize;
        int m = min(maxSize,other.maxSize);
        int i;
        //求出合并后的树的规模
        if(maxSize<other.maxSize)
        {
            maxSize = other.maxSize;
            if(other.forest[maxSize]!=NULL)
                ++maxSize;
        }
        else if(forest[maxSize]!=NULL)
            ++maxSize;
        //初始化队列
        forest = new Node *[maxSize];
        for(i=0;i<maxSize;++i)
            forest[i] = NULL;

        carry = NULL;
        for(i=0;i<m;++i)
        {
            if(carry==NULL)
            {
                if(tmp[i]==NULL)
                    forest[i] = other.forest[i];
                else
                {
                    if(other.forest[i]==NULL)
                        forest[i] = tmp[i];
                    else
                        carry = merge(other.forest[i],tmp[i]);
                }
            }
            else
            {
                if(tmp[i]!=NULL && other.forest[i]!=NULL)
                {
                    forest[i] = carry;
                    carry = merge(other.forest[i],tmp[i]);
                }
                else
                {
                    if(tmp[i]==NULL && other.forest[i]==NULL)
                    {
                        forest[i] = carry;
                        carry = NULL;
                    }
                    else if(tmp[i]==NULL)
                        carry = merge(other.forest[i],carry);
                    else
                        carry = merge(tmp[i],carry);
                }
            }
        }
        if(other.maxSize == m)
        {
            for(;i<tmpSize;++i)
            {
                if(carry == NULL)
                    forest[i] = tmp[i];
                else
                {
                    if(tmp[i] == NULL)
                    {
                        forest[i] = carry;
                        carry = NULL;
                    }
                    else
                        carry = merge(carry,tmp[i]);
                }
            }
        }
        else
        {
            for(;i<other.maxSize;++i)
            {
                if(carry == NULL)
                    forest[i] = other.forest[i];
                else
                {
                    if(other.forest[i] == NULL)
                    {
                        forest[i] = carry;
                        carry = NULL;
                    }
                    else
                        carry = merge(carry,other.forest[i]);
                }
            }
        }

        if(carry!=NULL)
            forest[i] = carry;
        for(i = 0;i<other.maxSize;++i)
            other.forest[i] = NULL;
        delete [] tmp;
    }

    void enQueue(T x)
    {
        bernoulli tmp;
        tmp.forest[0] = new Node(x);
        merge(tmp);
    }

    T deQueue()
    {
        int index = findmin();
        T top;
        if(index == 0)
        {
            top = forest[0]->data;
            delete forest[0];
            forest[0] = NULL;
            return top;
        }
        Node *t = forest[index],*son,*brother;
        int Size = int(pow(2,index)-1);
        bernoulli tmp(Size);
        top = t->data;
        forest[index] = NULL;

        son = t->son;
        delete t;
        int i=0;
        do{
            tmp.forest[i++] = son;
            brother = son->brother;
            son->brother = NULL;
        }while((son = brother)!=NULL);
//        for(;i<index;++i)
//        {
//            tmp.forest[i] = son;
//            son = son->brother;
//            tmp.forest[i]->brother = NULL;
//        }
        merge(tmp);
        return top;
    }
    bool isEmpty()
    {
        for(int i=0;i<maxSize;++i)
        {
            if(forest[i]!=NULL)
                return false;
        }
        return true;
    }
    T getHead()
    {
        int index = findmin();
        return forest[index]->data;
    }
};
int main()
{
    bernoulli<int> q(20050);
    int M;
    cin>>M;
    char instruction[10];
    int x;
    for(int i=0;i<M;++i)
    {
        cin>>instruction;
        if(instruction[0]=='i')
        {
            cin>>x;
            q.enQueue(x);
        }
        else if(instruction[0]=='d')
        {
            q.deQueue();
        }
        else if(instruction[0]=='m')
        {
            x = q.getHead();
            cout<<x<<endl;
        }
    }
    return 0;
}
