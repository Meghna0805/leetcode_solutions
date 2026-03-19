class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // forming the max table
        int n=prices.size();
        vector<int> maxT (n, 0);
        maxT[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxT[i] = max(prices[i], maxT[i+1]);
        }

        //using dp
        for(int i=0; i<n; i++){
            int profit = maxT[i] - prices[i];
            if(i>0) prices[i] = max(profit, prices[i-1]);
            else prices[i] = profit;
        }

        return prices[n-1];
    }
};