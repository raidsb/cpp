/*
https://www.hackerrank.com/challenges/one-month-preparation-kit-simple-text-editor/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-month-preparation-kit&playlist_slugs%5B%5D=one-month-week-three
Implement a simple text editor. The editor initially contains an empty string, . Perform  operations of the following  types:

append - Append string  to the end of .
delete - Delete the last  characters of .
print - Print the  character of .
undo - Undo the last (not previously undone) operation of type  or , reverting  to the state it was in prior to that operation.
Example



operation
index   S       ops[index]  explanation
-----   ------  ----------  -----------
0       abcde   1 fg        append fg
1       abcdefg 3 6         print the 6th letter - f
2       abcdefg 2 5         delete the last 5 letters
3       ab      4           undo the last operation, index 2
4       abcdefg 3 7         print the 7th characgter - g
5       abcdefg 4           undo the last operation, index 0
6       abcde   3 4         print the 4th character - d
The results should be printed as:

f
g
d
Input Format
*/

// PASSED

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int operate(vector<vector<string>> queries) {
    string s = "";
    vector<string> prevStack;
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i][0] == "1")
        {
            prevStack.push_back(s);
            s += queries[i][1];
            //cout << "1: " << s << endl;
        }
        else if (queries[i][0] == "2") {
            prevStack.push_back(s);
            s = s.substr(0, s.size() - stoi(queries[i][1]));
            //cout << "2: " << s << endl;
        }
        else if (queries[i][0] == "3") {
            cout << s[stoi(queries[i][1]) - 1] << endl;
        }
        else {
            s = prevStack.back();
            prevStack.pop_back();
            //cout << "4: " << s << endl;
        }
    }

    return 0;
}

int main_editor() {
    int q;
    vector<vector<string>> queries;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string query_string;
        vector<string> query_pieces;
        cin >> query_string;
        //cout << query_string << " ";
        //stringstream obj_ss(queryString);

        //getline(obj_ss, query_piece, ' ');
        query_pieces.push_back(query_string);
        //cout << query_piece << " ";
        if (query_string != "4") {
            //getline(obj_ss, query_piece, ' ');
            cin >> query_string;
            //cout << query_string << " ";
            query_pieces.push_back(query_string);
        }
        //cout << endl;
        queries.push_back(query_pieces);
    }

    operate(queries);
    return 0;
}
