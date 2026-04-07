class Solution {

    vector<int> ngl(vector<int>& height){
        vector<int> ngl;
        int i=0;
        int hmax=0;
        stack<int> st;
        int n2=height.size();
        for(int i=0;i<n2;i++){

            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }

            ngl.push_back(st.empty()?0:st.top());
            hmax= max(hmax,height[i]);
            st.push(hmax);
        }

        return ngl;

    }

    vector<int> ngr(vector<int>& height){
            vector<int> ngr;
        int hmax=0;
        stack<int> st;
        int n2=height.size();
        for(int i=n2-1;i>-1;i--){

            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }

            ngr.push_back(st.empty()?0:st.top());
            hmax= max(height[i],hmax);
            st.push(hmax);
        }

        reverse(ngr.begin(),ngr.end());
        return ngr;
    }
public:
    int trap(vector<int>& height) {
    vector<int> water(height.size(),0);
    int ans=0;
    vector<int> nextGreatL = ngl(height);
    vector<int> nextGreatR = ngr(height);

    for(int i=0;i<height.size();i++){
        int waterLevel;
        cout<<"ngl "<<i<<" "<<nextGreatL[i]<<endl;
        cout<<"ngr "<<i<<" "<<nextGreatR[i]<<endl;
        waterLevel= min(nextGreatL[i],nextGreatR[i])-height[i];
        water[i]=max(0,waterLevel);
        ans+=water[i];
    }
    

    return ans;

    }
};