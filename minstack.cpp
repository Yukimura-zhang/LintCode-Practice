/*
 * minstack.cpp
 *
 *  Created on: 2018年1月31日
 *      Author: yuki
 */

#include "minstack.h"

#define SAFE_DEL_OBJ(x)	\
	if(x != nullptr){	\
		delete x;	\
		x = nullptr;	\
	}

minstack::minstack() {
	// TODO Auto-generated constructor stub
	stack_main = new std::stack<int>;
	stack_helper = new std::stack<int>;
}

minstack::~minstack() {
	// TODO Auto-generated destructor stub
	SAFE_DEL_OBJ(stack_main);
	SAFE_DEL_OBJ(stack_helper);
}

void minstack::push(int number)
{
	stack_main->push(number);
	if(stack_helper->empty()){
		stack_helper->push(number);
	}else{
		if(stack_helper->top() >= number)
			stack_helper->push(number);
	}
}

void minstack::pop()
{
	if(stack_helper->top() == stack_main->top())
		stack_helper->pop();

	stack_main->pop();
}

int minstack::min()
{
	return stack_helper->top();
}

int minstack::top()
{
	return stack_main->top();
}

bool minstack::empty()
{
	return stack_main->empty();
}

unsigned int minstack::size()
{
	return stack_main->size();
}

