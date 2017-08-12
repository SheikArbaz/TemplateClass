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
int bfs_num[1005];
int dist[1005];
void bfs_complete(int s,vector<vii> adj_list){
			queue<int> q;
			q.push(s);bfs_num[s]=1;dist[s]=0;
			while(!q.empty()){
				int u=q.front();q.pop();
				//printf("visited %d\n",u );
				for (int v = 0; v <adj_list[u].size();++v)
				{
					int x=adj_list[u][v].first;
					if(bfs_num[x]==-1){
						q.push(x);
						bfs_num[x]=1;
						dist[x]=dist[u]+6;
					}
				}
			}
}
int main(int argc, char const *argv[]){
	int q,n,m,i,j;
	sf("%d",&q);
	while(q--){
		sf("%d%d",&n,&m);
		for(i=0;i<1005;i++){	dist[i]=-1;bfs_num[i]=-1;}
		
		adj_list.assign(n,vii());
		while(m--){
			sf("%d%d",&i,&j);
		adj_list[i-1].push_back(ii(j-1,6));
		adj_list[j-1].push_back(ii(i-1,6));
		}
		int s=0;
		sf("%d",&s);
		bfs_complete(s-1,adj_list);
		for(i=0;i<n;i++){
			if(i==s-1)	continue;
			printf("%d",dist[i] );
			if(i!=n)	printf(" ");
		}
		pf("\n");
		adj_list.clear();
	}
}