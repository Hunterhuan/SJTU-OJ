#include <iostream>

using namespace std;

template<class T>
class seqstack
{
private:
    T *data;
    int top_p;
    int maxSize;
    void doubleSpace()
    {
        T *tmp = data;
        data = new T[2*maxSize];
        for(int i=0;i<maxSize;++i)
            data[i] = tmp[i];
        maxSize *=2;
        delete [] tmp;
    }
public:
    seqstack(int initSize = 10)
    {
        data = new T[initSize];
        maxSize = initSize;
        top_p = -1;
    }
    ~seqstack(){
    delete [] data;
    }
    bool isempty()const
    {
        return top_p==-1;
    }
    void push(const T &x)
    {
        if(top_p==maxSize-1)
            doubleSpace();
        data[++top_p] = x;
    }
    T pop()
    {
        return data[top_p--];
    }
    T top()
    {
        return data[top_p];
    }
};
int main()
{
    seqstack<int> a;
    a.push(1);
    a.push(2);
    cout<<a.pop();
    cout<<a.pop();
    return 0;
}
