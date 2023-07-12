// 45. Jump Game 2
int jump(vector<int>& nums) {
    int curStop = 0;
    int curFur = 0;
    int res = 0;
    for (int i = 0; i < nums.size()-1; i++) {
        curFur = max(curFur, i + nums[i]);
        if (i == curStop) {
            curStop = curFur;
            res++;
        }
    }
    return res;
}


// 1326. Minimum Number of Taps to Open to Water a Garden
int minTaps(int n, vector<int>& ranges) {
    int len = ranges.size();
    vector<int> newR(len, 0);
    for (int i=0; i < len; i++) {
        int right = i + ranges[i];
        int left = max(0, i-ranges[i]);
        newR[left] = max(newR[left], right -left);
    }
    
    int curFur = 0, curStop = 0, jump = 0;
    for (int i =0; i < len-1; i++) {
        if (i>curFur) return -1;
        curFur = max(curFur, i+newR[i]);
        if (i == curStop) {
            curStop = curFur;
            jump++;
        }
    }
    return curFur >= len-1 ? jump : -1;
}


// 871. Min Number of Refueling Stops
int minRefuelStops(int target, int fuel, vector<vector<int>>& s) {
    int i = 0, res;
    int cur = fuel;
    priority_queue<int> pq;
    for (res = 0; cur < target; res++) {
        while (i < s.size() && s[i][0] <= cur) {
            pq.emplace(s[i][1]);
            i++;
        }
        if (pq.empty()) return -1;
        cur += pq.top(), pq.pop();
    }
    return res;
}