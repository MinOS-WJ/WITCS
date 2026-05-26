#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        list<char> text;
        list<char>::iterator cursor = text.begin();

        for (int i = 0; i < (int)line.size(); i++) {
            char ch = line[i];
            if (ch == '<') {
                if (cursor != text.begin())
                    cursor--;
            } else if (ch == '>') {
                if (cursor != text.end())
                    cursor++;
            } else if (ch == '[') {
                cursor = text.begin();
            } else if (ch == ']') {
                cursor = text.end();
            } else {
                text.insert(cursor, ch);
            }
        }

        for (list<char>::iterator it = text.begin(); it != text.end(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}