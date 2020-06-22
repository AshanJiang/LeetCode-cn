#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool sliceString(string s ,string delimiter, int times, string& slicedString, vector<string>& slicedVec)
    {
        string res = "";
        size_t pos = 0;
        int count = 0;
        string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            if (count >= times)
                break;
            token = s.substr(0, pos);
            res += token;
            slicedVec.push_back(token);
            s.erase(0, pos + delimiter.length());
            count++;
        }
        res += s;
        slicedVec.push_back(s);
        slicedString = res;
        if (count < times)
            return false;
        else
            return true;
    }

    bool patternMatching(string pattern, string value) {
        if (pattern.empty())
        {
            if (value.empty())
                return true;
            return false;
        }
        vector <int> v(2, 0);
        bool reverseFlag = false;
        if (pattern.front() == 'b')
            reverseFlag = true;
        for (const char& c : pattern)
        {
            if (c == 'a')
            {
                if (reverseFlag)
                    v[1]++;
                else
                    v[0]++;
            }
            if (c == 'b')
            {
                if (reverseFlag)
                    v[0]++;
                else
                    v[1]++;
            }
        }
        if (value.size() == 0)
        {
            if (v[1] == 0)
                return true;
            return false;
        }
        if (v[1] == 0)
        {
            v[1] = v[0];
            v[0] = 0;
        }
        for (int i = 0; i <= value.size(); i++)
        {
            string pa = value.substr(0, i); // 枚举a
            string slicedA = ""; // 去除模式a之后的字符串
            vector<string> slicedVec;
            bool flagA = sliceString(value, pa, v[0], slicedA, slicedVec); // 能否被a切分其出现次数
            // cerr << "pa = " << pa << " slicedA = " << slicedA << "\n";
            if (!flagA)
            {
                continue;
            }
            if (slicedA.size() % v[1] != 0)
            {
                continue;
            }
            else
            {
                int countb = 0;
                int sizeb = slicedA.size() / v[1];
                string pb = slicedA.substr(0, sizeb);
                if (pa == pb) // a和b不能表示相同字符串
                    continue;
                if (pb.empty() && slicedA.empty())
                    return true;
                slicedA.erase(0, sizeb);
                // cerr << "pb = " << pb << "\n";
                while (!slicedA.empty())
                {
                    if (slicedA.substr(0, sizeb) != pb)
                    {
                        break;
                    }
                    else
                    {
                        slicedA.erase(0, sizeb);
                        countb++;
                    }
                }
                if (countb == v[1] - 1)
                {
                    bool flag = true;
                    for (const string& s : slicedVec)
                    {
                        if (s.size() % pb.size() != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution ans;
    string pattern = "abbbaabbaabbbab";
    string value = "ndnnnnnnnnnnnndnnndnnnnnnnnnnndnnndnnnnnnnnnnnnnnndnnnnnn";
    cout << "ans = " << ans.patternMatching(pattern, value) << "\n";
	return 0;
}