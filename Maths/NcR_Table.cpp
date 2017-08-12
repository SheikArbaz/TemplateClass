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
#define MOD 1000000000
int main(int argc, char const *argv[])
{
	int a[1001][1001],T;
	a[1][0]=1;a[1][1]=1;
	int i,j,k;
	for(i=2;i<=1000;i++){
		a[i][0]=1;
		for(j=1;j<i;j++){
			a[i][j]=(a[i-1][j-1]%MOD+a[i-1][j]%MOD)%MOD;
		}
		a[i][i]=1;
	}
	sf("%d",&T);
	while(T--){
		sf("%d",&k);
		for(i=0;i<=k;i++)
			cout<<a[k][i]<<" ";
		cout<<endl;
	}
	return 0;
}