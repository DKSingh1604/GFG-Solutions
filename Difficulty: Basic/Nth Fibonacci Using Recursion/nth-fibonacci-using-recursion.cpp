class Solution {
  public:
    //   0, 1, 1, 2, 3, 5, 8, 13
    int nthFibonacci(int n) {
        // code here
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        return nthFibonacci(n-1) + nthFibonacci(n-2);
    }
};