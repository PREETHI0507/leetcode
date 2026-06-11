class Solution {
public:
    bool hasCycle(ListNode *head) {
        // If the list is empty or has only one node, a cycle isn't possible
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Traverse the list ensuring fast and fast->next are not null
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Moves 1 step
            fast = fast->next->next;    // Moves 2 steps
            
            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        // Fast reached the end of the list, so no cycle exists
        return false;
    }
};