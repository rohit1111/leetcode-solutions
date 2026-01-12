class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int i=0;
       int bestending=nums[i];
       int ans=nums[i];
       int n = nums.size();
       for(i=1;i<n;i++){
            int v1 = bestending + nums[i];
            int v2 = nums[i];
            bestending = max(v1,v2);
            ans = max(ans,bestending);
       }
       return ans; 
    }
};