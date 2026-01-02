class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxDiff = INT_MAX;
        int resultSum = 0;
        for(int i=0;i<n-2;i++){
            int start = i+1;
            int end = n-1;
            while(start<end){
                int totalSum = nums[i] + nums[start] + nums[end];
                int diff = abs(target - totalSum);
                if(maxDiff > diff){
                    maxDiff = diff;
                    resultSum = totalSum;
                }
                if(totalSum == target){
                    return resultSum;
                }
                else if(totalSum < target){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return resultSum;
    }
};