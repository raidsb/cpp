// std::vector.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-02
// Standard Template Library is commonly called STL. Provide containers and supporting datatypes and iterators.
// Vector: similar to c array but with a lot of functionalities 

/*
1- vector
2- exception
3- string
4- input/output
5- sets
6- map
*/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>

/**********************************************************************
*                              vectors                                *
***********************************************************************/
/*
use vectors instead of array:
1- dynamic-size containers 
2- the memory is managed for you
3- generic container class 
4- part of standard templace lib
*/
int practice_vectors() {
    // definition and initialization way 1
    std::cout << "vector from initializer list: " << std::endl;
    std::vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Can initialize a vector similar to c-array
    
    // definition and initialization way 2 from C-array
    const static size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "vector from C-array: " << std::endl;
    std::vector<int> vi2(ia, ia + size);
    for (int i : vi2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << std::endl;

    // define a vector of specific size
    std::vector<int> vec(20);

    // getting basic information about the vector: size, front, back.
    std::cout << "size: " << vi1.size() << std::endl;   // 10 for 10 elements 
    std::cout << "front: " << vi1.front() << std::endl; // 1 the first element 
    std::cout << "back: " << vi1.back() << std::endl;   // 10 the last element.. I think for a stack, this is the top of the stack.
    vi1.pop_back(); // to pop last element
    std::cout << std::endl;

    //*** iterating *** way 1: using vector iterator begin() and end()
    std::vector<int>::iterator itbegin = vi1.begin();   // iterator is a typedef. it takes the type of what the vector elements type
    std::vector<int>::iterator itend = vi1.end();
    for (auto it = itbegin; it < itend; ++it) {
        std::cout << *it << ' ';
    }

    //*** iterating *** way 2: using pointer incrementing    
    auto itbegin = vi1.begin(); // will automatically take the type of the vi1 vector elements
    auto itend = vi1.end();     // will automatically take the type of the vi1 vector elements
    for (auto it = itbegin; it < itend; ++it) {
        std::cout << *it << ' '; // it is like a pointer
    }        

    //*** iterating *** way 3: using a range for loop
    std::cout << "range-based for loop:" << std::endl;
    for (int i : vi1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << std::endl;
    
    //*** iterating backward *** way 1: using a for loop
    for (vector<my_class>::reverse_iterator i = my_vector.rbegin(); 
        i != my_vector.rend(); ++i ) { 
    } 
  
    //** iterating backward *** way 2: using a while loop
    vector<my_class>::iterator i = my_vector.end();
    while (i != my_vector.begin())
    {
         --i;
         /*do stuff */
    } 
    
    // accessing a particular element
    std::cout << std::endl;
    std::cout << "element at 5: " << vi1[5] << std::endl;   // can access a specific element 
    std::cout << "element at 5: " << vi1.at(5) << std::endl;// can access a specific elmenet another way
    vi1[5] = 10;
    std::cout << "element at 5: " << *vi1.begin() << std::endl; // cout << "The first cow is " << cattle.begin()->get_name() << endl;
    std::cout << "element at 5: " << *prev(vi1.end(), 2) << std::endl; // cout << "Next to last is " << prev(cattle.end(), 2)->get_name() << endl;
    std::cout << "element at 5: " << *(vi1.end() - 1) << std::endl; // cout << "The last cow is " << (cattle.end() - 1)->get_name() << endl;

    // inserting an element at a position
    std::cout << "insert 42 at begin + 5: " << std::endl;
    vi1.insert(vi1.begin() + 5, 42);   // inserting at position 5. also can use a minus to count from back
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1[5]: " << vi1[5] << std::endl;

    // erasing 
    std::cout << "erase at begin + 5: " << std::endl;
    vi1.erase(vi1.begin() + 5);
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1[5]: " << vi1[5] << std::endl;

    // push back like a stack
    std::cout << "push_back 47: " << std::endl;
    vi1.push_back(47);
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1.back() " << vi1.back() << std::endl;
    std::cout << std::endl;
    std::cout << "front: " << vi1.front() << std::endl; // 1 the first element 
    std::cout << "back: " << vi1.back() << std::endl;   // 10 the last element.. I think for a stack, this is the top of the stack.
    vi1.pop_back(); // to pop last element    

    // std::vector of strings
    std::cout << "vector of strings:" << std::endl;
    std::vector<std::string> vs = { "one", "two", "three", "four", "five" };
    for (const std::string& v : vs) {
        std::cout << v << std::endl;
    }

    // copying vectors 
    // method1: using the copy constructor
    // vector<int> vec2(vec1);
    
    // method2: using = 
    // vector<int> vec2 = vec1;
     
    // method3: iterating and push back
    // for (int i = 0; i < vect1.size(); i++)
    //   vect2.push_back(vect1[i]);

    // find element in vector // only for strings
    //std::vector<std::string>::iterator it = std::find(vs.begin(), vs.end(), 20);


    // slicing 
    // create a slice to hold the sub vector
    std::vector<int> intVector;
    int index1 = 0; int index2 = 0; int query = 0;
    std::vector<int> sliceVector = { intVector.begin() + index1 - 1, intVector.begin() + index2 }; // iterator to first item in array (first in slice) and the last.

    // erase it from the vector
    intVector.erase(intVector.begin() + index1 - 1, intVector.begin() + index2);

    // insert front or back
    if (query == 1) {
        intVector.insert(intVector.begin(), sliceVector.begin(), sliceVector.end()); // position, first element to consider in insert, last to consider.
    }
    return 0;

    // getting the sum of all elments in a vector 
    // #include <numeric>
    std::vector<int> v = { 0, 1, 2, 3 };
    int sum_of_elems = std::accumulate(v.begin(), v.end(), 0); // the last argument is the initial value, and also determine the type of the result 0 for int, 0.0f for float..
    /*
    Important Note: The last argument's type is used not just for the initial value, but for the type of the result as well. 
    If you put an int there, it will accumulate ints even if the vector has float. 
    If you are summing floating-point numbers, change 0 to 0.0 or 0.0f (thanks to nneonneo). See also the C++11 solution below
    */

    // get the max of number of numbers
    // #include <algorithm>
    auto max = max_element(v.begin(), v.end()); // or auto it = std::min_element(std::begin(vec), std::end(vec));
    // get the index of it     
    std::cout << "index of smallest element: " << std::distance(begin(v), max);

    // applying a condition to all elements of vector
    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i < 3; }))
    {

    }

    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i != 3; }))
    {

    }

    // get groups of adjacent same values in a vector. useful to avoid iterating all elements in a vector.
    // needs a special library
    /*
    const vector<int> l{ 1, 1, 2, 3, 3, 3, 1, 1 };
    auto x = l | view::group_by(std::equal_to<int>());

    //iterating the view 
    for (auto i = x.begin();i != x.end(); ++i)
        std::cout << *((*i).begin()) << " " << to_vector(*i).size() << std::endl;
    */
    /*
    #include <vector>
    #include <iostream>
    #include <range/v3/all.hpp>

    int main(int argc, char **argv) { 
        const std::vector<int> l{ 1, 1, 2, 3, 3, 3, 1, 1 };
        auto x = l | ranges::view::group_by(std::equal_to<int>());

        for (auto i = x.begin();i != x.end(); ++i) 
            std::cout <<  *((*i).begin()) << " " << ranges::to_vector(*i).size() << std::endl;
    */
    }
