//输入：一个数组
//输出：找一个子集，子集和能被7整除，且子集和最大,输出这个子集和 
//目前还有边缘条件没有涉及到：如1 1 1 1 1 2，是否还有其他边缘条件还不清楚 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000 

//全局变量 
int min_1_6;//min_1_6=min{number_of_same_rem[1]，number_of_same_rem[6]} 
int min_2_5;//min_2_5=min{number_of_same_rem[1]，number_of_same_rem[6]}  
int min_3_4;//min_3_4=min{number_of_same_rem[1]，number_of_same_rem[6]}  
int sum=0;//子集和 
int array[MAX]={0};//初始数组 
int rem[MAX]={0};//余数数组 
int number_of_same_rem[7]={0};//相同余数的元素个数(余数为0，1，2，3，4，5，6，故数组大小为7)
int transfer[MAX]={0};//中间过渡数组

//函数声明 
void initial();//初始化
void remainder();//求余数相同的元数个数 
int min(int x,int y);//找较小数
int sort(int a[MAX]);//冒泡排序
int sum_of_part(int x,int y);//算法关键一步（由龟哥提供思路） 

//主函数 
int main(void)
{
	initial();//输入数组初始化 
	 
	remainder();//求余数 
	
	
	//先找出能整除7（且不为0，这里不加判断是否为0的条件会有bug，但具体原因还不太清楚）的元素 
	for(int i=0;i<MAX;i++)
	{
		if(rem[i]==0&&array[i]!=0)
		{
			sum=+array[i];
		}
	}
	
	//找出对应余数相加为7的元素，比较这些元素个数的多少，个数多的一部分进行排序，选择较大的那一部分 
	int min_1_6=min(number_of_same_rem[1],number_of_same_rem[6]);
	int min_2_5=min(number_of_same_rem[2],number_of_same_rem[5]);
	int min_3_4=min(number_of_same_rem[3],number_of_same_rem[4]);
	
	if(min_1_6!=0)//若为0，则表示没有相匹配的元素，如有余数为1但没有余数为6的元素，以下同理 
	{
		if(number_of_same_rem[1]>=number_of_same_rem[6])
		{   
		    sum_of_part(1,min_1_6);
	    }
	    if(number_of_same_rem[6]>number_of_same_rem[1])
	    {
	    	sum_of_part(6,min_1_6);
		}
	}
	if(min_2_5!=0)
	{
		if(number_of_same_rem[2]>=number_of_same_rem[5])
		{   
		    sum_of_part(2,min_2_5);
	    }
	    if(number_of_same_rem[5]>number_of_same_rem[2])
	    {
	    	sum_of_part(5,min_2_5);
		}
	}
	if(min_3_4!=0)
	{
		if(number_of_same_rem[3]>=number_of_same_rem[4])
		{   
		    sum_of_part(3,min_3_4);
	    }
	    if(number_of_same_rem[4]>number_of_same_rem[3])
	    {
	    	sum_of_part(4,min_3_4);
		}
	}
	
	printf("子集和为%d\n",sum);

    /* 
	//测试
	 for(int i=0;i<5;i++)
	{
		printf("%d",transfer[i]);
	}
	printf("\n");
	for(int i=0;i<7;i++)
	{
		printf("%d",number_of_same_rem[i]);
	}
		printf("\n");
    */ 
	
	return 0;
} 

//初始化 
void initial()
{
	for(int i=0;i<MAX;i++)
	{
		scanf("%d",&array[i]);
		if(getchar()=='\n')//用户最多输入MAX个数，通过回车来结束输入 
		{
			break;
		}
	}
}

//求余数相同的元数个数
void remainder()
{
	 for(int i=0;i<MAX;i++)
	{
		rem[i]=array[i]%7;
		
		switch(rem[i])
		{
			case 1:
				number_of_same_rem[1]++;break;
			case 2:
				number_of_same_rem[2]++;break;
			case 3:
				number_of_same_rem[3]++;break;
			case 4:
				number_of_same_rem[4]++;break;
			case 5:
				number_of_same_rem[5]++;break;
			case 6:
				number_of_same_rem[6]++;break;
		}		
	} 
}

//找较小数 
int min(int x,int y)
{
	if(x<=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

//冒泡排序 
int sort(int a[MAX])
{
	int t;
	
	for(int i=0;i<MAX;i++)//变量i代表比较的趟数
    {
    	for(int j=0;j<MAX-i;j++)//变量j代表每趟两两比较的次数
        { 
		    if(a[j]<a[j+1])//较大数排在前面 
            {
                t=a[j];    //利用中间变量实现两值互换
                a[j]=a[j+1];
                a[j+1]=t;
	        }
	    } 
    }
}

//算法关键一步:找出对应余数相加为7的元素，比较这些元素个数的多少，个数多的一部分进行排序，选择较大的那一部分 
int sum_of_part(int x,int y)
{
	int j=0;
	for(int i=0;i<MAX;i++)
	{
		if(rem[i]==7-x)
		{
			sum+=array[i];
		}
				
		if(rem[i]==x)
		{
			transfer[j]=array[i];
			j++;
		}
	}
	
	sort(transfer);//对中间过渡数组排序，较大数在前 
	
	for(int j=0;j<y;j++)
	{
		sum+=transfer[j];
	}		
}
