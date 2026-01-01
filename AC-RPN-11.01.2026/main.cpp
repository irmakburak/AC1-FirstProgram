#include <iostream>
#include <sstream>
#include <string>
#include "StackArr.h"

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::stringstream ss(text);
    Stack<int, 100> stack;

    while (true) {
        std::string token;
        ss >> token;

        if (token.empty()) break;

        if (token != "+" && token != "-" && token != "*") {
            int value = std::stoi(token);
            stack.push(value);
        }
        else {
            int b = stack.pop();
            int a = stack.pop();

            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;

            stack.push(result);
        }
    }

    std::cout << stack.pop() << std::endl;
    return 0;
}
