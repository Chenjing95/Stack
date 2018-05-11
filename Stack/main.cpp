#include "MyStack.h"

void main()
{
	cout << "**************栈的顺序存储结构********************" << endl;

	MyStack1<int> mystack1;
	mystack1.Stack1Push(2);
	mystack1.Stack1Push(0);
	mystack1.Stack1Push(1);
	mystack1.Stack1Push(8);
	mystack1.Stack1Push(0);
	mystack1.Stack1Push(4);
	mystack1.Stack1Push(2);
	mystack1.Stack1Push(0);

	cout << "栈此时为：";
	mystack1.Stack1Show();

	cout << "栈的长度为：" << mystack1.Stack1Length() << endl;

	mystack1.Stack1Pop();
	cout << "执行一次出栈：";
	mystack1.Stack1Show();

	mystack1.Stack1Pop();
	cout << "执行两次出栈：";
	mystack1.Stack1Show();

	int z = mystack1.GetStack1Top();
	cout << "取此时栈的栈顶元素:" << z << endl;
	cout << "此时栈变为：";
	mystack1.Stack1Show();

	cout << "此时栈是否为空：" << mystack1.isEmptyStack1() << endl;



	cout << "**************栈的链式存储结构********************" << endl;
	MyStack2<int> mystack2;

	mystack2.Stack2Push(2);
	mystack2.Stack2Push(0);
	mystack2.Stack2Push(1);
	mystack2.Stack2Push(8);
	mystack2.Stack2Push(0);
	mystack2.Stack2Push(4);
	mystack2.Stack2Push(2);
	mystack2.Stack2Push(0);

	cout << "此时栈为：";
	mystack2.Stack2Show();

	cout << "第一次出栈：";
	mystack2.Stack2Pop();
	mystack2.Stack2Show();

	cout << "第二次出栈：";
	mystack2.Stack2Pop();
	mystack2.Stack2Show();

	cout << "**************栈的应用********************" << endl;
	StackApp stackapp;

	cout << "将十进制数157转换为八进制数后：";
	stackapp.Bit10ToOther(157, 8);

	cout << "表达式的计算" << endl;
	//char temp_char[] = { '#', '3', '+', '(', '5', '-', '1', ')', '*', '8', '#' };
	string expression = "#3+(5-1)*10#";
	
	for (int i = 1; i < expression.length() - 1; i++)
	{
		cout << expression[i] << " ";
	}
	cout << " = " << endl;
	cout<< stackapp.ExpressionResult(expression) << endl;
}