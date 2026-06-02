#include <iostream>
#include <climits>

const int MAX_AMOUNT = 1000005; 

int coins[] = {1, 2, 5, 10, 50, 100};
const int NUM_COINS = 6;


int min_coins = INT_MAX;

void dfs(int index, int remaining, int count) {
    if (remaining == 0) {
        if (count < min_coins) {
            min_coins = count;
        }
        return;
    }
    
    if (index < 0) return;
    
    if (remaining < 0) return;

    int max_k = remaining / coins[index];
    
    for (int k = max_k; k >= 0; --k) {
        if (count + k >= min_coins) {
             continue; 
        }
        
        dfs(index - 1, remaining - k * coins[index], count + k);
    }
}

int main() {
    double W;
    std::cin >> W;

    int target = (int)(W * 100 + 0.5);



    min_coins = INT_MAX;
    dfs(NUM_COINS - 1, target, 0);

    if (min_coins == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << min_coins << std::endl;
    }

    return 0;
}
