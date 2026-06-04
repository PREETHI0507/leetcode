class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect if there is a cycle and find the intersection point.
        // We initialize both pointers at the first element.
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];           // Moves 1 step
            fast = nums[nums[fast]];     // Moves 2 steps
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle (which is our duplicate number).
        // Reset the slow pointer to the start of the array.
        slow = nums[0];
        
        // Move both pointers at the same speed. Where they meet is the duplicate.
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow; // or return fast, since they are pointing to the same value
    }
};