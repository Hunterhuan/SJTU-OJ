#include <iostream>
using namespace std;

template <class T>
class priorityQueue
{
  private:
    int currentSize;
    T * data;
    int maxSize;

    void doubleSpace()
    {
        T *tmp = data;
        data = new T[maxSize << 1];
        for (int i = 0; i < currentSize; ++i)
            data[i] = tmp[i];
        maxSize *= 2;
        delete[] tmp;
    }
    void buildHeap()
    {
        if (currentSize <= 1)
            return;
        int tmp = 1;
        while (tmp < currentSize + 1)
            tmp <<= 1;
        for (int i = (tmp >> 1) - 1; i > 0; --i)
            percolateDown(i);
    }
    void percolateDown(int root)
    {
        int chil;
        T tmp;
        for (; root*2 <= currentSize; root = chil)
        {
            chil = root*2;
            if (chil < currentSize && data[chil - 1] > data[chil])
                ++chil;
            if (data[chil - 1] < data[root - 1])
            {
                tmp = data[chil - 1];
                data[chil - 1] = data[root - 1];
                data[root - 1] = tmp;
            }
            else
                break;
        }
    }

  public:
    priorityQueue(int capacity = 100) : maxSize(capacity), currentSize(0)
    {
        data = new T[capacity];
    }
    priorityQueue(const T data[], int size)
    {
        maxSize = size + 5;
        data = new T[maxSize];
        currentSize = size;
        for (int i = 0; i < currentSize; ++i)
            data[i] = data[i];
        buildHeap();
    }
    ~priorityQueue() { delete[] data; }
    bool isEmpty() { return currentSize == 0; }
    void enQueue(const T &x)
    {
    int i;
    T tmp;
    ++currentSize;
    if (currentSize > maxSize)
        doubleSpace();
    data[currentSize - 1] = x;
    i = currentSize;
    while (i > 1)
    {
        if (data[(i/2) - 1] > data[i - 1])
        {
            tmp = data[(i/2) - 1];
            data[(i/2) - 1] = data[i - 1];
            data[i - 1] = tmp;
        }
        i /= 2;
    }
    }
    T deQueue()
    {
        T ans = data[0];
        data[0] = data[--currentSize];
        percolateDown(1);
        return ans;
    }
    T getHead()
    {
        return data[0];
    }
};


int main()
{
    int n,tmp;
    long long res = 0;
    priorityQueue<int> q(50005);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>tmp;
        q.enQueue(tmp);
    }

    for(int j=n;j>1;--j)
    {
        tmp = 0;
        for (int i = 0; i < 2; ++i)
        {
            tmp += q.deQueue();
        }
        res += tmp;
        q.enQueue(tmp);
    }
    cout<<res;
    return 0;
}
