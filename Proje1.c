#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ogrenciListesi();
void ogrenciEkle();
void kitapListesi();
void kitapAlma(char *ad, char *soyad, char *kitap_adi);
void kitapEkle(char *ad);
void kitapIadesi(char *ad, char *soyad, char *kitap_adi);
void kitapSil(char *kitap_adi);


int main()
{
    printf("---KUTUPHANEMIZE H0SGELDINIZ---\n");
    printf("\n\n\n");
    printf("**Turkce Harf Kullanmayiniz**\n");
	while (1) 
	{
		int islem;

        printf("----------\n");
		printf("Ogrenci Isleri Icin : 1\nKitap Isleri Icin : 2\n");
		
		printf("Yapmak Istediginiz Islemi Seciniz : ");
		scanf("%d",&islem);
		
		if (islem==1) 
		{
            printf("----------\n");
			printf("---Ogrenci Isleri---\n");
			printf("Ogrenci Listesi : 1\n");
			printf("Ogrenci Ekleme : 2\n");
			printf("Ana Menuye Don : 3\n");
			printf("Cikis : 4\n");
            printf("----------\n");
			printf("Yapmak Istediginiz Islemi Seciniz : ");

			scanf("%d",&islem);
			
			if(islem==1){
				printf("---Ogrenci Listesi---\n");
			
				ogrenciListesi();
			}
			else if(islem==2){
				printf("---Ogrenci Ekleme---\n");
				
				ogrenciEkle();
			}
			else if(islem==3){
				printf("---Ana Menuye Don---\n");
			}
			else if(islem==4){
				printf("---Cikis---\n");
				break;
			}
			else {
				printf("---Yanlis Tuslama Yaptiniz!---\n");
			}
		}
		else if (islem==2) 
		{
            printf("----------\n");
			printf("---Kitap Isleri---\n");
			printf("Kitap Listesi : 1\n");
            printf("Kitap Odunc Al : 2\n");
			printf("Yeni Kitap Ekleme : 3\n");
			printf("Kitap Iadesi : 4\n");
			printf("Ana Menuye Don : 5\n");
			printf("Cikis : 6\n");
            printf("----------\n");
			printf("Yapmak Istediginiz Islemi Seciniz : ");
			scanf("%d",&islem);
			
			if (islem==1){
				printf("---Kitap Listesi---\n");
				
				kitapListesi();
			}
            else if (islem==2) {
                printf("---Kitap Odunc Al---\n");

                char ad[50];
                char soyad[50];
                char kitap_adi[100];

                printf("Lutfen adinizi ve soyadinizi giriniz: ");
                scanf("%s %s", ad,soyad);
                printf("Lutfen kitabin adini giriniz (Bosluk Birakmadan Yaziniz): ");
                scanf("%s", kitap_adi);

                kitapAlma(ad, soyad, kitap_adi);

                printf("Kitap basariyla odunc alindi.\n");

            }
			else if (islem==3){
				printf("---Yeni Kitap Ekleme---\n");

                char kitap_adi[100];
                printf("Lutfen eklemek istediginiz kitabin adini giriniz (Bosluk Birakmadan Yaziniz): ");
                scanf("%s", kitap_adi);
                printf("Kitap basariyla eklendi.\n");
                kitapEkle(kitap_adi);
				
			}
			else if (islem==4){
				printf("---Kitap Iadesi---\n");

                char ad[50];
                char soyad[50];
                char kitap_adi[100];
                printf("Lutfen adinizi giriniz : ");
                scanf("%s", ad);
                printf("----------\n");
                printf("Lutfen soyadinizi giriniz : ");
                scanf("%s", soyad);
                printf("----------\n");
                printf("Lutfen kitabin adini giriniz (Bosluk Birakmadan Yaziniz) : ");
                scanf("%s", kitap_adi);
                printf("----------\n");
                kitapIadesi(ad, soyad, kitap_adi);
                kitapSil(kitap_adi);
                printf("Kitap basariyla iade edildi.\n");
			}
			else if (islem==5){
				printf("---Ana Menuye Don---\n");
			}
			else if (islem==6){
				printf("---Cikis---\n");
				break;
			}
			else {
				printf("---Yanlis Tuslama Yaptiniz!---\n");
			}
		}
		else 
		{
			printf("---Yanlis Tuslama Yaptiniz!---\n");
		}		
	}
	return 0;
}

void ogrenciListesi()
{
	FILE *dosya;
	char veri[100], veri1[100];
	
	dosya = fopen("kitapAlmayanOgrenci.txt","r");
	
	while (fscanf(dosya,"%s %s",veri,veri1) != EOF){
		printf("%s %s\n",veri,veri1);
	}
	
	fclose(dosya);
	
	FILE *dosya1;
	char veri2[100], veri3[100];
	
	dosya1 = fopen("kitapAlanOgrenci.txt","r");
	
	while (fscanf(dosya1,"%s %s",veri2,veri3) != EOF){
		printf("%s %s\n",veri2,veri3);
	}
	
	fclose(dosya1);	
	
}

void ogrenciEkle ()
{
	char isim[50];
	char soyisim[50];
	printf("Isim Soyisim : ");
	scanf("%s %s",&isim,&soyisim);
	 
	FILE *dosya = fopen("kitapAlmayanOgrenci.txt","a");
	
	fprintf(dosya, "%s %s\n",isim,soyisim);
	
	fclose(dosya);
}

void kitapListesi()
{
	FILE *dosya;
	char satir[100];
	
	dosya = fopen("alinanKitap.txt","r");
	while (fgets(satir,100,dosya) != NULL){
		printf("%s",satir);
	}
	printf("\n");
	
	fclose(dosya);
	
	FILE *dosya1;
	char satir2[100];
	
	dosya1 = fopen("alinmayanKitap.txt","r");
	
	while (fgets(satir2,100,dosya1) != NULL){
		printf("%s",satir2);
	}
	
	fclose(dosya1);
	printf("\n");
	
}

