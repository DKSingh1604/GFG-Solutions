/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        // Your code here
        if(del_node == NULL || del_node -> next == NULL) return;
        
        del_node -> data = del_node -> next -> data;
        
        Node* temp = del_node -> next;
        
        del_node -> next = del_node -> next -> next;
        
        delete temp;
    }
};