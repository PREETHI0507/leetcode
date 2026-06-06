#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // We only need a 1D array to store the paths for the current row
        std::vector<int> dp(n, 1);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] on the right is the value from the cell above (previous row)
                // dp[j - 1] is the value from the cell to the left (current row)
                dp[j] += dp[j - 1]; 
            }
        }
        
        // The last element contains the number of unique paths to the finish
        return dp[n - 1];
    }
};