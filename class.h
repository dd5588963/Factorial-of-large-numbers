#pragma once
#include<iostream>
using namespace std;
struct node
{
	int val;//ÿ���ڵ��ֵ
	int carry;//��λ��ʶ
	node* next;//ǰ��
	node* last;//���
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
	void mul(int n);//���ݲ���n��ʼ�׳ˣ�����n!
	void output();//������
private:
	node* begin;//ͷ�ڵ�
	node* end;//βָ��
};

void Factorial::mul(int n)
{
	node* current = begin;
	int temp = 0;
	int i = 1;
	while (i < n + 1) {
		current = begin;
		//whileѭ����������
		while (current != NULL ) {
			current->val = (current->val) * i + current->carry;//�����ֵ��n
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