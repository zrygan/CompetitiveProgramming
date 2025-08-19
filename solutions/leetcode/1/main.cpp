#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> indexed;

        for (int i = 0; i < nums.size(); ++i) {
            indexed.emplace_back(nums[i], i);
        }

        sort(indexed.begin(), indexed.end());

        vector<int> res;

        int start = 0;
        int end = indexed.size() - 1;

        while (start < end) {

            int sum = indexed[start].first + indexed[end].first;

            if (sum == target) {
                res.push_back(indexed[start].second);
                res.push_back(indexed[end].second);  
                return res;

            } 
            else if (sum < target) ++start;
            else --end;                    
        }

        return res; 
    }
};