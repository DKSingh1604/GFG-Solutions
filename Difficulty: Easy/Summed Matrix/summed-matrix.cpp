
class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q > 2*n) {
            return 0;
        }
        
        else if(n >= q) {
            return q-1;
        }
        
        else 
            return (2*n - q + 1);
    }
};