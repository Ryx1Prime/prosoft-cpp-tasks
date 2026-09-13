#include <iostream>
#include <vector>


class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()){
            return 0;
        }
        
        int left = 0;
        int left_max = 0;
        int right_max = 0;
        int water_trapped = 0;
        int right = static_cast<int> (height.size()) - 1;
        
        while (left < right){
            if (height[left] <= height[right]){
                if (height[left] >= left_max){
                    left_max = height[left];
                }
                else{
                    water_trapped += left_max - height[left];
                }
                left++;

            }else{
                if (height[right] >= right_max){
                    right_max = height[right];
                }
                else{
                    water_trapped += right_max - height[right];
                }
                right--;
            }
        }

        return water_trapped;
    }
};


int main() {
    Solution solver;

    std::vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> test2 = {4, 2, 0, 3, 2, 5};
    std::vector<int> test3 = {1, 2};
    std::vector<int> test4 = {};

    std::cout << "Test 1 (expect 6): " << solver.trap(test1) << "\n";
    std::cout << "Test 2 (expect 9): " << solver.trap(test2) << "\n";
    std::cout << "Test 3 (expect 0): " << solver.trap(test3) << "\n";
    std::cout << "Test 4 (expect 0): " << solver.trap(test4) << "\n";

    return 0;
}