#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int V, const vector<vector<int>>& graph, vector<int>& visited);
void bfs(int V, const vector<vector<int>>& graph, vector<int>& visited);

int N, M, V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d %d", &N, &M, &V);

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    int a, b;
    for(int i = 0; i < M; i++) {  
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }

    vector<int> visitedDFS(N + 1, 0);
    vector<int> visitedBFS(N + 1, 0); 

    dfs(V, graph, visitedDFS);
    printf("\n");
    bfs(V, graph, visitedBFS);
    printf("\n");

    return 0;
}

void dfs(int V, const vector<vector<int>>& graph, vector<int>& visited) {
    visited[V] = 1;
    printf("%d ", V);
    for(int i = 1; i <= N; i++) {
        if(graph[V][i] == 1 && !visited[i]) {
            dfs(i, graph, visited);
        }
    }
}

void bfs(int V, const vector<vector<int>>& graph, vector<int>& visited) {
    queue<int> q;
    q.push(V);
    visited[V] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i = 1; i <= N; i++){
            if(graph[x][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}