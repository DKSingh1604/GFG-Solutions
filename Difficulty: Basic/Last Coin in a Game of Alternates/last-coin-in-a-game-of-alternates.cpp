class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        // Handle the edge case where the array might be empty.
        // Although typically problems like this guarantee at least one element.
        if (arr.empty()) {
            return 0; // Or throw an exception, depending on problem specific requirements.
                      // Assuming arr.size() >= 1 based on common GFG problem setups.
        }
        
        // Initialize two pointers: one at the beginning and one at the end of the array.
        int left = 0;
        int right = arr.size() - 1;

        // The game continues until only one coin remains.
        // This means we keep playing as long as there are at least two coins left (left < right).
        while (left < right) {
            // Both players follow a greedy strategy: they always pick the coin
            // with the maximum value from the two available ends.
            if (arr[left] >= arr[right]) {
                // If the coin at the left end is greater than or equal to the coin at the right end,
                // the current player picks the left coin.
                // This means the left boundary of the remaining coins moves one step to the right.
                left++;
            } else {
                // Otherwise (if the coin at the right end is greater),
                // the current player picks the right coin.
                // This means the right boundary of the remaining coins moves one step to the left.
                right--;
            }
        }

        // When the loop terminates, 'left' and 'right' pointers meet (left == right).
        // The element at this position is the last coin remaining in the array.
        return arr[left]; // Or arr[right], both are the same at this point.
    }
};