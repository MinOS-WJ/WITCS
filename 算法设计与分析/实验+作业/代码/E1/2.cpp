#include <iostream>
#include <iomanip>

int main() {
    int m, n;
    if (!(std::cin >> m >> n)) return 0;

    int matrix[100][100];

    int currentNum = 1;
    int totalLayers = m + n - 1;

    for (int layer = 0; layer < totalLayers; layer++) {

        if (layer % 2 != 0) {
            for (int i = 0; i < m; i++) {
                int j = layer - i;
                if (j >= 0 && j < n) {
                    matrix[i][j] = currentNum++;
                }
            }
        }
        else {
            for (int i = m - 1; i >= 0; i--) {
                int j = layer - i;
                if (j >= 0 && j < n) {
                    matrix[i][j] = currentNum++;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
