/*
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

    Example 1:
    Input: head = [1,2,2,1]
    Output: true
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head,*slow=head,*fast=head;
        while(slow && fast){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        ListNode* prev=NULL,*forw;
        while(slow){
            forw=slow->next;
            slow->next=prev;
            prev=slow;
            slow=forw;
        }

        while(prev && temp){
            if(prev->val!=temp->val) return false;
            prev=prev->next;
            temp=temp->next;
        }
        return true;
    }
};
