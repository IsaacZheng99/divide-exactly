//���룺һ������
//�������һ���Ӽ����Ӽ����ܱ�7���������Ӽ������,�������Ӽ��� 
//Ŀǰ���б�Ե����û���漰������1 1 1 1 1 2���Ƿ���������Ե����������� 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000 

//ȫ�ֱ��� 
int min_1_6;//min_1_6=min{number_of_same_rem[1]��number_of_same_rem[6]} 
int min_2_5;//min_2_5=min{number_of_same_rem[1]��number_of_same_rem[6]}  
int min_3_4;//min_3_4=min{number_of_same_rem[1]��number_of_same_rem[6]}  
int sum=0;//�Ӽ��� 
int array[MAX]={0};//��ʼ���� 
int rem[MAX]={0};//�������� 
int number_of_same_rem[7]={0};//��ͬ������Ԫ�ظ���(����Ϊ0��1��2��3��4��5��6���������СΪ7)
int transfer[MAX]={0};//�м��������

//�������� 
void initial();//��ʼ��
void remainder();//��������ͬ��Ԫ������ 
int min(int x,int y);//�ҽ�С��
int sort(int a[MAX]);//ð������
int sum_of_part(int x,int y);//�㷨�ؼ�һ�����ɹ���ṩ˼·�� 

//������ 
int main(void)
{
	initial();//���������ʼ�� 
	 
	remainder();//������ 
	
	
	//���ҳ�������7���Ҳ�Ϊ0�����ﲻ���ж��Ƿ�Ϊ0����������bug��������ԭ�򻹲�̫�������Ԫ�� 
	for(int i=0;i<MAX;i++)
	{
		if(rem[i]==0&&array[i]!=0)
		{
			sum=+array[i];
		}
	}
	
	//�ҳ���Ӧ�������Ϊ7��Ԫ�أ��Ƚ���ЩԪ�ظ����Ķ��٣��������һ���ֽ�������ѡ��ϴ����һ���� 
	int min_1_6=min(number_of_same_rem[1],number_of_same_rem[6]);
	int min_2_5=min(number_of_same_rem[2],number_of_same_rem[5]);
	int min_3_4=min(number_of_same_rem[3],number_of_same_rem[4]);
	
	if(min_1_6!=0)//��Ϊ0�����ʾû����ƥ���Ԫ�أ���������Ϊ1��û������Ϊ6��Ԫ�أ�����ͬ�� 
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
	
	printf("�Ӽ���Ϊ%d\n",sum);

    /* 
	//����
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

//��ʼ�� 
void initial()
{
	for(int i=0;i<MAX;i++)
	{
		scanf("%d",&array[i]);
		if(getchar()=='\n')//�û��������MAX������ͨ���س����������� 
		{
			break;
		}
	}
}

//��������ͬ��Ԫ������
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

//�ҽ�С�� 
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

//ð������ 
int sort(int a[MAX])
{
	int t;
	
	for(int i=0;i<MAX;i++)//����i����Ƚϵ�����
    {
    	for(int j=0;j<MAX-i;j++)//����j����ÿ�������ȽϵĴ���
        { 
		    if(a[j]<a[j+1])//�ϴ�������ǰ�� 
            {
                t=a[j];    //�����м����ʵ����ֵ����
                a[j]=a[j+1];
                a[j+1]=t;
	        }
	    } 
    }
}

//�㷨�ؼ�һ��:�ҳ���Ӧ�������Ϊ7��Ԫ�أ��Ƚ���ЩԪ�ظ����Ķ��٣��������һ���ֽ�������ѡ��ϴ����һ���� 
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
	
	sort(transfer);//���м�����������򣬽ϴ�����ǰ 
	
	for(int j=0;j<y;j++)
	{
		sum+=transfer[j];
	}		
}
