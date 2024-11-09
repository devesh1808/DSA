class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& s, vector<int>& e) {
        // Your code here
        int n = s.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({e[i], s[i]});
        }
        sort(v.begin(), v.end());
        int cnt = 1, endTime = v[0].first;
        for(int i=1; i<n; i++){
            if(v[i].second>endTime){
                cnt++;
                endTime = v[i].first;
            }
        }
        return cnt;
    }
};