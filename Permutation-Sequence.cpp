class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        //calculate the factorial
        for(int i = 1; i<= n; i++){
            nums.push_back(i);
            fact *= i;
        }
        //making k 0 index based
        k--;
        string result=\\;
        for(int i = 0; i< n ; i++){
            fact = fact / (n - i);
            int index = k / fact;
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k = k%fact;
        }
        return result;
    }
};