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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*curr = head;
        ListNode*prev = NULL;
        while(curr != NULL){
            if(head->val == val){
                ListNode*nodeToDelete = head;
                head = head->next;
                curr = curr->next;
                nodeToDelete->next = NULL;
            }
            else if(curr->val == val){
                ListNode*nodeToDelete = curr;
                prev->next = nodeToDelete->next;
                curr = curr->next;
                delete nodeToDelete;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }        
        return head;
    }
};