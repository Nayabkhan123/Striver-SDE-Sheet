/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = NULL,*forw=NULL;
        while(head){
            forw=head->next;
            head->next = prev;
            prev = head;
            head = forw;
        }
        return prev;
    }
};