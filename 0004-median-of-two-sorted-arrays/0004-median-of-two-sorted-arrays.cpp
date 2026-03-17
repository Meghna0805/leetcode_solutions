class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int n: nums1) merged.push_back(n);
        for(int n: nums2) merged.push_back(n);

        sort(merged.begin(), merged.end());

        int n = merged.size();

        if(n%2 == 0) return (merged[n/2-1]+merged[n/2])/2.0;

        else return merged[n/2];
    }
};