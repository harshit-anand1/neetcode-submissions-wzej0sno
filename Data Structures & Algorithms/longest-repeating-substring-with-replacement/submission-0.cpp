class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        int maxLen = 0;
        int maxfreq = 0;
        int freq[26] = {0};  // ✅ Array instead of map
        
        while(j < s.length()) {
            freq[s[j] - 'A']++;  // Direct array access
            maxfreq = max(maxfreq, freq[s[j] - 'A']);
            
            if((j - i + 1) - maxfreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
