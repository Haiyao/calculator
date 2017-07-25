#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>


const int n=30;
int s1[31]; //操作数栈
char s2[31]; //运算符栈
int t1,t2;
int num[4];  //提取表达式中的整数
char a[400];


typedef struct{ 
float rmz; 
float lmz; 
}complex; 





void main()
{
	int w,r,o,g,choice, l,u;
	float j,k;
	float rmz1,lmz1,rmz2,lmz2;
	char str[30],str1[30],str2[30];
	complex com1,com2,com3;



	int calculator(char *f);
	complex getAComplex(float a,float b);
	complex addComplex(complex complex1,complex complex2);
	complex subComplex(complex complex1,complex complex2);
	complex productComplex(complex complex1,complex complex2);
	complex divideComplex(complex complex1,complex complex2);
	float getComplexRmz(complex complex1);
	float getComplexLmz(complex complex1);
	void PrintCom(complex com1);
	void zifu(char str);



	printf("         集成121班  青岛科技大学   制作 2012.12.15  版本 bate1.0     学号。1208040101\n\n\n\n");
	printf("*************************\n");
	printf("1.实数运算\n");
	printf("2.复数运算\n");
	printf("3.字符串运算\n");
	printf("*************************\n");
	printf("选择的运算方式，输入选择数字回车");
	scanf("%d",&w);
	switch(w)
	{
	case 1:loop:printf("请输入你的运算公式，如：1*89-45，回车");
			scanf("%s",a);
			printf("%s=%d",a,calculator(a));
			printf("\n");
			printf("如果要进行求绝对值运算和开根号，请输入1.退出按任意键\n");
			scanf("%d",&r);
			
			if(r==1)
			{
				printf("绝对值1，开根号2，请选择，回车。退出按任意键。");
				scanf("%d",&o);
				if(o==1)
					{printf("请输入数字");
					 scanf("%f",&j);
					 k=fabs(j);
					 printf("%f",k);
					}
				else{ if(o==2)
					{
						 printf("请输入数字");
						 scanf("%f",&j);
						 k=sqrt(j);
						 printf("%f",k);
					
					}
				
				
				}
			 
			
			
			}
			printf("继续实数运算请按1,否则按任意键退出\n");


				
				scanf("%d",&g);
				if(g==1)
					goto loop;
			
					
			break;
	case 2:printf("1.求两个复数的和\t2.求两个复数的差\t3.求两个复数的积\n4.求两个复数的商\t5.分离出实部\t\t6.分离出虚部\t\t7.退出\n\n");
 
			 printf("输入第1个复数的实部和虚部,两数字之间用英文逗号间隔:");
			 scanf("%f,%f",&rmz1,&lmz1);
			 com1=getAComplex(rmz1,lmz1);
			 printf("所生成的复数1为:");
			 PrintCom(com1);
			 printf("输入第2个复数的实部和虚部,两数字之间用英文逗号间隔:");
			 scanf("%f,%f",&rmz2,&lmz2);
			 com2=getAComplex(rmz2,lmz2);
			 printf("所生成的复数2为:");
			 PrintCom(com2);
                    
			printf("输入你的选择:");
			scanf("%d",&choice);
			switch(choice)
		 {
			case 1:
				com3=addComplex(com1,com2);
				printf("两个复数的和为:");
				PrintCom(com3);
				break;
			case 2:
				com3=subComplex(com1,com2);
				printf("两个复数的差为：");
				PrintCom(com3);
			case 3:
				com3=productComplex(com1,com2);
				printf("两个复数的积为：");
				PrintCom(com3);
				break;
			case 4:
				com3=divideComplex(com1,com2);
				printf("两个复数的商是：");
				PrintCom(com3);
			case 5:
				printf("复数1的实部为:%7.2f\n",getComplexRmz(com1));  
				printf("复数2的实部为:%7.2f\n", getComplexRmz(com2));
				break;
			case 6:
				printf("复数1的虚部为:%7.2f\n",getComplexLmz(com1));  
				printf("复数2的虚部为:%7.2f\n",getComplexLmz(com2)); 
				break;
		

			case 7:
				break;
			default:
				printf("请输入1～6的数字!\n"); break;
			}  
			break;
	case 3:printf("请输入字符串，两个字符串中间用+号连接\n");
			scanf("%s",str);
			l=0;
			u=0;
			while(str[l]!='+')
			{
				
				str1[l]=str[l];
				l++;
			}
			
			str1[l]='\0';
			l=l++;
			while(str[l]!='\0')
			{
				str2[u]=str[l];
				l++;
				u++;
			}
			
			str2[u]='\0';
			printf("加的的字符串是  ：%s\n",strcat(str1,str2));

			
			break;
	default:printf("错误啊，1，2，3\n");
	}
}




