// class Solution {
//   public:
//     void reverseArray(vector<int>& arr, int s, int e){
        
        
//         while(s<=e){
//             swap(arr[s++], arr[e--]);
            
//         }
//     } 
    
//     void rotateclockwise(vector<int>& arr, int k) {
//         // code here
//         int n = arr.size();
        
        
//         if(n == 1 || n == 0) return;
//         if(k > n){
//             k = k % n;
//         }
//         // reverseArray(arr, 0, n-1);
//         // reverseArray(arr, 0, k-1);
//         // reverseArray(arr, k, n-1);
//         reverse(arr.begin(), arr.end());
//         reverse(arr.begin(), arr.begin() + k-1);
//         reverse(arr.begin() + k, arr.end());
        
//     }
// };

class Solution {
  public:
    vector<int> rotateclockwise(vector<int>& arr, int k)
    {   
        // if(arr[] == [])
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        return arr;
    }
};