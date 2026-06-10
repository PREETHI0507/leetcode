class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to anchor the start of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Loop until one of the lists runs out of nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next; // Move list1 pointer forward
            } else {
                tail->next = list2;
                list2 = list2->next; // Move list2 pointer forward
            }
            tail = tail->next; // Move the tail pointer forward
        }
        
        // Wire up any remaining nodes from whichever list is left over
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // The merged list actually starts right after the dummy node
        return dummy.next;
    }
};