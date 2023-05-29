class MyQueue {
public:
    stack<int>s1,s2;
    int tmp;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        while(!s2.empty()){
            tmp = s2.top();
            s1.push(tmp);
            s2.pop();
        }
        return x;
    }
    
    int peek() {
       while(!s1.empty()){
            tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
        int x = s2.top();
        while(!s2.empty()){
            tmp = s2.top();
            s1.push(tmp);
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */