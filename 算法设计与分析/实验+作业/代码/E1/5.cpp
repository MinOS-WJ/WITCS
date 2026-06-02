#include <iostream>


int n;
int total = 0;
int partition[35];
int depth = 0;

void dfs(int remaining, int max_val) {
    if (remaining == 0) {
        for (int i = 0; i < depth; ++i) {
            if (i > 0) std::cout << " ";
            std::cout << partition[i];
        }
        std::cout << std::endl;
        total++;
        return;
    }

    for (int i = std::min(remaining, max_val); i >= 1; --i) {
        partition[depth] = i;
        depth++;
        
        dfs(remaining - i, i); 
        
        depth--;
    }
}

int main() {
    if (!(std::cin >> n)) return 0;

    dfs(n, n);

    std::cout << "total = " << total << std::endl;

    return 0;
}