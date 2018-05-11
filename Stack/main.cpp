#include "MyStack.h"

void main()
{
	cout << "**************ջ��˳��洢�ṹ********************" << endl;

	MyStack1<int> mystack1;
	mystack1.Stack1Push(2);
	mystack1.Stack1Push(0);
	mystack1.Stack1Push(1);
	mystack1.Stack1Push(8);
	mystack1.Stack1Push(0);
	mystack1.Stack1Push(4);
	mystack1.Stack1Push(2);
	mystack1.Stack1Push(0);

	cout << "ջ��ʱΪ��";
	mystack1.Stack1Show();

	cout << "ջ�ĳ���Ϊ��" << mystack1.Stack1Length() << endl;

	mystack1.Stack1Pop();
	cout << "ִ��һ�γ�ջ��";
	mystack1.Stack1Show();

	mystack1.Stack1Pop();
	cout << "ִ�����γ�ջ��";
	mystack1.Stack1Show();

	int z = mystack1.GetStack1Top();
	cout << "ȡ��ʱջ��ջ��Ԫ��:" << z << endl;
	cout << "��ʱջ��Ϊ��";
	mystack1.Stack1Show();

	cout << "��ʱջ�Ƿ�Ϊ�գ�" << mystack1.isEmptyStack1() << endl;



	cout << "**************ջ����ʽ�洢�ṹ********************" << endl;
	MyStack2<int> mystack2;

	mystack2.Stack2Push(2);
	mystack2.Stack2Push(0);
	mystack2.Stack2Push(1);
	mystack2.Stack2Push(8);
	mystack2.Stack2Push(0);
	mystack2.Stack2Push(4);
	mystack2.Stack2Push(2);
	mystack2.Stack2Push(0);

	cout << "��ʱջΪ��";
	mystack2.Stack2Show();

	cout << "��һ�γ�ջ��";
	mystack2.Stack2Pop();
	mystack2.Stack2Show();

	cout << "�ڶ��γ�ջ��";
	mystack2.Stack2Pop();
	mystack2.Stack2Show();

	cout << "**************ջ��Ӧ��********************" << endl;
	StackApp stackapp;

	cout << "��ʮ������157ת��Ϊ�˽�������";
	stackapp.Bit10ToOther(157, 8);

	cout << "���ʽ�ļ���" << endl;
	//char temp_char[] = { '#', '3', '+', '(', '5', '-', '1', ')', '*', '8', '#' };
	string expression = "#3+(5-1)*10#";
	
	for (int i = 1; i < expression.length() - 1; i++)
	{
		cout << expression[i] << " ";
	}
	cout << " = " << endl;
	cout<< stackapp.ExpressionResult(expression) << endl;
}