#include <iostream>
#include <cmath>

int main() {
    int value = 0;
    std::cin.sync_with_stdio(false);
    int result = 0;
    while (std::cin >> value) {
        int r = value, r_ = 0;
        while ((r = floor(r/3)-2) > 0) {
            r_ += r;
        }
        result += r_;
    }
    std::cout << result << '\n';
    return 0;
}
