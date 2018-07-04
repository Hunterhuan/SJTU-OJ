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
int main(){
    int timer=0;
    double bus_wait=0,van_wait=0;
    linkqueue<int> bus,van;
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        if(tmp1==1)
            van.push_back(tmp2);
        else
            bus.push_back(tmp2);
    }
    double n1 = bus.size(),n2 = van.size();
    for(timer = 0; true;timer+=10){
        int count = 0;
        for(;count<8 && !bus.isEmpty() &&bus.get_front()<=timer;++count){
            bus_wait += timer-bus.get_front();
            bus.pop_front();
        }
        for(;count<10 &&!van.isEmpty() &&van.get_front()<=timer;++count){
            van_wait += timer-van.get_front();
            van.pop_front();
        }
        for(;count<10 && !bus.isEmpty() &&bus.get_front()<=timer;++count){
            bus_wait += timer-bus.get_front();
            bus.pop_front();
        }
        if(bus.isEmpty() && van.isEmpty())
            break;
    }
    printf("%.3f",bus_wait/n1);
    cout<<' ';
    printf("%.3f",van_wait/n2);
    return 0;
}
