class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int start=0;
       int end=0;
       int n = s.size();
       unordered_map<char,int> freq;
       int res= INT_MIN;

       for(end=0;end<n;end++){
            freq[s[end]]++;

            int k = end - start + 1;

            while(freq.size() < k){
                freq[s[start]]--;
                if(freq[s[start]] == 0){
                    freq.erase(s[start]);
                }
                start++;
                k = end - start + 1;
            }

            k = end - start + 1;
            res = max(res,k);
       }
       if(res == INT_MIN){
        return 0;
       }
       return res; 
    }
};