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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode*temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count == n){
            temp = head->next;
            return temp;
        }
        int Nodeindex = count - n;
        int var = 1;
        ListNode*curr = head;
        while(var < Nodeindex && curr!=NULL){
            curr = curr->next;
            var++;
        }
        curr->next = curr->next->next;
        return head;
    }
};