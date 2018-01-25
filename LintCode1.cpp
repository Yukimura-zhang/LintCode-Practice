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
	/* Your code ran too much time than we expected. Check your time complexity.
	 * Time limit exceeded usually caused by infinite loop
	 * if your time complexity is the best.*/
#if 0
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
#endif

	/*
	 * 从上面的分析知：尾数0的个数，取决于分解因式中2，5成对出现的次数，即5的次数；
	 * 但上面的算法还是太耗时，循环遍历了每个阶乘元素；
	 * 这样思考，1,2,3,4...36中，有多少个元素能够整除5？5，10，15，20，25（可以整除2次），30，35
	 * 其实用最大元素36对5反复去商，就能够获得含5因式的个数
	 */
	int num = 0;
	while(n > 4){
	   num += n / 5;
	   n /= 5;
	}

	return num;
}

/*计算数字k在0到n中的出现的次数，k可能是0~9的一个值*/
int LintCode3(int n,int k)
{
	/*
	 * 假设有一个4位数N=ABCD（3456），我们现在来考虑B位上出现4的次数，
	 * 分析完它，就可以用同样的方法去计算ACD位上出现4的次数。
	 *  第一种情况：当B小于4时，假设是A3CD，则4出现在B位上的次数只能由A位决定(A*10)
	 *  第二种情况：当B等于4时，假设是A4CD，则4出现在B位上的次数是A位(A*10)+CD+1；
	 *  代表A4CD 和 A400
	 *  第三种情况：当B大于4时，假设是A5CD，则4出现在B位上的次数是A位(A + 1)*10；
	 *  总结一下：
	 *  当某一位的数字小于i时，该位出现i的次数为：更高位数字x当前位数
	 *  当某一位的数字等于i时，该位出现i的次数为：更高位数字x当前位数+低位数字+1
	 *  当某一位的数字大于i时，该位出现i的次数为：(更高位数字+1)x当前位数
	 */

	int high = 0 ,cur = 0, low = 0,cnt = 0,base = 1;

	if(n == k)
		return 1;
	else if(n < k)
		return 0;
	else{
		/*
		 * base:1,10,100,1000...
		 * 怎样从个位到X位逐个取出高，当前，低位
		 */
		while(n / base > 0){
			high = n / (base * 10);
			cur = n / base % 10;
			low = n - (n/base) * base;

			if (cur < k)
				cnt += high * base;
			else if (cur == k)
				cnt += high * base + low + 1;
			else{
				//k为0的时候需要特殊处理,
				if(!k && !high)
					break;
				cnt += (high + 1) * base;
			}
			base *= 10;
		}
	}

	return cnt;
}


