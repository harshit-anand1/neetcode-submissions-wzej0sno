class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Create buckets: index = frequency, value = list of numbers with that frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> ans;
        // Traverse buckets in reverse (from high freq to low)
        for (int i = n; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
