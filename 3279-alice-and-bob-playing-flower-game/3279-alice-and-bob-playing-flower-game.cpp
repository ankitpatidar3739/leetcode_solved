class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_n, even_n;
        long long odd_m, even_m;

        odd_n=(n+1)/2;
        odd_m=(m+1)/2;

        even_m=m/2;
        even_n=n/2;

        long long total=odd_n*even_m+even_n*odd_m;

        return total;
    }
};