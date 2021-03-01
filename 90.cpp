#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100
void Nhap(int , int);
void Xuat(int , int);
int Max(int , int );
int Min(int , int);
void LkChanLe(int , int);
void TimX(int , int);
void TimVtX(int , int);
void SapXepTang(int , int);
int KtNt(int);
void TimVaDemNt(int, int);
void Menu();
int main()
{
	Menu();
}

void Nhap(int a[], int &n)
{
	do
	{
		printf("\nNhap so luong phan tu:  ");
		scanf("%d",&n);
		if(n>MAX||n<1)
		{
			printf("\nSo luong phan tu khong hop le: ");
		}
	}while(n>MAX||n<1);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\na[%d]: %d",i,a[i]);
	}
}
int Max(int a[], int n)
{
	int max=a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
int Min(int a[], int n)
{
	int min=a[0];
	for(int i=0; i<n; i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	return min;
}
void LkChanLe(int a[], int n)
{
	printf("\nNhung so chan trong day:");
	for(int i=0; i<n; i++)
	{
		if(a[i]%2==0)
		{
			printf("\n%d",a[i]);
		}
	}
	printf("\nNhung so le trong day:");
	for(int i=0; i<n; i++)
	{
		if(a[i]%2!=0)
		{
			printf("\n%d",a[i]);
		}
	}
}
void TimX(int a[], int n)
{
	int x;
	printf("\nNhap X: ");
	scanf("%d",&x);
	for(int i=0; i<n; i++)
	{
		if(a[i]==x)
		{
			printf("\nPhan tu a[%d] co gia tri bang x",i);
		}
	}
}
void TimVtX(int a[], int n)
{
	int x;
	printf("\nNhap x: ");
	scanf("%d",&x);
	for(int i=0; i<n; i++)
	{
		if(a[i]==x)
		{
			printf("\nphan tu a[%d] co gia tri %d nam o vi tri thu %d trong mang vua nhap ",i,x,i+1);
		}
	}
}
void SapXepTang(int a[], int n)
{
	for(int i=0; i<n-1 ; i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}
	
}
int KtNt(int a)
{
	if(a<2)
	{
		return 0;
	}
	else
	{
		for(int i=2; i<=a/2;i++)
		{
			if(a%i==0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void TimVaDemNt(int a[], int n)
{
	int dem=0;
	printf("\nCac so ngyen to: ");
	for(int i=0; i<n; i++)
	{
		if(KtNt(a[i]))
		{
			printf("\n%d",a[i]);
			dem++;
		}
	}
	printf("\nCo %d so nguyen to",dem);
}
void Menu()
{
	int a[MAX],n;
	char luachon;
	while(true)
	{
		system("cls");
		printf("\n\n\t\t=========MENU=========");
    	printf("\na. Nhap mang 1 chieu");
	    printf("\nb. Xuat mang 1 chieu");
    	printf("\nc. Tim phan tu nho nhat, lon nhat trong mang mot chieu");
    	printf("\nd. Liet ke chan le ");
    	printf("\ne. Tim phan tu co gia tri x nam trong mang vua nhap");
    	printf("\nf. Tim vi tri phan tu co gia tri bang x");
    	printf("\ng. Sap xep tang mang vua nhap");
    	printf("\nh. Tim va dem so nguyen to trong mang");
    	printf("\nESC: THOAT");
    	printf("\nBan chon: ");
    	luachon = getch();
    	if(luachon =='a')
    	{
    		Nhap(a,n);
		}
		else if (luachon == 'b')
		{
			Xuat(a,n);
			system("pause");
		}
		else if(luachon == 'c')
		{
			printf("\nPhan tu nho nhat va lon nhat lan luot la: %d va %d",Min(a,n),Max(a,n));
			system("pause");
		}
		else if(luachon == 'd')
		{
			LkChanLe(a,n);
			system("pause");
		}
		else if(luachon == 'e')
		{
			TimX(a,n);
			system("pause");
		}
		else if(luachon =='f')
		{
			TimVtX(a,n);
			system("pause");
		}
		else if(luachon == 'g')
		{
			SapXepTang(a,n);
			Xuat(a,n);
			system("pause");
			
		}
		else if(luachon == 'h')
		{
			TimVaDemNt(a,n);
			system("pause");
		}
		else if(luachon == 27)
		{
			break;
		}
		else
		{
			printf("\nLua chon cua ban khong hop le ! ");
			system("pause");
		}
	}
	
}
