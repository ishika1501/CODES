BRUTE FORCE:

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return  NULL;
}

OPTIMAL APPROACH :

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        Listnode* d1=head1;
        Listnode* d2=head2; 

        while(d1!=d2){
            d1=d1==NULL?head2:d1->next;
            d2=d2==NULL?head1:d2->next;
        }
        return d1;
    }
};