void kitapAlma(char *ad, char *soyad, char *kitap_adi){

    // alinmayanKitaplar.txt dosyas�ndan kitap ad�n� sil
    char line[200]; // okunan sat�r� tutacak string
    char temp[200]; // yeni sat�rlar� tutacak ge�ici string
    FILE *fp = fopen("alinmayanKitap.txt", "r"); // dosyay� okuma modunda a�
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her sat�r� oku
        if(strstr(line, kitap_adi) == NULL) { // e�er okunan sat�rda kitap ad� yoksa
            strcat(temp, line); // ge�ici stringe ekle
        }
    }
    fclose(fp); // dosyay� kapat
    fp = fopen("alinmayanKitap.txt", "w"); // dosyay� yazma modunda a�
    fprintf(fp, "%s", temp); // ge�ici stringi dosyaya yaz
    fclose(fp); // dosyay� kapat

    // alinanKitap.txt dosyas�na kitap ad�n� ekle
    FILE *fp2 = fopen("alinanKitap.txt", "a"); // dosyay� ekleme modunda a�
    fprintf(fp2, "%s\n", kitap_adi); // dosyaya kitap ad�n� yaz
    fclose(fp2); // dosyay� kapat

    // kitapAlmayanOgrenci.txt dosyas�ndan ��renci ad�n� ve soyad�n� sil
    strcpy(temp, ""); // ge�ici stringi temizle
    FILE *fp3 = fopen("kitapAlmayanOgrenci.txt", "r"); // dosyay� okuma modunda a�
    while(fgets(line, sizeof(line), fp3)) { // dosyadaki her sat�r� oku
        char okuyucu[100]; // okuyucunun ad�n� ve soyad�n� tutacak string
        sscanf(line, "%s", okuyucu); // sat�rdaki bilgileri parse et
        if(strcmp(okuyucu, ad) != 0 && strcmp(okuyucu, soyad) != 0) { // e�er ad ve soyad do�ru de�ilse
            strcat(temp, line); // ge�ici stringe ekle
        }
    }
    fclose(fp3); // dosyay� kapat
    fp3 = fopen("kitapAlmayanOgrenci.txt", "w"); // dosyay� yazma modunda a�
    fprintf(fp3, "%s", temp); // ge�ici stringi dosyaya yaz
    fclose(fp3); // dosyay� kapat

    // kitapAlanOgrenci.txt dosyas�na ��renciyi ekle
    FILE *fp4 = fopen("kitapAlanOgrenci.txt", "a"); // dosyay� ekleme modunda a�
    fprintf(fp4, "%s %s\n", ad, soyad); // dosyaya ��rencinin ad�n� ve soyad�n� yaz
    fclose(fp4); // dosyay� kapat

    // ogrencivekitap.txt dosyas�na ��renciyi ve kitab� ekle
    FILE *fp5 = fopen("ogrencivekitap.txt", "a"); // dosyay� ekleme modunda a�
    fprintf(fp5, "%s %s %s\n", ad, soyad, kitap_adi); // dosyaya ��rencinin ad�n�, soyad�n� ve kitap ad�n� yaz
    fclose(fp5); // dosyay� kapat

}

void kitapEkle(char *ad){

    FILE *fp = fopen("alinmayanKitap.txt", "a"); // dosyay� ekleme modunda a�
    fprintf(fp, "%s\n", ad); // dosyaya kitap ad�n� yaz
    fclose(fp); // dosyay� kapat



}

void kitapIadesi(char *ad, char *soyad, char *kitap_adi) {
    char okuyucu[100]; // okuyucunun ad ve soyad�n� tutacak string
    char line[200]; // okuyucunun bilgilerinin oldu�u sat�r� tutacak string
    FILE *fp = fopen("ogrencivekitap.txt", "r"); // dosyay� okuma modunda a�
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her sat�r� oku
        sscanf(line, "%s %s %s", okuyucu, kitap_adi, kitap_adi); // sat�rdaki bilgileri parse et
        if(strcmp(ad, okuyucu) == 0 && strcmp(soyad, soyad) == 0) { // e�er ad ve soyad do�ru ise
            fclose(fp); // dosyay� kapat
            fp = fopen("ogrencivekitap.txt", "w"); // dosyay� yazma modunda a�
            char temp[200]; // yeni sat�rlar� tutacak ge�ici string
            while(fgets(line, sizeof(line), fp)) { // dosyadaki her sat�r� oku
                if(strcmp(line, okuyucu) != 0) { // e�er okunan sat�r istenen sat�r de�ilse
                    strcat(temp, line); // ge�ici stringe ekle
                }
            }
            fprintf(fp, "%s", temp); // ge�ici stringi dosyaya yaz
            break; // d�ng�den ��k
        }
    }
    fclose(fp); // dosyay� kapat
}

void kitapSil(char *kitap_adi) {
    char line[200]; // okunan sat�r� tutacak string
    char temp[200]; // yeni sat�rlar� tutacak ge�ici string
    FILE *fp = fopen("alinanKitap.txt", "r"); // dosyay� okuma modunda a�
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her sat�r� oku
        if(strstr(line, kitap_adi) == NULL) { // e�er okunan sat�rda kitap ad� yoksa
            strcat(temp, line); // ge�ici stringe ekle
        }
    }
    fclose(fp); // dosyay� kapat
    fp = fopen("alinanKitap2"
               ".txt", "w"); // dosyay� yazma modunda a�
    fprintf(fp, "%s", temp); // ge�ici stringi dosyaya yaz
    fclose(fp); // dosyay� kapat
}






