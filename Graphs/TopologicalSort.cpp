#include <cstdio>
#include <vector>
using namespace std;
#define sf scanf
#define pf printf
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adj_list;
vi dfs_num;
vi srt;
void dfs(int u){
	dfs_num[u]=1;
	for (int v = 0; v <adj_list[u].size(); ++v){
		int x=adj_list[u][v].first;
		if(dfs_num[x]==-1)
			dfs(x);
	}
	srt.push_back(u);
}
int main(int argc, char const *argv[]){
	int n;
	sf("%d",&n);
	adj_list.assign(n,vii());
	dfs_num.assign(n,-1);
	int q,i,j,w;
	sf("%d",&q);
	while(q--){
		sf("%d%d",&i,&j);
		adj_list[i].push_back(ii(j,1));
	}
	for(i=0;i<n;i++)
		if(dfs_num[i]==-1)
			dfs(i);
	for(i=n-1;i>=0;i--)
		printf("%d ",srt[i] );
	pf("\n");
	return 0;
}