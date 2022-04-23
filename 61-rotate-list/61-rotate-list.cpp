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
        
    ListNode* rotateRight(ListNode* head, int k) {
        //brute force is o(k*n), take the last node each time and put it in the front
        //optimal solution is making use of the circular linked list with TC (n%k)
        
        if(!head || !head->next) return head;
        
        ListNode* temp = head;
        
        ListNode* p = head;
        ListNode* beforeNode = NULL;
        
        int len = 0;
        while(p){
            len++;
            beforeNode = p;
            p = p->next;
        }            
        
        k = k%len;
        
        int newlength = len - k;
        
        //make the given list a circular linked list by pointing the last node to the head of the list
        beforeNode->next = head;
        
        while(newlength-1 > 0){
            temp = temp->next;
            newlength--;
        }
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};