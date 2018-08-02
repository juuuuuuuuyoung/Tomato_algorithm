#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

using ii = pair<int, int>;

const int INF = 0x3F3F3F3F;

vector<ii> offices, people;

// i번 치킨집과 j번 집의 거리
int dist[13][2500];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int x, j = 0; j < n; ++j) {
			scanf("%d", &x);
			if (x == 1)
				people.push_back(make_pair(i, j));
			else if (x == 2)
				offices.push_back(make_pair(i, j));
		}
	}

	int o_size = offices.size(), p_size = people.size();
	for (int i = 0; i < o_size; ++i) {
		for (int j = 0; j < p_size; ++j) {
			ii o = offices[i], p = people[j];
			dist[i][j] = abs(o.first - p.first) + abs(o.second - p.second);
		}
	}

	int ans = INF;
	vector<bool> perm(o_size, false);
	for (int i = 0; i < m; ++i) perm[o_size - 1 - i] = true;
	do {
		// 각 사람들까지의 거리
		vector<int> D(p_size, INF);
		for (int i = 0; i < o_size; ++i) {
			if (!perm[i]) continue;
			for (int j = 0; j < p_size; ++j)
				D[j] = min(D[j], dist[i][j]);
		}

		int tans = 0;
		for (auto& t : D) tans += t;
		ans = min(ans, tans);
	} while (next_permutation(all(perm)));

	printf("%d\n", ans);

	return 0;
}
