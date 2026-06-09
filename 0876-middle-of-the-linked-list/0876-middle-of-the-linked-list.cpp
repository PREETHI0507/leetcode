/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Loop continues until fast reaches the end (nullptr) 
        // or the last node (fast->next == nullptr)
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // slow moves 1 step
            fast = fast->next->next; // fast moves 2 steps
        }
        
        // slow is now at the middle
        return slow;
    }
};