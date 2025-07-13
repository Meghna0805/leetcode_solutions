class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //A map to store the NGE linked to the element in nums2
        unordered_map<int, int> NGE;
        //A monotonic stack for storing the elements as they 
        stack<int> st;
        for(int i = nums2.size()-1; i>=0; i--){
            int curr = nums2[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            if(st.empty()) NGE[curr] = -1;
            else NGE[curr] = st.top();
            st.push(curr);
        }
        vector<int> ans;
        for(int num : nums1){
            ans.push_back(NGE[num]);
        }
        return ans;
    }
};