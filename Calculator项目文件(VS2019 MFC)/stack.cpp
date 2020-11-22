//求简单表达式的值
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "pch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MaxSize 100

class ErrorControl{
public:
	bool judge(char* exp) {
		int numOfSymbol = 0;//输入的双目运算符数
		int numOfNum = 0;//输入的数字个数非数字字符个数
		int numOfOpenparen = 0;//输入的左括号数
		int numOfCloseparen = 0;//输入的右括号数
		for (int i = 0; exp[i] != '\0'; i++) {
			if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
			{	//统计输入的双目运算符数
				numOfSymbol++;
			}
			else if ((exp[i] >= '0' && exp[i] <= '9'|| exp[i] == 'P')&&!(exp[i-1] >= '0' && exp[i-1] <= '9' || exp[i-1] == 'P' ||exp[i-1] == '.'))
			{	//统计输入的数字个数非数字字符个数
				numOfNum++;
			}
			else if (exp[i] == '(')
			{	//统计输入的左括号数
				numOfOpenparen++;
			}
			else if (exp[i] == ')')
			{	//统计输入的右括号数
				numOfCloseparen++;
			}
		}
		if (numOfSymbol + 1 != numOfNum|| numOfOpenparen != numOfCloseparen)
			return false;//如果输入的不符合规范，则返回false，告知此表达式错误，无法计算
		else
			return true;//如果输入的符合规范，则返回ture，告知此表达式正确，可计算
	}
};

//---------------------------------------------------------
//--运算符栈基本运算---------------------------------------
//---------------------------------------------------------
typedef struct
{
	char data[MaxSize];			//存放运算符
	int top;					//栈顶指针
} SqStack;
class Postexp {
public:
	void InitStack(SqStack*& s)		//初始化栈
	{
		s = (SqStack*)malloc(sizeof(SqStack));
		s->top = -1;
	}
	void DestroyStack(SqStack*& s)	//销毁栈
	{
		free(s);
	}
	bool StackEmpty(SqStack* s)		//判断栈是否为空
	{
		return(s->top == -1);
	}
	bool Push(SqStack*& s, char e)	//进栈元素e
	{
		if (s->top == MaxSize - 1)
			return false;
		s->top++;
		s->data[s->top] = e;
		return true;
	}
	bool Pop(SqStack*& s, char& e)	//出栈元素e
	{
		if (s->top == -1)
			return false;
		e = s->data[s->top];
		s->top--;
		return true;
	}
	bool GetTop(SqStack* s, char& e)	//取栈顶元素e
	{
		if (s->top == -1)
			return false;
		e = s->data[s->top];
		return true;
	}
	//---------------------------------------------------------

	void trans(char* exp, char postexp[])	//将算术表达式exp转换成后缀表达式postexp
	{
		char e;
		SqStack* Optr;						//定义运算符栈
		InitStack(Optr);					//初始化运算符栈
		int i = 0;							//i作为postexp的下标
		while (*exp != '\0')					//exp表达式未扫描完时循环
		{
			switch (*exp)
			{
			case '(':						//判定为左括号
				Push(Optr, '(');				//左括号进栈
				exp++;						//继续扫描其他字符
				break;
			case ')':						//判定为右括号
				Pop(Optr, e);				//出栈元素e
				while (e != '(')				//不为'('时循环
				{
					postexp[i++] = e;			//将e存放到postexp中
					Pop(Optr, e);			//继续出栈元素e
				}
				exp++;						//继续扫描其他字符
				break;
			case '+':						//判定为加或减号
			case '-':
				while (!StackEmpty(Optr))	//栈不空循环
				{
					GetTop(Optr, e);			//取栈顶元素e
					if (e != '(')				//e不是'('
					{
						postexp[i++] = e;		//将e存放到postexp中
						Pop(Optr, e);		//出栈元素e
					}
					else					//e是'(时退出循环
						break;
				}
				Push(Optr, *exp);			//将'+'或'-'进栈
				exp++;						//继续扫描其他字符
				break;
			case '*':						//判定为'*'或'/'号
			case '/':
				while (!StackEmpty(Optr))	//栈不空循环
				{
					GetTop(Optr, e);			//取栈顶元素e
					if(!(e=='(' || e=='+' || e=='-'))//将栈顶'*'或'/'运算符出栈并存放到postexp中
					{
						postexp[i++] = e;		//将e存放到postexp中
						Pop(Optr, e);		//出栈元素e
					}
					else					//e为非'*'或'/'运算符时退出循环
						break;
				}
				Push(Optr, *exp);			//将'*'或'/'进栈
				exp++;						//继续扫描其他字符
				break;
			case '^':
			case '!':
			case 'S':                        //开根号√以S替代
				while (!StackEmpty(Optr))	//栈不空循环
				{
					GetTop(Optr, e);			//取栈顶元素e
					if (e == '^' || e == '!' || e == 'S' )	//将栈顶'^'或'!'或'√'运算符出栈并存放到postexp中
					{
						postexp[i++] = e;		//将e存放到postexp中
						Pop(Optr, e);		//出栈元素e
					}
					else					//e为非'^'或'!'或'√'运算符时退出循环
						break;
				}
				Push(Optr, *exp);			//将'^'或'!'或'√'进栈
				exp++;						//继续扫描其他字符
				break;
			default:				//处理数字字符
				while (*exp >= '0' && *exp <= '9' || *exp == 'P'||*exp=='.') //判定为数字
				{

					postexp[i++] = *exp;
					exp++;
				}
				postexp[i++] = '#';	//用#标识一个数值串结束
			}
		}
		while (!StackEmpty(Optr))	//此时exp扫描完毕,栈不空时循环
		{
			Pop(Optr, e);			//出栈元素e
			postexp[i++] = e;			//将e存放到postexp中
		}
		postexp[i] = '\0';			//给postexp表达式添加结束标识
		DestroyStack(Optr);			//销毁栈		
	}
};

