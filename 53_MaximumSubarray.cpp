//BRUTE FORCE APPROCH passes 204/210 testcase
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};

// OPTIMAL APPROCH -> Kadane's Algorithm
int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi)
            maxi=sum;
            if(sum<0)
            sum=0;
        }
        return maxi;
    }

// if in the question substring has to be print.
int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int startindex=-1;
        int endindex=-1;
        int start=-1;
        for(int i=0;i<nums.size();i++){
            if(sum==0) start=i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                startindex=start;
                endindex=i;
            }
            
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
     