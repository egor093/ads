#include <iostream>
#include <stack>

using namespace std;

bool checkBrackets(string s)
{
    stack<char> stk;
    for (char symbol : s) {
        switch (symbol) {
        case '(':
        case '[':
        case '{':
            stk.push(symbol);
            break;
        case ')':
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
            break;
        case ']':
            if (stk.empty() || stk.top() != '[') {
                return false;
            }
            stk.pop();
            break;
        case '}':
            if (stk.empty() || stk.top() != '{') {
                return false;
            }
            stk.pop();
            break;
        default:
            break;
        }
    }
    return stk.empty();
}

bool checkCharacters(string s)
{
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}') {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    string s;
    cout << "Введите строку: ";
    cin >> s;
    if (checkCharacters(s)) {
        if (checkBrackets(s)) {
            cout << "Ковычки ";
        }
        else {
            cout << "Brackets are placed incorrectly";
        }
    }
    else {
        cout << "No brackets found in the string";
    }
    return 0;
}