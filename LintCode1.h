/*
 * LintCode1.h
 *
 *  Created on: 2018年1月24日
 *      Author: yuki
 */

#ifndef LINTCODE1_H_
#define LINTCODE1_H_
#include <iostream>
#include <vector>
#include <functional>

/*给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符*/
int LintCode1(int a,int b);

/*计算出n阶乘中尾部零的个数*/
int LintCode2(int n);

/*计算数字k在0到n中的出现的次数，k可能是0~9的一个值*/
int LintCode3(int n,int k);

/*设计一个算法，找出只含素因子2，3，5 的第 n 小的数。
 * 符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12。
 * 本题中1也认为是一个丑数*/
int LintCode4(int n);

/*寻找数组中第k大元素,要求时间复杂度为O(n)，空间复杂度为O(1)*/
int LintCode5(int k, std::vector<int> nums);

/*
 * 写出一个高效的算法来搜索 m × n矩阵中的值
 * 这个矩阵具有以下特性：
 * 每行中的整数从左到右是排序的。
 * 每行的第一个数大于上一行的最后一个整数。
 * */
bool LintCode28(std::vector<std::vector<int>> &matrix, int target);

/*
 * 对于一个给定的 source 字符串和一个 target 字符串,
 * 你应该在 source 字符串中找出 target字符串出现的第一个位置(从0开始)。
 * 如果不存在，则返回 -1。
 * 即：实现一个strstr
 */
int LintCode13(const char *source, const char *target);



#endif /* LINTCODE1_H_ */
