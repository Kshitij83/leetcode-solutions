class MinStack {
public:
    MinStack() {
    }
    stack<long> st;
    long mini = INT_MAX;
    void push(int val) {
        long value = val;
        if(st.empty()){
            st.push(value);
            mini = value;
        } 
        else{
            if(value>=mini) st.push(value);
            else{
                st.push(2*value - mini);
                mini = value;
            }
        }
    }
    void pop() {
        if(!st.empty()){
            long d = st.top();
            if(d>=mini) st.pop();
            else{
                st.pop();
                mini = 2*mini - d;
            }
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long d = st.top();
        if(d>=mini) return d;
        else return mini;
    }
    
    int getMin() {
        return mini;
    }

// Time Complexity: O(1)
// Space Complexity: O(2N)
    // MinStack() {
    // }

    // stack<pair<int,int>> st;
    // void push(int val) {
    //     int min1;
    //     if(st.empty()) min1=val;
    //     else{
    //         min1 = min(st.top().second,val);
    //     }
    //     st.push({val,min1});
    // }
    
    // void pop() {
    //     if(!st.empty()){
    //         st.pop();
    //     }
    // }
    
    // int top() {
    //     if(st.empty()) return -1;
    //     return st.top().first;
    // }
    
    // int getMin() {
    //     if(st.empty()) return -1;
    //     return st.top().second;
    // }


    //TC - O(logn), SC - O(n)
    // MinStack() {
    // }
    // stack<int> st;
    // map<int,int> mpp;
    // void push(int val) {
    //     st.push(val);
    //     mpp[val]++;
    // }
    
    // void pop() {
    //     if(!st.empty()){
    //         int d = st.top();
    //         st.pop();
    //         mpp[d]--;
    //         if(mpp[d]==0) mpp.erase(d);
    //     }
    // }
    
    // int top() {
    //     if(st.empty()) return -1;
    //     return st.top();
    // }
    
    // int getMin() {
    //     if(st.empty()) return -1;
    //     return mpp.begin()->first;
    // }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */