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
*                              strings                                *
***********************************************************************/
/* string: C++ strings use dynamic memory and manage it themselves. So if we append more text to a string, we don’t need to worry about memory corruption or cutting off strings.
Many current implementations also use optimization for short strings (e.g., to 16 bytes) that are not stored in dynamic memory, but directly in the string object itself.
This optimization can significantly reduce the expensive memory allocation and release.

Since text in double quotes is interpreted as a char array, we need to be able to denote that the text should be considered a string.
This is done with the suffix s, e.g., "Herbert"s.3 Unfortunately, it took us until C++14 to enable this. An explicit conversion
like string("Herbert") was always possible. A lightweight constant view on strings was added in C++17 that we will show in Section.
*/
int practice_stl_string() {
    std::string s1 = "This is a string";
    std::string::iterator it;

    // size & length
    std::cout << "size is same as length: " << s1.size() << std::endl;
    std::cout << "size is same as length: " << s1.length() << std::endl;

    // + for concatenation
    std::cout << "concatenated strings: ";
    std::string s2 = "this is also a string";
    std::cout << s1 + ":" + s2 << std::endl;
    std::cout << std::endl;

    // compare
    std::cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << std::endl;
    std::cout << "copy-assign s2 = s1" << std::endl;
    s2 = s1;
    std::cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << std::endl;
    std::cout << "is s1 > \"other string\"? " << (s1 > "other string" ? "yes" : "no") << std::endl;
    std::cout << "is s1 < \"other string\"? " << (s1 < "other string" ? "yes" : "no") << std::endl;
    std::cout << "is \"other string\"? > s1  " << ("other string" > s1 ? "yes" : "no") << std::endl;
    std::cout << "is \"other string\" < s1? " << ("other string" < s1 ? "yes" : "no") << std::endl;
    std::cout << std::endl;

    // iteration
    std::cout << "each character: ";
    for (char c : s1) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // insert & erase with an iterator
    it = s1.begin() + 5;
    s1.insert(it, 'X');
    std::cout << "s1 after insert: " << s1 << std::endl;

    it = s1.begin() + 5;
    s1.erase(it);
    std::cout << "s1 after erase: " << s1 << std::endl;
    std::cout << std::endl;

    // replace
    s1.replace(5, 2, "ain't");
    std::cout << "s1 after replace: " << s1 << std::endl;

    // substr
    std::cout << "substr: " << s1.substr(5, 5) << std::endl;

    // starts with
    // bool bl = s1.starts_with('W'); for new version?
    s1.compare(0, 1, s2) == 0; // first is position of first char in compare, second: size of substr to compare, last is the string to compare to

    // find
    size_t pos = s1.find("s");
    std::cout << "find first \"s\" in s1 (pos): " << pos << std::endl;

    // rfind
    pos = s1.rfind("s");
    std::cout << "find last \"s\" in s1 (pos): " << pos << std::endl;

    // converting string to int
    using namespace std;
    string str = "7";
    cout << "I am a string " << str << endl;
    int num = stoi(str);

    // converting to string 
    string to_string(int num);
    string to_string(long num);
    string to_string(long long num);
    string to_string(unsigned num);
    string to_string(unsigned long num);
    string to_string(unsigned long long num);
    string to_string(float num);
    string to_string(double num);
    string to_string(long double num);

    // converting a string to lower case
    string sit = "Something";
    for (int i = 0; i < sit.length(); i++) {
        sit[i] = tolower(sit[i]);
    }

    // converting a string to upper case
    string situ = "Something";
    for (int i = 0; i < situ.length(); i++) {
        situ[i] = toupper(situ[i]);
    }

    // get the last n characters in a string 
    // str.substr(str.size() - n); the first arg is the position of the first char in the substr, the second arg (dropped here) is the number of chars to include in the substr. here it means till end of the string.

    // get the first n characters in a string
    // str.substr(0, n); // first arg is the position to start getting the substr, second is number of chars to include 
    // str.substr(0, 0); // will return nothing, second arg is 0 characters 
    
    // check if a substr exists in a string
    /*
    if (s.find(c) == string::npos) {
        isFound = 1;
    }
    */

    // text string can be split by strings
    /*Very long text can be split into multiple sub - strings:

    std::string s3 = "This is a very long and clumsy text "
                     "that is too long for one line.";
    */

    // split string by delimeter
    /*
    string S, T;  // declare string variables  
    getline(cin, S); // use getline() function to read a line of string and store into S variable.  
    stringstream X(S); // X is an object of stringstream that references the S string  
    // use while loop to check the getline() function condition  
    while (getline(X, T, ' ')) {
        // X represents to read the string from stringstream, T use for store the token string and,
        // ' ' whitespace represents to split the string where whitespace is found. 

        cout << T << endl; // print split string  
    }
    */
    return 0;
}


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
