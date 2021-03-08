#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int sosv=0;
struct date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct date DATE;
struct SinhVien
{
  char hoten[30];
  char lop[30];
  int diemtb;
  DATE date;	
};
typedef struct SinhVien SV;
void NhapNgayThangNamSinh(SV &sv)
{
	int ngaymax;
	do
	{
	printf("\nNhap ngay sinh: ");
	fflush(stdin);
	scanf("%d",&sv.date.ngay);
	printf("\nNhap thang sinh: ");
	fflush(stdin);
	scanf("%d",&sv.date.thang);
	printf("\nNhap nam sinh: ");
	fflush(stdin);
	scanf("%d",&sv.date.nam);
	if(sv.date.ngay<1||sv.date.thang<1||sv.date.nam<1||sv.date.thang>12||sv.date.ngay>31)
	{
		printf("\nSo lieu khong hop le!");
	}
	else
	{
		switch(sv.date.ngay)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
			  	ngaymax = 31;
			  	break;
			}
			case 2:
			{
				if(sv.date.nam % 4 == 0 && sv.date.nam % 100 != 0 || sv.date.nam % 400 == 0)
				{
					ngaymax = 29;
				}
				else
				{
					ngaymax = 28;
					break;
				}
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				ngaymax = 30;
				break;
			}			
		}
		if(sv.date.ngay > ngaymax)
		{
			printf("\nSo lieu khong hop le! ");
		}
	}
	}while(sv.date.ngay<1||sv.date.thang<1||sv.date.nam<1||sv.date.thang>12||sv.date.ngay>31||sv.date.ngay > ngaymax);
}
void NhapSv(SV &sv)
{
	printf("\nNhap ho va ten: ");
	fflush(stdin);
	fgets(sv.hoten, sizeof sv.hoten, stdin);
	NhapNgayThangNamSinh(sv);
	printf("\nNhap ten lop: ");
	fflush(stdin);
	fgets(sv.lop, sizeof sv.lop, stdin);
	printf("\nNhap diem tb: ");
	fflush(stdin);
	scanf("%d",&sv.diemtb);	
}
void NhapDs(SV sv[], int &n)
{
	for(int i = 0; i<n; i++)
	{
		printf("\n\t\t***************");
		NhapSv(sv[i]);
	}
}
void XuatSv(SV sv)
{
	printf("\n*****************");
	printf("\nHo ten: %s",sv.hoten);
	printf("Ngay sinh: %d/%d/%d",sv.date.ngay,sv.date.thang,sv.date.nam);
	printf("\nLop: %s",sv.lop);
	printf("Diem tb: %d",sv.diemtb);
}
void XuatDs(SV sv[], int n)
{
	for(int i= 0; i<n; i++)
	{
		XuatSv(sv[i]);
	}
}
void SapXep(SV sv[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(sv[j].diemtb>sv[i].diemtb)
			{
				SV Tam = sv[i];
				sv[i] = sv[j];
				sv[j] = Tam;
			}
		}
	}
}
void Tim(SV sv[], int n)
{
	char s[30];
	int kt = 0;
	printf("\nNhap ten sinh vien can tim: ");
	fflush(stdin);
	fgets(s, sizeof s, stdin);
	for(int i=0; i<n; i++)
	{
		if(strcmp(s, sv[i].hoten)==0)
		{
			XuatSv(sv[i]);
			kt =1;
		}
	}
	if(kt==0)
	{
		printf("\nKhong tim thay thong tin!");
	}
}
void Menu()
{
	SV sv[100];
	int n;
	char luachon;
	while(true)
	{
		system("cls");
		printf("\n\n\t\t=========MENU=========");
		printf("\n1. Nhap thong tin sinh vien");
		printf("\n2. Xuat thong tin sinh vien");
		printf("\n3. Sap xep sinh vien theo diem");
		printf("\n4. Tim kiem thong tin sinh vien theo ten");
		printf("\nNhan ESC de thoat!");
		printf("\nMoi ban nhap lua chon: ");
		luachon = getch();
		switch(luachon)
		{
			case '1':
				{
					printf("\nNhap so luong sinh vien: ");
					scanf("%d",&n);
					NhapDs(sv,n);
					sosv++;
					break;
				}
			case '2':
			    {
			    	if(sosv<1)
					{
						printf("\nBan chua nhap thong tin!");
					}
					else
					{
						 XuatDs(sv,n);
					}		       
					system("pause");
					break;	
				}
			case '3':
			    {
			    	if(sosv<1)
					{
						printf("\nBan chua nhap thong tin!");
					}
					else
					{
						 SapXep(sv,n);
					}
			       	system("pause");
			       	break;
				}
			case '4':
			    {
			    	if(sosv<1)
					{
						printf("\nBan chua nhap thong tin!");
					}
					else
					{
						 Tim(sv,n);
					}
			    	system("pause");
			    	break;
				}
			case 27:
			    break;
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
int main()
{
  Menu();
}
