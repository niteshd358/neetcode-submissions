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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast){
            if(slow == head){
                if(slow)slow = slow->next;
                if(fast->next)fast = fast->next->next;
                continue;
            }
            if(slow == fast) return true;
            if(slow)slow = slow->next;
            if(fast->next)fast = fast->next->next;
        }

        return false;

    }
};
