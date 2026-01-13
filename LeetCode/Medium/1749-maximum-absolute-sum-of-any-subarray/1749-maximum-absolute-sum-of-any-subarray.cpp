class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i=0;
        int maxending=nums[i];
        int minending=nums[i];
        int ans=nums[i];

        int n = nums.size();

        for(i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = maxending + nums[i];
            int v3 = minending + nums[i];
            maxending = max(v1,max(v2,v3));
            minending = min(v1,min(v2,v3));
            ans = max(ans,max(abs(maxending),abs(minending)));
        }
        return abs(ans);    
    }
};