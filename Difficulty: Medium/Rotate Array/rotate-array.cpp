class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        if(d > n) d= d % n;
        reverse(arr.begin(), arr.begin()+d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
        // reverse(arr.begin(), arr.begin()+n-d);
        // reverse(arr.begin() + (n-d+1), arr.end());
    }
};