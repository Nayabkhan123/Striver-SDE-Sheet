//brute force gives Time Limit Exceeded
class Solution {
public:
    void f(int i,int j, int m,int n,int& cnt){
        if(i==m-1&&j==n-1){
            cnt+=1;
            return;
        }
        if(j<n-1) f(i,j+1,m,n,cnt);
        if(i<m-1) f(i+1,j,m,n,cnt);
    }
    int uniquePaths(int m, int n) {
        int cnt=0;
        f(0,0,m,n,cnt);
        return cnt;
    }
};
// using dynamic programming DP

int f(int i,int j, int m,int n,vector<vector<int>>&dp){
    if(i==m-1&&j==n-1){
        return 1;
    }
    if(i>m-1||j>n-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=f(i,j+1,m,n,dp);
    int bottom=f(i+1,j,m,n,dp);
    return dp[i][j]=right+bottom;
}
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(0,0,m,n,dp);
}
// using combination method 
    int uniquePaths(int m, int n) {
        int l = m+n-2;
        int r = min(m-1,n-1);
        double ans=1;
        for(int i=1;i<=r;i++){
            ans*=(double)(l-r+i)/i;
            cout<<(l-r+i)<<" "<<i <<" "<<ans<<" ";
        }
        return ans+0.5;
    }
