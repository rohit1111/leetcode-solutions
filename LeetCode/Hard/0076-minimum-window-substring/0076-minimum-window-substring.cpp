class Solution {
public:
    bool checkWindowInfo(vector<int> s, vector<int> t){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] < t[i]){
                return false;
            }
        }
        return true;
    } 
    string minWindow(string s, string t) {
        int start=0;
        int end=0;
        int n = s.size();
        int m = t.size();
        if(n<m)
            return "";
        vector<int> sFreq(256,0);
        vector<int> tFreq(256,0);
        for(int i=0;i<m;i++){
            tFreq[t[i]]++;
        }
        int res = INT_MAX;
        int sStart = -1;
        for(end=0;end<n;end++){
            sFreq[s[end]]++;
            while(checkWindowInfo(sFreq,tFreq)){
                int len = end - start + 1;
                if(res > len){
                    res = len;
                    sStart = start;
                }
                sFreq[s[start]]--;
                start++;
            }
        }
        //cout<<sStart<<" "<<res<<endl;
        if(res == INT_MAX){
            return "";
        }
        string ans = s.substr(sStart,res);
        return ans;
    }
};