class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);
        for(int i = index; i<nums.size(); i++){
            //Skip duplicates at same level
            if(i > index && nums[i] == nums[i-1]) continue;
            
            sub.push_back(nums[i]);
            helper(i + 1, nums, sub, ans);
            sub.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> ans;
        helper(0, nums, sub, ans);
        return ans;
    }
};