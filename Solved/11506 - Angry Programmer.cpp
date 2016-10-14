#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int N, M;
int S, T;
int gsize;
vii matrix, adj;
vi dists;

int dfs(int loc, int flow) {
  if (flow == 0) return 0;
  if (loc == T) return flow;
  
  int nextdist = dists[loc] + 1;
  int totflow = 0;
  for (int i = 0; i < adj[loc].size(); i++) {
    int next = adj[loc][i];
    if (dists[next] == nextdist) {
      int mflow = dfs(next, min(flow, matrix[loc][next]));
      
      if (mflow > 0) {
        matrix[loc][next] -= mflow;
        matrix[next][loc] += mflow;
        flow -= mflow;
        totflow += mflow;
        if (flow == 0) break;
      }

    }
  }
  
  return totflow;
}

bool bfs() {
  dists.assign(gsize, -1);
  queue<int> q;
  q.push(S);
  dists[S] = 0;
  
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    
    for (int i = 0; i < adj[top].size(); i++) {
      int next = adj[top][i];
      
      if (dists[next] == -1 && matrix[top][next] > 0) {
        q.push(next);
        dists[next] = dists[top] + 1;
      }
    }
  }
  
  return dists[T] != -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  while (cin >> N >> M, N || M) {
    
    S = 0, gsize = N * 2 - 2, T = gsize - 1;
     
    adj.assign(gsize, vi());
    matrix.assign(gsize, vi(gsize, 0));
    
    for (int i = 0; i < N-2; i++) {
      int n, c;
      cin >> n >> c;
      n = (n-1) * 2 - 1;
      
      matrix[n][n+1] = c;
      
      adj[n].push_back(n+1);
    }
    
    for (int i = 0; i < M; i++) {
      int x, y, c;
      cin >> x >> y >> c;
      int tx = x, ty = y;
      int sx = tx, sy = ty;
      
      if (x == 1) {
        sx = 0;
        tx = 0;
      }
      else if (x == N) {
        sx = T;
        tx = T;
      }
      else {
        sx = (x-1) * 2;
        tx = (x-1) * 2 - 1;
      }
      
      if (y == 1){
        sy = 0;
        ty = 0;
      }
      else if (y == N) {
        sy = T;
        ty = T;
      }
      else {
        sy = (y-1) * 2;
        ty = (y-1) * 2 - 1;
      };
      
      matrix[sx][ty] = c;
      matrix[sy][tx] = c;
      adj[sx].push_back(ty);
      adj[ty].push_back(sx);
      adj[sy].push_back(tx);
      adj[tx].push_back(sy);
    }
    
    int total = 0;
    while (bfs()) {
      total += dfs(S, 1e9);
    }
    
    cout << total << endl;
  }
}
