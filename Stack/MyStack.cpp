#include "MyStack.h"

char Percede(char a, char b)
{
	// ������������ȼ�����i�У������j�У��ң��Ƚ�
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
	MyStack2<AppDataType> OPTD;          // ��Ų�������ջ
	MyStack2<char> OPTR;                 // ��Ų�������ջ

	int len = expression.length();
	// �ж�������ʽ�Ƿ���ȷ
	if ((expression[0] != '#') && (expression[len - 1] != '#'))
	{
		cout << "Error Expression!" << endl;
		return AppDataType(-12138);
	}
	// ���ʽ�������
	// #���������ջ
	OPTR.Stack2Push(expression[0]);
	for (int i = 1; i < len ; )
	{
		cout << "��λ��Ԫ�أ�"<< expression[i] << endl;
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