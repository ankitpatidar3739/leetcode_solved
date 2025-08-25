class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long k=0;
        long long currentapples=0;

        while(currentapples<neededApples){
            k++;
            currentapples+=12*k*k;
        }
        return  k*8;
    }
};