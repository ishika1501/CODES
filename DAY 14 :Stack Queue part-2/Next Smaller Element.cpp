// Input 1:
//     A = [4, 5, 2, 10, 8]
// Output 1:
//     G = [-1, 4, -1, 2, 2]


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        if (st.empty()) v[i] = -1;
        else v[i] = st.top();
        st.push(A[i]);
    }
    return v;
}