#include "Graph.h"
#include "shorts.h"
#include<numeric>

int main(){
	int T,u,v;
	scanf("%d",&T);
	Graph G(T);
	FOR(i,0,T){
		scanf("%d %d",&u,&v);
		//printf("%d %d\n",u,v);
		G.putedge_undirected(u-1,v-1);
	}
	vi V;
	int a =0;
	FOR(i,0,T){
		PRINT(i);
		G.dfs(i,V);//);
		int sum = std::accumulate(all(V), 0);
		a = std::max(a,sum);
	}
	printf("%d",a);
	return 0;
}
