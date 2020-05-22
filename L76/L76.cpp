#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //不保证t中字母不重复
        if (s.size() == 0)
            return "";
        int upPtr = 0, lowPtr = -1;
        unordered_map <char, int> checktMap; //存储循环时t中所含字母出现的次数
        for (char c : t)
        {
            checktMap[c] = 0;
        }
        unordered_map <char, int> checkMap(checktMap); //检查t中所含字母出现的次数
        for (char c : t)
        {
            checkMap[c] += 1;
        }
        int check = checktMap.size();
        int checkCount = 0; //检查是否包含t中全部的字母
        int minLen = INT_MAX;
        int minPtr = 0;
        bool expandFlag = true;
        bool checkFlag = false; //判断是否已经包含t中所有字母
        while (true)
        {
            if (expandFlag)
            {
                //扩张
                lowPtr += 1;
                if (lowPtr >= s.size())
                {
                    break;
                }
                char expandChar = s[lowPtr];
                if (checktMap.find(expandChar) != checktMap.end())
                {
                    //if (checktMap[expandChar] == 0)
                    //    checkCount += 1;
                    checktMap[expandChar] += 1;
                    if (!checkFlag)
                    {
                        if (checktMap[expandChar] == checkMap[expandChar])
                        {
                            checkCount += 1;
                        }
                        if (checkCount == check)
                        {
                            checkFlag = true;
                        }
                    }
                }
            }
            else
            {
                //收缩
                char contractChar = s[upPtr];
                if (checktMap.find(contractChar) != checktMap.end())
                {
                    //不需要判断能不能收缩，之前判断过了
                    checktMap[contractChar] -= 1;
                }
                upPtr += 1;
            }

            if (checkFlag)
            {
                //找到了包含所有T的窗口，开始判断是扩张还是缩小
                char upCh = s[upPtr];
                if (checktMap.find(upCh) != checktMap.end())
                {
                    if (checktMap[upCh] - 1 < checkMap[upCh])
                    {
                        //不能收缩
                        if (lowPtr - upPtr + 1 < minLen)
                        {
                            minLen = lowPtr - upPtr + 1;
                            minPtr = upPtr;
                        }
                        expandFlag = true;
                    }
                    else
                    {
                        expandFlag = false;
                    }
                }
                else
                {
                    expandFlag = false;
                }
            }
            else
            {
                expandFlag = true;
            }
        }
        if (!checkFlag)
            return "";
        return s.substr(minPtr, minLen);
    }
};

int main()
{
    //string s = "ADOBECODEBANC";
    //string t = "ABC";
    string s = "aa";
    string t = "aa";
    Solution ans;
    cout << ans.minWindow(s, t);
	return 0;
}