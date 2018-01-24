/*
 * LintCode1.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#include "LintCode1.h"

using namespace std;

int LintCode1(int a,int b){
	/*
	 * 从二进制的角度来思考，比如a = 8(1000) b = 3(0011)：
	 * 抛开进位机制，00得0，01/10得1，11得0,这和异或一样；
	 * 11得0,再进位，这是相与再左移；
	 * 当进位进不动时，即进位为0时计算结束
	 */
	int sum = 0,carry = 0;

	//若一开始b为0，则不需要计算
	while(b){
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}

	return a;
}

/*计算出n阶乘中尾部零的个数*/
int LintCode2(int n)
{
	/*
	 * 0! = 1没有0，5! = 5 * 4 * 3 * 2 * 1，包含5*2，一定有0；
	 * 最小为5时，尾数第一次出现0；
	 * 尾数为0的次数即10的次方数，即使5,2成对出现的次数；
	 * 对每个乘数分解因式，假设可以获得x个2，y个5，可知y是绝对小于x的；
	 * 所以0的个数即为y;
	 */

	int i = 5,j = 0,num = 0;
	for(; i <= n; i+=5){
		j = i;
		while(!(j % 5)){
			num++;
			j /= 5;
		}
	}

	return num;
}


