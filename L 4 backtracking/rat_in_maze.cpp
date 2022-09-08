#include <iostream>
using namespace std;

bool solution[1001][1001] = {0}, visited[1001][1001] = {0};
int counter = 0;
bool check(char maze[][1001], int i, int j, int n, int m) {
	if (i == n - 1 && j == m - 1) { //end m aagya, ek answer aagya
		solution[i][j] = 1; // ye target tha apna to , isko bhi 1 kro
		for (int i = 0; i < n ; i++) { //printing that block
			for (int j = 0; j < m ; j++) {
				cout << solution[i][j];
			}
			cout << endl;
		}
		cout << endl;
		return false; // ek answer print kr diya, main ko bhej dega
		// agar isko return false krte to, saare possible path ko print kr dega(WON'T CONSIDER RIGHTMOST OR DOWNMOST PATH)
		//also visited[i][j] = 1; ko comment krna as, right ya down jana matter ni krta, aur apan ne main m already visited 1 kr rkhe h
	}

	//kya jaha pe khade h hum ,wo visited h
	if (visited[i][j] == 1) { //yaha pe ni jaa skte('X')
		return false;
	}

	//jis block pe khade ho usko 1 kardo aur visted krdo
	solution[i][j] = 1;

	//ab isme dobara visit ni krna h ..isko 1 krdo
	// visited[i][j] = 1;

	//rightmost path //isko isiliye pehle likha h kyunki right preference h
	if (j + 1 < m && !visited[i][j + 1]) { //!visited --> agar right block visited ni h to right m jaao
		bool rightans = check(maze, i, j + 1, n , m);
		if (rightans == 1) { //agr mai yaha se right m jaata hu to mai end mai phuch jaunga, 0 hua to down wala consider krenge
			return rightans;
		}
	}

	//down path
	if (i + 1 < n && !visited[i + 1][j]) {
		bool downans = check(maze, i + 1, j, n, m);
		if (downans == 1) {
			return downans;
		}
	}

	//jab na right jaa skte, na down jaa skte, to backtrack(retreat) karo,mtlb jaha jaa chuke the usko zero krdo wapas
	solution[i][j] = 0;
	return false; // do note ki yaha se jo answer aayega wo right down wale k andar jayega
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char maze[1001][1001];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'X') {
				visited[i][j] = 1;// kyunki yaha par jaana mana h
			}
		}
	}
	int ans = check(maze, 0, 0, n, m);
	if (ans == 0) {
		cout << "-1" << endl;
	}
	cout << endl << counter << endl;


	return 0;
}