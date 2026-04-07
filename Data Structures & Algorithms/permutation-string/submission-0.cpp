class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int i=0;
       int j=0;
       unordered_map<char,int> mp;

       unordered_map<char,int> mp2;

       for(auto it:s1){
          mp[it]++;
       }

        while(j<s2.length()){
            mp2[s2[j]]++;
            

            if(j-i+1<s1.length()){
                j++;
            }

            else if(j-i+1==s1.length()){
                if(mp==mp2)
                return true;

                mp2[s2[i]]--;

                if(mp2[s2[i]]==0)
                 mp2.erase(s2[i]);
                i++;
                j++;
            }


        }
        return false;

    }
};

