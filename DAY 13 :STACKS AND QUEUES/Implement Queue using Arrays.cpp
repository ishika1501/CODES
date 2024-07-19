

#include <iostream>
using namespace std;

class queue{
    int arr[1000];
    int front ;
    int rare;
    int currsize=0;
    int n=1000;
    
    public:
    queue(){
        front=0 ;
        rare=-1;
    }
    
    void enqueue(int val){
        if(currsize>n){
            cout<<"stack overflow"<<endl;
        }else{
            rare++;
            arr[rare%n]=val;
            currsize++;
        }
    }
    
    void dequeue(){
        if(currsize<0){
            cout<<"Empty queue"<<endl;
        }
        else{
            int x=arr[front];
            front++;
            currsize--;
            return val
        }
    }
    
    void isEmpty(){
        return currsize()==0;
    }
    
    int size() const {
        return currentSize;
    }
};


FROM GFG:

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};


//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
      arr[rear]=x;
      rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        if(front==rear)return -1;
        else
        return arr[front++];   
}