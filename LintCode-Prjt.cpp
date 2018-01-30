/*
 * LintCode-Prjt.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#include "LintCode1.h"
#include "LintCode10.h"

int main(int argc,char *argv[])
{
	int a = 123,b = 321,c = 0;
	c = LintCode1(a,b);
	std::cout << "LintCode1 a + b = " << c << std::endl;

	a = 36;
	c = LintCode2(a);
	std::cout << "LintCode2 c = " << c << std::endl;

	a = 21;
	b = 1;
	c = LintCode3(a,b);
	std::cout << "LintCode3 c = " << c << std::endl;

	a = 41;
	c = LintCode4(a);
	std::cout << "LintCode4 c = " << c << std::endl;

	std::vector<int> intvec;
	a = 12;
	for(b = 0; b < a; b++){
		intvec.push_back(b+1);
	}
	c = LintCode5(5,intvec);
	std::cout << "LintCode5 c = " << c << std::endl;

	std::string s1("((2)){[345]}[]");
	std::string s2("{((2)){[345]}[]");
	std::cout << "s1 = " << s1 << LintCode423(s1) << std::endl;
	std::cout << "s2 = " << s2 << LintCode423(s2) << std::endl;

	return 0;
}
