#include "shorts.h" 
#include<stack>
#include<queue>

#include "Graph.h"

using namespace std;

Graph::Graph(int n):
N(n)
{
	W = vvi(N);
}


void Graph::dfs(int start_vertex,vi &V){
	V = vi(N,false);
	stack<int> S;
	S.push(start_vertex);
	while(!S.empty()){
		int v = S.top();
		S.pop();
		V[v]= true;
		trav(W[v],it){
			if(!V[*it]){
				S.push(*it);
			}
		}
	}
}

void Graph::bfs(int start_vertex,vi &V){
	V = vi(N, false);
	queue<int> Q;
	Q.push(start_vertex);
	while(Q.empty()){
		int v = Q.front();
		Q.pop();
		V[v] = true;
		trav(W[v],it){
			if(!V[*it]){
				Q.push(*it);
			}
		}
	}
}

bool Graph::putedge_directed(uint32_t u,uint32_t v){
	if( u >=N || v>=N)
		return false;
	W[u].push_back(v);
	return true;
}
bool Graph::putedge_undirected(uint32_t u,uint32_t v){
	return \
	putedge_directed(u,v) && \
	putedge_directed(v,u);
}

bool Graph::connected_dfs(){
	int start_vertex = 0;
	vi V;
	dfs(start_vertex,V);
	trav(V,ii){
		printf("%d ",*ii);
	}

	return !cpresent(V,false);
}

bool Graph::connected_bfs(){
	int start_vertex=0;
	vi V;
	bfs(start_vertex,V);
	return !cpresent(V,false);
}

