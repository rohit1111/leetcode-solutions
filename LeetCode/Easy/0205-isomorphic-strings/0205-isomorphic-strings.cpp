class Solution {
public:
        // bool isIsomorphic(string s, string t) {
        //         int n = s.size();
        //         int firstPtr=0, secondPtr=0;
        //         vector<pair<char,char>> map;
        //         while(firstPtr<n){
        //                 auto it = find_if(map.begin(),map.end(),
        //                                 [&](const pair<char,char>&p){
        //                                 return p.first == s[firstPtr];});
        //                 if(it != map.end()){
        //                         if(it->first != s[firstPtr] || it->second != t[secondPtr])
        //                                 return false;
        //                         else{
        //                              firstPtr++;
        //                              secondPtr++;   
        //                         }                              
        //                 }else{
        //                       map.push_back({s[firstPtr++],t[secondPtr++]});  
        //                 }                
        //         }
        //         return true;
        // }
        bool isIsomorphic(string s, string t) {
                int n = s.size();
                int firstPtr=0, secondPtr=0;
                vector<pair<char,char>> map;
                while(firstPtr<n){
                        auto it = find_if(map.begin(),map.end(),
                                        [&](const pair<char,char>&p){
                                        return p.first == s[firstPtr];});
                        if(it != map.end()){
                                if(it->second != t[secondPtr])
                                        return false;                     
                        }else{
                              auto it1 = find_if(map.begin(),map.end(),
                                        [&](const pair<char,char>&p){
                                        return p.second == t[secondPtr];}); 
                              if(it1 != map.end())
                                return false;
                              map.push_back({s[firstPtr],t[secondPtr]});  
                        }
                        firstPtr++;
                        secondPtr++;                
                }
                return true;
        }        
};