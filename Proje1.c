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

    // alinmayanKitaplar.txt dosyasýndan kitap adýný sil
    char line[200]; // okunan satýrý tutacak string
    char temp[200]; // yeni satýrlarý tutacak geçici string
    FILE *fp = fopen("alinmayanKitap.txt", "r"); // dosyayý okuma modunda aç
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her satýrý oku
        if(strstr(line, kitap_adi) == NULL) { // eðer okunan satýrda kitap adý yoksa
            strcat(temp, line); // geçici stringe ekle
        }
    }
    fclose(fp); // dosyayý kapat
    fp = fopen("alinmayanKitap.txt", "w"); // dosyayý yazma modunda aç
    fprintf(fp, "%s", temp); // geçici stringi dosyaya yaz
    fclose(fp); // dosyayý kapat

    // alinanKitap.txt dosyasýna kitap adýný ekle
    FILE *fp2 = fopen("alinanKitap.txt", "a"); // dosyayý ekleme modunda aç
    fprintf(fp2, "%s\n", kitap_adi); // dosyaya kitap adýný yaz
    fclose(fp2); // dosyayý kapat

    // kitapAlmayanOgrenci.txt dosyasýndan öðrenci adýný ve soyadýný sil
    strcpy(temp, ""); // geçici stringi temizle
    FILE *fp3 = fopen("kitapAlmayanOgrenci.txt", "r"); // dosyayý okuma modunda aç
    while(fgets(line, sizeof(line), fp3)) { // dosyadaki her satýrý oku
        char okuyucu[100]; // okuyucunun adýný ve soyadýný tutacak string
        sscanf(line, "%s", okuyucu); // satýrdaki bilgileri parse et
        if(strcmp(okuyucu, ad) != 0 && strcmp(okuyucu, soyad) != 0) { // eðer ad ve soyad doðru deðilse
            strcat(temp, line); // geçici stringe ekle
        }
    }
    fclose(fp3); // dosyayý kapat
    fp3 = fopen("kitapAlmayanOgrenci.txt", "w"); // dosyayý yazma modunda aç
    fprintf(fp3, "%s", temp); // geçici stringi dosyaya yaz
    fclose(fp3); // dosyayý kapat

    // kitapAlanOgrenci.txt dosyasýna öðrenciyi ekle
    FILE *fp4 = fopen("kitapAlanOgrenci.txt", "a"); // dosyayý ekleme modunda aç
    fprintf(fp4, "%s %s\n", ad, soyad); // dosyaya öðrencinin adýný ve soyadýný yaz
    fclose(fp4); // dosyayý kapat

    // ogrencivekitap.txt dosyasýna öðrenciyi ve kitabý ekle
    FILE *fp5 = fopen("ogrencivekitap.txt", "a"); // dosyayý ekleme modunda aç
    fprintf(fp5, "%s %s %s\n", ad, soyad, kitap_adi); // dosyaya öðrencinin adýný, soyadýný ve kitap adýný yaz
    fclose(fp5); // dosyayý kapat

}

void kitapEkle(char *ad){

    FILE *fp = fopen("alinmayanKitap.txt", "a"); // dosyayý ekleme modunda aç
    fprintf(fp, "%s\n", ad); // dosyaya kitap adýný yaz
    fclose(fp); // dosyayý kapat



}

void kitapIadesi(char *ad, char *soyad, char *kitap_adi) {
    char okuyucu[100]; // okuyucunun ad ve soyadýný tutacak string
    char line[200]; // okuyucunun bilgilerinin olduðu satýrý tutacak string
    FILE *fp = fopen("ogrencivekitap.txt", "r"); // dosyayý okuma modunda aç
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her satýrý oku
        sscanf(line, "%s %s %s", okuyucu, kitap_adi, kitap_adi); // satýrdaki bilgileri parse et
        if(strcmp(ad, okuyucu) == 0 && strcmp(soyad, soyad) == 0) { // eðer ad ve soyad doðru ise
            fclose(fp); // dosyayý kapat
            fp = fopen("ogrencivekitap.txt", "w"); // dosyayý yazma modunda aç
            char temp[200]; // yeni satýrlarý tutacak geçici string
            while(fgets(line, sizeof(line), fp)) { // dosyadaki her satýrý oku
                if(strcmp(line, okuyucu) != 0) { // eðer okunan satýr istenen satýr deðilse
                    strcat(temp, line); // geçici stringe ekle
                }
            }
            fprintf(fp, "%s", temp); // geçici stringi dosyaya yaz
            break; // döngüden çýk
        }
    }
    fclose(fp); // dosyayý kapat
}

void kitapSil(char *kitap_adi) {
    char line[200]; // okunan satýrý tutacak string
    char temp[200]; // yeni satýrlarý tutacak geçici string
    FILE *fp = fopen("alinanKitap.txt", "r"); // dosyayý okuma modunda aç
    while(fgets(line, sizeof(line), fp)) { // dosyadaki her satýrý oku
        if(strstr(line, kitap_adi) == NULL) { // eðer okunan satýrda kitap adý yoksa
            strcat(temp, line); // geçici stringe ekle
        }
    }
    fclose(fp); // dosyayý kapat
    fp = fopen("alinanKitap2"
               ".txt", "w"); // dosyayý yazma modunda aç
    fprintf(fp, "%s", temp); // geçici stringi dosyaya yaz
    fclose(fp); // dosyayý kapat
}






