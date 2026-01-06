class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int n = nums.size();
        int res = INT_MAX;
        int sum = 0;

        while(end<n){
            sum = sum + nums[end];
            while(sum >= target){
                
                int len = end - start + 1;
                res = min(res,len);

                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        if(res == INT_MAX)
            res=0;
        return res;
    }
};