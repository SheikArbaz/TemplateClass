#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define sf scanf
#define pf printf
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adj_list;
vi dfs_num;
void dfs(int u){
	dfs_num[u]=1;
	for (int v = 0; v <adj_list[u].size(); ++v){
		int x=adj_list[u][v].first;
		if(dfs_num[x]==-1)
			dfs(x);
	}
	printf("%d ",u);
}
void dfs_complete(){//For each connected component..complete
	int cc=0;
	for (int i = 0; i <adj_list.size(); ++i)
	{
		if(dfs_num[i]==-1){
			printf("%d:- ",++cc);
			dfs(i);pf("\n");
		}
	}
}
int main(int argc, char const *argv[]){
	int n;
	sf("%d",&n);
	adj_list.assign(n,vii());
	int q,i,j,w;
	sf("%d",&q);
	while(q--){
		sf("%d%d",&i,&j);
		adj_list[i].push_back(ii(j,1));
		adj_list[j].push_back(ii(i,1));
	}
	dfs_num.assign(n,-1);//dfs_num will be affected.
	dfs_complete();
	return 0;
}