#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define sf scanf
#define pf printf
#define pub push_back
#define puf push_front
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adj_list;
vi bfs_num;
void bfs_complete(){
	int cc=0;
	for(int i=0;i<adj_list.size();++i){
		if(bfs_num[i]==-1){
			pf("%d:-",++cc);
			queue<int> q;
			q.push(i);bfs_num[i]=1;
			while(!q.empty()){
				int u=q.front();q.pop();
				pf("%d ",u);
				for (int v = 0; v <adj_list[u].size();++v)
				{
					int x=adj_list[u][v].first;
					if(bfs_num[x]==-1){
						q.push(x);
						bfs_num[x]=1;
					}
				}
			}
			pf("\n");
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
	bfs_num.assign(n,-1);
	bfs_complete();
	return 0;
}
/*printing adjacency list
for(i=0;i<adj_list.size();i++){
		printf("%d->",i);
		for(j=0;j<adj_list[i].size();j++){
			int x=adj_list[i][j].first;
			printf("%d ",x);
		}pf("\n");
	}
*/