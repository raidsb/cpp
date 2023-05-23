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

    //*** size & length ***
    std::cout << "size is same as length: " << s1.size() << std::endl;
    std::cout << "size is same as length: " << s1.length() << std::endl;

    //*** + for concatenation ***
    std::cout << "concatenated strings: ";
    std::string s2 = "this is also a string";
    std::cout << s1 + ":" + s2 << std::endl;
    std::cout << std::endl;

    //*** compare ***
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
