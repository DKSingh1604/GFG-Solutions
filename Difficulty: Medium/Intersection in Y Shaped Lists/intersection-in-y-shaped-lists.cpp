// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        map<Node*, bool> visited;
        
        while(temp1 != NULL){
            if(visited[temp1] == false){
                visited[temp1] = true;
            }
            else{
                return temp1;
            }
            
            temp1 = temp1 -> next;
            
        }
        while(temp2 != NULL){
            if(visited[temp2] == false){
                visited[temp2] = true;
            }
            else{
                return temp2;
            }
            
            temp2 = temp2 -> next;
        }
        
    }
};