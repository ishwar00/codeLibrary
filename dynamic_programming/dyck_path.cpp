
/*

link to the problem: https://practice.geeksforgeeks.org/problems/dyck-path1028/1

*/

#include<bits/stdc++.h>

class Solution {
	int dc[2] = { +1, 0 };
	int dr[2] = { 0, -1 };
	vector<vector<int64_t>> grid;
public:

	bool okay(int const& i, int const& j) {
		int N = grid.front().size();
		return i < Nand i >= 0 and j < Nand j >= 0 and (j + i) < N;
	}

	void dyck_path(int const& i, int const& j) {
		for (int d = 0; d < 2; ++d) {
			int R = i + dr[d];
			int C = j + dc[d];
			if (okay(R, C)) {
				if (grid[R][C] == 0)	dyck_path(R, C);
				grid[i][j] += grid[R][C];
			}
		}
	}
};