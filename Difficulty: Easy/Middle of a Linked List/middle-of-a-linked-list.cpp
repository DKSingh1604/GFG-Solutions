/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node* temp = head;
        
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        
        temp = head;
        for(int i = 0; i < count/2; i++){
            temp = temp -> next;
            
        }
        return temp -> data;
    }
};