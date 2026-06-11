class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Boundary check
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // Loop runs until the two pointers meet each other
        while (pA != pB) {
            // Move to the next node, or switch to the head of the other list if NULL
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        // Either they met at the intersection node, or both are nullptr (no intersection)
        return pA;
    }
};