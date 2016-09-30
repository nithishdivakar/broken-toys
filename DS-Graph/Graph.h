#include "shorts.h"

class Graph{
private:
	vvi W;
	int N;
public:
	Graph(int n);
	void dfs(int,vi&);
	void bfs(int,vi&);
	bool connected_bfs();
	bool connected_dfs();
	bool putedge_undirected(uint32_t u,uint32_t v,uint32_t w);
	bool putedge_undirected(uint32_t u,uint32_t v);
	bool putedge_directed(uint32_t u,uint32_t v);
	bool putedge_directed(uint32_t u,uint32_t v,uint32_t w);
};
