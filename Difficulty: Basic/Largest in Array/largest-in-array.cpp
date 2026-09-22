class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 1) return arr[0];
        priority_queue<int> maxHeap;
        
        for(int i = 0; i < n; i++){
            maxHeap.push(arr[i]);
        }
        
        return maxHeap.top();
    }
};
