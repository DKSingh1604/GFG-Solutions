/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head == NULL){
            return head;
        }
        
        if(x == 1){
            Node* tempHead = head;
            head = tempHead -> next;
            tempHead -> next = NULL;
            return head;
        }
        
        
        
        Node* temp = head;
        for(int i = 1; i < x-1; i++){
            temp = temp -> next;
        }
        Node* toDelete = temp ->  next;
        temp -> next = toDelete -> next;
        toDelete -> next = NULL;
        
        return head;
    }
};