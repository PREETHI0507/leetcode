#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If the list is empty, return an empty list
        if (intervals.empty()) {
            return {};
        }
        
        // Step 1: Sort the intervals based on the starting time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        // Step 2: Iterate and merge
        for (const auto& interval : intervals) {
            // If merged is empty or there is no overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // If there is an overlap, merge the current interval with the previous one
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};