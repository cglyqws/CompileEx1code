#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
char stmp[1005];
char stack[1006];
char stackn[1006];
char topchar,topn;
int top;
int tempint;
int L;
int i;
int priority[110][110];
void initpriority()
{
	//1 > -1 < -2 Пе 2 =   
	priority['+']['+'] = 1;
	priority['+']['*'] = -1;
	priority['+']['i'] = -1;
	priority['+']['('] = -1;
	priority['+'][')'] = 1;
	
	priority['*']['+'] = 1;
	priority['*']['*'] = 1;
	priority['*']['i'] = -1;
	priority['*']['('] = -1;
	priority['*'][')'] = 1;
	
	priority['i']['+'] = 1;
	priority['i']['*'] = 1;
	priority['i']['i'] = -2;
	priority['i']['('] = -2;
	priority['i'][')'] = 1;
	
	priority['(']['+'] = -1;
	priority['(']['*'] = -1;
	priority['(']['i'] = -1;
	priority['(']['('] = -1;
	priority['('][')'] = 2;
	
	priority[')']['+'] = 1;
	priority[')']['*'] = 1;
	priority[')']['i'] = -2;
	priority[')']['('] = -2;
	priority[')'][')'] = 1;
	
	priority['#']['+'] = -1;
	priority['#']['*'] = -1;
	priority['#']['i'] = -1;
	priority['#']['('] = -1;
	priority['#'][')'] = -1;
	priority['#']['#'] = -3;
	
	priority[')']['#'] = 1;
	priority['i']['#'] = 1;
	priority['+']['#'] = 1;
	priority['*']['#'] = 1;
}
int main (int argc, char *argv[])
{
	initpriority();
	
	FILE *in = fopen(argv[1],"rt");	
	while  (fgets(stmp,1000,in))
	{
		for (i=0;;i++)
		{
			if (!top) topchar = '#';
			else topchar = stack[top-1];
			if (stmp[i]=='\r'||stmp[i] =='\n'||stmp[i]==0)
			{
				stmp[i] = '#';
			}
			switch (priority[topchar][stmp[i]])
			{
				case 1:
					while (priority[topchar][stmp[i]]==1)
					{
						if (topchar == 'i')
						{
							top--;
							stackn[topn++] = 'F';
							printf("R\n");
						}
						else if (topchar == '+')
						{
							if (topn+L+1-top>1)
							{
								topn--;
								top--;
								printf("R\n");
							}
							else {
								printf("RE\n");
								return 0;
							}
						}
						else if (topchar == '*')
						{
							if (topn+L+1-top>1)
							{
								topn--;
								top--;
								printf("R\n");
							}
							else {
								printf("RE\n");
								return 0;
							}
						}
						else if (topchar == ')')
						{
							top-=2;
							L--;
							printf("R\n");
						}
						if (!top) topchar = '#';
						else topchar = stack[top-1];
					}
					i--;
					break;
				case 2:
					stack[top++] = stmp[i];
					printf("I%c\n",stmp[i]);
					break;
				case -3:
					return 0;					
				case -1:
					stack[top++] = stmp[i];
					if (stmp[i]=='(') L++;
					printf("I%c\n",stmp[i]);
					break;
				case -2:
					printf("E\n");
					return 0;
				case 0:	
					printf("E\n");
					return 0;
			}
		}
		memset(stmp, 0, sizeof(stmp));
		memset(stack, 0,sizeof(stack));	
		top = 0;
	}
//	scanf("%s",stmp);

//	for (i=0;;i++)
//		{
//			if (!top) topchar = '#';
//			else topchar = stack[top-1];
//			if (stmp[i]=='\r'||stmp[i] ='\n'||stmp[i]==0)
//			{
//				stmp[i] = '#';
//			}
//			switch (priority[topchar][stmp[i]])
//			{
//				case 1:
//					while (priority[topchar][stmp[i]]==1)
//					{
//						if (topchar == 'i')
//						{
//							top--;
//							stackn[topn++] = 'F';
//							printf("R\n");
//						}
//						else if (topchar == '+')
//						{
//							if (topn+L+1-top>1)
//							{
//								topn--;
//								top--;
//								printf("R\n");
//							}
//							else {
//								printf("RE\n");
//								return 0;
//							}
//						}
//						else if (topchar == '*')
//						{
//							if (topn+L+1-top>1)
//							{
//								topn--;
//								top--;
//								printf("R\n");
//							}
//							else {
//								printf("RE\n");
//								return 0;
//							}
//						}
//						else if (topchar == ')')
//						{
//							top-=2;
//							L--;
//							printf("R\n");
//						}
//						if (!top) topchar = '#';
//						else topchar = stack[top-1];
//					}
//					i--;
//					break;
//				case 2:
//					stack[top++] = stmp[i];
//					printf("I%c\n",stmp[i]);
//					break;
//				case -3:
//					return 0;					
//				case -1:
//					stack[top++] = stmp[i];
//					if (stmp[i]=='(') L++;
//					printf("I%c\n",stmp[i]);
//					break;
//				case -2:
//					printf("E\n");
//					return 0;
//				case 0:	
//					printf("E\n");
//					return 0;
//			}
//		}
	
}
