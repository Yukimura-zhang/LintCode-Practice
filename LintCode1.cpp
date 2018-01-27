/*
 * LintCode1.cpp
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#include "LintCode1.h"
#include <set>

#define ENABLE_MULTISET	(0)

using namespace std;

/*给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符*/
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
   *  第一种情况：当B小于4时，假设是A3CD，则4出现在B位上的次数只能由A位决定(A*100)
   *  第二种情况：当B等于4时，假设是A4CD，则4出现在B位上的次数是A位(A*100)+CD+1；
   *  代表A4CD 和 A400
   *  第三种情况：当B大于4时，假设是A5CD，则4出现在B位上的次数是A位(A + 1)*100；
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
    	  //k为0的时候需要特殊处理,真实的数据中，0不能在高位!
        if(!k && !high)
        	break;
        cnt += (high + 1) * base;
      }
      base *= 10;
    }
  }

  return cnt;
}

/*设计一个算法，找出只含素因子2，3，5 的第 n 小的数。
 * 符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12。
 * 本题中1也认为是一个丑数*/
int LintCode4(int n)
{
	/*
	 * 观察1，2, 3, 4, 5, 6, 8, 9, 10, 12...,可得所有元素都是2，3，5的倍数
	 * 1*2，1*3，1*5，2最小，第二个元素是2；
	 * 2*2，1*3，1*5，3最小，第三个元素是3；
	 * 2*2，2*3，1*5，4最小，第四个元素是4；
	 * 4*2，2*3，1*5, 5最小，第五个元素是5；
	 * 4*2，2*3，2*5，6最小，第六个元素是6；
	 */

	auto min3 = [](int a,int b,int c){
		int tmp = a > b?b:a;
		return tmp > c?c:tmp;
	};
	int *ugly = new int[n];
	ugly[0] = 1;
	//int times2 = 1,times3 = 1,times5 = 1;
	int times2 = 0,times3 = 0,times5 = 0;
	for(int i = 1; i < n; i++){
#if 0
		/*ugly[i] = min3(times2*2,times3*3,times5*5);
		if(ugly[i] == times2*2)
			times2++;
		else if(ugly[i] == times3*3)
			times3++;
		else
			times5++;*/

		ugly[i] = min3(times2*2,times3*3,times5*5);
		if(ugly[i] == times2*2)
			times2++;
		if(ugly[i] == times3*3)
			times3++;
		if(ugly[i] == times5*5)
			times5++;
#endif
		/*
		 * 请思考注释的方法为何错误？
		 * 首先是丑数的含义，丑数是2/3/5的倍数，但2/3/5的倍数不一定是丑数，比如14
		 * 丑数的因子只能有2，3，5，注释的方法把times单纯当作倍数来算，这是错误一；
		 * 其次，为什么要用if...if...if,而不是if...else if...else?
		 * 运算原理是这样的，任何一个丑数 * 2/3/5之后会得一个新的丑数，假设1为U1,
		 * 明显U2 = min3(U1*2,U1*3,U1*5)，U2 = U1*2，
		 * 那么U3 = min3(U2*2,U1*3,U1*5)，U3 = U1*3；
		 * 那么U4 = min3(U2*2,U2*3,U1*5)，U4 = U2*2；
		 * 那么U5 = min3(U3*2,U2*3,U1*5)，U5 = U1*5；
		 * 那么U6 = min3(U3*2,U2*3,U2*5)，U6 = U3*2 = U2*3；
		 * 那么U7 = min3(U4*2,U3*3,U2*5)，U7 = U4*2；
		 * 看U6和U7，就明白为什么用if...if...if;
		 * 然后times2/3/5其实表示当前最小U应该是用第几个U和2/3/5相乘来取最小值
		 */
		ugly[i] = min3(ugly[times2]*2,ugly[times3]*3,ugly[times5]*5);
		if(ugly[i] == ugly[times2]*2)
			times2++;
		if(ugly[i] == ugly[times3]*3)
			times3++;
		if(ugly[i] == ugly[times5]*5)
			times5++;
	}

	return ugly[n-1];
}

