#include "main.h"
#include "gtest/gtest.h"

using namespace std;

// 測試 "plus" 功能
TEST(ModuleATest, TestPlus) {
    vector nums = {1, 2, 3, 4};
    EXPECT_EQ(module_A(nums, "plus"), 10);  // 測試總和是否為 10
}

// 測試 "sort" 功能
TEST(ModuleATest, TestSort) {
    vector nums = {4, 2, 1, 3};
    module_A(nums, "sort");
    const vector expected = {1, 2, 3, 4};  // 預期結果
    EXPECT_EQ(nums, expected);  // 測試排序後的數列是否正確
}

// 測試不合法的 config
TEST(ModuleATest, TestInvalidConfig) {
    vector nums = {1, 2, 3};
    EXPECT_THROW(module_A(nums, "unknown"), std::invalid_argument);  // 測試是否丟出錯誤
}

// 測試空數列
TEST(ModuleATest, TestEmptyList) {
    vector<int> nums = {};
    EXPECT_EQ(module_A(nums, "plus"), 0);  // 測試空數列的總和應為 0
    module_A(nums, "sort");
    EXPECT_TRUE(nums.empty());  // 測試空數列排序後仍為空
}