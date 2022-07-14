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
        ListNode* p = head;
        ListNode* q = NULL;
        int count = 0;
        
        if(n == 1 && !head->next){
            head = NULL;
            return head;
        }
        
        if(n == 1){
            while(p->next != NULL){
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;          
            return head;
        }
        
        while(p != NULL){
            count++;
            p = p->next;
        }
                
        p = head;
        q = NULL;
        n = n-1;
        
        int todelete = count-n;
        
        if(todelete == 1){
            head = head->next;
            return head;
        }
        
        for(int i = 0; i < todelete-1; i++){
            q = p;
            p = p->next;
        }
        
        q->next = p->next;
        delete p;
        
        return head;
    }
};