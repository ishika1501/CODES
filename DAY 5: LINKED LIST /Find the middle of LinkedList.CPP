BRUTE FORCE :

WE can traverse the linked list to find the length , say n;
then again run a for loop till n/2 and return that;


OPTIMAL APPROACH :

fast and slow approach 
take 2 pointers

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    if(head==NULL)return NULL;
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow ;
    }
};