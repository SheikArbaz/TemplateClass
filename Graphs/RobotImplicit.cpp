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
int main(int argc, char const *argv[]){
	int n,m,s,i,j;
	char a[105][105],ref[50005];
	while(sf("%d%d%d",&n,&m,&s)){
		for(i=0;i<n;i++)	for(j=0;j<m;j++)	sf(" %c",&a[i][j]);
		sf("%s",ref);
		int face1=-1,face2=-1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				if(a[i][j]=='N' || a[i][j]=='S' ||a[i][j]=='L' ||a[i][j]=='O'){
					if(a[i][j]=='N'){face1=i-1;face2=j;}
					if(a[i][j]=='S'){face1=i+1;face2=j;}
					if(a[i][j]=='L'){face1=i;face2=j+1;}//east
					if(a[i][j]=='N'){face1=i;face2=j-1;}
					break;
				}
			}
	}
	return 0;
}