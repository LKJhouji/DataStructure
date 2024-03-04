// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int>& a, vector<int>& b) {
    vector<int> c;
    int t = 0;
    for (size_t i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(1);
    return c;
}
