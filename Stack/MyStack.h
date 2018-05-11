#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/***********************ջ��˳��洢�ṹ*************************/
#define MaxNum 1024
template<class datatype>
class MyStack1
{
public:
	MyStack1();
	~MyStack1();
	bool isEmptyStack1();       // �ж��Ƿ��ջ
	int Stack1Length();         // ��ջ�ĳ���
	bool Stack1Push(datatype x);   // ��Ԫ��xѹ��ջ
	datatype Stack1Pop();       // ջ��Ԫ�س�ջ������ջ��Ԫ��
	datatype GetStack1Top();           // ����ջ��Ԫ�أ�ջ�����仯
	void Stack1Show();                // ��ջ�׵�ջ����ʾԪ��


private:
	datatype *S;    // ָ��ջ��ָ��
	int Top;       // ջ��λ��

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
		cout << "ջ����" << endl;
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
		cout << "��ջ��" << endl;
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
		cout << "��ջ��" << endl;
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


/***********************ջ����ʽ�洢�ṹ*************************/
template<class datatype>
struct Node
{
	datatype data;     // ������
	struct Node *next;   // ָ����ָ����һ�����
};

template<class datatype>
class MyStack2
{
public:
	MyStack2();          // �޲ι�����
	~MyStack2();
	bool Stack2Push(datatype x);         //  ��Ԫ��xѹ��ջ
	datatype Stack2Pop();              // ��ջ������ջ��Ԫ��
	datatype GetStack2Top();           // ����ջ��Ԫ�أ�ջ�����仯
	void Stack2Show();             // ��ʾջԪ��


private:
	Node<datatype> *Top;     // ջ��ָ��
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
	p->next = Top;           // p����һ�������ΪTop
	Top = p;
	return true;
}

template<class datatype>
datatype MyStack2<datatype>::Stack2Pop()
{
	if (Top == NULL)
	{
		cout << "��ջ��" << endl;
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
		cout << "��ջ��" << endl;
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

/***********************ջ��Ӧ��*************************/
#define AppDataType int
char Percede(char a, char b);
AppDataType Operate(AppDataType a, char op, AppDataType b);
class StackApp
{
public:
	void Bit10ToOther(int value, int base);             // ��ʮ��������nת��Ϊ8����
	AppDataType ExpressionResult(string expression);     // ������ʽ��ֵ

private:

};



#endif