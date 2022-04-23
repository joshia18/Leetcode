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
    ListNode* reverse(ListNode* root){
        ListNode* temp = root;
        ListNode* p = temp;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        return q;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        
        //the idea behind this solution is we keep the first half of ll as it is and reverse the second half of ll
        while(fast && fast->next){
            temp = slow;
            slow =slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        ListNode* second = reverse(slow);
        
        ListNode* first = head;
        
        while(first != NULL){
            ListNode* fnex = first->next;
            ListNode* snex = second->next;
            first->next = second;
            
            //this is an important step here to do the merging successfully
            //only if fnex is not null we can perform the next step
            
            if(fnex == NULL) break;
            
            second->next = fnex;
            first = fnex;
            second = snex;
        }
        
        
    }
};