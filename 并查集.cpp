//路径压缩
int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
vector<int> a = vector<int> (n, 0); // C++里的一种数组结构

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == a[u] ? u : a[u] = find(a[u]); // 路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    a[v] = u;
}


//按秩合并
int n = 1005; // n根据题目中节点数量而定，一般比节点数量大一点就好
vector<int> a = vector<int> (n, 0); // C++里的一种数组结构
vector<int> r = vector<int> (n, 1); // 初始每棵树的高度都为1

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        r[i] = 1; // 也可以不写
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == a[u] ? u : find(a[u]);// 注意这里不做路径压缩
}

// 判断 u 和 v是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根

    if (r[u] <= r[v]) a[u] = v; // rank小的树合入到rank大的树
    else a[v] = u;

    if (r[u] == r[v] && u != v) r[v]++; // 如果两棵树高度相同，则v的高度+1因为，方面 if (rank[u] <= rank[v]) father[u] = v; 注意是 <=
}


