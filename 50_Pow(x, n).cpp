// optimal approch
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00000;
        long long m = abs(n);
        while(m>0){
            if(m%2==0){
                x = x*x ; 
                m=m/2;
 
            }
            else{
                ans=ans*x;
                m=m-1;
            }
        }
        if(n<0) return 1/ans;
        return ans;
    }
};
//brute force (runs 304/306 testcases)
class Solution {
public:
    double myPow(double x, int n) {
        double temp = x;
        if(x==-1) {
            if(n%2==0) return 1;
            else return -1;
        }
        if(n==0 || x==1) return 1;
        for(int i=0;i<abs(n)-1;i++){
            x=x*temp;
        }
        if(n<0) x=1/x;
        return x;
    }
};