class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //when we see operands we need to push that in our stack
        stack<int> st;
        for(string ch: tokens){
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/"){
                st.push(stoi(ch));
            }
            else{
                int ans;
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(ch == "+"){
                    ans=b+a;
                }
                else if(ch == "-"){
                    ans = b-a; 
                }
                else if(ch == "*"){
                    ans = b*a;
                }
                else if(ch == "/"){
                    ans = b/a;
                }
                st.push(ans);
            }
        }
        return st.top();
    }
};