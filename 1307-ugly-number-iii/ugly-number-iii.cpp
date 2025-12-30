class Solution {
public:
    // Linear Approach : TLE
    // int nthUglyNumber(int n, int a, int b, int c) {
    //     int minm = 1;
    //     int maxm = min(a, min(b, c)) * n;
    //     int uglyNumberCount = 0;
    //     for (int i = minm; i <= maxm; i++) {
    //         if (i % a == 0 || i % b == 0 || i % c == 0) {
    //             uglyNumberCount++;
    //         }
    //         if (uglyNumberCount == n) {
    //             return i;
    //         }
    //     }
    //     return 0;
    // }
long long  calculateGCD(long long  a, long long  b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Manual LCM function using GCD
long long  manualLCM(long long  a, long long b) {
    if (a == 0 || b == 0) return 0;
    return ((a / calculateGCD(a, b))*b);
    //return (std::abs(a * b)) / calculateGCD(a, b);
}
    int nthUglyNumber(int n, int a, int b, int c) {
        long long start = 1, end = min(a, min(b, c)) * n;
        long long ab = manualLCM(a, b);
        long long bc = manualLCM(b, c);
        long long ac = manualLCM(a, c);
        long long abc = manualLCM(a, bc);
        
        int ans = 0;
        while (start < end) {
            long long mid = start + (end - start) / 2;

            long long countDivisible =
                mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid/abc;

            // if (countDivisible == n) {
            //     return mid;
            // }
            if (countDivisible >= n) {
                ans=mid;
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};