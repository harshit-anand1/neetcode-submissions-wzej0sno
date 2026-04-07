// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> mp;
//         vector<int> ans;
//         for(int i=0;i<nums.size();i++){
            
//             if(mp.find(target-nums[i])!=mp.end())
//              {
//              ans.push_back(mp[nums[i]]);
//              ans.push_back(i);
//              }
            
//             mp[nums[i]]=i;
//         }

//         return ans;



//     }
// };



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};