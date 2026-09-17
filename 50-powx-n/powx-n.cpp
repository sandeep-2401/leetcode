class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        double ans = 1.0;
        if(p<0) p*=-1;
        while(p){
            if(p%2){
                ans*=x;
                p-=1;
            }
            else{
                x*=x;
                p/=2;
            }
        }

        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};