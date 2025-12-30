class Solution {
public:
    // //Brute Force Approach: TC: O(n^2), SC: O(1)
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int n = numbers.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(numbers[i]+numbers[j] == target){
    //                 return {i+1,j+1};
    //             }
    //         }
    //     }
    //     return {-1,-1};
    // }


    // //Better Approach, Hash Map: TC: O(n), SC: O(n)
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     unordered_map<int,int> mp;
    //     int n = numbers.size();
    //     for(int i=0;i<n;i++){
    //         int need = target - numbers[i];
    //         if(mp.find(need) != mp.end()){
    //             return {mp[need]+1,i+1};
    //         }
    //         mp[numbers[i]] = i;
    //     }
    //     return {};
    // }

    //Optimize Approach, Two pointer: TC: O(n), SC: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end = numbers.size() -1;

        while(start<end){
            if(numbers[start]+numbers[end] == target){
                return {start+1,end+1};
            }
            if(numbers[start]+numbers[end] > target){
                end--;
            }else{
                start++;
            }
        }
        return {};
    }
};