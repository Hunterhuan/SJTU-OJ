#include <iostream>
using namespace std;

//使用别人的code

class bernoulli
{
private:
    struct node
    {
        int data;
        node *son, *brother;

        node() {}
        node(int x, node *p = NULL, node *q = NULL) :data(x), son(p), brother(q) {}
    };

    node **forest;
    int len;

    node* merge(node *t1, node *t2)
    {
        if (t1->data > t2->data)
            return merge(t2, t1);
        t2->brother = t1->son;
        t1->son = t2;
        return t1;
    }

    void clear(node *p)
    {
        if (p)
        {
            node *tmp = p->son;
            delete p;
            while (tmp)
            {
                p = tmp->brother;
                clear(tmp);
                tmp = p;
            }
        }
    }

    void doubleSpace()
    {
        node **tmp = new node*[len * 2]();
        for (int i = 0;i < len;++i) tmp[i] = forest[i];
        len *= 2;
        delete[]forest;
        forest = tmp;
    }
public:
    bernoulli(int initSize=10):len(initSize)
    {
        forest = new node*[len]();
    }
    ~bernoulli()
    {
        for (int i = 0;i < len;++i) clear(forest[i]);
        delete[]forest;
    }
    void insert(int x)
    {
        node *tmp = new node(x);
        int i;
        for (i = 0;i < len;++i)
        {
            if (!forest[i]) break;
            tmp = merge(forest[i], tmp);
            forest[i] = NULL;
        }
        if (i == len) doubleSpace();
        forest[i] = tmp;
    }
    void merge(bernoulli &other)
    {
        if (&other == this) return;
        while (len <= other.len)doubleSpace();
        node* carry = NULL;
        for (int i = 0;i < other.len;++i)
        {
            if (forest[i] && other.forest[i])
            {
                if (carry)
                {
                    carry = merge(carry, other.forest[i]);
                    other.forest[i] = NULL;
                }
                else
                {
                    carry = merge(forest[i], other.forest[i]);
                    other.forest[i] = forest[i] = NULL;
                }
            }
            else
            {
                if (carry)
                {
                    if (forest[i] || other.forest[i])
                    {
                        carry = merge((other.forest[i] == NULL ? forest[i] : other.forest[i]), carry);
                        other.forest[i] = forest[i] = NULL;
                    }
                    else
                    {
                        forest[i] = carry;
                        carry = NULL;
                    }
                }
                else
                {
                    if (!forest[i])
                    {
                        forest[i] = other.forest[i];
                        other.forest[i] = NULL;
                    }
                }
            }
        }
        if (carry) forest[other.len] = carry;
    }
    int pop()
    {
        int min = 0x7fffffff;
        int pos = -1;
        for (int i = 0;i < len;++i)
        {
            if (forest[i] && forest[i]->data < min)
            {
                min = forest[i]->data;
                pos = i;
            }
        }
        if (pos == -1) return -1;
        bernoulli sub(pos+1);       //pos可能为0；
        int i = pos - 1;
        node *res = forest[pos]->son;
        while (res)
        {
            sub.forest[i--] = res;
            res = res->brother;
            sub.forest[i + 1]->brother = NULL; //因为插入用的是反序。
        }
        delete forest[pos];
        forest[pos] = NULL;
        merge(sub);
        return min;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int x, y;
    bernoulli *q = new bernoulli[N];
    for (int i = 0;i < N;++i)
    {
        cin >> x;
        q[i].insert(x);
    }
    int command;
    for (int i = 0;i < M;++i)
    {
        cin >> command;
        switch (command)
        {
        case 0:
            cin >> x >> y;
            q[x].merge(q[y]);
            break;
        case 1:
            cin >> x;
            cout << q[x].pop() << '\n';
            break;
        case 2:
            cin >> x >> y;
            q[x].insert(y);
        }
    }
    cin.get();
    cin.get();
    delete[]q;
    return 0;
}
