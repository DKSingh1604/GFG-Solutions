/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        int len = 0;
        Node* temp = head;
        // vector<int> hashArray(1000001);
        
        while(temp){
            len++;
            temp = temp -> next;
        }
        int count;
        if(len > k) count = len - k + 1;
        else if(len == k) return head -> data;
        else return -1;
        
        temp = head;
        while(temp && count > 1){
            temp = temp -> next;
            count--;
        }
        
        return temp -> data;
        
        
    }
};