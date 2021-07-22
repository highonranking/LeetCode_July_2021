/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next || k <= 1) {
        return head;
    }
    
    ListNode dummy(0), *prev = &dummy;
    prev->next = head;
    
    while (true) {
        ListNode* it = prev->next;
        int count = 0;
        while (it) {
            ++count;
            if (count == k) {
                break;
            }
            it = it->next;
        }
        if (count < k) {
            break;
        }
        
        ListNode* nextPrev = prev->next;
        
        ListNode* prev2 = NULL, *cur = prev->next, *next = NULL;
        for (int i = 0; i < k; ++i) {
            next = cur->next;
            cur->next = prev2;
            prev2 = cur;
            cur = next;
        }
        
        prev->next = prev2;
        nextPrev->next = cur;
        
        prev = nextPrev;
    }
    
    return dummy.next;
}
};
