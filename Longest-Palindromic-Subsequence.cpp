class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp){
        //Base Case
        if(i>j) return 0;
        if(i == j) return 1;

        //Checking for memoisation 
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //Recursive choises
        if(s[i] == s[j]){
            dp[i][j] =  2+solve(i+1, j-1, s, dp);
        }
        else{
            dp[i][j] =  max(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1) );
        return solve(0 , s.length()-1, s , dp);
    }
};