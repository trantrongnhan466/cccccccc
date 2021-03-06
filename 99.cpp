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
bool KtNt(int);
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
bool KtNt(int a)
{
	if(a<2)
	{
		return false;
	}
	else
	{
		for(int i=2; i<=a/2;i++)
		{
			if(a%i==0)
			{
				return false;
			}
		}
	}
	return true;
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
    	switch(luachon)
    	{
    		case 'a':
         	{
    	    	Nhap(a,n);
    	    	break;
	    	}
		    case 'b':
	    	{
		    	Xuat(a,n);
		    	system("pause");
		    		break;
	    	}
		    case 'c':
	    	{
		     	printf("\nPhan tu nho nhat va lon nhat lan luot la: %d va %d",Min(a,n),Max(a,n));
		    	system("pause");
		    		break;
	    	}
	        case 'd':
	    	{
		    	LkChanLe(a,n);
		    	system("pause");
		    		break;
	    	}
        	 case 'e':
	    	{
			TimX(a,n);
			system("pause");
				break;
	    	}
        	 case 'f':
	    	{
		    	TimVtX(a,n);
		    	system("pause");
		    		break;
	    	}
	      case 'h':
		{
			SapXepTang(a,n);
			Xuat(a,n);
			system("pause");
				break;
			
		}
     	 case 'g':
		{
			TimVaDemNt(a,n);
			system("pause");
				break;
		}
     	 case 27:
		{
			break;
		}
	default:
		{
			printf("\nLua chon cua ban khong hop le ! ");
			system("pause");
		}
		}
		if(luachon==27)
		{
			break;
		}
    
	}
	
}
