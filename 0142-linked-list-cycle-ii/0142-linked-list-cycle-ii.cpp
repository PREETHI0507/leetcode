class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;
        
        // Step 1: Detect if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                hasCycle = true;
                break; // Cycle found!
            }
        }
        
        // If no cycle exists, return null as required
        if (!hasCycle) return nullptr;
        
        // Step 2: Find the entry point of the cycle
        ListNode* entry = head;
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }
        
        return entry; // This is the node where the cycle begins
    }
};