// 71_simplifyPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string simplifyPath(string path) {
	vector<string> res;
	size_t start = path.find('/');
	size_t end = path.find('/', start + 1);
	while (end != string::npos)
	{
		string s = path.substr(start + 1, end - start - 1);
		if (s != ""&&s != ".")
		{
			if (s == "..")
			{
				if (res.size() > 0)
				{
					res.pop_back();
				}
			}
			else
			{
				res.push_back(s);
			}
		}
		start = end;
		end = path.find('/', end + 1);
	}

	string s = path.substr(start + 1, path.size() - start - 1);
	if (s != ""&&s != ".")
	{
		if (s == "..")
		{
			if (res.size() > 0)
			{
				res.pop_back();
			}
		}
		else
		{
			res.push_back(s);
		}
	}

	string r;
	for (int i = 0; i < res.size(); i++)
	{
		r += "/" + res[i];
	}
	if (r.size() == 0)
	{
		return "/";
	}
	return r;
}

vector<int> plusOne(vector<int>& digits) {
	int c = 1;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (!c)return digits;
		digits[i]++;
		if (digits[i] > 9)
		{
			digits[i] = 0;
			c = 1;
		}
		else
		{
			c = 0;
		}

	}
	if (c)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
}

int main() 
{
// 	cout << simplifyPath("/a/./b/../../c/").c_str() << endl;
// 	cout << simplifyPath("/a/../../b/../c//.//").c_str() << endl;
// 	cout << simplifyPath("/a//b////c/d//././/..").c_str() << endl;
	vector<int> digits;
	digits.push_back(9);
	plusOne(digits);
	for (size_t i = 0; i < digits.size(); i++)
	{
		cout << digits[i] << " ";
	}
    return 0;
}

