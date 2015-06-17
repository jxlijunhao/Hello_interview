//����ÿ��Byte����8��Bitλ  
#include<stdio.h>
#include<memory.h>  
#define BYTESIZE 8  

void SetBit(char *p, int posi)  
{  
	for(int i=0; i<(posi/BYTESIZE); i++)    
		p++;   
	*p = *p|(0x01<<(posi%BYTESIZE));//����Bitλ��ֵ1  
	return;  
}  

void BitMapSortDemo()  
{  
	//Ϊ�˼���������ǲ����Ǹ���  
	int num[] = {3,5,2,10,6,12,8,14,9};  

	//BufferLen���ֵ�Ǹ��ݴ���������������ֵȷ����  
	//�������е����ֵ��14�����ֻ��Ҫ2��Bytes(16��Bit)  
	//�Ϳ����ˡ�  
	const int BufferLen = 2;  
	char *pBuffer = new char[BufferLen];  

	//Ҫ�����е�Bitλ��Ϊ0������������Ԥ֪��  
	memset(pBuffer,0,BufferLen);  
	for(int i=0;i<9;i++)  	
		SetBit(pBuffer,num[i]);   //���Ƚ���ӦBitλ����Ϊ1  
		

	//���������  
	for(int i=0;i<BufferLen;i++)//ÿ�δ���һ���ֽ�(Byte)  
	{  
		for(int j=0;j<BYTESIZE;j++)//������ֽ��е�ÿ��Bitλ  
		{  
			//�жϸ�λ���Ƿ���1�����������������жϱȽϱ���  
			//���ȵõ��õ�jλ�����루0x01����j�������ڴ����е�  
			//λ�ʹ������������������ж������Ƿ�ʹ�����  
			//�����ͬ  
			if((*pBuffer&(0x01<<j)) == (0x01<<j))  
				printf("%d ",i*BYTESIZE + j);  
		}  
		pBuffer++;  
	}  
}  

//int main()  
//{  
//	BitMapSortDemo();  
//	return 0;  
//}  