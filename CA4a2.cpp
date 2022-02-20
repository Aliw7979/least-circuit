#include<iostream>
#include<vector>
#include<map>
#include<iterator>

using namespace std;
#define MAX_SIZE 99999

struct coordination {
	int first;
	int second;
};
int checker(vector<int> adj[], int v,vector<bool>& repeat, vector<int>& color);

int main(){
	
	int n, m;
	cin >> n >> m;
	int temp1, temp2;
	struct coordination edge;
	vector<struct coordination> edges;
	vector<int> j[MAX_SIZE];
	for (int i = 0;i < m;i++) {
		cin >> temp1 >> temp2;
		edge.first = temp1;
		edge.second = temp2;
		edges.push_back(edge);
		j[temp1].push_back(temp2);
		j[temp2].push_back(temp1);
	}
	vector<bool> repeat(MAX_SIZE);
	vector<int> color(MAX_SIZE);
	repeat[1] = true;
	color[1] = 0;

	
	if (checker(j, 1, repeat, color)) {
		cout << "YES" << endl;
		for (int i=0;i<edges.size();i++) {
			cout << color[edges[i].first];
		}
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}

int checker(vector<int> adj[], int v,vector<bool>& repeat, vector<int>& color){
	for (int i = 0;i <adj[v].size();i++) {
		if (repeat[adj[v][i]] == 0) {
			repeat[adj[v][i]] = 1;
			color[adj[v][i]] = !color[v];
			if (!checker(adj, adj[v][i], repeat, color))
				return 0;
		}
		else if (color[adj[v][i]] == color[v])
			return 0;
	}
	return 1;
}