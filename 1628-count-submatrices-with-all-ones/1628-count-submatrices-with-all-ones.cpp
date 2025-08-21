#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Step 1: Calculate consecutive ones ending at each column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    dp[i][j] = (j > 0) ? dp[i][j-1] + 1 : 1;
                }
            }
        }
        
        int total_submatrices = 0;
        
        // Step 2: Count all submatrices
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    int min_width = dp[i][j];
                    // Iterate upwards from current row to count all valid rectangles
                    for (int k = i; k >= 0; --k) {
                        min_width = min(min_width, dp[k][j]);
                        total_submatrices += min_width;
                    }
                }
            }
        }
        
        return total_submatrices;
    }
};