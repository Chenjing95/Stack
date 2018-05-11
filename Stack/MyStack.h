#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/***********************栈的顺序存储结构*************************/
#define MaxNum 1024
template<class datatype>
class MyStack1
{
public:
	MyStack1();
	~MyStack1();
	bool isEmptyStack1();       // 判断是否空栈
	int Stack1Length();         // 求栈的长度
	bool Stack1Push(datatype x);   // 将元素x压进栈
	datatype Stack1Pop();       // 栈顶元素出栈，返回栈顶元素
	datatype GetStack1Top();           // 返回栈顶元素，栈本身不变化
	void Stack1Show();                // 从栈底到栈顶显示元素


private:
	datatype *S;    // 指向栈的指针
	int Top;       // 栈顶位置

};

template<class datatype>
MyStack1<datatype>::MyStack1()
{
	S = new datatype[MaxNum];
	Top = 0;
}

template<class datatype>
MyStack1<datatype>::~MyStack1()
{
	delete[]S;
	S = NULL;
	Top = 0;
}

template<class datatype>
bool MyStack1<datatype>::isEmptyStack1()
{
	if (Top <= 0)
		return true;
	else
		return false;
}

template<class datatype>
int MyStack1<datatype>::Stack1Length()
{
	return Top;
}

template<class datatype>
bool MyStack1<datatype>::Stack1Push(datatype x)
{
	if (Top >= MaxNum - 1)
	{
		cout << "栈已满" << endl;
		return false;
	}
	else
	{
		S[++Top] = x;
		return true;
	}
}

template<class datatype>
datatype MyStack1<datatype>::Stack1Pop()
{
	if (Top <= 0)
	{
		cout << "空栈！" << endl;
		return datatype(-1);
	}
	else
	{
		return S[Top--];
	}
}

template<class datatype>
datatype MyStack1<datatype>::GetStack1Top()
{
	if (Top <= 0)
	{
		cout << "空栈！" << endl;
		return datatype(-1);
	}
	else
	{
		return S[Top];
	}
}

template<class datatype>
void MyStack1<datatype>::Stack1Show()
{
	for (int m = 1; m <= Top; m++)
	{
		cout << S[m] << "  ";
	}
	cout << endl;
}


/***********************栈的链式存储结构*************************/
template<class datatype>
struct Node
{
	datatype data;     // 数据域
	struct Node *next;   // 指针域，指向下一个结点
};

template<class datatype>
class MyStack2
{
public:
	MyStack2();          // 无参构造器
	~MyStack2();
	bool Stack2Push(datatype x);         //  将元素x压进栈
	datatype Stack2Pop();              // 出栈，返回栈顶元素
	datatype GetStack2Top();           // 返回栈顶元素，栈本身不变化
	void Stack2Show();             // 显示栈元素


private:
	Node<datatype> *Top;     // 栈顶指针
};

template<class datatype>
MyStack2<datatype>::MyStack2()
{
	Top = new Node<datatype>;
	Top = NULL;
}

template<class datatype>
MyStack2<datatype>::~MyStack2()
{
	Top = NULL;
}

template<class datatype>
bool MyStack2<datatype>::Stack2Push(datatype x)
{
	Node<datatype> *p = new Node<datatype>;
	p->data = x;
	p->next = Top;           // p的下一个结点置为Top
	Top = p;
	return true;
}

template<class datatype>
datatype MyStack2<datatype>::Stack2Pop()
{
	if (Top == NULL)
	{
		cout << "空栈！" << endl;
		return datatype(-1);

	}
	else
	{
		Node<datatype> *p = Top;
		Top = p->next;
		datatype x = p->data;
		delete p;
		return x;
	}
}

template<class datatype>
datatype MyStack2<datatype>::GetStack2Top()
{
	if (Top == NULL)
	{
		cout << "空栈！" << endl;
		return datatype(-12318);
	}
	else
	{
		return Top->data;
	}
}

template<class datatype>
void MyStack2<datatype>::Stack2Show()
{
	Node<datatype> *p = Top;
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}

/***********************栈的应用*************************/
#define AppDataType int
char Percede(char a, char b);
AppDataType Operate(AppDataType a, char op, AppDataType b);
class StackApp
{
public:
	void Bit10ToOther(int value, int base);             // 将十进制数字n转换为8进制
	AppDataType ExpressionResult(string expression);     // 计算表达式的值

private:

};



#endif