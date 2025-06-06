class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int LtoR = 1;
        int RtoL = 1;
        int maxProd = INT_MIN;

        for(int i = 0; i<n; i++){
            if(LtoR == 0) LtoR = 1;

            if(RtoL == 0) RtoL = 1;

            LtoR*=nums[i];

            int j = n-i-1;
            RtoL*=nums[j];

            maxProd = max({LtoR, RtoL, maxProd});

        }
        return maxProd;

    }
};