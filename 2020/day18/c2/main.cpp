#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

using Stack = std::stack<char>;
using StackI = std::stack<size_t>;
using Set = std::set<char>;

uint8_t prec(const char c) {
    uint8_t r;
    switch (c) {
    case '+':
    case '-':
        r = 1;
        break;
    case '*':
    case '/':
        r = 0;
        break;
    }
    return r;
}


std::string yard(const std::string& input) {
    std::string r;
    Set op = {'+', '-', '/', '*'};
    Stack s;
    for (const auto& c: input) {
        std::string cc;
        cc = c;
        if (c == ' ') continue;
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                r += s.top();
                r += " ";
                s.pop();
            }
            s.pop();
        } else if (op.find(c) == op.end()) {
            r += c;
            r += " ";
        } else if (op.find(c) != op.end()){
            while (!s.empty()
                   && prec(c) <= prec(s.top())
                   && s.top() != '(') {
                r += s.top();
                r += " ";
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        if (s.top() != ')' && s.top() != '(') {
            r += s.top(); r += ' ';
        }
        s.pop();
    }
    return r;
}

size_t eval(const std::string& input) {
    Set op = {'+', '-', '/', '*'};
    StackI s;
    for (const auto& c: input) {
        if (c == ' ') continue;
        std::string cc;
        cc = c;
        if (op.find(c) == op.end()) {
            s.push(c - '0');
        } else {
            size_t v1 = s.top(); s.pop();
            size_t v2 = s.top(); s.pop();
            if (c == '*') {
                s.push(v1 * v2);
            } else if (c == '/') {
                s.push(v1 / v2);
            } else if (c == '+') {
                s.push(v1 + v2);
            } else if (c == '-') {
                s.push(v1 - v2);
            }
        }
    }
    return s.top();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::string expr;
    size_t result = 0;
    while (std::getline(std::cin, expr)) {
        size_t v = eval(yard(expr));
        result += v;
    }
    std::cout << result << '\n';
    return 0;
}