/*寻找数组中第k大元素,要求时间复杂度为O(n)，空间复杂度为O(1)*/
int LintCode5(int k, vector<int> nums)
{
	if(!nums.size() || static_cast<int>(nums.size()) < k)
		return 0;

#if ENABLE_MULTISET
	/*
	 * 利用multiset来完成的话超级简单
	 * 它是个可以插入重复元素的有序集和，就是说插进去的数据，就已经排好序了，默认是升序
	 * 因为是自动排序，所以元素是不支持修改的，必须先erase，再insert。
	 *
	 * 首先插入k个元素，此时这k个元素都是有序的，明显begin是最小的一个
	 * 其他的元素，如果比begin大，则清除原来最小的一个(清除的同时会对k-1个元素排序，即set[0]变成原来第二小的)；
	 * 之后再插入(插入的同时会对k个元素重新排序,set[0]是插入新元素之后最小的)；
	 *
	 * 如此反复，直至操作完所有元素，最后set中就是前k个大元素
	 */
	//multiset<int,greater<int>>set;//降序
	multiset<int,less<int>>set;//升序，multiset<int> set;

	for(int i= 0; i < static_cast<int>(nums.size()); i++) {
		if(static_cast<int>(set.size()) < k)  {
			set.insert(nums[i]);
		}
		else {
			if(nums[i] >= *set.begin())  {
				set.erase(*set.begin());
				set.insert(nums[i]);
			}
		}
	}
	return *set.begin();
#else
	/* 快速排序
	 * 通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
	 * 然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行。
	 * 一趟快速排序的算法是：
	 * 1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
	 * 2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
	 * 3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]互换；
	 * 4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]互换；
	 * 5）重复第3、4步，直到i>=j。
	 * 快排选的key值对排序时间复杂度是有较大影响的，想一下：
	 * 如果选中的key是最大/最小元素，一趟下来并不能把数组分成两部分，那就变成冒泡了，
	 * 所以key值需要是一个中间值，比如高中低位的中间值。
	 */

	auto swap = [](int &a,int &b){
		a = a + b;
		b = a - b;
		a = a - b;
		/* b不能为0
		 * a = a * b;
		 * b = a / b;
		 * a = a / b
		 */
	};

	//[&]才能捕获swap
	auto getmid = [&](vector<int> &vec,int low,int high,int mode = 0){
		//mode 0 为升序，!0为降序
		if(high == low){
			return vec[low];
		}
		else if((high - low) == 1){
			if(vec[low] > vec[high] && !mode)
				swap(vec[low],vec[high]);
			if(vec[low] < vec[high] && mode)
				swap(vec[low],vec[high]);
		}
		else{
			/*
			 * 我们需要将的结果是vec[mid] <= vec[low] <= vec[high]
			 * 即：把中间值放到low，这样可以不改变原来快排从low开始的基本思路
			 */
			int mid = low + (high - low) / 2;
			if(vec[mid]> vec[high])
				swap(vec[mid],vec[high]);
			if(vec[low]> vec[high])
				swap(vec[low],vec[high]);
			if(vec[mid]> vec[low])
				swap(vec[mid],vec[low]);
		}
		return vec[low];
	};

	/*
	 * 错误：use of ‘qsort’ before deduction of ‘auto’*
	 * 注意，不能再使用auto qsort = [&](vector<int> &vec,int low,int high,int mode = 0)
	 * 因为qsort会递归调用，auto无法自动推导类型
	 */
	 function<void(vector<int> &,int,int,int)> qsort;
	 qsort = [&](vector<int> &vec,int low,int high,int mode = 0){
		//mode 0 为升序，!0为降序
		if(low >= high)
			return;

		int first = low,last = high;
		int key = getmid(vec,low,high,mode);
		//元素个数小于2的情况，直接用getmid来处理，不用再排序
		if(high - low <= 1)
			return;

		while(first < last){
			if(!mode){//升序
				while(first < last && vec[last] >= key){
					last--;
				}
				vec[first] = vec[last];

				while(first < last && vec[first] <= key){
					first++;
				}
				vec[last] = vec[first];
			}else{//降序
				while(first < last && key >= vec[last]){
					last--;
				}
				vec[first] = vec[last];

				while(first < last && key <= vec[first]){
					first++;
				}
				vec[last] = vec[first];
			}
		}
		vec[first] = key;
		qsort(vec,low,first -1,mode);
		qsort(vec,first + 1,high,mode);
	};

	qsort(nums,0,nums.size()-1,1);

	return nums[k-1];
#endif
}
