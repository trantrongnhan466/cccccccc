#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name
{
	char TacGia[30];
	char TenSach[30];
};
typedef struct name Name;
struct book_st
{
	Name ten;
	char theloai[30];
	int giatien;
};
typedef struct book_st bookList;
bookList Enter(bookList &a)
{
	printf("\nNhap ten sach: ");
	fflush(stdin);
	gets(a.ten.TenSach);
	printf("Nhap ten tac gia: ");
	fflush(stdin);
	gets(a.ten.TacGia);
	printf("Nhap the loai: ");
	fflush(stdin);
	gets(a.theloai);
	printf("Nhap gia tien: ");
	scanf("%d",&a.giatien);
}
void Enters(bookList *&a, int &n)
{	
    if(n==0)
	{
	 	a=(bookList*)malloc(sizeof(bookList));
	} 
	else
	{
	   realloc(a,(n+1)*sizeof(bookList));	
	}  
	printf("\nNhap cuon sach thu %d",n+1);
	Enter(a[n]);
	n++;	
}
void arrange(bookList *a, int n)
{
	for(int i=0; i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(a[i].theloai,a[j].theloai)<0)
			{
				bookList flag= a[i];
				a[i] = a[j];
				a[j] = flag;
			}
		}
	}
}
void statistics(bookList *a, int n)
{
	arrange(a,n);
	int flag=0;
	for(int i= flag; i<n; i= flag)
	{
		int count = 1;
		for(int j = flag+1; j<n; j++)
		{
			if(strcmp(a[i].theloai,a[j].theloai)== 0)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if(count>0)
		{
		   printf("\nThe loai %s co %d quyen",a[flag].theloai,count);
		   flag =flag + count;	
		}
	}
	
}
void printfLine(int n)
{
	printf("\n");
	for(int i=1; i<=n; i++)
	{
		printf("=");
	}
}
void OutPut(bookList a, int i)
{
	printfLine(100);
	printf("\n00%d",i+1);
	printf("||%-15s",a.ten.TenSach);
	printf("||%-20s",a.ten.TacGia);
	printf("||%-15s",a.theloai);
	printf("||%d",a.giatien);
}
void OutPuts(bookList *a, int n)
{
	printf("\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
	for(int i=0; i<n; i++)
	{
		OutPut(a[i],i);
	}
}
void LookUp(bookList *a, int n)
{
	char typeBook[30];
	int kt=1;
	printf("\nNhap The Loai Sach Can Tim: ");
	fflush(stdin);
	gets(typeBook);
	printf("\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
	for(int i= 0; i<n; i++)
	{
		if(strcmp(a[i].theloai,typeBook)==0)
		{
				OutPut(a[i],i);
				kt=0;
		}
	}
	if(kt)
	{
		printf("\nKhong co quyen sach thuoc the loai %s trong du lieu",typeBook);
	}
}
void Delete(bookList *&a, int &n)
{
	int stt;
	OutPuts(a,n);
    do
	{
		printf("\nNhap so thu tu cua quyen sach can xoa: ");
		scanf("%d",&stt);
		if(stt <1 || stt > n)
		{
			printf("\nVi tri xoa can nam trong doan thu tu [1;%d]",n);
		}
	}while(stt <1 || stt > n);
	stt--;
    for(int i= stt+1; i<n; i++)
	{
		   a[i-1]=a[i];
	}
     n--;
	realloc(a,n*sizeof(bookList));
}
void Add(bookList *&a, int &n)
{
	int stt;
	bookList b ;
	OutPuts(a,n);
	do
	{
		printf("\nNhap so thu tu cua quyen sach can them: ");
		scanf("%d",&stt);
		if(stt < 1 || stt > n+1)
		{
			printf("\nVi tri them can nam trong doan thu tu [1;%d]",n+1);
		}
	}while(stt<1 || stt >n+1);
	stt--;
	printf("\nNhap thong tin quyen sach can them:");
	Enter(b);
	realloc(a,(n+1)*sizeof(bookList));
	for(int i=n-1; i>= stt; i--)
	{
		a[i+1] = a[i];
	}
    a[stt]=b;
	n++;
}
void upDate(bookList *&a, int n)
{
	int stt;
	do
	{
		printf("\nNhap so thu tu cua quyen sach can cap nhat: ");
		scanf("%d",&stt);
		if(stt <1 || stt > n)
		{
			printf("\nVi tri cap nhat can nam trong doan thu tu [1;%d]",n);
		}
	}while(stt <1 || stt > n);
	stt--;
	for(int i=0; i<n; i++)
	{
		if(stt==i)
		{
			Enter(a[i]);
			return;
		}
	}
}
void SaveData(bookList *a, int n)
{
	
}
int main()
{
	bookList *a;
	int n=0;
	Enters(a,n);
	Enters(a,n);
	Enters(a,n);
	OutPuts(a,n);
    upDate(a,n);
	OutPuts(a,n);
	free(a);
}
