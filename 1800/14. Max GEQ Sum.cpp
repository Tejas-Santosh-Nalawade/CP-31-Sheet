#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NEG_INF = -1e15;

// Next Greater Element indices
vector<int> findNextGreaterIndices(const vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, n);

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

// Previous Greater Element indices
vector<int> findPrevGreaterIndices(const vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n, -1);

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

// Segment tree range max query
int query(vector<int>& seg, int node, int start, int end, int l, int r) {
    if(r < start || l > end) return NEG_INF;
    if(l <= start && end <= r) return seg[node];

    int mid = (start + end) / 2;
    return max(
        query(seg, 2*node, start, mid, l, r),
        query(seg, 2*node+1, mid+1, end, l, r)
    );
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int size = 1;
    while(size < n) size *= 2;

    vector<int> prefix(n), suffix(n);

    prefix[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + arr[i];

    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        suffix[i] = suffix[i+1] + arr[i];

    vector<int> prefSeg(2*size, NEG_INF);
    vector<int> suffSeg(2*size, NEG_INF);

    for(int i = 0; i < n; i++) {
        prefSeg[size+i] = prefix[i];
        suffSeg[size+i] = suffix[i];
    }

    for(int i = size-1; i >= 1; i--) {
        prefSeg[i] = max(prefSeg[2*i], prefSeg[2*i+1]);
        suffSeg[i] = max(suffSeg[2*i], suffSeg[2*i+1]);
    }

    vector<int> nextGreater = findNextGreaterIndices(arr);
    vector<int> prevGreater = findPrevGreaterIndices(arr);

    bool ok = true;

    for(int i = 0; i < n; i++) {

        int rightMax = query(prefSeg, 1, 0, size-1,
                             i+1, nextGreater[i]-1) - prefix[i];

        int leftMax = query(suffSeg, 1, 0, size-1,
                            prevGreater[i]+1, i-1) - suffix[i];

        if(max(leftMax, rightMax) > 0) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--)
        solve();

    return 0;
}