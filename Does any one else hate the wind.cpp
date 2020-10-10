#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<char>> grid;
vector<pii> wind;
int n, m;
int k;
int t;
int w;
unordered_map<char,pii> charToDir;
vector<pii> dirs({pii(1,0), pii(-1,0), pii(0,1), pii(0,-1), pii(0,0)});

pii getLocation(char c) {
	rep(i,0,sz(grid)) rep(j,0,sz(grid[i])) {
		if (grid[i][j] == c) {
			return pii(i,j);
		}
	}
	assert(false);
	return pii(0,0);
}

bool legal(pii a) {
	int i = a.first;
	int j = a.second;
	return !(i < 0 || j < 0 || i >= n || j >= m) && grid[i][j] != 'L';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	charToDir['S'] = pii(1,0);
	charToDir['N'] = pii(-1,0);
	charToDir['E'] = pii(0,1);
	charToDir['W'] = pii(0,-1);
	charToDir['X'] = pii(0,0);
	cin >> n >> m;
	cin >> k;
	cin >> t;
	cin >> w;

  grid.resize(n, vector<char>(m));
	rep(i,0,n) rep(j,0,m) cin >> grid[i][j];

	wind.resize(w);
	rep(i,0,w) {
		char c; cin >> c;
		wind[i] = charToDir[c];
	}

	vector<vector<vector<bool>>> shop(4010, vector<vector<bool>>(n, vector<bool>(m)));

	rep(i,0,t) {
		int y, x, f; cin >> y >> x >> f;
		shop[f][y][x] = true;
	}

	pii startLocation = getLocation('M');
	pii goal = getLocation('P');

	vector<vi> maxFood(n, vi(m,-1));
	maxFood[startLocation.first][startLocation.second] = k;

	rep(d,0,w) {
		vector<vi> newMaxFood(n, vi(m,-1));
		bool changedSomething = false;
		rep(i,0,n) rep(j,0,m) if (maxFood[i][j] > 0) {
			trav(movement, dirs) {
				int newI = i+movement.first;
				int newJ = j+movement.second;
				pii a(newI, newJ);
				pii windMovement = wind[d];
				newI += windMovement.first;
				newJ += windMovement.second;
				pii b(i+windMovement.first, j+windMovement.second);
				if (newI != i || newJ != j) {
					if (!legal(a) && !legal(b)) continue;
					if (!legal(pii(newI, newJ))) continue;
				}
				newMaxFood[newI][newJ] = max(newMaxFood[newI][newJ], maxFood[i][j]-1);
				changedSomething = true;
				if (shop[d+1][newI][newJ]) {
					newMaxFood[newI][newJ] = k;
				}
				if (pii(newI,newJ) == goal) {
					cout << d+1 << endl;
					return 0;
				}
			}
		}
		if (!changedSomething) {
			cout << -1 << endl;
			return 0;
		}
		maxFood = newMaxFood;
	}
	cout << -1 << endl;
}
