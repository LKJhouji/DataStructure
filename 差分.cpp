void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

insert(i, i, a[i]); //用前缀和数组构造差分数组

