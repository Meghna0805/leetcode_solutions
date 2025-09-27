class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> ump;

        priority_queue<pair<int, int>> maxheap;

        for(auto it: nums) ump[it]++;

        for(auto it: ump){
            maxheap.push({it.second, it.first});

        }

        while(k--){
            ans.push_back(maxheap.top().second);

            maxheap.pop();
        }

        return ans;

    }
};