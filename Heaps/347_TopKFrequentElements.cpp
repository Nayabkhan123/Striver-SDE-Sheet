/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return 
    the answer in any order.

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};