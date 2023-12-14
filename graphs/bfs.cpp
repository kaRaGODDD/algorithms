#include <iostream>
#include <vector>
#include <queue>

#define FILE

void bfs(int vertex, std::vector<bool>& visited,std::vector<int>& cost_vector,const std::vector<std::vector<int>>& adj_mtx,int& cost) {
    std::queue<int> q;
    q.push(vertex);
    while(!q.empty()) {
       auto get_vertex = q.front();
       q.pop();
       if (!visited[get_vertex]) {
          cost_vector[get_vertex] = cost;
          cost++;
          visited[get_vertex] = true;
       }
       for(int i = 0; i < adj_mtx.size(); ++i) {
            if (adj_mtx[get_vertex][i] && !visited[i]) {
                q.push(i);
            }
       }
    }

}


int main() {
  
#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n{};
    std::cin >> n;
    std::vector<std::vector<int>> adj_mtx(n,std::vector<int>(n));
    std::vector<bool> visited(n);
    std::vector<int> cost_vector(n);
    int cost = 1;

    for(auto&& x : adj_mtx) {
        for(auto&& y : x) {
            std::cin >> y;
        }
    }

    for(int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(i,visited,cost_vector,adj_mtx,cost);
        }
    }

    for(const auto& x : cost_vector) {
        std::cout << x << ' ';
    }

    return EXIT_SUCCESS;
}
