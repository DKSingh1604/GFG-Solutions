/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        if(!head) return 0;
        int count = 0;
        
        while(head){
            count++;
            head = head -> next;
        }
        return count;
        
    }
};