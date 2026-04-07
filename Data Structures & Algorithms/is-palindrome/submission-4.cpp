class Solution {
public:
    bool isPalindrome(string s) {
       
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            else if(!isalnum(s[j])){
                j--;
                continue;
            } 

            else if(tolower(s[i])!=tolower(s[j])){
            cout<<s[i]<<" "<<s[j];
            return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
