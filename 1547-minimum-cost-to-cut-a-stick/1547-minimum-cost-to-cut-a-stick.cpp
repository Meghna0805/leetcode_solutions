class Solution {
public:
    int stickCut(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        //Base case
        if(i>j) return 0;

        //Check dp if already present
        if(dp[i][j]!=-1) return dp[i][j];

        int mini = INT_MAX;
        //Recurrsion

        for(int index =i; index<=j; index++){
            int cost = cuts[j+1]-cuts[i-1] + stickCut(i, index-1, cuts, dp) + stickCut(index+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(c+1, vector<int>(c+1, -1));
        return stickCut(1, c, cuts , dp);
    }
};