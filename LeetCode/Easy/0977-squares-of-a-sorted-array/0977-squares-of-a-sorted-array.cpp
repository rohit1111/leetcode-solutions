class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<n;i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }

        if(neg.size() == 0){
            for(int i=0;i<n;i++){
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }
        if(pos.size() == 0){
            for(int i=0;i<n;i++){
                nums[i] = nums[i] * nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }

        
        int ptrPos = 0;
        int ptrNeg = 0;

        int posSize = pos.size();
        int negSize = neg.size();

        for(int i=0;i<posSize;i++){
            pos[i] = pos[i] * pos[i];
        }

        for(int i=0;i<negSize;i++){
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(),neg.end());

        int indexNums = 0;
        while(ptrPos < posSize && ptrNeg < negSize){
            if(pos[ptrPos] < neg[ptrNeg]){
                nums[indexNums++] = pos[ptrPos++];
            }else{
                nums[indexNums++] = neg[ptrNeg++];
            }
        }

        while(ptrPos < posSize){
            nums[indexNums++] = pos[ptrPos++];
        }
        while(ptrNeg < negSize){
            nums[indexNums++] = neg[ptrNeg++];
        }
        return nums;
    }
};