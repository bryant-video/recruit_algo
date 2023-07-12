// 315. Count of Smaller Number After Self
typedef pair<int, int> pii;
vector<int> res;
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    res.resize(n, 0);
    vector<pii> numsIdx;
    for (int i = 0; i < n; i++) {
        numsIdx.emplace_back(nums[i], i);
    }
    mergesort(numsIdx, 0, n);
    return res;
}
void mergesort(vector<pii>& numsIdx, int left, int right) {
    if (right-left <= 1) return;
    int mid = (left+right)/2;
    mergesort(numsIdx, left, mid);
    mergesort(numsIdx, mid, right);
    
    int j = mid;
    for (int i = left; i < mid; i++) {
        while (j < right && numsIdx[i].first > numsIdx[j].first) j++;
        res[numsIdx[i].second] += (j-mid);
    }
    inplace_merge(numsIdx.begin()+left, numsIdx.begin()+mid, numsIdx.begin()+right);
}



// 327. Count of Range Sum
int lower, upper;
int countRangeSum(vector<int>& nums, int l, int u) {
    lower = l, upper = u;
    int n = nums.size();
    vector<long> sum(n+1, 0);
    for(int i=0; i<n; i++) sum[i+1] = sum[i]+nums[i];
    return mergeSort(sum, 0, n+1);
}

int mergeSort(vector<long>& sum, int left, int right) {
    if (right-left <= 1) return 0;
    int mid = (left+right)/2;
    int j=mid, k=mid, count=0;
    count = mergeSort(sum,left,mid) + mergeSort(sum,mid,right);

    for(int i = left; i<mid; i++) {
        while (j < right && sum[j] - sum[i] < lower) j++;
        while (k < right && sum[k] - sum[i] <= upper) k++;
        count += k-j;
    }

    inplace_merge(sum.begin()+left, sum.begin()+mid, sum.begin()+right);
    return count;
}



// 2426. Numbers of Pairs Satisfying Inequality
long long numberOfPairs(vector<int>& A, vector<int>& B, int diff) {
    for (int i = 0; i < A.size(); i++) {
        C.emplace_back(A[i]-B[i]);
    }
    int left = 0, right = A.size();
    return mergesort(left, right);
}

long long mergesort(int left, int right) {
    if (right - left <= 1) return 0;
    int mid = (left+right) / 2;
    long long count = 0;
    int j = mid;
    count = mergesort(left, mid) + mergesort(mid, right);
    for (int i = left; i < mid; i++) {
        while (j < right && C[i] > C[j] + dif) {
            j++;
        }
        count += (right - j);
    }
    inplace_merge(C.begin()+left, C.begin()+mid, C.begin()+right);
    return count;
}