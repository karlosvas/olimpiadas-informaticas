#include <iostream>
#include <stack>
using namespace std;

int main() {
    string text;

    while (getline(cin, text)) {
        stack<char> parStack;

        bool balanced = true;

        for (char c : text) {
            if (c == '(' || c == '[' || c == '{') {
                parStack.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (parStack.empty()) {
                    balanced = false;
                    break;
                } else {
                    char top = parStack.top();
                    parStack.pop();
                    if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                        balanced = false;
                        break;
                    }
                }
            }
        }

        if (!parStack.empty()) {
            balanced = false;
        }

        if (balanced) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

