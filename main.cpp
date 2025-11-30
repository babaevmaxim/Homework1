#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int executeOperation(int a, int b, string op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b; 
    return 0;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Ошибка: Не удалось открыть input.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        stack<int> numbers;

        while (ss >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (numbers.size() >= 2) {
                    int b = numbers.top();
                    numbers.pop();
                    int a = numbers.top();
                    numbers.pop();
                    int result = executeOperation(a, b, token);
                    numbers.push(result);
                }
            } else {
                try {
                    numbers.push(stoi(token));
                } catch (...) {
                }
            }
        }

        if (!numbers.empty()) {
            outputFile << line << " = " << numbers.top() << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
