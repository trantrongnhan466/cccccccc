#include<stdio.h>
#include<stdlib.h>
void Nhap(int &a, int &b)
{
	printf("\nNhap a: ");
	scanf("%d",&a);
	printf("\nNhap b: ");
	scanf("%d",&b);
}
int cong(int a, int b)
{
	return a+b;
}
int tru(int a, int b)
{
	return a-b;
}
int nhan(int a, int b)
{
	return a*b;
}
int chia(int a, int b)
{
	return a/b;
}
void Menu(int a, int b)
{
	int luachon;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t=========MENU=========");
		printf("\n1.Nhap hai so nguyen a va b");
		printf("\n2. a+b");
		printf("\n3. a-b");
		printf("\n4. a/b");
		printf("\n5. a*b");
		printf("\n0.Thoat");
		printf("\nMoi nhap lua chon: ");
		scanf("%d",&luachon);
		switch(luachon)
		{
			case 1:
				{
					Nhap(a,b);
					break;
				}
			case 2:
				{
					printf("\nTong la %d",cong(a,b));
					system("pause");
					break;
				}
			case 3:
				{
					printf("\nHieu la %d",tru(a,b));
					system("pause");
					break;
				}
			case 4:
			    {
				    printf("\nThuong la %d",chia(a,b));
				    system("pause");
				    break;
				}	
			case 5:
			   {
			   	printf("\nTich la %d",nhan(a,b));
			   	system("pause");
			   	break;
				   } 
			case 0:
			{
				break;
						}	    	
			default:
			{
	            printf("\nKhong hop le");
	            
				   }	   
		}
		if(luachon==0)
		{
			break;
		}
	}
}
int main()
{
	int a,b;
	Menu(a,b);
}

