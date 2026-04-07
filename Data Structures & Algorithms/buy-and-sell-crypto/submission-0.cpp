class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNo = INT_MAX;
        int diff=0;
        int maxProfit = INT_MIN;
        for(int i=0;i<prices.size();i++){
           minNo =  prices[i]<minNo?prices[i]:minNo;
           diff =prices[i]-minNo;


            maxProfit =max(diff,maxProfit);
        }
        return maxProfit
        ;
    }
};
