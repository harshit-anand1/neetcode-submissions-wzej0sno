class MinStack {
public:
    // MinStack() {
        
    // }


    stack<int> s;
    stack<int> ss;
    
    void push(int val) {
        s.push(val);
        if(ss.size() ==0 || val<=ss.top())
        ss.push(val);
    }
    
    void pop() {
        if(s.size()==0) return ;
        int el = s.top();
        s.pop();
        if(el==ss.top())
        ss.pop();
    }
    
    int top() {
        if(!s.empty())
        return s.top();
    }
    
    int getMin() {
        return ss.empty()?-1:ss.top();
    }
};
