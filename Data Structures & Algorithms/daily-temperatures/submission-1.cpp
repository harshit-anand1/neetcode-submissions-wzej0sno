class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res;
        for(int i= temperatures.size()-1;i>=0;i--){
           
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                    st.pop();
                 
            }
            
            res.push_back(st.empty()?0:st.top()-i);

            st.push(i);




           
        }
        reverse(res.begin(),res.end());

        return res;
    }
};
