/*
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
    is not a multiple of k then left-out nodes, in the end, should remain as it is.
    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
*/

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
    pair<ListNode*,ListNode*> reverse(ListNode* head, int k,ListNode* node){
        ListNode* temp = head,*prev=NULL,*forw=head;
        while(k--){
            forw=temp->next;
            temp->next=prev;
            prev=temp;
            temp = forw;
        }
        head->next = forw;
        if(node) node->next=prev;
        return {prev,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        temp=head;
        ListNode* ans=NULL;
        ListNode*node=NULL;
        while(cnt>=k){
            pair<ListNode*,ListNode*> a = reverse(temp,k,node);
            node=a.second;
            if(!ans) ans=a.first;
            temp = node->next;
            cnt-=k;            
        }
        return ans;
    }
};