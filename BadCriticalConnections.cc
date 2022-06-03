#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <iterator>
void printConnections(std::vector <std::vector<int>> const &a) {
    std::cout << "The connections are : " << std::endl;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.at(i).size(); j++) {
            std::cout << a.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void printNodes(std::vector <int> const &a) {
    std::cout << "The nodes are : ";

    for(int i=0; i < a.size(); i++) {
        std::cout << a.at(i) << ' ';
    }
    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////

std::vector<int> getNeighbors(std::vector<std::vector<int>>& connections, int node) {
    std::vector<int> result;
    for(int i = 0; i < connections.size(); i++) {
        std::vector<int> connection = connections.at(i);
        if(connection.at(0) == node) {
            result.push_back(connection.at(1));
        }
        if(connection.at(1) == node) {
            result.push_back(connection.at(0));
        }
    }
    return result;
}

bool canReachIndirectly(std::vector<std::vector<int>> connections, std::vector<int> connection) {
    connections.erase(find(connections.begin(), connections.end(), connection)); // remove the connection

    int startNode = connection.at(0);
    int endNode = connection.at(1);
   
    std::vector<int> exploredSet;
    std::vector<int> fringeSet = {startNode};

    while(!fringeSet.empty()) {
        for (int i = 0; i < fringeSet.size(); i++) {
            int node = fringeSet.at(i);

            // find all neighbors of each node in the fringe set
            std::vector<int> neighbors = getNeighbors(connections, node); 

            for(int j = 0; j < neighbors.size(); j++) {
                int neighbor = neighbors.at(j);

                if(node == endNode) {
                    // stop if we've reached the endNode
                    return true;
                }
                else if(std::find(exploredSet.begin(), exploredSet.end(), neighbor) == exploredSet.end() 
                && std::find(fringeSet.begin(), fringeSet.end(), neighbor) == fringeSet.end()) { 
                    fringeSet.push_back(neighbor); // add neighbor to fringe set if it is not already included
                }
            }
            exploredSet.push_back(node); // add node to explored set
            fringeSet.erase(find(fringeSet.begin(), fringeSet.end(), node)); // remove node from fringe set
        }
    }
    return false;
}

std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
    std::vector<std::vector<int>> result;
    for(int i = 0; i < connections.size(); i++) {
        std::vector<int> connection = connections.at(i);
        if(!canReachIndirectly(connections, connection)) {
            result.push_back(connection);
            }
        }
    return result;
}

int main() {
    std::vector<std::vector<int>> test1 = {{0,1},{1,2},{2,0},{1,3}};
    std::vector<std::vector<int>> criticalConnections1 = criticalConnections(69, test1);
    printConnections(criticalConnections1);

    std::vector<std::vector<int>> test2 = {{0,1},{1,2},{2,3},{3,0},{1,4}};
    std::vector<std::vector<int>> criticalConnections2 = criticalConnections(69, test2);
    printConnections(criticalConnections2);

    std::vector<std::vector<int>> test3 = {{0,1},{2,3},{3,0},{1,4}};
    std::vector<std::vector<int>> criticalConnections3 = criticalConnections(69, test3);
    printConnections(criticalConnections3);

    return 0;
}



