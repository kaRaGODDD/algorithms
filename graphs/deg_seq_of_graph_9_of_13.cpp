#include <iostream>
#include <vector>
#include <algorithm>

#define FILE

//passing 9 of 13 tests MLE exclude the containing of matrix 

int main() {
#undef FILE 
#ifdef FILE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n{},m{};
    std::cin >> n >> m;

    std::vector<int> adj(n,0);

    for(int i = 0; i < m; ++i) {
        int x,y;
        std::cin >> x >> y;
        --x;
        --y;
        adj[x]++;
        adj[y]++;
    }
    

    for(int i = 0; i < adj.size(); ++i) {
        std::cout << adj[i] << " ";
    }

    return EXIT_SUCCESS;
}
