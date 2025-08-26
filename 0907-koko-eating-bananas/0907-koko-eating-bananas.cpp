class Solution {
    long long findmax(std::vector<int>& piles) {
        long long maxi = 0;
        for (int pile : piles) {
            if (pile > maxi) {
                maxi = pile;
            }
        }
        return maxi;
    }

    long long calh(std::vector<int>& piles, long long hourly) {
        long long totalh = 0;
        for (int pile : piles) {
            totalh += (pile + hourly - 1) / hourly;
        }
        return totalh;
    }

public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        long long low = 1;
        long long high = findmax(piles);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid == 0) { // To handle cases where mid could become 0 and cause division by zero.
                low = mid + 1;
                continue;
            }

            long long totalh = calh(piles, mid);
            if (totalh <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};