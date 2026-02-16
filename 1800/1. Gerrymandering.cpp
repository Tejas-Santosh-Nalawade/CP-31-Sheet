#include <bits/stdc++.h>

using namespace std;

int calculateMaxScore(int index, int toggle, vector<string> &sequences, vector<vector<int>> &voteScores, vector<vector<int>> &memo) {
	int sequenceLength = sequences[0].size();

	if (index >= sequenceLength) {
		return 0;
	}

	if (memo[index][toggle] != -1) {
		return memo[index][toggle];
	}

	int maxScore = 0;

	if (toggle == 0) {
		int score = (voteScores[0][index + 1] + voteScores[0][index + 2] + voteScores[0][index + 3]) / 2 + 
					(voteScores[1][index + 1] + voteScores[1][index + 2] + voteScores[1][index + 3]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 3, 0, sequences, voteScores, memo));

		score = (voteScores[1][index + 1] + voteScores[0][index + 2] + voteScores[0][index + 1]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 1, 1, sequences, voteScores, memo));

		score = (voteScores[1][index + 1] + voteScores[1][index + 2] + voteScores[0][index + 1]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 1, 2, sequences, voteScores, memo));
	}
	else if (toggle == 1) {
		int score = (voteScores[0][index + 2] + voteScores[0][index + 3] + voteScores[0][index + 4]) / 2 + 
					(voteScores[1][index + 1] + voteScores[1][index + 2] + voteScores[1][index + 3]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 3, 1, sequences, voteScores, memo));

		score = (voteScores[1][index + 1] + voteScores[1][index + 2] + voteScores[0][index + 2]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 2, 0, sequences, voteScores, memo));
	}
	else if (toggle == 2) {
		int score = (voteScores[1][index + 2] + voteScores[1][index + 3] + voteScores[1][index + 4]) / 2 + 
					(voteScores[0][index + 1] + voteScores[0][index + 2] + voteScores[0][index + 3]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 3, 2, sequences, voteScores, memo));

		score = (voteScores[0][index + 1] + voteScores[0][index + 2] + voteScores[1][index + 2]) / 2;
		maxScore = max(maxScore, score + calculateMaxScore(index + 2, 0, sequences, voteScores, memo));
	}

	return memo[index][toggle] = maxScore;
}

void solveTestCase() {
	int sequenceLength;
	cin >> sequenceLength;
	vector<string> sequences(2);
	vector<vector<int>> voteScores(2, vector<int>(sequenceLength + 8, 0));

	for (int i = 0; i < 2; i++) {
		cin >> sequences[i];
		for (int j = 0; j < sequenceLength; j++) {
			if (sequences[i][j] == 'A') {
				voteScores[i][j + 1] = 1;
			}
		}
	}

	vector<vector<int>> memo(sequenceLength + 9, vector<int>(3, -1));
	int result = calculateMaxScore(0, 0, sequences, voteScores, memo);
	cout << result << endl;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) {
		solveTestCase();
	}
	return 0;
}