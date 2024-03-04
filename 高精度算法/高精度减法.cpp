//A >= B
bool cmp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int>& a, vector<int>& b)  {
    vector<int> c;
    int t = 0;
    for (size_t i = 0; i < a.size(); i++) {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
