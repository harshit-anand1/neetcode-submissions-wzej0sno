class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        } 

        for(auto it:t){
            mp[it]--;
            if(mp[it]==0) mp.erase(it);
        }

        return mp.size()?false:true;
    }
};
