class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0;
        int e = (row*col) - 1;
        int mid = s + (e-s)/ 2;
        
        //applying binary search vali approach 
        while(s <= e){
            //bss upr jo mid nikala h vo linear array me h to humee to mid 2d array ka chahiye 
            int element  = matrix[mid/col][mid%col];
            // ab bss conditions laga krr dekh lo
            if(element == target){
                return 1;
            }
            else if(target < element ){
                e = mid -1;
            }
            else if(target > element){
                s = mid +1;
            }

            mid = s+ (e-s)/2;
        }
        return 0;
    }
};