// PASSED

/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-balanced-brackets/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-three 
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.

Function Description

Complete the function isBalanced in the editor below.

isBalanced has the following parameter(s):

string s: a string of brackets
Returns

string: either YES or NO
*/
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    const char* bracketsArr = s.c_str();
    vector<char> bracketsStack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            bracketsStack.push_back(s[i]);
        }
        else {
            if (bracketsStack.size() == 0) return "NO";
            char topChar = bracketsStack.back();
            if (topChar == '(' && s[i] == ')') bracketsStack.pop_back();
            else if (topChar == '[' && s[i] == ']') bracketsStack.pop_back();
            else if (topChar == '{' && s[i] == '}') bracketsStack.pop_back();
            else return "NO";
        }
    }
    
    if (bracketsStack.size() > 0) return "NO";
    return "YES";
}

int main_Balanced()
{
    // single case
    cout << isBalanced("[(({") << endl;;
    /*
    fstream myFile;
    string str;    
    myFile.open("BalancedBrackets/input09.txt");
    int n = 629;
    
    for (int i = 0; i < 629; i++) {
        getline(myFile, str);
        //cout << str << endl;
        cout << isBalanced(str) << endl;
    }
    */
    return 0;
}
