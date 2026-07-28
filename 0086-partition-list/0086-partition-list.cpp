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
    ListNode* partition(ListNode* head, int x) {
        ListNode smaller(0);
        ListNode larger(0);
        ListNode* small= &smaller;
        ListNode* large= &larger;
        while(head){
            if(head->val >=x) {
                large->next= head;
                large=large->next;
            }
            else {
                small->next= head;
                small= small->next;
            }
            head= head->next;
        }
        large->next= nullptr;
        small->next= larger.next;
        return smaller.next;
    }
};