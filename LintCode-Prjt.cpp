/*
 * LintCode-Prjt.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#include "LintCode1.h"

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

	return 0;
}



