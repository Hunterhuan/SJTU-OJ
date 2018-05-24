#include <iostream>
#include <stdio.h>
using namespace std;

template<class elemType>
class queue
{public:
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual void push_back(const elemType &x) = 0;
    virtual void pop_front() = 0;
    virtual elemType get_front() = 0;
    virtual ~queue(){}
};

template<class elemType>
class linkqueue:public queue<elemType>
{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x,node *N = NULL)
        {
            data = x;
            next = N;
        }
        node():next(NULL){}
        ~node(){}
    };

    node *front,*rear;
    int length;
public:
    linkqueue(){
        front = rear = NULL;
        length = 0;
    }
    ~linkqueue(){
        node *tmp;
        while(front!=NULL){
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return length==0;
    }
    void push_back(const elemType &x)
    {
        if(rear == NULL)
            front = rear = new node(x);
        else{
            rear->next = new node(x);
            rear = rear->next;
        }
        ++length;
    }
    void pop_front(){
        node *tmp = front;
        front = front->next;
        delete tmp;
        --length;
    }
    elemType get_front(){
        return front->data;
    }
    int size(){
        return length;
    }
    void display(){
        node *tmp = front;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<' ';
            tmp = tmp->next;
        }
        cout<<endl;
    }
};
int main()
{

}
