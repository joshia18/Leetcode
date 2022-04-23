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
    int length(ListNode* root){
        ListNode* p = root;
        
        int len = 0;
        while(p){
            len++; p = p->next;
        }
        
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        //brute force is o(k*n), take the last node each time and put it in the front
        
        if(!head || !head->next) return head;
        
        ListNode* temp = head;
        
        k = k%length(head);
        
        while(k > 0){
            
            ListNode* beforelast = NULL;
            ListNode* last = NULL;
            
            while(temp->next != NULL){
                beforelast = temp;
                temp = temp->next;
            }
            
            beforelast->next = NULL;
            temp->next = head;
            head = temp;
            k--;
        }
        
        return head;
    }
};