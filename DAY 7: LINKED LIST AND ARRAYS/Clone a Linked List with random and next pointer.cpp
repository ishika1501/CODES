//BRUTE FORCE 

we can use a extra space of unorederd map 
we can use hashing 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node*, Node*> mpp;

        //create copy of each node and store that in the map
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        temp=head;
        while(temp!=NULL){
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }
};

//OPTIMAL APPROACH :

1. insert copy nodes in between 
2. connect random pointer 
3. connect next pointer 


class Solution {
public:
     void insertCopy(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);  
            copy->next = nextElement;  
            temp->next = copy;         
            temp = nextElement;     
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;    
            if (temp->random) {   
                copyNode->random = temp->random->next; 
            } else {
                copyNode->random = NULL;   
            }
            temp = temp->next->next;   
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);   
        Node* res = dummyNode;            

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;   
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        insertCopy(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
