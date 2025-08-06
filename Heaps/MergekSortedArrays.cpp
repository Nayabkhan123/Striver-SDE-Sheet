/*
    Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into 
    one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, 
    as an ArrayList in java, and list in python).


    Examples :

    Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
    Output: 1 2 3 4 5 6 7 8 9
    Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. 
    The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
*/

class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>ans;
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
            int row = it.second.first;
            int col = it.second.second;
            if(col+1<K) pq.push({arr[row][col+1],{row,col+1}});
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                pq.push(arr[i][j]);
            }
        }
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        return ans;
    }
};