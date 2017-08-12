#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
vector<int> recorrerA;// = { -2, -1, 1, 2, 2, 1, -1, -2};
vector<int> recorrerB;//[ = {1, 2, 2, 1, -1, -2, -2, -1};
int n,x,y;
int visited[26][26] = {0};
bool validPosition(int a, int b)
{
    return ((a <=n && a > 0) && (b <=n && b > 0)) ? true : false;
}
void change_recur(){
	recorrerA.clear();
	recorrerA.push_back(-y);recorrerA.push_back(-x);recorrerA.push_back(x);recorrerA.push_back(y);
	recorrerA.push_back(y);recorrerA.push_back(x);recorrerA.push_back(-x);recorrerA.push_back(-y);
	recorrerB.clear();
	recorrerB.push_back(x);recorrerB.push_back(y);recorrerB.push_back(y);recorrerB.push_back(x);
	recorrerB.push_back(-x);recorrerB.push_back(-y);recorrerB.push_back(-y);recorrerB.push_back(-x);
}
int bfs(int a1, int a2, int b1, int b2)
{
    queue<pair <int, int> > s;
    pair <int, int> start (a1, a2);
    s.push(start);
    visited[a1][a2] = 1;
    while (s.empty() == false)
    {
        pair <int, int> top = s.front();
        s.pop();
        if (top.first == b1 && top.second == b2)
            return visited[b1][b2];
        for (int i = 0; i < 8; i++)
        {
            int newA = top.first + recorrerA[i], newB = top.second + recorrerB[i];
            if (validPosition(newA, newB))
            {
                if (visited[newA][newB] == 0)
                {
                    visited[newA][newB] = visited[top.first][top.second] + 1;
                    pair <int, int> node (newA, newB);
                    s.push(node);
                }
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    cin>>n;
    int a[n+1][n+1];
    for(i=1;i<n;i++) for(j=1;j<n;j++)	a[i][j]=-1;
	x=i=1;y=j=1;
	memset (visited, 0, sizeof visited);
	change_recur();
	int resp = bfs(1, 1, n, n) - 1;
	a[i][j]=resp;
    for(i=1;i<n;i++){
    	cout<<a[1][i];// already calculated
    	for(j=2;j<n;j++){
    		if(i>j)
    			 cout<<" "<<a[j][i];
    		else{
    			x=i;y=j;
    			memset (visited, 0, sizeof visited);
    			change_recur();
    			int resp = bfs(1, 1, n, n) - 1;
    			a[i][j]=resp;
    			cout <<" "<<resp;
    		 }
    	}cout<<endl;
    }
    return 0;
}