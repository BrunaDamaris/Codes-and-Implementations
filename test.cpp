/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> list[1000];
int vis[1000],v = 0;
int graph[10][10];

void dfs(int u){
	vis[u] = 1;
	cout << u << endl;
	for(auto v: list[u]){
		if(vis[v] == 0){
			dfs(v);
		}
	}
}

int main(){
	int i;
	vector< pair <int, int> > arestas;
	arestas.push_back(make_pair(1, 2));
	arestas.push_back(make_pair(1, 3));
	arestas.push_back(make_pair(2, 4));
	arestas.push_back(make_pair(3, 5));
	list[1].push_back(2);
	list[1].push_back(3);
	list[2].push_back(4);
	list[3].push_back(5);
	for(i = 0;i < 1000;++i) vis[i] = 0;
	dfs(1);
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#define maxi 10000

using namespace std;

vector<int> list[maxi];
int vis[maxi],v,dist[maxi];

void dfs(int u){
	vis[u] = 1;
	for(auto v: list[u]){
		if(vis[v] == 0){
			dist[v] = dist[u] + 1;
			dfs(v);
		}
	}
}

int main() {
	vector< pair <int, int> > arestas;
	int numberofedges,u,v,number[maxi],i,numbers,minor = maxi,minorindex = maxi;
	cin >> numberofedges;
	for(i = 1;i < numberofedges;++i) {
		cin >> u >> v;
		arestas.push_back(make_pair(u,v));
		list[u].push_back(v);
	}
	for(i = 1;i <= maxi;++i) {
		vis[i] = 0;
		dist[i] = 0;
		number[i] = 0;
	}
	int cases;
	cin >> cases;
	for(i = 1;i <= cases;++i){
		cin >> numbers;
		number[numbers] = numbers;
	}
	dfs(1);
	for(i = 1;i <= numberofedges;++i){
		//cout << dist[i] << "!" << number[i] << endl;
		if(dist[i] <= minor && dist[i] != 0 && number[i] != 0) {
			minor = dist[i];
		}
	}
	/*for(i = 1; i <= numberofedges;++i){
		if(dist[i] == minor) 
		{
			if(i <= minorindex && number[i] != 0) minorindex = i;
		}
	}
	cout << minorindex << endl;*/
	for(i = 1; i <= numberofedges;++i){
		if(number[i] != 0){
				cout << i << endl;
				break;
			}
	}
}

*/
