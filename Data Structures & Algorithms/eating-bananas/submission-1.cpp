class Solution {
public:

    bool canEat(int mid,const vector<int>& piles, int h){
        long long time  = 0;
        for(auto it:piles){
            time += (it + (long long)mid - 1) / mid;
        }
        return time<=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1;
       int high = *max_element(piles.begin(),piles.end());
       int ans = 0;
       while(low<=high){
         int mid = low + (high-low)/2;

         if(canEat(mid,piles,h)){
            ans  = mid;
            high = mid-1;
        }
        else low= mid+1;
       } 
       return ans;
    }
};