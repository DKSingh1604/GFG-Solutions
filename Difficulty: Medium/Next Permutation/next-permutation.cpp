class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        int i = n-2;
        while(i >= 0 && arr[i] >= arr[i+1]){
            i--;
        }
        if(i >= 0){
            int j = n-1;
            while(arr[j] <= arr[i]){
                j--;
            }
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin()+i+1, arr.end());
    }
};

// int n = arr.size();
//     int i = n - 2;

//     // Step 1: Find first decreasing element from the end
//     while (i >= 0 && arr[i] >= arr[i + 1]) {
//         i--;
//     }

//     if (i >= 0) {
//         // Step 2: Find just-greater element and swap
//         int j = n - 1;
//         while (arr[j] <= arr[i]) {
//             j--;
//         }
//         swap(arr[i], arr[j]);
//     }

//     // Step 3: Reverse the suffix
//     reverse(arr.begin() + i + 1, arr.end());