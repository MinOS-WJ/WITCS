#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    int count = 0;
    
    for (long long k = 2; k * (k + 1) / 2 <= n; ++k) {
        long long numerator = n - k * (k - 1) / 2;
        
        if (numerator > 0 && numerator % k == 0) {
            long long a = numerator / k;
            count++;
            
            for (long long i = 0; i < k; ++i) {
                if (i > 0) cout << "+";
                cout << (a + i);
            }
            cout << endl;
        }
    }

    return 0;
}