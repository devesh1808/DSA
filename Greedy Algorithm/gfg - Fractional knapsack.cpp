class Solution {
  public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        double one = (double)(a.first)/(double)(a.second);
        double two = (double)(b.first)/(double)(b.second);
        return one>two;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        double ans = 0.0;
        vector<pair<int, int>> v;
        int n = val.size();
        for(int i=0; i<n; i++){
            v.push_back({val[i], wt[i]});
        }
        sort(v.begin(), v.end(), comp);
        for(int i=0;i<n;i++){
            if(capacity == 0) break;
            if(v[i].second<=capacity){
                ans += v[i].first;
                capacity -= v[i].second;
            }
            else{
                ans += double(capacity)*(v[i].first/double(v[i].second));
                capacity = 0;
            }
        }
        return ans;
    }
};