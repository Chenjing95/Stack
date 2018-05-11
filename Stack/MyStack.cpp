#include "MyStack.h"

char Percede(char a, char b)
{
	// 定义运算符优先级表，第i行（左）与第j列（右）比较
	char table[8][8] = {
		{ ' ', '+', '-', '*', '/', '(', ')', '#' },
		{ '+', '>', '>', '<', '<', '>', '<', '>' },
		{ '-', '>', '>', '<', '<', '>', '<', '>' },
		{ '*', '>', '>', '>', '>', '>', '<', '>' },
		{ '/', '>', '>', '>', '>', '>', '<', '>' },
		{ '(', '>', '>', '>', '>', '>', ' ', '>' },
		{ ')', '<', '<', '<', '<', '=', '<', ' ' },
		{ '#', '<', '<', '<', '<', ' ', '<', 'e' }
	};
	int i = 0;
	int j = 0;

	for (i = 0; i < 8; i++)
	{
		if (table[i][0] == a)
			break;
	}
	for (j = 0; j < 8; j++)
	{
		if (table[0][j] == b)
			break;
	}
	return table[i][j];

}

AppDataType Operate(AppDataType a, char op, AppDataType b)
{
	if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	}
	else if (op == '*')
	{
		return a*b;
	}
	else if (op == '/')
	{
		return a / b;
	}

	return AppDataType(-12138);

}






void StackApp::Bit10ToOther(int n, int base)
{
	MyStack2<int> stackbit;
	while (n != 0)
	{
		stackbit.Stack2Push(n%base);
		n = n / base;
	}
	stackbit.Stack2Show();
}

AppDataType StackApp::ExpressionResult(string expression)
{
	MyStack2<AppDataType> OPTD;          // 存放操作数的栈
	MyStack2<char> OPTR;                 // 存放操作符的栈

	int len = expression.length();
	// 判断输入表达式是否正确
	if ((expression[0] != '#') && (expression[len - 1] != '#'))
	{
		cout << "Error Expression!" << endl;
		return AppDataType(-12138);
	}
	// 表达式计算过程
	// #先入操作符栈
	OPTR.Stack2Push(expression[0]);
	for (int i = 1; i < len ; )
	{
		cout << "该位置元素："<< expression[i] << endl;
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(' || expression[i] == ')'|| expression[i] == '#' )
		{
			cout << "OPTR:";
			OPTR.Stack2Show();
			char percede_res = Percede(expression[i], OPTR.GetStack2Top());
			cout << percede_res << endl;
			if (percede_res == '>')
			{
				OPTR.Stack2Push(expression[i]);
				i++;
			}
			else if (percede_res == '<')
			{
				char op = OPTR.Stack2Pop();
				AppDataType b = OPTD.Stack2Pop();
				AppDataType a = OPTD.Stack2Pop();
				AppDataType temp_res = Operate(a, op, b);
				OPTD.Stack2Push(temp_res);
			}
			else if (percede_res == '=')
			{
				OPTR.Stack2Pop();
				i++;
			}
			else if (percede_res == ' ')
			{
				cout << "Expected '('" << endl;
				i++;
			}
			else if (percede_res == 'e')
			{
				return OPTD.GetStack2Top();
			}
		}
		else
		{
			char temp[] = { expression[i] };
			OPTD.Stack2Push(atoi(temp));
			cout << "OPTD:";
			OPTD.Stack2Show();
			i++;
		}		
	}
	return OPTD.GetStack2Top();
	
}