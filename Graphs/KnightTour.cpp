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

vector<int> recorrerA[8];//= { -2, -1, 1, 2, 2, 1, -1, -2};
vector<int> recorrerB[8]; //= {1, 2, 2, 1, -1, -2, -2, -1};
int visited[26][26] = {0};
int n,x,y;
void change_recur(){
    recorrerA.push_back(-x);recorrerA.push_back(-(x-1));recorrerA.push_back(x-1);recorrerA.push_back(x);recorrerA.push_back(x);
    recorrerA.push_back(x-1);recorrerA.push_back(-(x-1));recorrerA.push_back(-x);
   
    recorrerB.push_back(y-1);recorrerB.push_back(y);recorrerB.push_back(y);recorrerB.push_back(y-1);recorrerB.push_back(-(y-1));
    recorrerB.push_back(-y);recorrerB.push_back(-y);recorrerB.push_back(-(y-1));
}
bool validPosition(int a, int b)
{
    return ((a < n+1 && a > 0) && (b < n+1 && b > 0)) ? true : false;
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
}
int main()
{
    int a1, a2, b1, b2;
    cin>>n;
    cin>>x>>y;
    change_recur();
    while (cin >>a1>>a2>>b1>>b2)
    {
        a1++;a2++;b1++;b2++;
        memset (visited, 0, sizeof visited);
        int resp = bfs(a1, a2, b1, b2) - 1;
        resp = (resp == -1) ? -1 : resp;
        cout << "To get from " << a1<<" "<<a2 << " to " << b1<<" "<<b2  << " takes " << resp << " knight moves." << endl;
    }
    return 0;
}
/*
while (cin >>a1>>a2>>b1>>b2)
    {
    	++a1;++a2;++b1;++b2;
    	cin>>x>>y;
    	change_recur();
        memset (visited, 0, sizeof visited);

        // a2 = m.find(node1[0]) + 1;
        // b2 = m.find(node2[0]) + 1;
        // a1 = atoi(&node1[1]);
        // b1 = atoi(&node2[1]);
        int resp = bfs(a1, a2, b1, b2) - 1;
        //resp = (resp == -1) ? 0 : resp;
        cout <<  resp << " knight moves." << endl;
    }
*/