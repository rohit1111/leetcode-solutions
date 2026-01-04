class Solution {
public:
    // // TC: O(n^3), SC: O(1), Integer Overflow for larger input values
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> ans;
    //     for(int i=0;i<n-3;i++){
    //         //to remove the duplicates
    //         while(i>0 && nums[i] == nums[i-1]){
    //             i++;
    //         }
    //         for(int j=i+1;j<n-2;j++){
    //             //to remove the duplicates
    //             while(j > i+1 && nums[j] == nums[j-1]){
    //                 j++;
    //             }
    //             int remaining = target - nums[i] - nums[j];
    //             int start = j + 1;
    //             int end = n-1;
    //             while(start<end){
    //                 int currSum = nums[start] + nums[end];
    //                 if(currSum == remaining){
    //                     //add the result
    //                     ans.push_back({nums[i],nums[j], nums[start], nums[end]});
    //                     //incr start
    //                     //befor incr remove the duplicates
    //                     while(start<end && nums[start] == nums[start+1]){
    //                         start++;
    //                     }
    //                     //decr end
    //                     //before decr remove the duplicates
    //                     while(start<end && nums[end] == nums[end - 1]){
    //                         end--;
    //                     }
    //                     start++;
    //                     end--;
    //                 }
    //                 else if (currSum < remaining){
    //                     start++;
    //                 }else{
    //                     end--;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            //to remove the duplicates
            while(i>0 && i<n-3 && nums[i] == nums[i-1]){
                i++;
            }
            for(int j=i+1;j<n-2;j++){
                //to remove the duplicates
                while(j > i+1 && j < n-2 && nums[j] == nums[j-1]){
                    j++;
                }
                long long remaining = (long long)target - nums[i] - nums[j];
                int start = j + 1;
                int end = n-1;
                while(start<end){
                    long long currSum = nums[start] + nums[end];
                    if(currSum == remaining){
                        //add the result
                        ans.push_back({nums[i],nums[j], nums[start], nums[end]});
                        //incr start
                        //befor incr remove the duplicates
                        while(start<end && nums[start] == nums[start+1]){
                            start++;
                        }
                        //decr end
                        //before decr remove the duplicates
                        while(start<end && nums[end] == nums[end - 1]){
                            end--;
                        }
                        start++;
                        end--;
                    }
                    else if (currSum < remaining){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};