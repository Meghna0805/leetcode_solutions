class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1; i>=0; i--) swap(nums1[i], nums1[i+n]);
        int i=n, j=0, k=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]) {
                swap(nums1[i], nums1[k]);
                i++;
            }
            else{
                swap(nums2[j], nums1[k]);
                j++;
            }
            k++;
        }
        if(j<nums2.size()){
            for(;j<nums2.size();j++){
                nums1[k] = nums2[j];
                k++;
            }
        }
    }
};