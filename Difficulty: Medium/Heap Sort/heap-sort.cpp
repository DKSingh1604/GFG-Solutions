// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    
    void heapify(vector<int>& arr, int n, int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest]) largest = left;
            if (right < n && arr[right] > arr[largest]) largest = right;

            // If i is already largest, stop
            if (largest == i) break;

            swap(arr[i], arr[largest]);
            i = largest; // continue heapifying down iteratively
        }
    }

    // Main function to do heap sort
    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Step 2: Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);  // Move current root to end
            heapify(arr, i, 0);    // Heapify reduced heap
        }
    }
};