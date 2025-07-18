/*
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. The list should be made by splicing together the nodes 
    of the first two lists.
    Return the head of the merged linked list.

    Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    Example 2:

    Input: list1 = [], list2 = []
    Output: []
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        ListNode* combineList = new ListNode(-1);
        ListNode* ans = combineList;
        while(list1 && list2){
            if(list1->val<list2->val){
                combineList->next = list1;
                list1=list1->next;
            }
            else{
                combineList->next = list2;
                list2=list2->next;
            }
            combineList = combineList->next;
        }
        if(list1) combineList->next = list1;
        if(list2) combineList->next = list2;
        return ans->next;
    }
};