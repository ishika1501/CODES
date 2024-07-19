
class MyQueue {
public:
    MyQueue() {}
    stack<int>input , output;

    void push(int x) {
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        input.push(x);
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    
    int pop() {
        int x=output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        return output.top();
    }
    
    bool empty() {
        return !output.size();
    }
};