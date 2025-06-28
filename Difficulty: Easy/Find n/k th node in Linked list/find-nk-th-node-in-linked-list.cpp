/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    int fractional_node(struct Node *head, int k) {
        // your code here
        
        if(head == NULL){
            return 0;
        }
        int n = 0;
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp ->  next;
            n++;
            
        }
        int d = n/k;
        temp = head;
        for(int i = 0; i < d; i++){
            temp = temp -> next;
        }
        return temp -> data;
    }
};