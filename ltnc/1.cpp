#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    cout << "Hello " << name << "!";
    return 0;
}