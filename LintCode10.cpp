/*
 * LintCode10.cpp
 *
 *  Created on: 2018年1月30日
 *      Author: yuki
 */
#include "LintCode10.h"
#include <stack>

using namespace std;

/*
 * 有效的括号序列
 * 给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'
 * 判定是否是有效的括号序列。
 */
bool LintCode423(std::string &s)
{
	/*
	 * 利用栈的特性，先进后出，top始终是最近的一个括号
	 * 如果匹配则pop，不匹配则push，最后栈为空则全匹配上
	 */
	stack<char> cstack;

	auto isbrace = [](char c){
		if(c == '(' || c == '[' || c == '{'||
				c == ')' || c == ']' || c == '}')
			return true;

		return false;
	};
	auto ismatch = [](char c1,char c2){
		if((c1 == '(' && c2 == ')') ||
				(c1 == '[' && c2 == ']') ||
				(c1 == '{' && c2 == '}'))
			return true;

		return false;
	};

	for(auto c = s.begin();c != s.end();c++){
		if(isbrace(*c) == true){
			if(!cstack.size())
				cstack.push(*c);
			else{
				if(ismatch(cstack.top(),*c) == true)
					cstack.pop();
				else
					cstack.push(*c);
			}
		}
	}
	if(!cstack.size())
		return true;

	return false;
}




