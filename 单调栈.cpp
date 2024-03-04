vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> st;  //装下标    //sp = n
    vector<int> res(T.size(), 0);    //sp = n
    for (int i = 0; i < T.size(); i++) {
        while (!st.empty() && T[i] > T[st.top()]) {
            res[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i); //都要插入
    }
    return res;
}

