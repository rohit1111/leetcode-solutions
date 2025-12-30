class Solution {
public:
    // //Brute Force Approach: TC: O(n) SC: O(1)
    // int removeDuplicates(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> temp;
    //     if(n == 0)
    //         return 0;
    //     temp.push_back(nums[0]);    
    //     for(int i=1;i<n;i++){
    //         if(nums[i] != nums[i-1]){
    //             temp.push_back(nums[i]);
    //         }
    //     }

    //     for(int i=0;i<temp.size();i++){
    //         nums[i] = temp[i];
    //     }
    //     return temp.size();
    // }


    //Optimized Approach: Two Pointer. TC: O(n) SC: O(1)
    int removeDuplicates(vector<int>& nums) {
        int uniqueElements = 1;
        int uniquePtr = 0;
        int checkPtr = 1;
        int n = nums.size();
        for(int checkPtr=1;checkPtr<n;checkPtr++){
            if(nums[checkPtr] != nums[checkPtr - 1]){
                uniqueElements++;
                uniquePtr++;
                nums[uniquePtr] = nums[checkPtr];
            }
        }
        return uniqueElements;
    }
};