class MyStack {
public:
    queue<int> q1,q2;
    int tmp;
    MyStack() {
        
    }
    
    void push(int x) {
        // while(!q1.empty()){
        //     tmp = q1.front();
        //     q2.push(tmp);
        //     q1.pop();
        // }
        // q1.push(x);
        // while(!q2.empty()){
        //     tmp = q2.front();
        //     q1.push(tmp);
        //     q2.pop();
        // }
        q1.push(x);
    }
    
    int pop() {
        // tmp = q1.front();
        // q1.pop();
        // return tmp;
        while(q1.size()>1){
            tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
        
        int x = q1.front();
        q1.pop();
        // while(!q2.empty()){
        //     int tmp = q2.front();
        //     q1.push(tmp);
        //     q2.pop();
        // }
        swap(q1,q2);
        return x;
    }
    
    int top() {
        // tmp = q1.front();
        // return tmp;
        while(q1.size() > 1){
            tmp = q1.front();
            q2.push(tmp);
            q1.pop();
        }
        int x = q1.front();
        q2.push(q1.front());
        q1.pop();
        // while(!q2.empty()){
        //     int tmp = q2.front();
        //     q1.push(tmp);
        //     q2.pop();
        // }
        swap(q1,q2);
        return x;
        
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