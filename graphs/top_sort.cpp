#include <iostream>
#include <vector>

//ключевая идея хранить откуда пришли и как бы в обратную сторону идти

void dfs(int x, std::vector<std::vector<int>>& adj_lst, std::vector<bool>& used) {
    used[x] = true;
    for(int i = 0; i < adj_lst[x].size(); ++i) {
        if (!used[adj_lst[x][i]]) {
            dfs(i,adj_lst,used);
        }
    }
    std::cout << x << " "; 
}

int main() {
   
    int n{},m{};
    std::cin >> n >> m;
    
    std::vector<bool> used(n);
    std::vector<std::vector<int>> adj_lst(n,std::vector<int>(m));
    
    for(std::size_t i = 0; i < m; ++i) {
        int x{},y{};
        std::cin >> x >> y;
        adj_lst[y].push_back(x);
    }
    
    for(int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i,adj_lst,used);
        }
    }



    return EXIT_SUCCESS;
}
