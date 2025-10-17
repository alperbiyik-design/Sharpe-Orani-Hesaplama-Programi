#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	printf("*************************\n");
	printf("Sharpe Orani Hesaplama Programi\n");
	printf("*************************\n\n");
	
	float sharpeOrani,yatirimGetirisi,risksizFaizOrani,standartSapma;
	//float ile tan�mlamam�z�n nedeni ondal�kl� say�lar kullan�ca��m�z i�indir.
	
	printf("Yatirimin veya varligin beklenen getirisini giriniz: ");
	scanf("%f",&yatirimGetirisi);
	
	printf("Risksiz faiz oraninizi giriniz: ");
	scanf("%f",&risksizFaizOrani);
	
	printf("Standart sapma oraninizi giriniz: ");
	scanf("%f",&standartSapma);
	
	float Yt = yatirimGetirisi/100.0; // Yt'nin anlam� (Yat�r�m Getirisidir.)
	float Rgo = risksizFaizOrani/100.0;//Rgo'nun anlam� (Risksiz faiz oran�d�r.)
	float Ss = standartSapma/100.0;//Ss'nin anlam� (Standart sapmad�r.)
	//bu �steki 3 sat�rl�k kod kullan�c�dan y�zde olarak al�nan de�erleri matematiksel hesaplamalarda
    //kullan�labilecek ondal�k formata d�n��t�rmektir i�indir.
    
	if(Ss==0)
	{
		printf("Standart sapma sifir olamaz. Lutfen tekrar deneyin.");
		return 1;
	}
	//yukar�daki if kodunun amac� paydada s�f�r olamayaca�� i�in olas� hatalar� �nleme i�indir.
	
	sharpeOrani=(Yt-Rgo)/Ss;
	
	if(sharpeOrani < 0)
    {
        printf("Risksiz getirinin altinda performans %.4f . Cok kotu bir yatirim.\n", sharpeOrani);
    }
	else if (sharpeOrani >= 0 && sharpeOrani < 1)
	{
		printf("Kotu risk-ayarli getiri %.4f . Lutfen yatirimi yaparken dikkat edin.\n", sharpeOrani);
	}
	else if (sharpeOrani >= 1 && sharpeOrani < 2)
	{
		printf("Iyi getiri. %.4f ile iyi bir yatirim yaptiniz.\n", sharpeOrani);
	}
	else if (sharpeOrani >= 2 && sharpeOrani < 3)
	{
		printf("Cok iyi getiri. %.4f ile cok iyi bir yatirim yaptiniz.\n", sharpeOrani);
	}
	else
	{
		printf("Mukemmel getiri. %.4f ile mukemmel bir yatirim yaptiniz.\n", sharpeOrani);
	}
	system("pause");//Windows konsolu an�nda kapand��� i�in kapanmas�n� �nlemek i�in yapt�m.
	return 0;
}
