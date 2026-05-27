#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    
    bool operator == (const Student& rhs) const {
        return this->name == rhs.name;
    }
    
    bool operator < (const Student& rhs) const {
        return this->score > rhs.score;
    }
};

int main() {
    vector<Student> table;
    char op;
    
    while (cin >> op) {
        if (op == 'A') {
            string name;
            int score;
            cin >> name >> score;
            Student target;
            target.name = name;
            vector<Student>::iterator it = find(table.begin(), table.end(), target);
            
            if (it != table.end()) {
                it->score = score;
            } else {
                target.score = score;
                table.push_back(target);
            }
            
        } else if (op == 'R') {
            string name;
            cin >> name;
            
            Student target;
            target.name = name;
            vector<Student>::iterator it = find(table.begin(), table.end(), target);
            
            if (it != table.end()) {
                table.erase(it);
            }
            
        } else if (op == 'P') {
            if (table.empty()) {
                cout << "[空]" << endl;
            } else {
                for (vector<Student>::iterator it = table.begin(); it != table.end(); it++) {
                    cout << it->name << " " << it->score << endl;
                }
            }
            
        } else if (op == 'S') {
            sort(table.begin(), table.end());
        }
    }
    
    return 0;
}
