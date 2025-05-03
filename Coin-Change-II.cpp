class Solution {
public:
    int countWays(int index, int amount, vector<int>& coins, vector<vector<int>>& dp){
        //Base case
        if(amount == 0) return 1;
        if(index == coins.size()) return 0;

        //If already computed(memoisation)
        if(dp[index][amount] != -1) return dp[index][amount];

        int ways = 0;
        
        //Including curr coin if possible
        if(coins[index] <= amount){
            ways += countWays(index, amount - coins[index] , coins, dp);
        }
        //Exclude the curr coin
        ways+=countWays(index+1, amount, coins, dp);

        return dp[index][amount] = ways;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        return countWays(0 , amount, coins, dp);
    }
};