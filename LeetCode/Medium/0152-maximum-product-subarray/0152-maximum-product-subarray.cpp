class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=0;
        int bestending=nums[i];
        int minending=nums[i];
        int ans=nums[i];
        int n = nums.size();

        for(i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = bestending * nums[i];
            int v3 = minending * nums[i];
            bestending = max(v1,max(v2,v3));
            minending = min(v1,min(v2,v3));
            ans = max(ans,max(bestending,minending));
        }
        return ans;
    }
};