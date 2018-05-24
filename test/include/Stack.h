#ifndef STACK_H
#define STACK_H

template<class elemType>
class Stack
{
    private:
        elemType *data;
        int top_p;
        int maxSize;
        void doubleSpace(){
            elemType *tmp = data;
            data = new elemType[maxSize*2];
            for(int i=0;i<maxSize;++i)
                data[i] = tmp[i];
            maxSize *=2;
            delete [] tmp;
        }
    public:
        Stack(int initSize=10){
            data = new elemType[initSize];
            maxSize = initSize;
            top_p = -1;
        }
        virtual ~Stack(){
            delete [] data;
        }
        void pop(){
            top_p--;
        }
        void push(const elemType &x){
            if(top_p+1==maxSize)
                doubleSpace();
            data[++top_p] = x;
        }
        bool isEmpty() const{
            return top_p==-1;
        }
        elemType top() const{
            return data[top_p];
        }
};

#endif // STACK_H
