#include <iostream>

using namespace std;
class bigint
{
    friend ostream &operator<<(ostream &os,const bigint &c);
    friend istream &operator>>(istream &is,bigint &c);
public:
    struct node{
        int value;
        node *next;
        node():next(NULL){}
        node(const int &v,node *n = NULL):value(v),next(n){}
    };
    node *head;
    int size;

    bigint():size(0)
    {
        head = new node;
    }
    bigint(const bigint &c)
    {
        head = new node;
        size = c.size;
        node *tmp = c.head->next;
        node *tmp2 = head;
        while(tmp!=NULL)
        {
            tmp2->next = new node(tmp->value,NULL);
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
    }
    ~bigint(){
        clear();
        delete head;
    }
    void clear()
    {
        node *p = head->next;
        while(p!=NULL)
        {
            node *q = p;
            p = p->next;
            delete q;
        }
    }
    void add(int n)
    {
        node *p = head;
        p->next = new node(n,p->next);
        ++size;
    }
    void traverse()const
    {
        node *p = head->next;
        while(p){
            cout<<p->value;
            p = p->next;
        }
    }
    int length()
    {
        return size;
    }
    bigint& operator=(const bigint &c)
    {
        if(this!=&c){
            clear();
            size = c.size;
            node *tmp = c.head->next;
            node *tmp2 = head;
            while(tmp!=NULL)
            {
                tmp2->next = new node(tmp->value,NULL);
                tmp2 = tmp2->next;
                tmp = tmp->next;
            }
        }
        return *this;
    }
    bigint operator+(const bigint &b)
    {
        bigint c;
        node *link_a = head->next;
        node *link_b = b.head->next;
        node *link_c = c.head;
        c.size = 0;
        bool flag = false;
        while(true)
        {
            if(link_a==NULL &&link_b==NULL && !flag)
                break;
            if(link_a==NULL &&link_b==NULL && flag)
            {
                link_c->next = new node(1,NULL);
                ++c.size;
            }
            if(link_a!=NULL &&link_b!=NULL)
            {
                int res = link_a->value+link_b->value;
                if(flag)
                {
                    ++res;
                    flag = false;
                }
                if(res>=10)
                {
                    flag = true;
                    res = res%10;
                }
                link_c->next = new node(res,NULL);
                link_c = link_c->next;
                link_b = link_b->next;
                link_a = link_a->next;
                ++c.size;

            }
            else
            {
                node *tmp;
                int value1=0,value2=0;
                if(link_a)
                    value1 = link_a->value;
                if(link_b)
                    value2 = link_b->value;
                int res = value1+value2;
                if(flag)
                {
                    ++res;
                    flag = false;
                }
                if(res>=10)
                {
                    flag = true;
                    res = res%10;
                }
                link_c->next = new node(res,NULL);
                link_c = link_c->next;
                ++c.size;
                if(link_b)
                    link_b = link_b->next;
                if(link_a)
                    link_a = link_a->next;
            }
        }
        return c;
    }
};
istream &operator>>(istream &is,bigint &c)
{
    char s[1000005];
    cin>>s;
    char tmp = s[0];
    int i=0;
    while(tmp)
    {
        c.add(tmp-'0');
        tmp = s[++i];
    }
    return is;
}
ostream &operator<<(ostream &os,const bigint &c)
{
    int len=0;
    int tmp[100005];
    bigint::node *p = c.head->next;
    while(p)
    {
        tmp[len] = p->value;
        p = p->next;
        ++len;
    }
    for(int i=len-1;i>=0;--i)
    {
        cout<<tmp[i];
    }
    return os;
}
int main()
{
    bigint q;
    cin>>q;
    bigint p;
    cin>>p;
    bigint c;
    c = q+p;
    cout<<c;
    return 0;
}
