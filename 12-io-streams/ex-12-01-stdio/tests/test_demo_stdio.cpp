#include <gtest/gtest.h>
#include "demo_stdio.hpp"

// Test fot the function int writeToFile(const Student &student)
TEST(DemoStdioTest, PrintStudentInfo) {
    Student student{"Alice", 20, 3.8};
    int status = writeToFile(student);
    EXPECT_EQ(status, 0);
}