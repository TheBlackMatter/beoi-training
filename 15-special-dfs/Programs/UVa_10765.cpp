#include <bits/stdc++.h>
using namespace std;
int n, m, tmp = -1, child = 0;
vector<vector<int>> adjL;
vector<int> num, low;
vector<bool> vis, vis2;
vector<pair<int, int>> artP;


void dfs( int u, int parent ){
	num[u] = low[u] = tmp++;
	vis[u] = true;
	for( int v : adjL[u] ){
		if( !vis[v] ){
			dfs(v, u);
			if( u == 0 ) child++;
			if( low[v] >= num[u] && u != 0 )
				artP[u].first++;
			
		} else if( v != parent )
			low[u] = min(low[u], num[v]);
	}
}

bool Greater(const pair<int, int>& a, const pair<int, int>& b){
	if(a.first == b.first)
		return a.second < b.second;

	return a.first > b.first;
}

int main(){
	while( cin >> n >> m && n != 0 ){
		int x, y;
		adjL.assign(n, vector<int>(0));
		num.assign(n, 0);
		low.assign(n, 0);
		vis.assign(n, false);
		for( int i = 0; i < n; ++i )
			artP.push_back(make_pair(1, i));

		while( true ){
			cin >> x >> y;
			if( x != -1 ){
				adjL[x].push_back(y);
				adjL[y].push_back(x);
			}
			else break;
		}

		dfs(0, -1);

		sort(artP.begin(), artP.end(), Greater);
		for( int j = 0; j < m; ++j )
			cout << artP[j].second << " " << artP[j].first << endl;
		
	}
	return 0;
}
