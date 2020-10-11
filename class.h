#pragma once
#include<iostream>
using namespace std;
struct node
{
	int val;//每个节点的值
	int carry;//进位标识
	node* next;//前驱
	node* last;//后继
	node() :val(0),carry(0),next(NULL), last(NULL) {};

};

class Factorial
{
public:
	Factorial()
	{
		begin = new node();
		begin->val = 1;
		end = begin;
	}
	void mul(int n);//根据参数n开始阶乘，计算n!
	void output();//输出结果
private:
	node* begin;//头节点
	node* end;//尾指针
};

void Factorial::mul(int n)
{
	node* current = begin;
	int temp = 0;
	int i = 1;
	while (i < n + 1) {
		current = begin;
		//while循环遍历链表
		while (current != NULL ) {
			current->val = (current->val) * i + current->carry;//链表的值×n
			current->carry = 0;
			if (current->val >= 1000)
			{
				temp = current->val % 1000;
				if (current->next == NULL)
				{
					current->next = new node();
					current->next->last = current;
					current->next->val = (current->val - temp) / 1000;
					current->val = temp;
					current = current->next;
				}
				else
				{
					current->next->carry = (current->val - temp) / 1000;
					current->val = temp;
					current = current->next;
					continue;
				}
			}
			end = current;
			current = current->next;
		}
		i++;
	}
}

void Factorial::output()
{
	while (end != NULL)
	{
		if (end->next == NULL)
		{
			cout << end->val << ',';
			end = end->last;
			continue;
		}
		if (end->val == 0)
		{
			cout << "000,";
		}
		//1-9
		else if (end->val > 1 && end->val < 10)
		{
			cout << "00" << end->val << ',';
		}
		else if (end->val >= 10 && end->val < 100)
		{
			cout << '0' << end->val << ',';
		}
		else cout << end->val<<',';
		end = end->last;
	}
}