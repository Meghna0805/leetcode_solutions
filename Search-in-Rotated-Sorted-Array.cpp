#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the pivot (smallest element in rotated sorted array)
    int pivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid;

        while (s < e) {
            mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {  // Pivot is in the right half
                s = mid + 1;
            } else {  // Pivot is in the left half
                e = mid;
            }
        }
        return s;  // Pivot index
    }

    // Standard binary search function
    int BinarySearch(int s, int e, vector<int>& nums, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;  // Found target
            }
            if (target > nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;  // Target not found
    }

    int search(vector<int>& nums, int target) {
        int pivots = pivot(nums);
        int n = nums.size();

        // Search in the correct half of the rotated array
        if (target >= nums[pivots] && target <= nums[n - 1]) {
            return BinarySearch(pivots, n - 1, nums, target);
        } else {
            return BinarySearch(0, pivots - 1, nums, target);
        }
    }
};
