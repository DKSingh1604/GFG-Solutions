/*Struture of the node of the linked list is as:

struct Node {
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
    int modularNode(Node *head, int k) {
        // code here
        int lastPos = -1;
        int pos = 1;
        int lastData = -1;
        
        Node* temp = head;
        
        while(temp){
            if(pos % k == 0){
                //if didvible by k
                lastPos = pos;
                lastData = temp -> data;
            }
            temp = temp -> next;
            pos++;
        }
        
        return lastData;
    }
};