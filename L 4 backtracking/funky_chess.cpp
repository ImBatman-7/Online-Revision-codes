#include <iostream>
#include <algorithm>
using namespace std;
int n;
int grid[10][10];
int saare_one = 0, ans = -1, N = 10; // N == max limit of chess board
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};


void input_grid() {
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				saare_one++;
			}
		}
	}

}
void knight(int x, int y, int counter) {
	ans = max(counter, ans);
	for (int i = 0; i < 8 ; i++) {
		int x_co = x + dx[i];
		int y_co = y + dy[i];

		if (x_co >= 0 && y_co >= 0 && y_co < N && x_co < N && grid[x_co][y_co] == 1) {
			grid[x_co][y_co] = 0; //you cant go to a box once visited
			knight(x_co, y_co, counter + 1);
			grid[x_co][y_co] = 1; //backtracking, yaha par kahi aur se bhi aa skte h, isiliye 1 krdo
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	input_grid();
	grid[0][0] = 0;
	knight(0, 0, 1);
	cout << saare_one - ans << endl;
	return 0;
}