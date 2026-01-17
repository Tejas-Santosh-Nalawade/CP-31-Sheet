#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9;
const ll MODULO = 1000000007;

const vector<ll> DX{-1, 0, 1, 0};
const vector<ll> DY{0, 1, 0, -1};

ll computeGCD(ll a, ll b) {
	while (b != 0) {
		ll temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

ll computeLCM(ll a, ll b) {
	return (a / computeGCD(a, b)) * b;
}

ll computePower(ll base, ll exponent) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result *= base;
		}
		base *= base;
		exponent /= 2;
	}
	return result;
}

int main() {
	ll rows, columns;
	cin >> rows >> columns;
	vector<string> grid(rows);
	pair<ll, ll> start, end;

	for (ll i = 0; i < rows; ++i) {
		cin >> grid[i];
		for (ll j = 0; j < columns; ++j) {
			if (grid[i][j] == 'S') start = {i, j};
			if (grid[i][j] == 'T') end = {i, j};
		}
	}

	vector<vector<vector<vector<bool>>>> visited(
		rows, vector<vector<vector<bool>>>(columns, vector<vector<bool>>(4, vector<bool>(4, false)))
	);

	queue<vector<ll>> stateQueue;
	for (ll direction = 0; direction < 4; ++direction) {
		ll nextX = start.first + DX[direction];
		ll nextY = start.second + DY[direction];
		if (nextX >= 0 && nextY >= 0 && nextX < rows && nextY < columns && grid[nextX][nextY] != '#') {
			stateQueue.push({nextX, nextY, direction, 1, 1});
			visited[nextX][nextY][direction][1] = true;
		}
	}

	while (!stateQueue.empty()) {
		auto state = stateQueue.front();
		stateQueue.pop();

		ll x = state[0], y = state[1], dir = state[2], turnCount = state[3], distance = state[4];

		if (make_pair(x, y) == end) {
			cout << distance << '\n';
			return 0;
		}

		for (ll newDir = 0; newDir < 4; ++newDir) {
			ll nextX = x + DX[newDir];
			ll nextY = y + DY[newDir];
			ll newTurnCount = (newDir == dir) ? turnCount + 1 : 1;

			if (newTurnCount > 3 || nextX < 0 || nextY < 0 || nextX >= rows || nextY >= columns || grid[nextX][nextY] == '#')
				continue;
			if (visited[nextX][nextY][newDir][newTurnCount])
				continue;

			visited[nextX][nextY][newDir][newTurnCount] = true;
			stateQueue.push({nextX, nextY, newDir, newTurnCount, distance + 1});
		}
	}

	cout << -1 << '\n';
	return 0;
}