class Solution {
  public:
    int findSum(int n) {
        int sum=0;
        // Approach-1: TC: O(n)
        // for(int i=0;i<=n;i++){
        //     sum += i;
        // }
        
        // Approach-2: TC: O(1)
        sum = n * (n+1);
        sum = sum/2;
        return sum;
    }
};
