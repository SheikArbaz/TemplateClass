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
int main(int argc, char const *argv[]){
	vector<vii> adj_list;
	map<string,int> map_string_int;
	vector<string> int_string;
	int n;
	sf("%d",&n);
	adj_list.assign(n,vii());
	vi order;
	int i,j,k;
	char str[60],str1[100];
	for(i=0;i<n;i++){
		sf(" %s",str);
		map_string_int[str]=i;
		int_string.push_back(str);
	}
	int qx,in_deg[n];
	for(i=0;i<n;i++)	in_deg[i]=0;
	sf("%d",&qx);
	while(qx--){
		sf(" %s %s",str,str1);
		i=map_string_int[str],j=map_string_int[str1];
		adj_list[i].push_back(ii(j,1));
		in_deg[j]++;
	}
	//for(i=0;i<n;i++)	pf("%s->%d  ",int_string[i].c_str(),in_deg[i]);	pf("\n");
	queue<int> q;
	for(i=0;i<n;i++)
		if(in_deg[i]==0)	q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		order.push_back(x);
		for(i=0;i<adj_list[x].size();i++){
			int v=adj_list[x][i].first;
			in_deg[v]--;
			if(in_deg[v]==0)	q.push(v);
		}
	}
	for(i=0;i<n;i++){
		printf("%s ",int_string[order[i]].c_str() );
	}pf("\n");
	return 0;
}