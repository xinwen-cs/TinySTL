//
// Created by henrywen on 2023/8/2.
//

#ifndef TINYSTL_TEST_H
#define TINYSTL_TEST_H

#include <iostream>
#include <vector>

namespace tinystl::test {

// define green
// define red

// encapsulate single test case
class TestCase {
public:
    TestCase(const char* case_name) : testcase_name(case_name) {}

    virtual void Run() = 0;
public:
    const char* testcase_name;
    int nTestResult;
    double nFailed;
    double nPassed;
};

// Unit Test stored in vector
class UnitTest {
public:
    static UnitTest* GetInstance();

    TestCase* RegisterTestCase(TestCase* testcase);

    void Run();

public:
    TestCase* CurrentTestCase;
    double nPassed;
    double nFailed;

protected:
    std::vector<TestCase*> testcases_;
};

UnitTest* UnitTest::GetInstance() {
    static UnitTest instance;
    return &instance;
}

TestCase* UnitTest::RegisterTestCase(TestCase *testcase) {
    testcases_.push_back(testcase);
    return testcase;
}

void UnitTest::Run() {
    for (auto it : testcases_) {
        TestCase* testcase = it;
        CurrentTestCase = testcase;

        testcase->nTestResult = 1;
        testcase->nFailed = 0;
        testcase->nPassed = 0;


        testcase->Run();

        if (testcase->nFailed == 0) {
            std::cout << "green" << std::endl;
        } else {
            std::cout << "red" << std::endl;
        }

        std::cout << " " << testcase->nPassed << " / " << testcase->nPassed + testcase->nFailed << "Cases passed\n";

        std::cout << "green" << " End TestCase\n";

        if (testcase->nTestResult) {
            ++nPassed;
        } else {
            ++nFailed;
        }

        std::cout << "green" << "==========================================\n";

        std::cout << "Total TestCase : " << nPassed + nFailed << std::endl;
        std::cout << "Total Passed : " << nPassed << std::endl;
        std::cout << "Total Failed : " << nFailed << std::endl;
    }
}

#define TESTCASE_NAME(testcase_name) \
    testcase_name##_TEST

#define TINYSTL_TEST(testcase_name)                             \
class TESTCASE_NAME(testcase_name) : public TestCase {          \
public:                                                         \
    TESTCASE_NAME(testcase_name)(const char* case_name)         \
        :TestCase(case_name) {};                                \
    virtual void Run();                                         \
private:                                                        \
    static TestCase* const testcase_;                           \
};                                                              \
                                                                \
TestCase* const TESTCASE_NAME(testcase_name)                    \
    ::testcase_ = UnitTest::GetInstance()->RegisterTestCase(    \
        new TESTCASE_NAME(testcase_name)(#testcase_name));      \
void TESTCASE_NAME(testcase_name)::Run()

#define TEST(testcase_name) \
    TINYSTL_TEST(testcase_name)

#define RUN_ALL_TESTS() \
    tinystl::test::UnitTest::GetInstance()->Run()

/*****************************************************************************************/

#define EXPECT_TRUE(Condition) do {                                   \
    if (Condition) {                                                  \
        UnitTest::GetInstance->CurrentTestCase->nPassed++;            \
        std::cout << "Except_TRUE succeeded\n";                       \
    } else {                                                          \
        UnitTest::GetIntance()->CurrentTestCase->nTestResult = 0;     \
        UnitTest::GetIntance()->CurrentTestCase->nFailed++;           \
        std::cout << " EXPECT_TRUE failed\n;"                         \
    }                                                                 \
} while(0)


}

#endif //TINYSTL_TEST_H
