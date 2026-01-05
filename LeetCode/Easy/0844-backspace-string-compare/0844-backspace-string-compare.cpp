class Solution {
public:
    string removeBackSpaceChar(string s){
        stack<char> s1;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '#'){
                if(!s1.empty())
                    s1.pop();
            }else{
                s1.push(s[i]);
            }
        }
        s = "";
        while(!s1.empty()){
            s += s1.top();
            s1.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }

    bool backspaceCompare(string s, string t) {
        string sRemove = removeBackSpaceChar(s);
        string tRemove = removeBackSpaceChar(t);
        //cout<<sRemove<<" "<<tRemove<<endl;
        if(sRemove.compare(tRemove) != 0){
            return false;
        }

        return true;
    }

};