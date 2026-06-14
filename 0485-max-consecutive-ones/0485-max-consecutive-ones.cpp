class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        
        for (int num : nums) {
            if (num == 1) {
                count++;
            } else {
                // Streak is broken, update maxCount and reset current count
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        
        // Final check to catch a streak that goes up to the very last element
        return max(maxCount, count);
    }
};