#include <bits/stdc++.h>
using namespace std;

#define forRange(i, l, r) for(int i = int(l); i < int(r); i++)
#define sizeOf(a) int((a).size())

struct Segment {
    int left, right;

    bool operator< (const Segment &other) const {
        if (left != other.left)
            return left < other.left;
        return right < other.right;
    };
};

void solve() {
    int numSegments;
    cin >> numSegments;

    vector<Segment> segments(numSegments);
    forRange(i, 0, numSegments) 
        cin >> segments[i].left >> segments[i].right;

    vector<int> answer(numSegments, 0);

    for (int pass = 0; pass < 2; pass++) {
        vector<int> order(numSegments);
        iota(order.begin(), order.end(), 0); 
        sort(order.begin(), order.end(), [&segments](int i, int j){
            if (segments[i].left != segments[j].left)
                return segments[i].left < segments[j].left;
            return segments[i].right > segments[j].right;
        });

        set<int> activeRights; 
        for (int idx : order) {
            auto it = activeRights.lower_bound(segments[idx].right);
            if (it != activeRights.end())
                answer[idx] += *it - segments[idx].right;
            activeRights.insert(segments[idx].right);
        }
        for (auto &s : segments) {
            s.left = -s.left;
            s.right = -s.right;
            swap(s.left, s.right);
        }
    }

    map<Segment, int> segmentCount;
    for (auto s : segments)
        segmentCount[s]++;
    
    for (int i = 0; i < numSegments; i++)
        if (segmentCount[segments[i]] > 1)
            answer[i] = 0;

    for (int val : answer)
        cout << val << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--)
        solve();
    
    return 0;
}
