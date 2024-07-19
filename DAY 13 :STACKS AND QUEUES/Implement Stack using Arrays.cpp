#include <iostream>
using namespace std;
class stack{
    int arr[100];
    int top;
    int maxsize;
    
    public :
    stack(){
        top=-1;
    }
    
    void push(int val){
        if(top>=masize-1){
            cout<<"stcka overflow"<<endl;
        }else{
            arr[++top]=val;
        }
    }
    
    int pop(){
        if(top<0){
            cout<<"empty stack"<<endl;
        }else{
           int x= arr[top];
           top--;
           return x;
        }
    }
    
    int seek(){
       return arr[top];
    }
    
};
    
FROM GFG :


class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


void MyStack ::push(int x) {
   if(top>1000){
       return;
   }else{
       arr[++top]=x;
   }
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top<0){
        return -1;
    }else{
        int x=arr[top];
        top--;
        return x;
    }
}