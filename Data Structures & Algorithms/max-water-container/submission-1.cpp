class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j= heights.size()-1;
        int maxVol = 0;
        int vol=0;

        while(i<j){
            vol = (j-i)*min(heights[i],heights[j]);
            maxVol=max(vol,maxVol);
            heights[i]<heights[j]?i++:j--;
        }
        return maxVol;
    }
};
