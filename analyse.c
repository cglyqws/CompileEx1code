#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
char stmp[1005];
char stack1[500];
char stack2[500];
int top1,top2;
int tempint;
int i;
int priority[105][105];
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
}
int main (int argc, char *argv[])
{
	initpriority();
	
	FILE *in = fopen(argv[1],"rt");
	
	int size = sizeof(stmp) ;
		
	while  (fgets(stmp,1000,in))
	{
		for (i=0;stmp[i]!='\r'&&stmp[i]!='\n';i++)
		{
			if (stmp[i] == 'i')
			{
				stack1[top1++] = 'i';
				printf("Ii\n");
				continue;
			}
			else 
			{
				switch (priority[stack2[top2-1]][stmp[i]])
				{
					case 1:
						while (priority[stack2[top2-1]][stmp[i]]==1)
						{
							if (top1>1)
							{
								top1--;
								top2--;
								printf("R\n");
								if (!top2) break;
							}
							else 
							{
								printf("RE\n");
								return 0;
							}
						}
						break;
					case 2:
						top2--;
						break;
					case -1:
						stack2[top2++] = stmp[i];
						printf("I%c\n",stmp[i]);
						break;
					case -2:
						printf("E\n");
						return 0;
				}
			}
			
		}
		

		memset(stmp, 0, sizeof(stmp));
		memset(stack1, 0,sizeof(stack1));
		memset(stack2, 0,sizeof(stack2));
		top1 = 0;
		top2 = 0;
	}
	
}
