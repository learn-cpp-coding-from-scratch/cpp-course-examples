// ============================================
// SELECTION STATEMENTS IN C++
// if-else statement example
// ============================================

#include <iostream>
#include <string>

// ============================================
// 1. IF STATEMENT
// ============================================
void ifExample() {
    int age = 18;
    
    if (age >= 18) {
        std::cout << "You are an adult" << std::endl;
    }
}

// ============================================
// 2. IF-ELSE STATEMENT
// ============================================
void ifElseExample() {
    int score = 75;
    
    if (score >= 60) {
        std::cout << "Passed!" << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
    }
}

// ============================================
// 3. IF-ELSE IF-ELSE LADDER
// ============================================
void ifElseIfExample() {
    int grade = 85;
    
    if (grade >= 90) {
        std::cout << "Grade: A" << std::endl;
    } else if (grade >= 80) {
        std::cout << "Grade: B" << std::endl;
    } else if (grade >= 70) {
        std::cout << "Grade: C" << std::endl;
    } else if (grade >= 60) {
        std::cout << "Grade: D" << std::endl;
    } else {
        std::cout << "Grade: F" << std::endl;
    }
}

// ============================================
// 4. NESTED IF STATEMENTS
// ============================================
void nestedIfExample() {
    int age = 25;
    bool hasLicense = true;
    
    if (age >= 18) {
        if (hasLicense) {
            std::cout << "You can drive" << std::endl;
        } else {
            std::cout << "You need a license" << std::endl;
        }
    } else {
        std::cout << "You are too young to drive" << std::endl;
    }
}

// ============================================
// 5. LOGICAL OPERATORS IN CONDITIONS
// ============================================
void logicalOperatorsExample() {
    int age = 25;
    bool isStudent = false;
    
    // AND operator
    if (age >= 18 && age <= 65) {
        std::cout << "Working age" << std::endl;
    }
    
    // OR operator
    if (age < 18 || isStudent) {
        std::cout << "Discount available" << std::endl;
    } else {
        std::cout << "No discount" << std::endl;
    }
    
    // NOT operator
    if (!isStudent) {
        std::cout << "Regular price" << std::endl;
    }
}

// ============================================
// 6. COMPLEX CONDITION EXAMPLE
// ============================================
void complexConditionExample() {
    int temperature = 25;
    bool isRaining = false;
    bool isWeekend = true;
    
    if ((temperature > 20 && temperature < 30) && !isRaining && isWeekend) {
        std::cout << "Perfect day for a picnic!" << std::endl;
    } else if (isRaining) {
        std::cout << "Stay indoors, it's raining" << std::endl;
    } else if (temperature <= 20) {
        std::cout << "Too cold for outdoor activities" << std::endl;
    } else {
        std::cout << "Maybe another day" << std::endl;
    }
}

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    std::cout << "\n=== IF STATEMENT ===" << std::endl;
    ifExample();
    
    std::cout << "\n=== IF-ELSE STATEMENT ===" << std::endl;
    ifElseExample();
    
    std::cout << "\n=== IF-ELSE IF LADDER ===" << std::endl;
    ifElseIfExample();
    
    std::cout << "\n=== NESTED IF ===" << std::endl;
    nestedIfExample();

    std::cout << "\n=== LOGICAL OPERATORS ===" << std::endl;
    logicalOperatorsExample();
    
    std::cout << "\n=== COMPLEX CONDITIONS ===" << std::endl;
    complexConditionExample();
    
    return 0;
}