#include <iostream>
using namespace std;

template<class elemType>
class list
{
public:
    virtual void clear() = 0;
    virtual int length() const=0;
    virtual void insert(int i,const elemType &x)=0;
    virtual void remove(int i) =0;
    virtual int search(const elemType &x)const=0;
    virtual elemType visit(int i) const=0;
    virtual void traverse()const =0;
    virtual ~list(){};
};

template<class elemType>
class seqList:public list<elemType>
{
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initSize=10);
    seqList(const seqList<elemType> &obj);

    ~seqList(){
        delete [] data;}
    void clear(){currentLength=0;}
    int length()const{
    return currentLength;}
    void insert(int i,const elemType &x);
    void remove(int i);
    int search(const elemType &x)const;
    elemType visit(int i)const{return data[i];}
    void traverse()const;
    seqList<elemType> operator+(const seqList<elemType> &obj)
    {
        seqList<elemType> c(currentLength+obj.currentLength);
        int i=0,j=0;
        for(i=0;i<currentLength;++i)
        {
            c.data[i] = data[i];
        }
        for(j=0;j<obj.currentLength;++j)
        {
            c.data[i+j] = obj.data[j];
        }
        c.currentLength = i+j;
        return c;
    }
    seqList<elemType> &operator=(const seqList<elemType> &obj)
    {
        if(this==&obj)
            return *this;
        delete []data;
        currentLength = obj.currentLength;
        maxSize = obj.maxSize;
        data = new elemType[maxSize];
        for(int i=0;i<currentLength;++i)
            data[i] = obj.data[i];
        return *this;
    }
};
template<class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i=0;i<currentLength;++i)
        data[i] = tmp[i];
    delete [] tmp;
}

template<class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}
template<class elemType>
seqList<elemType>::seqList(const seqList<elemType> &obj)
{
    currentLength = obj.currentLength;
    maxSize = obj.maxSize;
    data = new elemType[maxSize];
    for(int i=0;i<currentLength;++i)
        data[i] = obj.data[i];
}
template<class elemType>
void seqList<elemType>::insert(int i,const elemType &x)
{
    if(currentLength==maxSize)
        doubleSpace();
    for(int j = currentLength;j>i;j--)
        data[j] = data[j-1];
    data[i] = x;
    ++currentLength;
}
template<class elemType>
void seqList<elemType>::remove(int i)
{
    for(int j=i;j<currentLength-1;++j)
        data[j] = data[j+1];
    --currentLength;
}
template<class elemType>
int seqList<elemType>::search(const elemType &x)const
{
    for(int i=0;i<currentLength;++i)
    {
        if(data[i]==x)
            return i;
    }
    return -1;
}
template<class elemType>
void seqList<elemType>::traverse()const
{
    for(int i=0;i<currentLength;++i)
        cout<<data[i]<<' ';
}

template<class elemType>
void combine(seqList<elemType> &a,seqList<elemType> &b)
{
    int n,m;
    elemType tmp;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        a.insert(i,tmp);
    }
    for(int i=0;i<m;++i)
    {
        cin>>tmp;
        b.insert(i,tmp);
    }
    seqList<elemType> c;
    c = a+b;
    c.traverse();
}

int main()
{
    char type[10];
    cin>>type;
    if(type[0]=='i')
    {
        seqList<int> a,b;
        combine(a,b);
    }
    else if(type[0]=='c')
    {
        seqList<char> a,b;
        combine(a,b);
    }
    else
    {
        seqList<double> a,b;
        combine(a,b);
    }
    return 0;
}
