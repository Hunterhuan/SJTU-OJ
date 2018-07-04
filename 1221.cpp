#include <iostream>
#include <cstring>
using namespace std;
template<class T>
class bst
{
private:
    struct node
    {
        T data;
        node *left, *right;
        node(const T &x, node *l = NULL, node *r = NULL)
        {
            data = x;
            left = l;
            right = r;
        }
    };
    node *root;
    void clear(node *t)
    {
        if(t==NULL)
            return;
        clear(t->left);
        clear(t->right);
        delete t;
    }
public:
    bst()
    {
        root = NULL;
    }
    ~bst()
    {
        clear(root);
    }
    int get_size(node *t)
    {
        if(t==NULL)
            return 0;
        else
            return get_size(t->left)+get_size(t->right)+1;
    }
    bool find(const T &x)const
    {
        node *now = root;
        while(now!=NULL)
        {
            if(x> now->data)
                now = now->right;
            else if(x<now->data)
                now = now->left;
            else
                return true;
        }
        return false;
    }
    void insert(const T &x, node *&t)
    {
        if(t==NULL)
            t = new node(x, NULL,NULL);
        else if(x < t->data)
            insert(x,t->left);
        else if(x > t->data)
            insert(x,t->right);
        else
            t->left = new node(x,t->left,NULL);
    }
    void insert(const T &x)
    {
        insert(x,root);
    }
    void delete_single(const T &x, node *&t)
    {
        if(t==NULL)
            return;
        if(t->data < x)
            delete_single(x,t->right);
        else if(t->data > x)
            delete_single(x,t->left);
        else
        {
            if(t->right!=NULL && t->left!=NULL)
            {
                node *tmp = t->right;
                while(tmp->left !=NULL)
                    tmp = tmp->left;
                t->data = tmp->data;
                delete_single(t->data,t->right);
            }
            else
            {
                node *tmp = t;
                if(t->left!=NULL)
                    t = t->left;
                else
                    t = t->right;
                delete tmp;
            }
        }
    }
    void delete_single(const T &x)
    {
        delete_single(x,root);
    }
    void delete_less_than(const T &x, node *&t )
    {
        if(t==NULL)
            return;
        if(t->data >= x)
            delete_less_than(x,t->left);
        else
        {
            node *tmp = t;
            clear(t->left);
            t = t->right;
            delete tmp;
            delete_less_than(x,t);
        }
    }
    void delete_less_than(const T &x)
    {
        delete_less_than(x,root);
    }
    void delete_greater_than(const T &x, node *&t)
    {
        if(t==NULL)
            return;
        if(t->data < x)
            delete_greater_than(x,t->right);
        else if(t->data == x)
            clear(t->right);
        else
        {
            node *tmp = t;
            t = t->left;
            clear(tmp->right);
            delete tmp;
            delete_greater_than(x,t);
        }
    }
    void delete_greater_than(const T &x)
    {
        delete_greater_than(x,root);
    }
    void delete_interval(const T &a, const T &b)
    {
        delete_interval(a,b,root);
    }
    void delete_interval(const T &a, const T &b, node *&t)
    {
        if(t==NULL)
            return;
        if(t->data <= a)
            delete_interval(a,b,t->right);
        else if(t->data >=b)
            delete_interval(a,b,t->left);
        else{
            delete_single(t->data,t);
            delete_interval(a,b,t);
        }
    }
    bool findith(int i,T &x)
    {
        return findith(i,x,root);
    }
    bool findith(int i, T &x, node *t)
    {
        if(t==NULL)
            return false;
        int rs = get_size(t->left);
        if(rs==i-1)
        {
            x = t->data;
            return true;
        }
        if(rs >= i)
            return findith(i,x,t->left);
        else
            return findith(i-rs-1,x,t->right);
    }

};
int main()
{
    int N;
    string str;
    cin>>N;
    int tmp,x;
    bst<int> b;
    for(int i=0;i<N;++i)
    {
        cin>>str;
        cin>>tmp;
        if(str=="insert")
            b.insert(tmp);
        else if(str=="find")
        {
            if(b.find(tmp))
                cout<<'Y'<<endl;
            else
                cout<<'N'<<endl;
        }
        else if(str=="find_ith")
        {
            if(b.findith(tmp,x))
                cout<<x<<endl;
            else
                cout<<'N'<<endl;
        }
        else if(str=="delete")
        {
            b.delete_single(tmp);
        }
        else if(str=="delete_greater_than")
        {
            b.delete_greater_than(tmp);
        }
        else if(str=="delete_less_than")
        {
            b.delete_less_than(tmp);
        }
        else if(str=="delete_interval")
        {
            cin>>x;
            b.delete_interval(tmp,x);
        }
    }
    return 0;
}
