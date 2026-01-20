class Solution {
public:
    int identifyX(string result){
        int ans = -1;
        int n = result.size();
        for(int i=0;i<n;i++){
            if(result[i] == 'X'){
                ans = i;
                break;
            }
        }
        return ans;
    }
    string reorganizeString(string s) {
        // vector<int> freq(26,0);
        // vector<int> freq_temp(26,0);
        // int n = s.size();


        // for(int i=0;i<n;i++){
        //     freq[s[i] - 97]++;
        //     freq_temp[s[i] - 97]++;
        // }
        // freq_temp.erase(remove(freq_temp.begin(),freq_temp.end(), 0), freq_temp.end());
        // string result = "";
        // char prev;
        // while(freq_temp.size()>0){
        //     cout<<result<<" "<<freq_temp.size()<<endl;
        // for(int i=0;i<freq.size();i++){
        //     char temp = i + 97;
        //     if(freq[i]>0 && prev != temp){
        //         result += i+97;
        //         freq[i]--;
        //         freq_temp[i]--;
        //         prev=i+97;
        //     }else if(freq[i] > 0 && prev == temp){
        //         return "";
        //     }
        //     freq_temp.erase(remove(freq_temp.begin(), freq_temp.end(), 0), freq_temp.end());
        // }
        // }
        // // for(int i=0;i<26;i++){
        // //     char temp = i + 97;
        // //     if(freq[i]>0 && prev != temp){
        // //         result += i+97;
        // //         freq[i]--;
        // //         prev=i+97;
        // //     }else if(prev == temp){
        // //         return "";
        // //     }
        // // }              
        // return result;

        // int i=0;
        // int j=1;

        // int n = s.size();
        // //sort(s.begin(),s.end());
        // if(n==1){
        //     return s;
        // }else{
        //     while(j<=n-1){
        //         cout<<i<<" "<<j<<" "<<n-1<<" "<<s<<endl;
        //         if(s[i] == s[j]){
        //             j++;
        //             if(j==n && i!=j-1 && s[i] == s[j-1])
        //                 return "";
        //         }else{
        //             if(j-i>1){
        //                 swap(s[i+1],s[j]);
        //                 i++;
        //                 j=i;
        //             }else{
        //                 //if(s[i] != s[j]){
        //                 //if(s[i] == s[j] && j==n-1)
        //                 //    return "";
        //                 cout<<s[i]<<" "<<s[j]<<endl;

        //                     i++;
        //                     //j++;
        //                     j=i;
        //                 //}else{
        //                 //    return "";
        //                 //}
        //             }
        //         }
        //     }
        // }
        // return s;

        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        vector<int> freqC(26, 0);
        for(char c:s){
            freqC[c - 'a']++;
        }

        vector<pair<char,int>> v(freq.begin(),freq.end());
        int maxFreq = *max_element(freqC.begin(), freqC.end());
        if (maxFreq > (s.size() + 1) / 2)
            return "";
        sort(v.begin(),v.end(),[](auto &a, auto &b){return a.second > b.second;});
        int n = s.size();
        //string result="";
        // string result(n,'X');
        // // for(auto a: v){
        // //     result.append(a.second,a.first);
        // // }
        // int pos=0;
        // int next=0;
        // for(int i=0;i<v.size();i++){
        //     cout<<pos<<" "<<result<<" "<<n<<" For "<<v[i].first<<" "<<next<<endl;
        //     int flag=0;
        //     while(v[i].second>0){
        //         if(pos >= n)
        //             return "";
        //         //result += v[i].first;
        //         if(flag==0){
        //             result[pos]= v[i].first;
        //             v[i].second--;
        //         }else{
        //             result.insert(result.begin(),v[i].first);
        //             result.pop_back(); 
        //             v[i].second--;
        //             flag=0;
        //         }
        //         pos +=2;
        //         if(pos == n){
        //             pos -=1;
        //             flag=1;
        //         }
        //         cout<<"\t"<<result <<" "<<pos<<endl;
        //         //cout<<"in-1 "<<pos<<" "<<result<<endl;
        //     }
        //     //cout<<pos<<" "<<result<<" "<<n<<" "<<v[i].first<<endl;
        //     if(v[i].second>0 && pos >n)
        //         return "";

        //     //identify X positions
        //     pos = identifyX(result);
        //     //pos = next+1;
            
        //     //next = pos+1;
        // }
        // for(int i=1;i<n;i++){
        //     if(result[i] == result[i-1])
        //         return "";
        // }
        string result(s.size(), ' ');
        int idx = 0;
        for (auto &[ch, count] : v) {
        while (count--) {
            if (idx >= s.size())
                idx = 1;
            result[idx] = ch;
            idx += 2;
        }
    }
    //return result;
        return result;

    }
};