#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color(n, -1); // -1: chưa tô màu, 0: nhóm A, 1: nhóm B

    for(int i = 0; i < n; i++) {
        // Kiểm tra thành phần liên thông chưa tô màu 
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int neighbor : graph[node]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }

        }
    }
    return true;
}    

void bfs(vector<vector<int>> graph, int start) {
	int n = graph.size(); 
    vector<bool> visited(n, false);  
    queue<int> q;  

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; 

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // int G[6][6] = { {0, 1, 0, 0, 0, 1},
    //                 {1, 0, 1, 0, 0, 0},
    //                 {0, 1, 0, 1, 0, 0},
    //                 {0, 0, 1, 0, 1, 0},
    //                 {0, 0, 0, 1, 0, 1},
    //                 {1, 0, 0, 0, 1, 0} };
    // int n = 6;

    // vector<vector<int>> graph(n, vector<int>());
    // 	for (int i = 0; i < n; ++i) {
    // 		for (int j = 0; j < n; ++j) {
    // 			if (G[i][j]) graph[i].push_back(j);
    // 		}
    // 	}

    // isBipartite(graph) ? cout << "Yes" : cout << "No";

    int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				                {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				                {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				                {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				                {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				                {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				                {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				                {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				                {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}   };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
    return 0;
}