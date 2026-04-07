class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n =temperatures.size();
        vector<int> res(n);
        for(int i= temperatures.size()-1;i>=0;i--){
           
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                    st.pop();
                 
            }
            
            res[i] = st.empty()?0:st.top()-i;

            st.push(i);




           
        }
       // reverse(res.begin(),res.end());

        return res;
    }
};
