BRUTE FORCE :

we can normally take a stack and put the elements there.
then make a linked by taking each element out of that untill it is empty 


OPTIMAL WAY :

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * curr=head;
        ListNode * nex =NULL;
        ListNode* prev=NULL;

        while(curr!=NULL){
            nex =curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
};