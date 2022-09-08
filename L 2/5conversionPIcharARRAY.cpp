#include<iostream>
using namespace std;
#include<cstring>

void convert(char s[], int i) {
	if (s[i] == '\0' or s[i + 1] == '\0') {
		return ;
	}
	if (s[i] == 'p' and s[i + 1] == 'i') {
		// cout << sizeof(*s) / sizeof(char) << endl;
		for (int j = strlen(s); j >= i + 2 ; j--) {
			s[j + 2] = s[j]; //string m last m se shuru krke sbhi characters ko 2 kada aage badha\
			do, aur piche se current i ke 2 aage tak aao bas kyunki "pi" ki jagah "3." le lega.
		}
		s[i] = '3';
		s[i + 1] = '.';
		s[i + 2] = '1';
		s[i + 3] = '4';
	}
	convert(s, i + 1);
}



int main() {
	char s[100000];
	cin >> s;
	convert(s, 0);
	cout << s << endl;
}