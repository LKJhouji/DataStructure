bool check(int mid) {

}

int bsearch(vector<int>& arr, int target) {
    int l = -1, r = n;
    while (l + 1 != r) {    //这样两个区间不会重合，不容易出错
        int mid = l + r >> 1;
        if (arr[mid] <= target) l = mid;    
        else r = mid;
    }
    return l;   // <= target 最大值
}

int bsearch(vector<int>& arr, int target) {
    int l = -1, r = n;
    while (l + 1 != r) {
        int mid = l + r >> 1;  
        if (arr[mid] >= target) r = mid;
        else l = mid;
    }
    return r;   // >= target 最小值
}

