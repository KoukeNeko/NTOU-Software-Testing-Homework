#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<string> config_type = {"plus", "sort"};

int module_A(vector<int>& nums, const string& config) {
    if (ranges::find(config_type, config) == config_type.end()) {
        throw invalid_argument("ErrorConfig");
    }
    if (config == "plus") {
        int ans = 0;
        for (const int num : nums) {
            ans += num;
        }
        return ans;
    }
    if (config == "sort") {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return 0;
    }
    return 0;
}