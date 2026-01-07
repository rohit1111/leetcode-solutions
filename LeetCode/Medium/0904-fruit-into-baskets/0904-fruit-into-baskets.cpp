class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0;
        int end=0;
        int n = fruits.size();
        int res = INT_MIN;
        int k = 2;
        unordered_map<int,int> freq;

        for(end=0;end<n;end++){
            freq[fruits[end]]++;

            while(freq.size() > k){
                freq[fruits[start]]--;
                
                if(freq[fruits[start]] == 0){
                    freq.erase(fruits[start]);                    
                }
                start++;
            }
            if(freq.size() <= k){
                int len = end - start + 1;
                res = max(res,len);
            }            
        }
        if(res == INT_MIN)
            return -1;
        return res; 
    }
};