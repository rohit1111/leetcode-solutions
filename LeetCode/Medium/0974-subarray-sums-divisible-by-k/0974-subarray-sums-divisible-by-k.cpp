class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> f;
        int sum=0;
        f[sum]++;
        int res=0;
        for(int i=0;i<n;i++){
            sum += nums[i];

            int check=0;
            // if(sum>=0)
                check = sum%k;
            // else{           
            //     check = sum%k;
            //     check *= -1;
            //     check += k;  
            // }
            if(check<0)
                check += k;
            int freq = f[check];
            res += freq;
            f[check]++;
        }
        return res;
    }
};