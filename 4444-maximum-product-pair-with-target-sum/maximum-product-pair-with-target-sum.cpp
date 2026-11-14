class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        priority_queue<tuple<int,int,int>> pq;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(i != j && nums[i] + nums[j] == target && nums[i] > nums[j]) {
                    int prod = nums[i] * nums[j];
                    pq.push({prod, i, j});
                }
            }
        }

        if(!pq.empty()) {
            auto it = pq.top();
            return {get<1>(it), get<2>(it)};
        }

        return {-1, -1};
    }
};