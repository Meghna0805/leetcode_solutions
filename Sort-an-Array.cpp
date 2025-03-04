class Solution {
public:
    void heapify(vector<int>& nums, int n, int index){
        
        int largest = index;
        int left = 2* index + 1;
        int right = 2* index + 2;

        if(left < n && nums[left] > nums[largest]){
            largest = left;
        }
        if(right < n && nums[right] > nums[largest]){
            largest  = right;
        }
        if(largest != index){
            swap(nums[index] , nums[largest]);
            heapify(nums, n, largest);
        }
    }
    void heapSort(vector<int>& nums){
        int n = nums.size();
        for(int i = (n/2)  -1; i>=0; i-- ){
            heapify(nums, n , i);
        }

        for(int i = n-1; i>=0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};