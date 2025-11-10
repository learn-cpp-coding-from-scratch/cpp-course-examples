// ...existing code...
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    using std::cout;
    using std::endl;

    int a = 7;
    int b = 3;

    cout << "Integer operands (a = " << a << ", b = " << b << ")\n";
    cout << "a + b = " << (a + b) << '\n';
    cout << "a - b = " << (a - b) << '\n';
    cout << "a * b = " << (a * b) << '\n';
    cout << "a / b (integer division) = " << (a / b) << '\n';
    cout << "a % b (remainder) = " << (a % b) << '\n';

    double x = 7.0;
    double y = 3.0;

    cout << "\nFloating-point operands (x = " << x << ", y = " << y << ")\n";
    cout << std::fixed << std::setprecision(6);
    cout << "x / y = " << (x / y) << '\n';
    cout << "fmod(x, y) = " << std::fmod(x, y) << '\n'; // remainder for floats

    cout << "\nMixed-type behavior and casting\n";
    cout << "a / (double)b = " << (a / (double)b) << '\n';
    cout << "static_cast<double>(a) / b = " << (static_cast<double>(a) / b) << '\n';

    cout << "\nCompound assignments and increments\n";
    int c = a; // copy
    c += b; cout << "c += b -> " << c << '\n';
    c = a;
    c *= b; cout << "c *= b -> " << c << '\n';

    int d = 5;
    cout << "d initial = " << d << '\n';
    cout << "postfix d++ returns " << d++ << ", now d = " << d << '\n';
    d = 5;
    cout << "prefix ++d returns " << ++d << ", now d = " << d << '\n';

    cout << "\nOperator precedence and parentheses\n";
    int r1 = a + b * 2;           // multiplication first
    int r2 = (a + b) * 2;         // parentheses change order
    cout << "a + b * 2 = " << r1 << '\n';
    cout << "(a + b) * 2 = " << r2 << '\n';

    cout << "\nUnary + and -\n";
    cout << " -a = " << -a << ", +a = " << +a << '\n';

    cout << "\nDivision edge cases\n";
    int small = 1;
    int large = 2;
    cout << "small / large (ints) = " << (small / large) << "  (truncation)\n";
    cout << "static_cast<double>(small) / large = " << (static_cast<double>(small) / large) << '\n';

    cout << "\nDemonstration done.\n";
    return 0;
}
