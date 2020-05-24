#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = -1;
        istringstream iss(sentence);
        vector<string> tokens{ istream_iterator<string>{iss},
                      istream_iterator<string>{} };
        for (int i = 1; i <= tokens.size(); i++)
        {
            if (tokens[i - 1].find(searchWord) == 0)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string s = "i love eating burger";
    string search = "burg";
    cout << ans.isPrefixOfWord(s, search);
    return 0;
}