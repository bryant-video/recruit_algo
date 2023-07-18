// 1235. Maximum Profit in Job Scheduling
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  int n = startTime.size();
  vector<vector<int>> jobs;
  for (int i = 0; i < n; ++i) {
      jobs.push_back({endTime[i], startTime[i], profit[i]});
  }
  sort(jobs.begin(), jobs.end());
  map<int, int> dp = {{0, 0}};
  for (auto& job : jobs) {
      int cur = prev(dp.upper_bound(job[1]))->second + job[2];
      if (cur > dp.rbegin()->second)
          dp[job[0]] = cur;
  }
  return dp.rbegin()->second;
}

// 2008. Maximum Earning from taxi
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
  map<int, long long> dp = {{0,0}};
  sort(rides.begin(), rides.end(), [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; } );
  for (auto& ride : rides) {
    int start = ride[0], end = ride[1], tip = ride[2];
    long long profit = prev(dp.upper_bound(start))->second + (end-start+tip);
    if (profit > dp.rbegin()->second) 
      dp[end] = profit;
  }
  return dp.rbegin()->second;
}