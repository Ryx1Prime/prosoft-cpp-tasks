#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        std::vector<std::pair<int,int>> elements;
        for (auto x: count){
            elements.push_back(x);
        }

        sort(elements.begin(), elements.end(),
        [](const std::pair<int,int>& a, const std::pair<int,int>& b){
            return a.second > b.second;
        });
        std::vector<int> answer;

        for (int i = 0; i < k; i++){
            answer.push_back(elements[i].first);
        }

        return answer;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    std::cout << "Test [1,1,1,2,2,3], k=2 (expect [1,2]): ";
    for (int x : solver.topKFrequent(nums1, 2)) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::vector<int> nums2 = {1};
    std::cout << "Test [1], k=1 (expect [1]): ";
    for (int x : solver.topKFrequent(nums2, 1)) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::vector<int> nums3 = {4, 4, 4, 5, 5, 6, 6, 6, 6};
    std::cout << "Test [4,4,4,5,5,6,6,6,6], k=2 (expect [6,4]): ";
    for (int x : solver.topKFrequent(nums3, 2)) {
        std::cout << x << " ";
    }
    std::cout << "\n";


    return 0;
}