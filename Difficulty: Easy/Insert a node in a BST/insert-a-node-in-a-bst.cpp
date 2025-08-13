// Function to insert a node in a BST.

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* insert(Node* node, int key) {

        // Your code goes here
        if(!node){
            Node* newNode = new Node(key);
            return newNode;
        }
        
        if(key < node -> data){
            node -> left = insert(node -> left, key);
            
        }
        
        if(key > node -> data){
            node -> right = insert(node -> right, key);
        }
        
        return node;
        
        
    }
};