void calcu() //一次计算
{
 int x1,x2,x;
 char p;
 //弹出一个运算符
 p=s2[t2--];
 //弹出两个操作数
 x2=s1[t1--];
 x1=s1[t1--];
 //进行一次运算
 switch(p) 
	{
		 case '+':x=x1+x2;break;
		 case '-':x=x1-x2;break;
		 case '*':x=x1*x2;break;
		 case '/':x=x1/x2;
	}
 //结果压入操作数栈
 s1[++t1]=x;
}



int calculator(char *f)
{
 int v,i=0;
 char *p=f;
 t1=t2=0;  //设置空栈
 while (*p!='\0')
 switch(*p) {
 case '+': case '-':
  while (t2&&(s2[t2]!='('))
  //执行先遇到的加、减、乘、除运算
  calcu();
  //当前运算符进栈
  s2[++t2]=*p;
  //读下一个字符
  p++;   
  break;
 case '*': case '/':
  if (t2&&(s2[t2]=='*')||(s2[t2]=='/'))
  //执行先遇到的乘、除运算
   calcu();
  //当前运算符进栈
  s2[++t2]=*p;
  //读下一个字符
  p++;
  break;
 case '(':
  //左括号进栈
  s2[++t2]=*p;
  //读下一个字符
  p++;
  break;
 case ')':
  while (s2[t2]!='(')
  //执行括号内的加、减、乘、除运算
   calcu();
  //弹出左括号
  t2--;
  //读下一个字符
  p++;
  break;
 default:
  //把字符串转换成整数值
  v=0;
  do {
   v=10*v+*p-'0';
   p++;
  } while((*p>='0')&&(*p<='9'));
  //操作数进栈
  s1[++t1]=v;
  num[i++]=v;
 };
 //执行先遇到的加、减、乘、除运算
 while (t2) calcu();
 //返回结果
 return s1[t1];
}


complex getAComplex(float a,float b){ 
 complex complex1;
 complex1.rmz=a; 
 complex1.lmz=b; 
 return complex1;
} //构造一个复数
 
complex addComplex(complex complex1,complex complex2) 
{ complex complex3;
 complex3.rmz=complex1.rmz+complex2.rmz; 
 complex3.lmz=complex1.lmz+complex2.lmz; 
 return complex3; 
} //两个复数求和
 
complex subComplex(complex complex1,complex complex2) 
{ 
 complex complex3;
 complex3.rmz=complex1.rmz-complex2.rmz; 
 complex3.lmz=complex1.lmz-complex2.lmz; 
 return complex3; 
} //求两个复数的差

complex productComplex(complex complex1,complex complex2) 
{ 
 complex complex3; 
 complex3.rmz=complex1.rmz*complex2.rmz+complex1.lmz*complex2.lmz; 
 complex3.lmz=complex1.lmz*complex2.rmz+complex2.lmz*complex2.rmz; 
 return complex3;
} //求两个复数的积 

complex divideComplex(complex complex1,complex complex2)
{
	complex complex3;
	complex3.rmz=complex1.rmz/complex2.rmz+complex1.lmz/complex2.lmz;
	complex3.lmz=complex1.lmz/complex2.rmz+complex1.lmz/complex2.rmz;
	return complex3;
}

float getComplexRmz(complex complex1) 
{ 
 return complex1.rmz; 
} //分离出实部

float getComplexLmz(complex complex1) 
{ 
 return complex1.lmz; 
} //分离出虚部

void PrintCom(complex com1)
{
 if(com1.rmz>0||com1.lmz==0)   
 {
  if(com1.rmz!=0&&com1.lmz!=0)
   printf("%7.2f+i%7.2f\n",com1.rmz,com1.lmz);     
  else if(com1.rmz==0&&com1.lmz!=0) 
   printf("i%7.2f\n",com1.lmz);
  else if(com1.rmz!=0&&com1.lmz==0)
   printf("%7.2f\n",com1.rmz);     
  else if(com1.rmz==0&&com1.lmz==0)
   printf("%7.2f\n",com1.rmz);
 }
 else
 {printf("%7.2f\n",com1.rmz);
 if(com1.rmz==0&&com1.lmz==0)
   printf("%7.2f\n",com1.rmz);
 }
 //打印复数
}


