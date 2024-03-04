#include <iostream>
#include <string>
#include <vector>
using namespace std;

void nextn(string& s, vector<int>& next, int n) {
	next[0] = 0;
	int i = 1, j = 0;
	while (i < n) {
		while (j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		next[i] = j;
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	//s 匹配串，t 模式串
	int sn, tn;
	string s, t;
	cin >> tn >> t >> sn >> s;
	vector<int> next(tn, 0);
	nextn(t, next, tn);


	int i = 0, j = 0;
	while (i < sn) {
	    while (j && t[j] != s[i]) j = next[j - 1];
	    if (t[j] == s[i]) j++;
	    if (j == tn) {
	        // 匹配成功代码 
	        cout << i - j + 1 << " ";
	        j = next[j - 1];
	    }
	    i++;
	}

    
	return 0;
}