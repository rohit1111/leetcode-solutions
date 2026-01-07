class Solution {
public:
    int findMax(vector<int> freq){
        int n = freq.size();
        int maxS = INT_MIN;
        for(int i=0;i<n;i++){
            maxS = max(maxS,freq[i]); 
        }
        return maxS;
    }
    int characterReplacement(string s, int k) {
        int start=0;
        int end=0;
        int n = s.size();
        vector<int> freq(255,0);
        int res = INT_MIN;

        for(end=0;end<n;end++){
            freq[s[end]]++;
            int len = end - start + 1;
            int maxlen = findMax(freq);
            int diff = len - maxlen;
            while(diff > k){
                freq[s[start]]--;
                start++;
                maxlen = findMax(freq);
                len = end - start + 1;
                diff = len - maxlen;
            }
            len = end - start + 1;
            res = max(res,len);
        }
        if(res == INT_MIN){
            return 0;
        }
        return res;
    }
};