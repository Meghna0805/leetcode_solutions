class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int threshold = floor(nums.size()/2);

        unordered_map<int, int> freq;

        for(int i: nums){
            freq[i]++;
        }

        for(auto i : freq){
            if(i.second>threshold){
                return i.first;
            }
        }
        return 0;
        
    }

};