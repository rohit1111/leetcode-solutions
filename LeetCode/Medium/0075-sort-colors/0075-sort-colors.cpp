class Solution {
public:
    // //Brute Force: TC: O(n) SC: O(n)
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> zeros;
    //     vector<int> ones;
    //     vector<int> twos;
    //     for(int i=0;i<n;i++){
    //         if(nums[i] == 0){
    //             zeros.push_back(nums[i]);
    //         }else if(nums[i] == 1){
    //             ones.push_back(nums[i]);
    //         }else{
    //             twos.push_back(nums[i]);
    //         }
    //     }
    //     int index=0;
    //     int i=0;
    //     while(i < zeros.size()){
    //         nums[index++] = zeros[i++]; 
    //     }
    //     i=0;
    //     while(i<ones.size()){
    //         nums[index++] = ones[i++]; 
    //     }
    //     i=0;
    //     while(i<twos.size()){
    //         nums[index++] = twos[i++]; 
    //     }        
    // }

    // //Better Approach/Optimal: TC: O(n) SC: O(1) Pass:2
    // void sortColors(vector<int>& nums) {
    //     int counterZero = 0 , counterOne = 0, counterTwo = 0;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i] == 0){
    //             counterZero++;
    //         }else if(nums[i] == 1){
    //             counterOne++;
    //         }else{
    //             counterTwo++;
    //         }
    //     }
    //     int index = 0;
    //     int i= 0;
    //     while(i < counterZero){
    //         nums[index++] = 0;
    //         i++;
    //     }
    //     i = 0;
    //     while(i < counterOne){
    //         nums[index++] = 1;
    //         i++;
    //     }
    //     i = 0;
    //     while(i < counterTwo){
    //         nums[index++] = 2;
    //         i++;
    //     }                
    // }

    //Better/Optimal Approach: TC: O(n), SC: O(1), Pass: 1, Two Pointer
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid=0, high=n-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};