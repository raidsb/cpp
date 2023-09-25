/*
C++ Containers library
The Containers library is a generic collection of class templates (because can be used with different data types) 
and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks.

There are two (until C++11)three (since C++11) classes of containers:
[1] sequence containers
[2] associative containers
[3] unordered associative containers

each of which is designed to support a different set of operations.

The container manages the storage space that is allocated for its elements and provides member functions to access them,
either directly or through iterators (objects with properties similar to pointers).

Most containers have at least several member functions in common, and share functionalities.
Which container is the best for the particular application depends not only on the offered functionality,
but also on its efficiency for different workloads.

[1] Sequence containers
Sequence containers implement data structures which can be accessed sequentially.

[1.1] array
(C++11)
static contiguous array
(class template)

[1.2] vector
dynamic contiguous array
(class template)

[1.3] deque
double-ended queue
(class template)

[1.4] forward_list
(C++11)

[1.5] singly-linked list
(class template)
list

[1.6] doubly-linked list
(class template)

[2] Associative containers
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

[2.1] set
collection of unique keys, sorted by keys
(class template)

[2.2] map
collection of key-value pairs, sorted by keys, keys are unique
(class template)

[2.3] multiset
collection of keys, sorted by keys
(class template)

[2.4] multimap
collection of key-value pairs, sorted by keys
(class template)

[3] Unordered associative containers (since C++11)
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).

[3.1] unordered_set
(C++11)
collection of unique keys, hashed by keys
(class template)

[3.2] unordered_map
(C++11)
collection of key-value pairs, hashed by keys, keys are unique
(class template)

[3.3] unordered_multiset
(C++11)
collection of keys, hashed by keys
(class template)

[3.4] unordered_multimap
(C++11)
collection of key-value pairs, hashed by keys
(class template)

[4]Container adaptors
Container adaptors provide a different interface for sequential containers.

[4.1] stack
adapts a container to provide stack (LIFO data structure)
(class template)

[4.2] queue
adapts a container to provide queue (FIFO data structure)
(class template)

[4.3] priority_queue
adapts a container to provide priority queue
(class template)

[4.4] flat_set
(C++23)
adapts a container to provide a collection of unique keys, sorted by keys
(class template)

[4.5] flat_map
(C++23)

adapts two containers to provide a collection of key-value pairs, sorted by unique keys
(class template)

[4.6] flat_multiset
(C++23)
adapts a container to provide a collection of keys, sorted by keys
(class template)

[4.7] flat_multimap
(C++23)
adapts two containers to provide a collection of key-value pairs, sorted by keys
(class template)

[5] Views
Views provide flexible facilities for interacting with one- or multi-dimensional views over a non-owning array of elements.

[5.1] span
(C++20)
a non-owning view over a contiguous sequence of objects
(class template)

[5.2] mdspan
(C++23)
a multi-dimensional non-owning array view
(class template)
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
*                              exceptions                             *
***********************************************************************/
#include <exception>

namespace BW {
    class E : public std::exception { // inheriting from the base class exception and set the new class as public
        const char* msg;
        E();
    public:
        E(const char* s) noexcept(true) : msg(s) {}
        const char* what() const noexcept(true) { return msg; }
    };
}

void broken() {
    std::cout << "this is a broken function" << std::endl;
    throw std::exception(); // --> now with definition of class E can use throw BW::E("ouch!").
}

int practice_exceptions() {
    std::cout << "let's have an emergency!" << std::endl;
    // case 1
    // broken(); // exception is not handled.

    // case 2. handling using the generic exception class
    /* try {
         broken();
       } catch (std::exception& e) {
          std::cout << e.what() << std::endl;
       }
    */

    // case 3 . using the defined exception 
    /*
    try {
        broken();
    }
    catch (BW::E & e) {
        std::cout << e.what() << std::endl;
    }
    */

    return 0;
}

// exceptions you can define to use in different situations and use them to catch
const BW::E e_ouch("ouch!");
const BW::E bad("bad!");
const BW::E worse("worse!");

