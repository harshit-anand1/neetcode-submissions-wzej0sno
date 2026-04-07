class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        vector<vector<int>> freqArr(nums.size()+1);

        //storing the frequency of occuring of each element in a map
        for(auto it:nums){
            mp[it]++;
        }

        //keeping the freq as index i and value as the
        // list of number which occurs i times
        for(auto it:mp){
            freqArr[it.second].push_back(it.first);
        }

        for(int i= freqArr.size()-1;i>=0;i--){
            for(auto n : freqArr[i]){
                res.push_back(n);
            }
            if(res.size()==k) return res;
        }

        return res ;

    }
};