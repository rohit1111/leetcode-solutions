class Solution {
public:
        //TC: O(n), SC: O(1)
        int maxDepth(string s) {
                int maxV = INT_MIN;
                int n = s.size();
                int countP = 0;
                for(int i=0;i<n;i++){
                        if(s[i] == '('){
                                countP++;
                        }else if(s[i] == ')'){
                                countP--;
                        }
                        maxV = max(maxV,countP);
                }
                return maxV;
        }
};