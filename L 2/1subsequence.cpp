/*
print every subsequences of a string
for eg - abc --> ' ', a,b,c,ab,bc,ac,abc(maintained order)
*/

#include <bits/stdc++.h>
using namespace std;
void subsequences(char *in, char *output, int i, int j) {
	// Stop:
	if (in[i] == '\0') { //input array k last m phoch chuke ho
		output[j] = '\0';//output array bhar chuka h, to usme null daldo
		cout << output << " " << endl;
		return;
	}
	subsequences(in, output, i + 1, j); // include here

	output[j] = in[i];
	subsequences(in, output, i + 1, j + 1); //exclude here

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char in[1000], output[1000];
	cin >> in;

	subsequences(in, output, 0, 0);
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// void check(int *a, int i, int n, int *subset, int j) {
// 	if (i == n) {
// 		int id = 0;
// 		while (id < j) {
// 			cout << subset[id] << ' ';
// 			id++;
// 		}
// 		cout << endl;
// 		return;
// 	}
// 	check(a, i + 1, n, subset, j);
// 	subset[j] = a[i];
// 	check(a, i + 1, n, subset, j + 1);

// }
// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int n , x , y;
// 		cin >> n >> x >> y;
// 		int a[n], b[n];
// 		for (int i = 0; i < n ; i++) {
// 			cin >> a[i];
// 		}
// 		for (int i = 0; i < n ; i++) {
// 			cin >> b[i];
// 		}
// 		int subset[100];
// 		check(a, 0, n, subset, 0);
// 	}
// 	return 0;
// }