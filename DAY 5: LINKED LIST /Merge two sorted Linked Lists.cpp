BRUTE FORCE:

The brute force approach would be to extract all the elements
from both the lists into an additional array then sorting the array and 
Then creating a new combined linked list.


OPTIMAL APPROACH :

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *temp=new ListNode();
        ListNode *ans=temp;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        
        if(l1!=NULL)temp->next=l1;
        else temp->next=l2;

        return ans->next;

    }
};