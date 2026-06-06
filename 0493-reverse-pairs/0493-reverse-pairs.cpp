#include <vector>

class Solution {
public:
    int merge(std::vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        
        // Step 1: Count the reverse pairs
        // We do this before the actual merge so the subarrays are still separated
        for (int i = low; i <= mid; ++i) {
            // Use 2LL to prevent integer overflow
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            // All elements from (mid + 1) to (j - 1) satisfy the condition
            count += (j - (mid + 1)); 
        }

        // Step 2: Standard Merge Sort combining step
        std::vector<int> temp;
        int left = low, right = mid + 1;
        
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        
        // Collect remaining elements
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }
        
        // Copy sorted elements back to the original array
        for (int i = low; i <= high; ++i) {
            nums[i] = temp[i - low];
        }
        
        return count;
    }

    int mergeSort(std::vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        int reversePairsCount = mergeSort(nums, low, mid);     // Count in left half
        reversePairsCount += mergeSort(nums, mid + 1, high); // Count in right half
        reversePairsCount += merge(nums, low, mid, high);    // Count crossing halves and merge
        
        return reversePairsCount;
    }

    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};