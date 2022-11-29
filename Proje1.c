#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	while (1) 
	{
		int islem;
		printf("Ogrenci Isleri Icin : 1\nKitap Isleri Icin : 2\n");
		
		printf("Yapmak Istediginiz Islemi Secin : ");
		scanf("%d",&islem);
		
		if (islem==1) 
		{
			printf("Ogrenci Isleri\n");
			printf("Ogrenci Listesi : 1\n");
			printf("Ana Menuye Don : 2\n");
			printf("Cikis : 3\n");
			printf("Yapmak Istediginiz Islemi Secin : ");
			scanf("%d",&islem);
			
			if(islem==1){
				printf("Ogrenci Listesi\n");
			}
			else if(islem==2){
				printf("Ana Menuye Don\n");
			}
			else if(islem==3){
				printf("Cikis\n");
				break;
			}
			else {
				printf("Yanlis Tuslama Yaptiniz!\n");
			}
		}
		else if (islem==2) 
		{
			
			printf("Kitap Isleri\n");
			printf("Kitap Listesi : 1\n");
			printf("Odunc Alinan Kitaplar ve Odunc Alan Kisi : 2\n");
			printf("Yeni Kitap Ekleme : 3\n");
			printf("ISBN Numarasina Gore Kitap Arama : 4\n");
			printf("Isme Gore Kitap Arama : 5\n");
			printf("Kitap Iadesi : 6\n");
			printf("Ana Menuye Don : 7\n");
			printf("Cikis : 8\n");
			printf("Yapmak Istediginiz Islemi Secin : ");
			scanf("%d",&islem);
			
			if (islem==1){
				printf("Kitap Listesi\n");
			}
			else if (islem==2){
				printf("Odunc Alinan Kitaplar ve Odunc Alan Kisi\n");
			}
			else if (islem==3){
				printf("Yeni Kitap Ekleme\n");
			}
			else if (islem==4){
				printf("ISBN Numarasina Gore Kitap Arama\n");
			}
			else if (islem==5){
				printf("Isme Gore Kitap Arama\n");
			}
			else if (islem==6){
				printf("Kitap Iadesi\n");
			}
			else if (islem==7){
				printf("Ana Menuye Don\n");
			}
			else if (islem==8){
				printf("Cikis\n");
				break;
			}
			else {
				printf("Yanlis Tuslama Yaptiniz!\n");
			}
		}
		
		else 
		{
			printf("Yanlis Tuslama Yaptiniz!\n");
		}
			
	}
	return 0;
}
