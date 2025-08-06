/*
    You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding 
    one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k 
    maximum sum combinations, sorted in non-increasing order.

    Examples:

    Input: a[] = [3, 2], b[] = [1, 4], k = 2
    Output: [7, 6]
    Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
*/

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>s;
        pq.push({a[0]+b[0],{0,0}});
        s.insert({0,0});
        vector<int>ans;
        int n=a.size();
        while(!pq.empty() && k--){
            auto it = pq.top();
            int sum = it.first;
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back(sum);
            pq.pop();
            if(i<n && !s.count({i+1,j})){
                pq.push({a[i+1]+b[j],{i+1,j}});
                s.insert({i+1,j});
            }
            
            if(j<n && !s.count({i,j+1})){
                pq.push({a[i]+b[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=a[i]+b[j];
                pq.push(sum);
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int>ans(k);
        int i=k-1;
        while(!pq.empty()){
            ans[i]=pq.top();
            pq.pop();
            i--;
        }
        return ans;
    }
};
