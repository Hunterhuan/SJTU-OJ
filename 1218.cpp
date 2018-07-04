#include <iostream>

using namespace std;


template<class T>
class Set{
private:
    T *data;
    int size;
    int maxSize;
    void double_space()
    {
        maxSize <<= 1;
        T *tmp = data;
        data = new T [maxSize];
        for(int i=0;i<size;++i)
            data[i] = tmp[i];
        delete [] tmp;
    }

    bool exist(T x)const
    {
        for(int i=0;i<size;++i)
            if(x==data[i])
                return true;
        return false;
    }
public:
    Set(int l=20)
    {
        size = 0;
        maxSize = l;
        data = new T [maxSize];
    }
    Set(const Set<T> &b)
    {
        size = b.size;
        maxSize = b.maxSize;
        data = new T [maxSize];
        for(int i=0;i<size;++i)
            data[i] = b.data[i];
    }
    ~Set()
    {
        delete [] data;
    }

    int get_size()
    {
        return size;
    }
    void insert(T x)
    {
        int i=0;
        for(;i<size;++i)
        {
            if(data[i]==x)
                return;
            if(data[i]>x)
                break;
        }
        if(size==maxSize)
            double_space();
        for(int j=size;j>=i;--j)
            data[j+1] = data[j];
        data[i] = x;
        size++;
    }
    void earse(T x)
    {
        int i;
        for(i=0;i<size;++i)
            if(data[i]==x)
                break;
        if(i!=size)
        {
            for(;i<size-1;++i)
                data[i] = data[i+1];
            --size;
        }
    }
    void Set_intersection(T other [], int length)
    {
        T *tmp;
        tmp = new T [maxSize];
        int current = 0;
        for(int i=0;i<size;++i)
        {
            int j=0;
            for(;j<length;++j)
                if(other[j]==data[i])
                    break;
            if(j!=length)
            {
                tmp[current] = data[i];
                ++current;
            }
        }
        delete [] data;
        data = tmp;
        size = current;
    }
    void Set_union(T other[], int length)
    {
        for(int i=0;i<length;++i)
            insert(other[i]);
    }
    void Set_difference(T other[], int length)
    {
        T *tmp = new T [maxSize];
        int current = 0;
        for(int i=0;i<size;++i)
        {
            int j=0;
            for(;j<length;++j)
            {
                if(other[j]==data[i])
                    break;
            }
            if(j==length)
            {
                tmp[current] = data[i];
                ++current;
            }
        }
        size = current;
        delete [] data;
        //cout<<tmp[0]<<' '<<tmp[1]<<endl;
        data = tmp;
    }
    void display()
    {
        for(int i=0;i<size;++i)
            cout<<data[i]<<' ';
        cout<<endl;
    }
};
int main()
{
    int N;
    cin>>N;
    char s;
    int length;
    Set<int> ans(1000);
    for(int i=0;i<N;++i)
    {
        cin>>s;
        cin>>length;
        int arr[length];
        for(int j=0;j<length;++j)
            cin>>arr[j];
        if(s=='+')
        {
            ans.Set_union(arr,length);
        }
        else if(s=='-')
        {
            ans.Set_difference(arr,length);
        }
        else
        {
            ans.Set_intersection(arr,length);
        }
        ans.display();
    }
    return 0;
}
