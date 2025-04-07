class Solution {
public:
    void helper(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        if(index == candidates.size() || target<0) return;

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            helper(index, temp, ans, candidates, target-candidates[index]);
            temp.pop_back();
        }

        helper(index+1, temp, ans, candidates, target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, temp , ans, candidates, target);
        return ans;
    }
};