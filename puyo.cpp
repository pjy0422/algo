#include<bits/stdc++.h>
using namespace std;


int m, n;
string s;

#define X first
#define Y second
/*9 2
ABCCBCCDA*/


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> m;
	cin >> s;
	s += '$';
	stack<pair<char, int>>v;
	for (int i = 0; i < s.size(); i++) {
		if (v.empty()) {
			v.push({ s[i],1 });
		}
		else if (v.top().X == s[i])
			v.top().Y++;
		else {
			if (v.top().Y >= m) {
				v.pop();
				i--;
			}
			else {
				v.push({ s[i],1 });
			}
		}
	}
	v.pop();
	if (v.empty()) {
		cout << "CLEAR!";
		return 0;
	}
	stack<char>f;
	while (!v.empty()) {
		f.push(v.top().X);
		v.pop();
	}
	while (!f.empty()) {
		cout << f.top();
		f.pop();
	}
	
}