//---------------------------------------------------------
//--操作数栈基本运算---------------------------------------
//---------------------------------------------------------
typedef struct
{
	double data[MaxSize];			//存放数值
	int top;						//栈顶指针
} SqStack1;
class Compvalue {
public:
	void InitStack1(SqStack1*& s)		//初始化栈
	{
		s = (SqStack1*)malloc(sizeof(SqStack1));
		s->top = -1;
	}
	void DestroyStack1(SqStack1*& s)	//销毁栈
	{
		free(s);
	}
	bool StackEmpty1(SqStack1* s)		//判断栈是否为空
	{
		return(s->top == -1);
	}
	bool Push1(SqStack1*& s, double e)	//进栈元素e
	{
		if (s->top == MaxSize - 1)
			return false;
		s->top++;
		s->data[s->top] = e;
		return true;
	}
	bool Pop1(SqStack1*& s, double& e)	//出栈元素e
	{
		if (s->top == -1)
			return false;
		e = s->data[s->top];
		s->top--;
		return true;
	}
	bool GetTop1(SqStack1* s, double& e)	//取栈顶元素e
	{
		if (s->top == -1)
			return false;
		e = s->data[s->top];
		return true;
	}
	//---------------------------------------------------------

	CString compvalue(char* postexp)	//计算后缀表达式的值
	{
		CString s;
		bool arrivePoint;            //判断输入数值时是否为小数，即是否遇到小数点
		int numOfPointRight;         //累加数，计算小数点右边有几位
		double pointLeft,pointRight,a, b, c, e;//pointLeft浮点数整数部分数值,pointRight浮点数小数部分数值
		SqStack1* Opnd;				//定义操作数栈
		InitStack1(Opnd);			//初始化操作数栈
		while (*postexp != '\0')		//postexp字符串未扫描完时循环
		{
			switch (*postexp)
			{
			case '+':				//判定为'+'号
				Pop1(Opnd, a);		//出栈元素a
				Pop1(Opnd, b);		//出栈元素b
				c = b + a;				//计算c
				Push1(Opnd, c);		//将计算结果c进栈
				break;
			case '-':				//判定为'-'号
				Pop1(Opnd, a);		//出栈元素a
				Pop1(Opnd, b);		//出栈元素b
				c = b - a;				//计算c
				Push1(Opnd, c);		//将计算结果c进栈
				break;
			case '*':				//判定为'*'号
				Pop1(Opnd, a);		//出栈元素a
				Pop1(Opnd, b);		//出栈元素b
				c = b * a;				//计算c
				Push1(Opnd, c);		//将计算结果c进栈
				break;
			case '^':				//判定为'^'号
				Pop1(Opnd, a);		//出栈元素a
				Pop1(Opnd, b);		//出栈元素b
				c = pow(b, a);			//计算c
				Push1(Opnd, c);	//将计算结果c进栈
				break;
			case 'S':				//判定为'√'号
				Pop1(Opnd, a);		//出栈元素a
				c = sqrt(a);			//计算c
				Push1(Opnd, c);	//将计算结果c进栈
				break;
			case '!':				//判定为'!'号
				Pop1(Opnd, a);		//出栈元素a
				c = 1;
				if (a != 0) {
					if (a - (int)a == 0)
						for (int i = 1; i <= a; i++)
							c = c * i;      //计算c
					else                   //当阶乘数值不为整数时显示错误
					{
						s = "错误";      //显示出错
						DestroyStack1(Opnd);		//销毁栈
						return s;
					}
				}
				Push1(Opnd, c);	//将计算结果c进栈
				break;
			case '/':				//判定为'/'号
				Pop1(Opnd, a);		//出栈元素a
				Pop1(Opnd, b);		//出栈元素b
				if (a != 0)
				{
					c = b / a;			//计算c
					Push1(Opnd, c);	//将计算结果c进栈
					break;
				}
				else
				{
					s = "错误";      //显示出错
					DestroyStack1(Opnd);		//销毁栈
					return s;
				}
				break;
			default:				//处理数字字符
				pointLeft = 0;				//将连续的数字字符转换成对应的数值存放到d中
				pointRight = 0;
				numOfPointRight = 0;
				arrivePoint = false;
				while (*postexp >= '0' && *postexp <= '9' || *postexp == 'P'||*postexp=='.')   //判定为数字字符
				{
					if (*postexp == 'P')   //判断是否输入的为π
					{
						pointLeft = 3.1415926535897;
						postexp++;
					}
					else
					{
						if (*postexp != '.'&& !arrivePoint) {           //计算小数点左边的数值大小
							pointLeft = 10 * pointLeft + *postexp - '0';
							postexp++;
						}
						else if (*postexp == '.')      //检测到小数点
						{
							arrivePoint = true;
							postexp++;
						}
						else                          //计算小数点右边数值大小
						{
							numOfPointRight++;        //计算小数点右边位数
							pointRight = pointRight + (*postexp - '0')*pow(0.1,numOfPointRight);
							postexp++;
						}
					}
					c = pointLeft + pointRight;     //小数点左右数值相加，计算总数值
				}
				Push1(Opnd, c);		//将数值c进栈
				break;
			}
			postexp++;				//继续处理其他字符
		}
		GetTop1(Opnd, e);			//取栈顶元素e
		DestroyStack1(Opnd);		//销毁栈
		s.Format(_T("%lf"), e);		//将double的e转成CString的s
		return s;					//返回s
	}
};