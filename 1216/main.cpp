#include <iostream>
#include <stdio.h>
using namespace std;
template<class T>
class priorityQueue
{
public:
    priorityQueue(int init = 100)
    {
        data = new T[init];
        maxSize = init;
        currentSize = 0;
    }
    priorityQueue(const T num[], int size)
    {
        maxSize = size + 10;
        currentSize = size;
        data = new T[maxSize];
        for(int i=0;i<size;++i)
            data[i+1] = num[i];
        buildHeap();
    }
    ~priorityQueue()
    {
        delete [] data;
    }
    int findmin(T x)
    {
        T m;
        int index = -1;
        for(int i=1;i<=currentSize;++i)
        {
            if(data[i]>x &&(index==-1 || data[i]<m))
            {
                m = data[i];
                index = i;
            }
        }
        return index;
    }
    void decreaseKey(int i, T n)
    {
        T x;
        int index = i;
        data[index] -= n;
        for(x = data[i] ; index>1 && x<data[index/2]; index/=2)
            data[index] = data[index/2];
        data[index] = x;
    }
    bool isEmpty()const
    {
        return currentSize == 0;
    }
    void enQueue(const T&x)
    {
        if(currentSize==maxSize-1)
            doubleSpace();
        int index = ++currentSize;
        for(;index>1&&x<data[index/2];index/=2)
            data[index] = data[index/2];
        data[index] = x;
    }
    T deQueue()
    {
        T x = data[1];
        data[1] = data[currentSize];
        currentSize--;
        percolateDown(1);
        return x;
    }
    T getHead()const
    {
        return data[1];
    }
private:
    int currentSize;
    T *data;
    int maxSize;
    void doubleSpace()
    {
        T *tmp = data;
        maxSize *=2;
        data = new T[maxSize];
        for(int i=0;i<=currentSize;++i)
            data[i] = tmp[i];
        delete [] tmp;
    }
    void buildHeap()
    {
        for(int i=currentSize/2;i>0;--i)
            percolateDown(i);
    }
    void percolateDown(int index)
    {
        int child;
        T tmp = data[index];
        for(;index*2<=currentSize;index=child)
        {
            child = index*2;
            if(child!=currentSize&&data[child+1]<data[child])
                child++;
            if(data[child]<tmp)
                data[index] = data[child];
            else
                break;
        }
        data[index] = tmp;
    }
};
int main()
{
    priorityQueue<int> q(20050);
    int M;
    cin>>M;
    char instruction[10];
    int x,x1;
    for(int i=0;i<M;++i)
    {
        cin>>instruction;
        if(instruction[0]=='i')
        {
            cin>>x;
            q.enQueue(x);
        }
        else if(instruction[0]=='f')
        {
            cin>>x;
            cout<<q.findmin(x)<<endl;
        }
        else
        {
            cin>>x>>x1;
            q.decreaseKey(x,x1);
        }
    }
    return 0;
}
