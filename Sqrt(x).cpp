class Solution {
public:
    long long int mySqrt(int x) {
        int sqr;
        int s = 0;
        int e = x;
        long long int mid = s+(e-s)/2;
        long long ans =-1;
        while(s<=e){
            long long int sqr = mid*mid;
            if(sqr == x){
                return mid;
            }
            if(sqr < x){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
        
    }
};