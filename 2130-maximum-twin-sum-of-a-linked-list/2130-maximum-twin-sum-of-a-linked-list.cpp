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
        ListNode* p = root;
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
    
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp;
        
        while(fast && fast->next){
            fast = fast->next->next;
            temp = slow;
            slow = slow->next;
        }
        
        temp->next = reverse(slow);
        
        ListNode* p = head;
        ListNode* q = temp->next;
        
        int ans = 0;
        
        while(q){
            int sum = p->val+q->val;
            ans = max(ans, sum);
            p = p->next;
            q = q->next;
        }
        
        return ans;
    }
};