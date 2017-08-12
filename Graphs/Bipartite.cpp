#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define sf scanf
#define pf printf
#define pub push_back
#define puf push_front
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int color[205];
int is_bipartite(vector<vii> adj_list,int u){
	color[u]=0;
	int v,i;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u=q.front();q.pop();
		for(i=0;i<adj_list[u].size();i++){
			v=adj_list[u][i].first;
			if(color[v]==-1){
				color[v]=1-color[u];
				q.push(v);
			}
			else if(color[v]!=-1 && color[v]==color[u])
				return 0;
		}
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	vector<vii> adj_list(205);
	int n,t,num_edges,i,j;
	while(sf("%d",&n)&& n){
		adj_list.clear();
		adj_list.assign(n,vii());
		for(i=0;i<205;i++)	color[i]=-1;
		sf("%d",&num_edges);
		while(num_edges--){
			sf("%d%d",&i,&j);
			adj_list[i].push_back(ii(j,1));
			adj_list[j].push_back(ii(i,1));
		}
		int m=is_bipartite(adj_list,0);
		printf("%s\n",(m==0)?"NOT BICOLORABLE":"BICOLORABLE" );
	}
}