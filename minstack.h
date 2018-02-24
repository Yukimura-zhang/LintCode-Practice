/*
 * minstack.h
 *
 *  Created on: 2018年1月31日
 *      Author: yuki
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_

#include <stack>
using namespace std;

class minstack {
public:
	minstack();
	virtual ~minstack();
	void push(int number);
	int pop();
	int min();

	int top();
	bool empty();
	unsigned int size();

private:
	stack<int> *stack_main;
	stack<int> *stack_helper;
};

#endif /* MINSTACK_H_ */
