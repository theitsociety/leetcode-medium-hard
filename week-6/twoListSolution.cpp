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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()  == 0) return NULL;
        
        int lo = 0;
        int hi = lists.size()-1;
        while(hi != 0){
            lists[lo++] = mergeTwoLists(lists[lo], lists[hi--]);
             
            if(lo >= hi){
                lo = 0;
            }
        }
        return lists[0];
        
    }
    
    ListNode* mergeTwoListsRecursive(ListNode* a, ListNode* b){
        
        if(a == NULL) return b;
        if(b == NULL) return a;
        
        if(a->val < b->val){
            a->next = mergeTwoListsR(a->next, b);
            return a;
        }
        else{
             b->next = mergeTwoListsR(a, b->next);
            return b;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        
        ListNode dummy;
        ListNode* head = &dummy;
        
        while(a != NULL && b != NULL){
            
            if(a->val < b->val){
                head->next = a;
                a = a->next;
            }
            else{
                head->next = b;
                b = b->next;
            }
            head = head->next;
        }
        
        head->next = (a != NULL) ? a : b;
        return dummy.next;
    }
};
