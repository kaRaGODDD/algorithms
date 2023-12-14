#include <iostream>
#include <fstream>
#include <vector>

static int cost = 0;

#define FILE

void dfs(int vertex, std::vector<std::vector<int>> &matrix, std::vector<bool> &used, std::vector<int> &cost_vector, int n){
	++cost;
	cost_vector[vertex] = cost;
	used[vertex] = true;
	for(int i = 0; i < n; i++) {
		if(matrix[vertex][i] && !used[i]){
             dfs(i,matrix,used, cost_vector, n);
        }
    }
    
}

int main(){

#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj_mtx(n, std::vector<int>(n, 0));
    std::vector<int> cost(n, 0);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> adj_mtx[i][j];
        }
    }

    std::vector<bool> used(n, false);
	
    for (int i = 0; i < n; i++)
      	if (used[i] == false)
       		dfs(i, adj_mtx, used, cost,n);

    for(const auto& x : cost) {
        std::cout << x << " ";
    }

}
