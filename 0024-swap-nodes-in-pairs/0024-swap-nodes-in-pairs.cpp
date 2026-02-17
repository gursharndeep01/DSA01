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
    void rec(ListNode* head,ListNode* ph){
        if(!head || !head->next) return ;
        ListNode* tempu=head->next;
        head->next=tempu->next;
        tempu->next=head;
        if(ph)ph->next=tempu;
        rec(head->next,head);
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first=head->next;
        rec(head,NULL);
        return first;
    }
};