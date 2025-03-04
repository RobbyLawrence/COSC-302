#include <iostream>
using namespace std;

void print_values() {
    for (int j = 0;j<5;j++) {
        cout << j << endl;
    }
}
int main() {
    for (int i = 0;i<10;i++) {
        print_values();
    }
    return 0;
}
