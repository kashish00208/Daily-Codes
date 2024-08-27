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
        if(head == NULL){
            return NULL;
        }
        ListNode*test = head;
        for(int i=0;i<k;i++){
            if(!test){
                return head;
            }
            else{
                test = test->next;
            }
        }
        int count = 0;
        ListNode*forward = NULL;
        ListNode*previous = NULL;
        ListNode*current = head;
        while(current!=NULL && count<k){
            forward = current->next;
            current ->next = previous;
            previous = current;
            current = forward;
            count++;
        }
        if(forward !=NULL){
            head->next = reverseKGroup(forward,k);
        }
        return previous;
    }
};