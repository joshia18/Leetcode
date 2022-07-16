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
        
        // if(n == 1){
        //     while(p->next != NULL){
        //         q = p;
        //         p = p->next;
        //     }
        //     q->next = p->next;
        //     delete p;          
        //     return head;
        // }
        
        //this method involves counting the number of elements first and then deleting, there is another method
//         while(p != NULL){
//             count++;
//             p = p->next;
//         }
                
//         p = head;
//         q = NULL;
//         n = n-1;
        
//         int todelete = count-n;
        
//         if(todelete == 1){
//             head = head->next;
//             return head;
//         }
        
//         for(int i = 0; i < todelete-1; i++){
//             q = p;
//             p = p->next;
//         }
        
//         q->next = p->next;
//         delete p;
        
//         return head;
        
        //another method
        ListNode* node = new ListNode(0);
        node->next = head;
        //careful left is assigned to node
        ListNode* left = node;
        ListNode* right = head;
        
        while(n--){
            right = right->next;
        }
        
        while(right){
            left = left->next;
            right = right->next;
        }
        
        left->next = left->next->next;
        
        return node->next;
    }
};