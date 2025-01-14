class Solution {
public:
    double myPow(double x, int n) {
        long X;
        if(n == 0){
            return 1;
        }
        if(x == 1){
            return 1;
        }
        if(n<0){
            X = -(long)n;
            return 1.0/myPow(x,X);
        }
        double ans = myPow(x,n/2);
        if(n%2 == 0){
            return ans*ans;
        }else{
            return x*ans*ans;
        }
    }
    
};