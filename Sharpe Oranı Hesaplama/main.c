#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	printf("*************************\n");
	printf("Sharpe Orani Hesaplama Programi\n");
	printf("*************************\n\n");
	
	float sharpeOrani,yatirimGetirisi,risksizFaizOrani,standartSapma;
	//float ile tanýmlamamýzýn nedeni ondalýklý sayýlar kullanýcaðýmýz içindir.
	
	printf("Yatirimin veya varligin beklenen getirisini giriniz: ");
	scanf("%f",&yatirimGetirisi);
	
	printf("Risksiz faiz oraninizi giriniz: ");
	scanf("%f",&risksizFaizOrani);
	
	printf("Standart sapma oraninizi giriniz: ");
	scanf("%f",&standartSapma);
	
	float Yt = yatirimGetirisi/100.0; // Yt'nin anlamý (Yatýrým Getirisidir.)
	float Rgo = risksizFaizOrani/100.0;//Rgo'nun anlamý (Risksiz faiz oranýdýr.)
	float Ss = standartSapma/100.0;//Ss'nin anlamý (Standart sapmadýr.)
	//bu üsteki 3 satýrlýk kod kullanýcýdan yüzde olarak alýnan deðerleri matematiksel hesaplamalarda
    //kullanýlabilecek ondalýk formata dönüþtürmektir içindir.
    
	if(Ss==0)
	{
		printf("Standart sapma sifir olamaz. Lutfen tekrar deneyin.");
		return 1;
	}
	//yukarýdaki if kodunun amacý paydada sýfýr olamayacaðý için olasý hatalarý önleme içindir.
	
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
	system("pause");//Windows konsolu anýnda kapandýðý için kapanmasýný önlemek için yaptým.
	return 0;
}
