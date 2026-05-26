#include <fstream>
#include <string>
using namespace std;

void count(ifstream& fin, ofstream& fout) {
    string id;
    int num;
    while (fin >> id >> num) {
        int total = 0, price;
        for (int i = 0; i < num; ++i) {
            fin >> price;
            total += price;
        }
        fout << id << " " << total << endl;
    }
}