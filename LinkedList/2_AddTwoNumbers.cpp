/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored 
    in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the 
    sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
    Example 2:

    Input: l1 = [0], l2 = [0]
    Output: [0]
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1);
        ListNode* ans = curr;
        int carry=0;
        while(l1 || l2){
            curr->next = new ListNode(); 
            curr=curr->next;
            int sum = carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=0;
            if(sum>9){
                curr->val = sum%10;
                carry=1;
            }
            else{
                curr->val = sum;
            }
        }
        if(carry) curr->next = new ListNode(carry);
        return ans->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1);
        ListNode* ans = curr;
        int carry=0;
        while(l1 && l2){
            curr->next = new ListNode(); 
            curr=curr->next;
            int sum = l1->val + l2->val + carry;
            carry=0;
            if(sum>9){
                curr->val = sum%10;
                carry=1;
            }
            else{
                curr->val = sum;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1 || l2){
            ListNode* node = l1?l1:l2;
            while(node){
                curr->next = new ListNode();
                curr = curr->next;
                int sum = node->val+carry;
                carry=0;
                if(sum>9){
                    curr->val = sum%10;
                    carry=1;
                }
                else{
                    curr->val = sum;
                }
                node=node->next;
            }
        }
        if(carry) curr->next = new ListNode(carry);
        return ans->next;
    }
};