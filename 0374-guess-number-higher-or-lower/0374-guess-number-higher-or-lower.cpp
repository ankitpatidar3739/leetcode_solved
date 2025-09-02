class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Recalculate mid
            int result = guess(mid); // Call the API
            
            if (result == 0) {
                return mid; // Found the number
            } else if (result == -1) {
                high = mid - 1; // Pick is lower
            } else { // result == 1
                low = mid + 1; // Pick is higher
            }
        }
        
        return -1; // Should not be reached if a number is always picked
    }
};