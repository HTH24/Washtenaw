//
//  main.cpp
//  cps272MP1
//
//  Created by TianHang Hu on 1/21/24.
//

#include <iostream>
#include <string>
#include "minivector.hpp"
using namespace std;

int main()
{   
//    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
//    miniVector<pair<string, int>> voteResult;
    miniVector<tuple<string, int, double>> voteResult;
    voteResult.readFromFile("/Users/tianhanghu/Desktop/WCC/CPS272/cps272MP1/cps272MP1/votes.txt");
    
    voteResult.sort();
    std::cout << "Total elements in miniVector: " << voteResult.size() << std::endl;
    std::cout << "Is miniVector empty? " << (voteResult.empty() ? "Yes" : "No") << std::endl;
        
    for (auto i = 0; i < voteResult.size(); ++i) {
        cout << showpoint << get<0>(voteResult[i]) << " " << get<1>(voteResult[i]) << " " << setprecision(3) << get<2>(voteResult[i]) << endl;
    }
    
    return 0;

}


//    // initializer list
//    vector<int> vector1 = {1, 2, 3, 4, 5};
//
//    // uniform initialization
//    vector<int> vector2{6, 7, 8, 9, 10};
//
//    // method 3
//    vector<int> vector3(5, 12);
//
//    cout << "vector1 = ";
//
//    // ranged loop
//    for (const int& i : vector1) {
//      cout << i << "  ";
//    }
//
//    cout << "\nvector2 = ";
//
//    // ranged loop
//    for (const int& i : vector2) {
//      cout << i << "  ";
//    }
//
//    cout << "\nvector3 = ";
//
//    // ranged loop
//    for (int i : vector3) {
//      cout << i << "  ";
//    }
    
//    vector<int> a;
//    for (int i = 1; i <=10 ; i++) {
//        a.push_back(i);
//    }
//
//    for (auto i = a.begin(); i != a.end(); ++i) {
//        cout << *i << " ";
//    }
//
//    for (auto i = a.cbegin(); i != a.cend(); ++i) {
//        cout << *i << " ";
//    }
//
//    cout << "\nOutput of rbegin and rend Function: ";
//    for (auto ir = a.rbegin(); ir != a.rend(); ++ir) {
//        cout << *ir << " ";
//    }
//
//    cout << "\nOutput of crbegin and crend Function: ";
//    for (auto ir = a.crbegin(); ir != a.crend(); ++ir) {
//        cout << *ir << " ";
//    }
