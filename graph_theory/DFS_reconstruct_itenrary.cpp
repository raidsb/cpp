/*
Reconstruct Itinerary
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Constraints
1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi

Input : tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}
Output : {"JFK","MUC","LHR","SFO","SJC"}
Expected Time Complexity: O(ElogE ), where E is equal to tickets.length
*/
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

vector<string>ans;
map<string, multiset<string>>m;
void dfs(string str)
{
    while (m[str].size() > 0)
    {
        auto it = m[str].begin();
        string str1 = *it;
        m[str].erase(it);
        dfs(str1);
    }
    ans.push_back(str);
}
vector<string> findItinerary(vector<vector<string>> tickets) {
    int n = tickets.size();
    ans.clear();
    m.clear();
    for (int i = 0; i < n; i++)
    {
        string str1 = tickets[i][0], str2 = tickets[i][1];
        m[str1].insert(str2);
    }
    dfs("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
}