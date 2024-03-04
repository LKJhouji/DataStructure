vector<int> alls;
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());

int find(int x) {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        int mid = i + j >> 1;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

//重点可以看题解，解释的非常清晰
