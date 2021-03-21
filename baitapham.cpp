#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void Nhap(int *&a, int &n)
{
	do
	{
		printf("\nNhap so luong phan tu: ");
	    scanf("%d",&n);
	    if(n<=0)
	    {
	    	printf("\nSo luong phan tu phai lon hon 0");
		}
	}while(n<=0);
	a = (int *)malloc(n*sizeof(int));
	for(int i = 0; i<n; i++)
	{
		printf("\nNhap a[%d]: ",i);
		scanf("%d",(a+i));
	}
}
void Xuat(int *a, int n)
{
	printf("\nCac phan tu cua mang la: ");
	for(int i=0; i<n; i++)
	{
		printf("\na[%d]: %d",i,*(a+i));
	}
}
int TinhTong(int *a, int &n)
{
	int s=0;
	for(int i=0; i<n; i++)
	{
		s = s + *(a+i);
	}
	return s;
}
int TimSoAm(int *a, int n)
{
	int max, max2,dem=0;
	for(int i=0; i<n; i++)
	{
		if(*(a+i)<0)
		dem++;
	}
	if(dem<=1)
	 return 1;
	for(int i=0; i<n ;i++)
	{
		if(a[i]<0)
		{
			max= a[i];
			break;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(a[i]>max && a[i]<0)
		max = a[i];
	}
    	for(int i=0; i<n ;i++)
	{
		if(a[i]<0 && a[i] != max)
		{
			max2= a[i];
			break;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(a[i]>max2 && a[i]<0 && a[i] != max )
		max2 = a[i];
	}
	return max2;
}
bool Ktnt(int x)
{
	if(x<2)
	{
		return false;
	}
	for(int i = 2; i<= x/2; i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
void LietKeVaDemSoNt(int *a, int n)
{
	int dem=0;
	for(int i=0; i<n; i++)
	{
		if(Ktnt(*(a+i)))
		{
			dem++;
		}
	}
	if(dem>0)
	{
		printf("\nCac so nguyen to trong day la:");
		for(int i=0; i<n; i++)
     	{
		    if(Ktnt(*(a+i)))
		    {
		    	printf("\n%d ",*(a+i));
		    }
	    }
	    printf("\nVay co %d so nguyen to trong day",dem);
	}
	else
	{
		printf("\nKhong co so nguyen to nao trong day!");
	}
}
void XuatDayDaoNguoc(int *a, int n)
{
	printf("\nCac phan tu cua mang in dao nguoc la:");
	for(int i=n-1; i>=0; i--)
	{
		printf("\na[%d]: %d",i,*(a+i));
	}
}
void Them(int *&a, int &n)
{
	int vt,x;
	printf("\nNhap vi tri can them: ");
	scanf("%d",&vt);
	if(vt>=0 && vt <=n)
	{
		printf("\nNhap phan tu can them: ");
      	scanf("%d",&x);
	    realloc(a,(n+1)*sizeof(int));
	    for(int i= n-1; i>=vt; i--)
         	{
    		*(a+i+1)= *(a+i);
        	}
        	*(a+vt)=x;
        	n++;
	}
	else
	{
		printf("\nVi tri them can nam trong doan [0;%d]",n);
	}

}
void Xoa(int *&a, int &n)
{
	int vt;
	printf("\nVi tri can xoa: ");
	scanf("%d",&vt);
	if(vt >=0 && vt<n)
	{
		for(int i= vt+1; i<n; i++)
	    {
		*(a+i-1)= *(a+i);
     	}
    	n--;
    	realloc(a,n*sizeof(int));
	}
	else
	{
		printf("\nVi tri them can nam trong doan [0;%d]",n-1);
	}
	
}
void Menu(int *&a, int &n)
{
	char luachon;
	while(true)
	{
		system("cls");
		printf("\na. Nhap mot day so nguyen gom n phan tu ");
		printf("\nb. Xuat day so nguyen vua nhap ra man hinh");
		printf("\nc. Tinh tong day so nguyen");
		printf("\nd. Tim phan tu am lon thu hai trong mang ");
		printf("\ne. Liet ke va dem so nguyen to co trong day");
		printf("\nf. Xuat dao nguoc mang");
		printf("\ng. Them mot phan tu x vao vi tri k");
		printf("\nh. Xoa mot phan tu o vi tri k");
		printf("\nNhan ESC de thoat");
		printf("\nNhap lua chon cua ban");
		luachon = getch();
		switch(luachon)
		{
			case 27:
			    return;
			case 'a':
				{
					Nhap(a,n);
					break;
				}
			case 'b':
			    {
			    	if(n>0)
			    	{
			    		Xuat(a,n);
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'c':
			    {
			    	if(n>0)
			    	{
			    		printf("\nTong cua day vua nhap la %d",TinhTong(a,n));
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'd':
			    {
			    	if(n>0)
			    	{
			    		if(TimSoAm(a,n)<0)
			    		{
			    			printf("\nPhan tu am lon thu hai trong mang la %d",TimSoAm(a,n));
						}
						else
						{
							printf("\nKhong ton tai phan tu am lon thu hai trong day");
						}
			    		
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'e':
			    {
			    	if(n>0)
			    	{
			    		LietKeVaDemSoNt(a,n);
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'f':
			    {
			    	if(n>0)
			    	{
			    		XuatDayDaoNguoc(a,n);
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'g':
			    {
			    	if(n>0)
			    	{
			    		Them(a,n);
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			case 'h':
			    {
			    	if(n>0)
			    	{
			    		Xoa(a,n);
					}
					else
					{
						printf("\nBan chua nhap du lieu!");
					}
					system("pause");
					break;
				}
			default:
			  printf("\nLua chon khong hop le");
			  system("pause");									
		}
		
	}
}
int main()
{
	int *a;
	int n=0;
	Menu(a,n);
	free(a);
}
