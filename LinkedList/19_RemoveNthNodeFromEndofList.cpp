/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head,*curr=head;
        while(n--){
            temp=temp->next;
            if(!temp) return head->next;
        }
        while(temp->next){
            temp=temp->next;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt=0;

        while(temp){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int it = cnt-n-1;
        if(it<0) return temp->next;
        
        while(it--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
