class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> result(n);
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            while(i>0 and i<n-2 and nums[i] == nums[i-1]){
                i++;
            }
            int start=i+1;
            int end = n -1;
            int sum = -1 * nums[i];
            while(start<end){
                int s = nums[start] + nums[end];
                if(s == sum){
                    //result[i].push_back(nums[i]);
                    //result[i].push_back(nums[start]);
                    //result[i].push_back(nums[end]);
                    vector<int> row = {nums[i],nums[start],nums[end]};
                    result.push_back(row);
                    start++;
                    end--;
                    while(start < n and nums[start] == nums[start-1]){
                        start++;
                    }
                    while(end >= 0 and nums[end] == nums[end+1]){
                        end--;
                    }
                }
                else if(s < sum){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return result;
    }
};