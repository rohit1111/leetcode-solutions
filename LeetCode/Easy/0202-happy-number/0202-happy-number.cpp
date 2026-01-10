class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            int d = n%10;
            sum += (d*d);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;

        while(fast!=1){
            slow=digitSum(slow);
            fast=digitSum(fast);
            fast=digitSum(fast);

            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;    
    }
};