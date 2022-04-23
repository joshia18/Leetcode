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
        
        //before_head's and after_head,s next keep the initial starting positions of those two separate linkedlists
        //one contains values less than x and the other one contains values greater than x
        //we link both of them atlast and return it
        ListNode* before_head = new ListNode();
        ListNode* before = before_head;
        ListNode* after_head = new ListNode();
        ListNode* after = after_head;
        
        while(head){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            
            head = head->next;
        }
        
        after->next = nullptr;
        before->next = after_head->next;
        
        return before_head->next;
        
    }
};