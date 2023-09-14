#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>  // For std::sort

// Task 1: Identify all unique triplets from an integer array that sum up to zero.
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    
    std::set<std::vector<int>> resultSet;  // Using a set to ensure unique results
    std::sort(nums.begin(), nums.end());
    
    if (nums.size() < 3) return {};  // Replaced continue with a return statement
    
    for(int i = 0; i < nums.size() - 2; ++i) {
        for(int j = i + 1; j < nums.size() - 1; ++j){
            for(int k = j + 1; k < nums.size(); ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    resultSet.insert({nums[i], nums[j], nums[k]});  // Using insert for sets
                }
            }
        }
    }
    
    return std::vector<std::vector<int>>(resultSet.begin(), resultSet.end());  // Convert set to vector
}

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = threeSum(nums);
    
    for (const auto& triplet : result) {
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
