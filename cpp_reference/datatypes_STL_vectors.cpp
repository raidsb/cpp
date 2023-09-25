/*
Vector
Defined in header <vector>

Explaining: the template declaration 
------------------------------------
template<
    class T,
    class Allocator = std::allocator<T>
> class vector;

The code snippet you provided is a partial declaration of a C++ template class named vector. 
This code declares a template class vector that can be parameterized with two template parameters: T and Allocator. 

Here's a breakdown of what this code represents:
template: This keyword indicates the beginning of a template declaration, indicating that you're declaring a template class.
<class T, class Allocator = std::allocator<T>>: This part specifies the template parameters for the vector template class:
    T: This is a type parameter and represents the type of elements that the vector will hold. 
    Users of the vector class can specify the element type when they instantiate an object of this class.

    Allocator: This is another type parameter and represents the allocator type to be used for memory management. 
    The default value for Allocator is std::allocator<T>, which is a standard allocator provided by the C++ Standard Library. 
    Users can also specify a custom allocator type when instantiating a vector object.

    class vector;: This part closes the template declaration and defines the template class vector. 
    The actual implementation of the vector class would follow this declaration, including its member functions and data members.

The C++ Standard Library includes a container class named std::vector that is similar to what's being declared here. However, the standard library std::vector is fully defined and implemented, while this code snippet represents a template declaration, and the actual implementation details are not provided here.

vector is a sequence container that encapsulates dynamic size arrays
namespace pmr {
    template< class T >
    using vector = std::vector<T, std::pmr::polymorphic_allocator<T>>;
}

pmr::vector is an alias template that uses a polymorphic allocator.

How elements are stored in vector?
----------------------------------
The elements are stored contiguously, which means that elements can be accessed not only through iterators, but also using offsets to 
regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer 
to an element of an array.

How the storage is handled for the vector?
------------------------------------------
The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, 
because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted,
but only when the additional memory is exhausted.

How the total amount of the allocated memory can be queried? 
------------------------------------------------------------
1. The total amount of allocated memory can be queried using capacity() function.
2. Extra memory can be returned to the system via a call to shrink_to_fit()[1].
3. Reallocations are usually costly operations in terms of performance. The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.


The complexity (efficiency) of common operations on vectors is as follows:
--------------------------------------------------------------------------
1. Random access - constant 𝓞(1).
2. Insertion or removal of elements at the end - amortized constant 𝓞(1).
3. Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).


Notes 
-----
1. std::vector (for T other than bool) meets the requirements of Container, AllocatorAwareContainer (since C++11), SequenceContainer, ContiguousContainer (since C++17) and ReversibleContainer.
2. Member functions of std::vector are constexpr: it is possible to create and use std::vector objects in the evaluation of a constant expression.
However, std::vector objects generally cannot be constexpr, because any dynamically allocated storage must be released in the same evaluation of constant expression.



Template parameters
-------------------
T - The type of the elements.
1. T must meet the requirements of CopyAssignable and CopyConstructible. (until C++11)
2. The requirements that are imposed on the elements depend on the actual operations performed on the container. 
Generally, it is required that element type is a complete type and meets the requirements of Erasable, but many 
member functions impose stricter requirements. (since C++11) (until C++17)
3. The requirements that are imposed on the elements depend on the actual operations performed on the container. 
Generally, it is required that element type meets the requirements of Erasable, but many member functions impose stricter requirements. 
This container (but not its members) can be instantiated with an incomplete element type if the allocator satisfies the allocator completeness requirements. (since C++17)
Feature-test macro Value Std Feature 
------------ ----- ----- --- -------
__cpp_lib_incomplete_container_elements 201505L (C++17) Minimal incomplete type support 

Allocator - An allocator that is used to acquire/release memory and to construct/destroy the elements in that memory. 
The type must meet the requirements of Allocator. The behavior is undefined (until C++20)The program is ill-formed (since C++20) if Allocator::value_type is not the same as T.

Specializations
The standard library provides a specialization of std::vector for the type bool, which may be optimized for space efficiency.

vector<bool>
space-efficient dynamic bitset
(class template specialization)


Iterator invalidation. what does it mean?
-----------------------------------------
Iterator invalidation refers to a situation in computer programming, particularly in languages like C++ and Java, where an iterator that points to an element within a data structure 
(e.g., an array, vector, list, or container) becomes invalid and can no longer be used safely to access or manipulate the underlying data. 
Iterator invalidation can occur for various reasons, and understanding it is crucial for writing reliable and bug-free code when working with data structures and iterators. 
Here are some common causes of iterator invalidation:
1. Element Removal: When an element is removed from a container, iterators that point to that element or any subsequent elements may become invalidated. 
This is because removing an element can change the memory layout of the container.

2. Container Resizing: Some container types, like C++ vectors, automatically resize themselves when they reach their capacity. 
When this happens, all iterators referring to elements in the container may become invalid because the underlying memory location has changed.

3. Insertion and Emplacement: Inserting elements into a container may also invalidate iterators, especially if the insertion operation causes the container to resize or reorganize its memory.

4. Clearing the Container: Clearing a container, which removes all elements from it, invalidates all iterators associated with that container.

5. Assigning a New Value to the Iterator: In some languages, like Java, directly reassigning a new value to an iterator can invalidate the original iterator.

6. Moving or Swapping Containers: Moving or swapping the content of one container into another can invalidate iterators, as the target container's memory layout may be different.

To avoid iterator invalidation issues, developers should follow these best practices:
1. Be Aware of Container Behavior: Understand how the specific container you're working with manages memory and when iterators might become invalid.

2. Use Iterator Functions: Many containers provide member functions (e.g., erase, insert, emplace) that return valid iterators or hints for insertion/removal operations. 
Use these functions to ensure iterator validity.

3. Recheck After Operations: After performing operations that modify a container, recheck or reacquire iterators to ensure they are still valid.

4. Avoid Mixing Iterators: Avoid using iterators from one container to manipulate another container.

5. Use Range-Based Loops: When possible, use range-based for loops, which automatically manage iterators and can help avoid iterator invalidation issues.

6. Iterator invalidation can lead to runtime errors, crashes, or unexpected behavior in your code, so it's essential to be cautious when working with 
iterators and understand the behavior of the containers you are using.

Iterator invalidation 
Operations	                 Invalidated
-----------                  ------------
All read only operations	 Never
swap, std::swap         	 end()
clear, operator=, assign	 Always
reserve, shrink_to_fit	     If the vector changed capacity, all of them. If not, none.
erase	                     Erased elements and all elements after them (including end())
push_back, emplace_back	     If the vector changed capacity, all of them. If not, only end().
insert, emplace	             If the vector changed capacity, all of them.
                             If not, only those at or after the insertion point (including end()).
resize	                     If the vector changed capacity, all of them. If not, only end() and any elements erased.
pop_back	                 The element erased and end().

*/


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
