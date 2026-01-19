class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> f;
        int sum=0;
        f[0]=1;         //sum=0 ek barr dekha he, to f[sum]++;
        int countSubarrays = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int check = sum - k;
            int freq = f[check];
            countSubarrays += freq;
            f[sum]++;
        }
        return countSubarrays;
    }
};