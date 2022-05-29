#include <iostream>
#include <vector>

void print(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++) {
        std::cout << a.at(i) << ' ';
    }
    std::cout << std::endl;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> vect;
    
    // find max int in nums
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(nums.at(i) + nums.at(j) == target && i != j) {
                vect.push_back(i);
                vect.push_back(j);
                return vect;
            }                
        }
    }
    return vect;
}

int main() {
    std::vector<int> nums1{ 10, 20, 15, 6, 7, 30 };
    std::vector<int> twoSum1 = twoSum(nums1, 22);
    print(twoSum1);

    std::vector<int> nums2{ 4, 5, 99, 3, 50, 7 };
    std::vector<int> twoSum2 = twoSum(nums2, 11);
    print(twoSum2);

    std::vector<int> nums3{ 3, 4, 5, 33, 2, 33 };
    std::vector<int> twoSum3 = twoSum(nums3, 66);
    print(twoSum3);

    return 0;
}



