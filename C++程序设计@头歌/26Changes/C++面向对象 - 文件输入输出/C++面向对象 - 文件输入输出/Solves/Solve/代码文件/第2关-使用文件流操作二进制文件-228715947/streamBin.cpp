#include <fstream>
#include <cstring>
using namespace std;


struct clothing {
    char label[12];
    int  numberRemaining;
};

int getNumber(ifstream& ifile, char* label) {
    clothing t;
    while (ifile.read((char*)&t, sizeof(t))) {
        if (strcmp(t.label, label) == 0) {
            return t.numberRemaining;
        }
    }
    return 0;
}