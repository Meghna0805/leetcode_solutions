class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int counteven = 0;
        int countodd = 0;
        int alternative = 1;

        for(int &num : nums){

            if(num%2 == 0) counteven++;
  
        }
        for(int &num : nums){

            if(num%2 != 0) countodd++;
  
        }


        int parity = nums[0]%2;

        for(int i=1; i<nums.size(); i++){
            int currParity = nums[i]%2;
            if(currParity != parity) {alternative++;
            parity = currParity;}
        }
        return max({alternative, countodd, counteven});
    }
};