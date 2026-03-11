#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long LL;

struct Edge {
    int from, to;
};

int currentEdgeIndex, numNodes;
const int MOD = 1e9 + 7;
LL primeFactors[100005];       
LL adjacencyStart[100005];     
LL visited[100005];           
LL edgeContribution[100005];   
Edge edges[200040];           


int compareEdges(Edge a, Edge b) { return a.from < b.from; }
int compareDescending(LL a, LL b) { return a > b; }

LL computeSubtreeSize(int node) {
    LL size = 1;
    visited[node] = 1;

    for (int i = adjacencyStart[node]; i < adjacencyStart[node + 1]; i++)
        if (!visited[edges[i].to])
            size += computeSubtreeSize(edges[i].to);

    edgeContribution[currentEdgeIndex] = size * (numNodes - size); // Contribution for this edge
    currentEdgeIndex++;

    return size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int k = 0, numPrimes;
        LL result = 1;

        cin >> numNodes;

        for (int i = 0; i < numNodes - 1; i++) {
            cin >> edges[i].from >> edges[i].to;
            edges[i + numNodes - 1].from = edges[i].to;
            edges[i + numNodes - 1].to = edges[i].from;
        }

        int edgeListSize = 2 * numNodes - 2;

        sort(edges, edges + edgeListSize, compareEdges);

        for (int i = 1; i < edgeListSize; i++) {
            if (edges[i].from > edges[i - 1].from) {
                for (int j = edges[i - 1].from + 1; j <= edges[i].from; j++)
                    adjacencyStart[j] = i;
            }
        }
        for (int j = edges[edgeListSize - 1].from + 1; j <= numNodes + 2; j++)
            adjacencyStart[j] = edgeListSize;

        currentEdgeIndex = k = 0;
        computeSubtreeSize(1);

        cin >> numPrimes;
        for (int i = 0; i < numPrimes; i++)
            cin >> primeFactors[i];

        sort(primeFactors, primeFactors + numPrimes, compareDescending);
        sort(edgeContribution, edgeContribution + numNodes - 1, compareDescending);

        if (numPrimes < numNodes) {
            for (int i = numPrimes; i < numNodes - 1; i++)
                primeFactors[i] = 1;
        } else {
            int i;
            for (i = numPrimes - 1; i > numPrimes - numNodes; k = i, i--)
                edgeContribution[i] = edgeContribution[i - numPrimes + numNodes - 1];
            for (; i; i--)
                edgeContribution[i] = edgeContribution[0];
        }

        int totalElements = max(numPrimes, numNodes - 1);
        
        int i;
        for (i = 0, result = edgeContribution[0]; i <= k; i++)
            result = result * primeFactors[i] % MOD;

        for (; i < totalElements; i++)
            result = (result + edgeContribution[i] * primeFactors[i]) % MOD;

        cout << result << endl;

        for (int i = 1; i <= numNodes; i++)
            visited[i] = 0;
    }
}