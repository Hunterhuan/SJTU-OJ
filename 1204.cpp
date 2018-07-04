#include <iostream>

using namespace std;
class edit
{
private:
    struct Node
    {
        char data[2500];
        int length;
        Node *next;
        Node(char x[]="",int l = 0,Node *n=NULL)
        {
            length = 0;
            for(int i=0;i<2500;++i)
            {
                ++length;
                data[i] = x[i];
                if(x[i]=='\0')
                    break;
            }
            --length;
            next = n;
        }
        ~Node()
        {
        }
    };


    Node *head;
    int line;
public:

    edit()
    {
        line = 0;
        char text[2500];

        Node *p = head = new Node;
        while(true)
        {
            cin.getline(text,2500);
            if(text[0]=='*')
                break;
            p->next = new Node(text);
            p = p->next;
            ++line;
        }
    }

    ~edit()
    {
        Node *p = head->next,*q;
        while(p!=NULL)
        {
            q = p->next;
            int count=0;
            cout<<p->data<<endl;
            delete p;
            p = q;
        }
        line = 0;
        delete head;
    }

    int lines()
    {
        return line;
    }

    void list(int n1,int n2)
    {
        if(n1<=0 || n1>lines()||n1>n2||n2<=0 ||n2>lines())
        {
            cout<<"Error!"<<endl;
            return;
        }
        Node *p = head->next ,*q;
        int count=1;
        while(p!=NULL)
        {
            q = p->next;
            if(count>=n1 && count<=n2)
                cout<<p->data<<endl;
            p = q;
            ++count;
        }
    }
    void del(int i,int j,int num)
    {
        if(i<=0 || i>lines())
        {
            cout<<"Error!"<<endl;
            return;
        }
        Node *p = head->next,*q;
        int count=1;
        while(p!=NULL)
        {
            q = p->next;
            if(count==i)
            {
                int str_length = p->length;
                if(j>=str_length||str_length<j+num-1 || j<=0 || num<0)
                {
                    cout<<"Error!"<<endl;
                    return;
                }
                int begin = j-1;
                while(true)
                {
                    p->data[begin] = p->data[begin+num];
                    if(begin + num ==str_length)
                        break;
                    ++begin;
                }
                p->length -= num;
            }
            p = q;
            ++count;
        }
    }
    void ins(int i,int j,char add[],int l)
    {
        Node *p = head->next,*q;
        int count=1;
        if(i<=0 || i>lines())
        {
            cout<<"Error!"<<endl;
            return;
        }

        while(p!=NULL)
        {
            q = p->next;
            if(count==i)
            {
                int str_length=p->length;
                if(j>str_length+1 || j<=0)
                {
                    cout<<"Error!"<<endl;
                    return;
                }

                for(int k=str_length;k>=j-1;--k)
                    p->data[k+l] = p->data[k];

                for(int k=0;k<l;++k)
                    p->data[j+k-1] = add[k];
                p->length += l;
                break;
            }
            p = q;
            ++count;
        }
    }
};

int main()
{
    edit txt;
    char instruction[10];
    while(true)
    {
        cin>>instruction;
        if(instruction[0]=='l')
        {
            int n1,n2;
            cin>>n1>>n2;
            txt.list(n1,n2);
        }
        else if(instruction[0]=='i')
        {
            int n1,n2;
            cin>>n1>>n2;
            char str[200];
            char tmp;
            cin.get(tmp);
            cin.getline(str,200);
            int length=0;
            for(length=0;length<2500;++length)
                if(str[length]=='\0')
                    break;
            txt.ins(n1,n2,str,length);
        }
        else if(instruction[0]=='d')
        {
            int n1,n2,n3;
            cin>>n1>>n2>>n3;
            txt.del(n1,n2,n3);
        }
        else if(instruction[0]=='q')
        {
            break;
        }
    }
    return 0;
}
