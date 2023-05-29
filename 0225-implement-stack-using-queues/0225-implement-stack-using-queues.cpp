class MyStack {
public:
    queue<int> q1,q2;
    int tmp;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            tmp = q2.front();
            q1.push(tmp);
            q2.pop();
        }
    }
    
    int pop() {
        tmp = q1.front();
        q1.pop();
        return tmp;
    }
    
    int top() {
        tmp = q1.front();
        return tmp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */