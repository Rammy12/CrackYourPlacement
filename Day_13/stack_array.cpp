#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        int top=-1;
    }
    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }

    }
    int peek()
    {
        if(top>=0 )
        {
            return arr[top];
        }
    }
    bool Isempty()
    {
        if(top==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    return 0;
}