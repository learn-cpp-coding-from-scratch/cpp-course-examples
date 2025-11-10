// ============================================
// SELECTION STATEMENTS IN C++
// ternary operator example
// ============================================

#include <iostream>
#include <string>

// ============================================
// 7. TERNARY OPERATOR (conditional operator)
// ============================================
void ternaryExample() {
    int a = 10, b = 20;
    
    // Simple ternary
    int max = (a > b) ? a : b;
    std::cout << "Max: " << max << std::endl;
    
    // Nested ternary
    int x = 5;
    std::string result = (x > 0) ? "Positive" : (x < 0) ? "Negative" : "Zero";
    std::cout << "Number is: " << result << std::endl;
}

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    std::cout << "\n=== TERNARY OPERATOR ===" << std::endl;
    ternaryExample();
    
    return 0;
}