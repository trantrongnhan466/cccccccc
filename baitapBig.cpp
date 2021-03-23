#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book_st
{
	char TacGia[30];
	char TenSach[30];
	char theloai[30];
	int giatien;
	int STT;
};
typedef struct book_st bookList;
void Enter(bookList &a)
{
	printf("\nNhap ten sach: ");
	fflush(stdin);
	gets(a.TenSach);
	printf("Nhap ten tac gia: ");
	fflush(stdin);
	gets(a.TacGia);
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
	a[n].STT=n+1;
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
	printf("||%-15s",a.TenSach);
	printf("||%-20s",a.TacGia);
	printf("||%-15s",a.theloai);
	printf("||%d",a.giatien);
}
void OutPuts(bookList *a, int n)
{
	statistics(a,n);
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
	FILE *cfPtr;
	cfPtr = fopen("book.dat","wb");
	rewind(cfPtr);
	for(int i=0; i<n ; i++)
	{
		fwrite(&a[i],sizeof(bookList),1,cfPtr);
	}
	fclose(cfPtr);
}
void textFile(FILE *readPtr)
{
	FILE *writePtr;
	int result;
	bookList a;
	writePtr = fopen("book.txt","w");
	rewind(readPtr);
	fprintf(writePtr,"\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
	while(!feof(readPtr))
	{
		result = fread(&a,sizeof(bookList),1,readPtr);
		if(result != 0 && a.STT !=0)
		{
			fprintf(writePtr,"\n00%d||%-15s||%-20s||%-15s||%d",a.STT,a.TenSach,a.TacGia,a.theloai,a.giatien);
		}
	}
	fclose(writePtr);
}
void OutPutFile(FILE *cfPtr)
{
	bookList a;
	int r;
    rewind(cfPtr);
	printf("\n%s||%-15s%-20s%-15s%s","STT","Ten Sach","Ten Tac Gia","The Loai","Gia Tien");
    while(!feof(cfPtr))
	{
		r= fread(&a,sizeof(bookList),1,cfPtr);
		if(r !=0 && a.STT !=0)
		{
			printfLine(100);
        	printf("\n00%d",a.STT);
        	printf("||%-15s",a.TenSach);
        	printf("||%-20s",a.TacGia);
        	printf("||%-15s",a.theloai);
        	printf("||%d",a.giatien);
		}
	    
	}
}
void updateRecord( FILE *fPtr)
{
	int stt;
	bookList a;
	printf("\nNhap so thu tu cua quyen sach can cap nhat thong tin: ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != stt )
	{
		printf("\nSo thu tu khong ton tai!");
	}
	else
	{
		printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	printf("\nNhap thong tin can cap nhat: ");
    	Enter(a);
    	printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	fseek(fPtr,(a.STT-1)*sizeof(bookList),SEEK_SET);
    	fwrite(&a,sizeof(bookList),1,fPtr);  	
	}
}
void deleteRecord(FILE *fPtr)
{
	bookList a;
	bookList blankBook = {"","","",0,0};
	int stt;
	printf("\nNhap so thu thu quyen sach can xoa: ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != stt)
	{
		printf("\nSo thu tu khong ton tai");
	}
	else
	{
		fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
		fwrite(&blankBook,sizeof(bookList),1,fPtr);
	}
}
void newRecord(FILE *fPtr)
{
    
	int stt;
	bookList a;
	printf("\nNhap so thu tu : ");
	scanf("%d",&stt);
	fseek(fPtr,(stt-1)*sizeof(bookList),SEEK_SET);
	fread(&a,sizeof(bookList),1,fPtr);
	if(a.STT != NULL )
	{
		printf("\nSo thu tu da ton tai!");
	}
	else
	{
    	printf("\nNhap thong tin can them: ");
    	Enter(a);
    	a.STT=stt;
    	printf("\n00%d",stt);
    	printf("||%-15s",a.TenSach);
    	printf("||%-20s",a.TacGia);
    	printf("||%-15s",a.theloai);
    	printf("||%d",a.giatien);
    	fseek(fPtr,(a.STT-1)*sizeof(bookList),SEEK_SET);
    	fwrite(&a,sizeof(bookList),1,fPtr);  	
	}
}
int enterChoice(void)
{
	int choice;
	system("cls");
	printf("%s","\n======MENU THAO TAC VOI FILE======\n"
	"1 - Luu tru thong tin da luu tu file nhi phan vao file van ban book.txt\n"
	"2 - Cap nhat thong tin\n"
	"3 - Them thong tin moi\n"
	"4 - Xoa thong tin\n"
	"5 - Hien thi thong tin trong file\n"
	"6 - Thoat\n"
	"Nhap lua chon cua ban: ");
	scanf("%d",&choice);
	return choice;
}
void menu(void)
{
	FILE *cfPtr;
	int Choice;
	cfPtr = fopen("book.dat","rb+");
	while((Choice = enterChoice()) !=6)
	{
		switch(Choice)
		{
			case 1:
				textFile(cfPtr);
				break;
			case 2:
				updateRecord(cfPtr);
				system("pause");
				break;
			case 3:
				newRecord(cfPtr);
				system("pause");
				break;
			case 4:
				deleteRecord(cfPtr);
				system("pause");
				break;
			case 5:
				OutPutFile(cfPtr);
				system("pause");
				break;
			default:
				printf("\nLua chon cua ban chua hop le !");
				system("pause");
			    break;	
		}
	}
	fclose(cfPtr);
}
int EnterChoice(void)
{
	int choice;
	system("cls");
	printf("%s","\n\t\t======MENU======\n"
	"1 - Nhap du lieu cua tung quyen sach\n"
	"2 - Sap xep, thong ke va hien thi thong tin chi tiet cua tung quyen sach theo the loai (Z->A)\n"
	"3 - Tim quyen sach theo the loai\n"
	"4 - Ghi vao tap tin nhi phan book.dat\n"
	"5 - Them du lieu cua tung quyen sach\n"
	"6 - Xoa du lieu cua tung quyen sach\n"
	"7 - Cap nhat du lieu cua tung quyen sach\n"
	"8 - Cac thao tac voi file da luu\n"
	"9 - Thoat\n"
	"Nhap lua chon cua ban: ");
	scanf("%d",&choice);
	return choice;
	
}
void Menu()
{
	bookList *a;
	int Choice,n=0;
	while((Choice = EnterChoice()) !=9)
	{
		switch(Choice)
		{
			case 1:
				Enters(a,n);
				break;
			case 2:
				if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					OutPuts(a,n);
				}
				system("pause");
				break;
			case 3:
				if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					LookUp(a,n);
				}
				system("pause");
				break;
			case 4:
				if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					SaveData(a,n);
				}
				system("pause");
				break;
			case 5:
			    if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					Add(a,n);
				}
				system("pause");
			    break;
			case 6:
				if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					Delete(a,n);
				}
				system("pause");
				break;
			case 7:
				if(n==0)
				{
					printf("\nBan chua nhap du lieu");
				}
				else
				{
					upDate(a,n);
				}
				system("pause");
				break;
			case 8:
				menu();
				break;
			case 9:
				break;
			default:
				printf("\nLua chon khong hop le !");
				system("pause");
				break;	
		}
	}
	free(a);
}
int main()
{
	Menu();
}
