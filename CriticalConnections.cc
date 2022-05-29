#include <iostream>
#include <vector>

void print(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++) {
        std::cout << a.at(i) << ' ';
    }
    std::cout << std::endl;
}

std::vector<int> criticalConnections(std::vector<int>& nums, int target) {
    std::vector<int> vect;
    
    
    return vect;
}

int main() {
    std::vector<int> graph1{ 10, 20, 15, 6, 7, 30 };
    std::vector<int> criticalConnections1 = twoSum(graph1, 22);
    print(criticalConnections1);

    return 0;
}



