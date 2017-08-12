#include <bits/stdc++.h>
#define sz 112345
using namespace std;
int n, m;
int incoming_edge_count[sz];
bool visited[sz];
vector<int> graph[sz], reverse_graph[sz];
vector<int> to_install;
vector<int> sorted_order;
set<int> S_all_to_install;

void init() {
  memset(visited, 0, sizeof visited);
  memset(incoming_edge_count, 0, sizeof incoming_edge_count);
  S_all_to_install.clear();
  sorted_order.clear();
  to_install.clear();
  for(int i=0;i<sz;i++) {
    graph[i].clear();
    reverse_graph[i].clear();
  }
}

void topo_sort() {
  set<int> S;
  for(int i=1;i<=n;i++) {
    if(incoming_edge_count[i] == 0) S.insert(i);
  }
  while(!S.empty()) {
    int node = *S.begin();
    sorted_order.push_back(node);
    S.erase(node);
    for(int i=0;i<reverse_graph[node].size();i++) {
      incoming_edge_count[reverse_graph[node][i]]--;
      if(incoming_edge_count[reverse_graph[node][i]] == 0) {
        S.insert(reverse_graph[node][i]);
      }
    }
  }
}

void find_all_dependencies(int node) {
  if(visited[node]) return;
  S_all_to_install.insert(node);
  visited[node] = true;
  for(int i=0;i<graph[node].size();i++) {
    find_all_dependencies(graph[node][i]);
  }
}

void find_all_programs_to_install() {
  for(int i=0;i<to_install.size();i++) {
    find_all_dependencies(to_install[i]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    init();
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) {
      int parents;
      scanf("%d", &parents);
      for(int j=0;j<parents;j++) {
        int parent_node;
        scanf("%d", &parent_node);
        graph[i].push_back(parent_node);
        reverse_graph[parent_node].push_back(i);
        incoming_edge_count[i] += 1;
      }
    }
    for(int i=0;i<m;i++) {
      int program;
      scanf("%d", &program);
      to_install.push_back(program);
    }
    find_all_programs_to_install();
    topo_sort();
    vector<int> ans;
    for(int i=0;i<sorted_order.size();i++) {
      if(S_all_to_install.find(sorted_order[i]) != S_all_to_install.end()) {
        ans.push_back(sorted_order[i]);
      }
    }
    printf("%lu\n", ans.size());
    for(int i=0;i<ans.size();i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}
