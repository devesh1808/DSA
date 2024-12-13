long long findScore(vector<int> &nums)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push({nums[i], i});
    long long score = 0, timer = 0;
    unordered_set<long long> s;
    while (!pq.empty())
    {
        long long val = pq.top().first;
        long long indx = pq.top().second;
        pq.pop();
        if (timer == 0)
        {
            score += val;
            s.insert(indx);
        }
        else
        {
            if (s.find(indx - 1) == s.end() && s.find(indx + 1) == s.end())
            {
                score += val;
                s.insert(indx);
            }
        }
        timer++;
    }
    return score;
}