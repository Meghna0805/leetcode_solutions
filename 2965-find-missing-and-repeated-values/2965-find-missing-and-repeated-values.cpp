class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> nums;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j<grid.size(); j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        int a, b = 0;

        for(int k =1; k<nums.size(); k++){
            int diff = nums[k] - nums[k-1];

            if(diff == 0) a = nums[k];

            else if(diff == 2) b = nums[k] -1;

        }
        int n = grid.size();
        if( b == 0) {
          b = nums[nums.size()-1] == n*n ? 1 : n*n;
        }
    return {a ,b};
    }
};