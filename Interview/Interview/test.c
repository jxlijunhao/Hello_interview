//#include<stdio.h>
//#define DF(a,b)  (a+2*b) 

//int fun(int x)
//{
//	return (x<3?1:(fun(x-1)+2*fun(x-2)));
//}
//int main()
//{
//	printf("%d",fun(4)+fun(5));
//}
////void main()
////{
////	int s=5;
////	int k= DF(s+1,s-3);
////	printf("%d",k);
////}


//int x, y, z, w;
//void p(int *y, int x)
//{
//	static int w;
//	*y++; x++; w = x+*--y;
//	printf("%d#%d#%d#%d#",x,*y,z,w);
//}
//int main(void)
//{
//	int x, y, z, w;
//	x=y=z=w=1;
//	do{
//		static int x;
//		p(&x, y);
//		printf("%d#%d#%d#%d#",x,y,z,w);
//	} while(0);
//	return 0;
//}
//#define  F1(var)  printf("var=%d", var)
//#define  F0(var)  F1(var * var)
//
//void main()
//{
//	int a =F0(3+4);
//	printf("%d\n",a);
//}

//int main(int argc, char** argv)
//{
//	while(**argv++!='a');
//	printf("%s", *argv);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//union
//{
//	int i;
//	char x[2];
//}a;
//
//void main()
//{	 
//	a.x[0] =10; 
//    a.x[1] =1;
//	printf("%d",a.i);
//}

