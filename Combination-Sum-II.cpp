class Solution {
public:
    void helper(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            helper(i+1, temp, ans, candidates, target-candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, temp, ans, candidates, target);
        return ans;
    }
};