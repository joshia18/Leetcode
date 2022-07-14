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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int count = 1;
        
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        
        //previous node to start node
        ListNode* temp = nullptr;
        
        while(count < left){
            temp = p;
            p = p->next;
            count++;
        }
        
        //exact start node for reversing, it's next will be NULL after reversing, so assign it to p if p exists
        ListNode* start = p;
        //cout << p->val;
        
        while(count <= right){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            count++;
        }
        
        //now p will be at the next node after end of the reversed list, so assign the end of reversed list to p
        //the start node stored before will be the end node after reversing, so assign its next to current p
        if(p) start->next = p;
        if(temp) temp->next = q;
        
        if(left == 1) return q;
        
        return head;
        
    }
};