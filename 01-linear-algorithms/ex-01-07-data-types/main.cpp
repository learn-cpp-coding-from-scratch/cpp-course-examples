#include <iostream>
#include <vector>
#include <iomanip>

// Do not use: using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::hex;
using std::dec;

int main() {

    int a = 7, b = 4;
    int mult;

    mult = a + b;

    cout << "mult = " << mult << '\n';

    char ch = 5;
    ch++;
    char c = 'x';
    int code = c;
    int code1 = 'x';
    double check = true;

    cout << "code  = " << code << "= (hex) = " << hex << code << " = (dec) = " << dec << code << '\n';

    cout << "check  = " << check << '\n';

    vector<int> numbers = { 7, 1, 2, 3, 4 };

    numbers[0]++;
    cout << "Size =  " << numbers.size() << '\n';

    for (auto tmp : numbers) {
        cout << tmp << '\n';
    }

    int x = 7;
    if (x > 5)         // if statement example
    {                  // begin block
        int n = 1;     // local variable
        cout << n;     // output statement
        if (n == 1) {

        }
    }                  // end block

    // cout << n;  // This would cause a compile error (n is out of scope)

    return 0;
}
