#include <cstdio>
#define sf scanf
#define pf printf
int n,m;
char a[100][100];
int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};
int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || r >= n || c < 0 || c >=m) return 0;
	if (a[r][c] != c1) return 0;
	int ans = 1;
	a[r][c] = c2;
	int p,q;
	for (int d = 0; d < 8; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}
int main(int argc, char const *argv[]){
	sf("%d%d",&n,&m);
	int i,j;
	char b[n+5][m+5];
	for(i=0;i<n;i++)	for(j=0;j<m;j++)	sf(" %c",&b[i][j]);
	int q;
	sf("%d",&q);
	while(q--){
		for(i=0;i<n;i++)	for(j=0;j<m;j++)	a[i][j]=b[i][j];
		sf("%d%d",&i,&j);
		printf("%d\n",floodfill(i-1,j-1,'W','.'));
	}
	return 0;
}