#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#define sf scanf
#define pf printf
#define pub push_back
#define po  pop
#define pob pop_back
#define puf push_front
#define mp make_pair
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef map<int,int> mpii;
typedef set<int> si;
typedef multiset<int> msi;
typedef long int i32;
typedef unsigned long int ui32;
typedef long long int i64;
typedef unsigned long long int  ui64;
vector<string> split(const string& s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    return elems;
}
//Arbaz's template ends here
const int INF = 2147483647;
const int MAX = 5005;
int D[MAX],P[MAX],N; // Keeps minimum distance to each node
vector<pair<int,int>> E[MAX]; // Adjacency list
void dijkstra()
{
    for(int i = 1; i <= N; i++){ D[i] = INF;P[i]=i;}
    D[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});

    while(!q.empty())
    {
        pair<int,int> p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr : E[u])
        {
            int v = pr.first;
            int next_dist = dist + pr.second;

            if(next_dist < D[v])
            {
                D[v] = next_dist;
                P[v]=u;
                q.push({next_dist,v});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
	int q,i=1,j,w;
	sf("%d%d",&N,&q);
	while(q--){
		sf("%d%d%d",&i,&j,&w);
		E[i].push_back(ii(j,w));
		E[j].push_back(ii(i,w));
	}
	dijkstra();
	pf("%d",(D[2]!=INF)?D[2]:-1);
	for(int i = 3; i <= N; i++){
		pf(" %d",(D[i]!=INF)?D[i]:-1);
	}pf("\n");
	pf("%d",(P[2]!=2)?P[2]:-1);
	for(int i = 3; i <= N; i++){
		pf(" %d",(P[i]!=i)?D[i]:-1);
	}pf("\n");
	return 0;
}