/**********************************************************************
*                       input/output formatting                       *
***********************************************************************/
#include <iomanip>

int practice_input_output_formatting() {
    // cout is a very common class from iostream
    std::cout << "Hello, World!" << std::endl;

    std::string istr;
    std::cout << "Prompt: ";    
    // In C++, you can read a single whitespace - separated token of input using cin, and print output to stdout using cout.
    std::cin >> istr;    // one word at a time
    std::string s;
    int n;
    std::cin >> s >> n;
    // This reads the first word("High") from stdinand saves it as string, then reads the second word("") from stdinand saves it as integer.
    // If we want to print these values to stdout, separated by a space, we write the following code :
    std::cout << s << " " << n << std::endl;
    //This code prints the contents of string, a single space(), then the integer.We end our line of output with a newline using endl.This results in the following output :
    //High 5
    std::cout << "Input: " << istr << std::endl;

    // using cin to add a line
    char buf[128];
    std::cin.getline(buf, sizeof(buf));
    std::cout << buf << std::endl;

    // integer formatting
    int i1 = 42;
    int i2 = 127;
    int i3 = 5555;
    std::cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "hex: " << std::hex << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "hex with showbase: " << std::showbase << std::hex << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "octal with showbase: " << std::oct << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "default: " << std::noshowbase << std::dec << i1 << ' ' << i2 << ' ' << i3 << std::endl << std::endl;

    // floating point formatting options
    double d1, d2, d3;
    d1 = 3.1415926534;
    d2 = 1234.5;
    d3 = 4.2e-10;
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "fixed: " << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "scientific: " << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "set precision (3): " << std::setprecision(3) << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "scientific (7): " << std::setprecision(7) << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl << std::endl;

    // string formatting options
    std::string s1 = "This is a string.";
    std::string s2 = "This is a much longer string.";
    std::string s3 = "Today's news: Big Light in Sky Slated to Appear in East";

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    std::cout << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setw(64) << std::right << s2 << std::endl;
    std::cout << std::setw(64) << std::right << s3 << std::endl;

    std::cout << std::setfill('-') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setfill(' ') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::left << s1 << std::endl;

    return 0;
}


/**********************************************************************
*                                   sets                              *
***********************************************************************/
#include <set>;

int practice_set() {
    // defining a set of type char
    std::set<char> a;
    
    // inserting an element to the set
    a.insert('G');
    a.insert('F');
    a.insert('G');

    // find an element
    a.find('F'); // return iterator of the type set<type> pointing to the element
    // const bool is_in = container.find(element) != container.end(); // to check if an item exists in the set.

    for (auto& str : a)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';

    // merging two sets
    /*
    std::set<int> odd = { 1, 3, 5 };
    std::set<int> even = { 2, 4, 6 };

    std::set<int> s(odd);
    s.insert(even.begin(), even.end());

    for (auto const& e : s) {
        std::cout << e << ' ';
    }
    */

    return 0;
}

/**********************************************************************
*                       maps                                          *
***********************************************************************/
#include <map>;
// search map by key. check if a key exists:
/*
if (m.find("f") == m.end()) {
  // not found
} else {
  // found
}
*/

void map_practice_1() {
    // iterating a map
    std::map<std::string, int> symbolTable;
    std::map<std::string, int>::iterator it;

    for (it = symbolTable.begin(); it != symbolTable.end(); it++)
    {
        std::cout << it->first    // string (key)
            << ':'
            << it->second   // string's value 
            << std::endl;
    }
}

//With C++11 (and onwards),
void map_practice_2() {
    std::map<std::string, int> symbolTable;
    for (auto const& x : symbolTable)
    {
        std::cout << x.first  // string (key)
            << ':'
            << x.second // string's value 
            << std::endl;
    }
}

//With C++17 (and onwards),
/*
void map_practice_2() {
    std::map<std::string, int> symbolTable;
    for (auto const& [key, val] : symbolTable)
    {
        std::cout << key        // string (key)
            << ':'
            << val        // string's value
            << std::endl;
    }
}
*/
