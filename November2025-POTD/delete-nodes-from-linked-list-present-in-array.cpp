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

 /*
  Approach : 
  step 1 : Initialize a unordered set s and insert all the elements in unordered_set 
  step 2 : Create a temp pointer pointing to head
  step 3 : Loop through the entire linked list
  step 4 : Check if the element exist in given array nums 
  step 5 : Delete the node   
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode*temp = head;
        ListNode*prev = NULL;
        while(temp){
            int nodeValue = temp->val;
            if(s.count(nodeValue)){
                if(temp==head){
                    head = head->next;
                    temp = head;
                    continue;
                }
                prev->next = temp->next;
                temp = prev->next;
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};