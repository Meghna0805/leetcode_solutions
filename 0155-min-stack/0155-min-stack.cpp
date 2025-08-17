class MinStack {
public:
    stack<long> st;
    long min;
    MinStack() {
        
    }
    //To iss approach me hum directly value nhi store krenge what we gonna do is hum diff store krnege taaki hum ek stack se hi apna kaam chala le and O(1) me saare func bnn bhi jae dekho kaise
    void push(int val) {
        //hum apne "st" stack me original value nhi store krr rhe but diff of val-min store krenge taaki jb hum top() or pop() se values retrieve krna chahe to easily trick lga krr krr ske
        if(st.empty()) {
            st.push(0); //just ek placeholder value
            min = val; //ab humara min h val
        }
        else{
            //agr st empty nhi h to usme diff= val - min push krr do
            st.push(val-min);
            //ab ye bhi check kro ki jo val use hui h vo khi min se choti to nhi? if yess to apna min bhi update krlo
            if(val<min) min = val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        //pop operation easy h bss ek variable lo pop usme st ka top store krr lo
        long pop = st.top();
        st.pop();
        //ab check kro if jo pop me value h vo <0 h to mtlb yha min update hua tha 
        if(pop <0) min = min-pop;
    }
    
    int top() {
        //top ko bhi store krr lo variable me
        long top = st.top();
        //Ab check kro khi top <0 to nhi h agr h to mtlb iss point prrr bhi min chng hua tha
        return top>=0? top+min : int(min);
    }
    
    int getMin() {
        return int(min);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */