/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
stack<int>s;
void QueueStack ::push(int x) {
    // code here
    q1.push(x);
    while(!q2.empty()){
        int val=q2.front();
        q1.push(val);
        q2.pop();
    }
    
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
        // Your Code
}

int QueueStack ::pop() {

    if(q2.empty()) return -1;
    int x=q2.front();
    q2.pop();
    return x;
    // code here
}