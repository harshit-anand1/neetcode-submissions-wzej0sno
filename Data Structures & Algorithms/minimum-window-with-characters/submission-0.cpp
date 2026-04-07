class Solution {
public:
    string minWindow(string s, string t) {
    int minLen  = INT_MAX;
    int minLeft=0;
    string res = "";
    int i=0;
    int j=0;
    
    unordered_map<char,int> mp;
    if(s.length()<t.length()) return "";

    for(auto it:t) mp[it]++;
    int count=mp.size();

    while(j<s.length()){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
        }


        while(count==0){
            if(j-i+1<minLen){
                minLen = j-i+1;
                minLeft = i;
            }
            
           if(mp.find(s[i])!=mp.end()){
            mp[s[i]]++;
            if(mp[s[i]]==1) count++;
        }
        i++;

        }
        j++;


    }

    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);

    }
};
