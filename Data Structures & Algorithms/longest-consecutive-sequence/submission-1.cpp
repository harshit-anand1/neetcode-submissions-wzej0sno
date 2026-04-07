class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     int len=1;
     int maxLen=0;
     
     unordered_set<int> s;

     for(auto it:nums){
        s.insert(it);
     }

     for(int i=0;i<nums.size();i++){
        len=0;
        int el=nums[i];
        while(s.find(el)!=s.end()){
            len++;
            el++;
        }
        maxLen= max(maxLen,len);
     }

     return maxLen;

    }
};
