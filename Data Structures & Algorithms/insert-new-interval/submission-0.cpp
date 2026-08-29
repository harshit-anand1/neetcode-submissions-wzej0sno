class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> copyIntervals = intervals;
            copyIntervals.push_back(newInterval);
    sort(copyIntervals.begin(), copyIntervals.end());        
    vector<vector<int>> ans;
    ans.push_back(copyIntervals[0]);
    for(int i=1; i<copyIntervals.size(); i++){
        int a = ans.size()-1;
        if(copyIntervals[i][0] <= ans[a][1]){
            ans[a][1]  = max(copyIntervals[i][1], ans[a][1]);
        }
        else{
            ans.push_back(copyIntervals[i]);
        }
    }
    return ans;
    }
};
