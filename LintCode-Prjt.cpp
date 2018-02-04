/*
 * LintCode-Prjt.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#include "LintCode1.h"
#include "LintCode10.h"
#include "minstack.h"

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


	//得到一个4行7列的数组
	//由vector实现的二维数组，可以通过resize()的形式改变行、列值
	std::vector<std::vector<int>> array(4);
	for (auto i = array.begin(); i != array.end(); i++)
		(*i).resize(7);

	for(a = 0; a < 4; a++){
		for(b = 0; b < 7; b++)
			array[a][b] = a*b;
	}
	std::cout << "array[2][2] = " << array[2][2] << std::endl;
	std::cout << " LintCode28(array,10000) =  "
			<< LintCode28(array,10000) << std::endl;
	std::cout << " LintCode28(array,array[2][2]) =  "
			<< LintCode28(array,array[2][2]) << std::endl;

	minstack mstack;
	for(a = 0; a < 9; a++){
		mstack.push(a);
	}
	std::cout << " LintCode12() size = " << mstack.size() << std::endl;
	std::cout << " LintCode12() min = " << mstack.min() << std::endl;
	std::cout << " LintCode12() top = " << mstack.top() << std::endl;

	std::cout << "abccfcab, cfc " << LintCode13("abccfcab", "cfc") << std::endl;
	std::cout << "abccfcab, cab " << LintCode13("abccfcab", "cab") << std::endl;
	std::cout << "source, target " << LintCode13("source", "target") << std::endl;
	std::cout << "abcdabcdefg, bcd " << LintCode13("abcdabcdefg", "bcd") << std::endl;
	std::cout << ",  " << LintCode13("", "") << std::endl;
	std::cout << "abcdabcdefg, e " << LintCode13("abcdabcdefg", "e") << std::endl;
	std::cout << "abcdabcdefg, fg " << LintCode13("abcdabcdefg", "fg") << std::endl;

	return 0;
}
