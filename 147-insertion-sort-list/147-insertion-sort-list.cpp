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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int minnum = INT_MAX, length = 0;
        
        ListNode* newhead = new ListNode(head->val);
        ListNode* temp = head->next;
        
        while(temp != NULL){
            int value = temp->val;
            ListNode* node = new ListNode(value);
            
            ListNode* p = newhead;
            ListNode* q = nullptr;
            
            if(value < p->val){
                node->next = p;
                newhead = node;
            }
            else{
                q = newhead;
                p = newhead->next;
                
                while(p && !(q->val <= value && p->val >= value)){
                    q = p;
                    p = p->next;
                }
                
                if(p == nullptr){
                    q->next = node;
                }
                else{
                    q->next = node;
                    node->next = p;
                }
                
            }
            
            temp = temp->next;
        }
        
        return newhead;
         
    }
};