#include <vector>
#include <list>
#include <iterator>
#include <iostream>

#include "easyfind.hpp"

// main used to test functionality of easyfind();
int main (void) {
    std::vector<int> intVector; // {8, 3, 3, 12, 66, -8, 9, 3, 5, 6}
    std::list<int>  intList; // {8, 7, 7, 12, 66, -8, 9, 7, 5, 6}

    intVector.push_back(8);
    intVector.push_back(3);
    intVector.push_back(3);
    intVector.push_back(12);
    intVector.push_back(66);
    intVector.push_back(-8);
    intVector.push_back(9);
    intVector.push_back(3);
    intVector.push_back(5);
    intVector.push_back(6);

    intList.push_back(8);
    intList.push_back(7);
    intList.push_back(7);
    intList.push_back(12);
    intList.push_back(66);
    intList.push_back(-8);
    intList.push_back(9);
    intList.push_back(7);
    intList.push_back(5);
    intList.push_back(6);

    std::cout << "intVector contents: [";
    for (std::vector<int>::const_iterator i = intVector.begin(); i != intVector.end(); ++i)
        std::cout << *i << ' ';
    std::cout << ']' << std::endl << std::endl;

    std::cout << "Using easyfind() to see if 9 is inside intVector (should be a match): \n";
    std::vector<int>::iterator itv = easyfind(intVector, 9);
    std::cout << "Address of intVector[6]: " << &intVector[6] << ", value of intVector[6] = " << intVector[6] << ". Address returned by easyfind(): " << &(*itv) << ", value at address: " << *itv << std::endl;
    std::cout << std::endl;

    try {
        std::cout << "Using easyfind() to see if 7 is inside intVector (should be no match): \n";
        std::vector<int>::iterator it = easyfind(intVector, 7);
        std::cout << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl << std::endl; 
    }


    std::cout << "intList contents: ";
    for (std::list<int>::const_iterator i = intList.begin(); i != intList.end(); ++i)
        std::cout << *i << " -> ";
    std::cout << "NULL" << std::endl;

    std::cout << "Test to show that easyfind() returns the first 7 of the intList: \n";
    std::list<int>::iterator itl = intList.begin();     // setting iterator itl to intList[0].
    itl++;                                              // advancing iterator itl to intList[1] for comparison with easyfind().

    std::cout << "Address of intList[1]: " << &(*itl) << ", value of intList[1] = " << *itl << ". Address returned by easyfind(): " << &(*(easyfind(intList, 7))) << ", value at address: " << *(easyfind(intList, 7)) << std::endl;
   
    return 0;
}
