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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* third = nullptr;
        ListNode* last = nullptr;
        
        if(!first && !second) return nullptr; if(!first) return second; if(!second) return first;
        
        if(first->val < second->val){
            third = first;
            last = first;
            first = first->next;
            last->next = nullptr;
        }
        else{
            third = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
        
        while(first && second){
            if(first->val < second->val){
                last->next = first;
                last = first;
                first = first->next;
                last->next = nullptr;
            }
            else{
                last->next = second;
                last = second;
                second = second->next;
                last->next = nullptr;
            }
        }
        
        if(first) last->next = first;
        if(second) last->next = second;
        
        return third;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //using merge sort
        if(lists.size() == 0) return nullptr;
        
        int n = lists.size();
        
        while(lists.size() != 1){
            n = lists.size();
            
            vector<ListNode*> temp;
            
            for(int i = 0; i+1 < n; i+=2){
                temp.push_back(merge(lists[i], lists[i+1]));
            }
            
            if(n%2 != 0 && n!=1) temp.push_back(lists[lists.size()-1]);
            lists = temp;
        }
        
        return lists[0];
        
    }
};