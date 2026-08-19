/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        if(!head) return newNode;
        
        
        Node* temp = head;
        
        //will end at the second last node
        while(temp -> next){
            temp = temp -> next;
        }
        
        
        
        temp -> next = newNode;
        newNode -> next = NULL;
        
        return head;
    }
};