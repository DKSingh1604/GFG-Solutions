class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        
        // Min-heap: (value, row, col)
        priority_queue< tuple<int,int,int>, 
                        vector<tuple<int,int,int>>, 
                        greater<tuple<int,int,int>> > mini;
        
        
        //put the first element of every array into minHeap
        for(int i = 0; i < K; i++){
            mini.push({arr[i][0], i, 0});
        }
        
        vector<int> result;
        
        //extract and push in the result
        while(!mini.empty()){
            auto [val, row, col] = mini.top();
            mini.pop();
            result.push_back(val);
            
            if(col + 1 < K){
                mini.push({arr[row][col+1], row, col+1});
            }
        }
        
        return result;
    }
};