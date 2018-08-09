#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void zad1(){
	printf("Написать программу, которая заменяет все первые\nбуквы каждого слова во введенной фразе символом «~»\n");
	printf("Введите строку:\n");
	char str[300],q[2]="~";
	gets(str);
	gets(str);
	if(str[0]!=' ')
	strncpy(str,q,1);
	for(int i=0;i<strlen(str);i++){
		if(str[i]==' '&&str[i+1]!=' ')
		strncpy(str+i+1,q,1);
		}
	puts(str);
	}
void zad2(){
	printf("Написать программу, которая заменяет все четные буквы \n(знаки препинания и пробелы не рассматривать)\n во введенной фразе символом «*». \n");
	printf("Введите строку:\n");
	char str[300],q[2]="*";
	gets(str);
	gets(str);
	int m=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!=','&&str[i]!=' '&&str[i]!='.'&&str[i]!='!'&&str[i]!='?'){
			if(m%2==0){
				strncpy(str+i,q,1);
				}
			m++;	
			}
		}
	puts(str);
}

void zad3(){
	printf("Написать программу, которая заменяет все гласные буквы\nво введенной фразе на букву «е».\nПодсчитать количество гласных.");
	printf("Введите строку на русском языке:\n");
	char str[300],q[10]="а",qq[10]="е",*p;
	gets(str);
	gets(str);
	int m=1,k=0;
	while(m==1){
			p=strstr(str,qq);
			if(p==NULL) break;
			strncpy(p,q,strlen(q));
			}
	strcpy(q,"е");		
	for(int i=0;i<10;i++){
		if(i==0) strcpy(qq,"а");
		if(i==1) strcpy(qq,"ё");
		if(i==2) strcpy(qq,"и");
		if(i==3) strcpy(qq,"о");
		if(i==4) strcpy(qq,"у");
		if(i==5) strcpy(qq,"ы");
		if(i==6) strcpy(qq,"э");
		if(i==7) strcpy(qq,"ю");
		if(i==8) strcpy(qq,"я");
		while(m==1){
			p=strstr(str,qq);
			if(p==NULL) break;
			strncpy(p,q,strlen(q));
			k++;
			}
		}		
	puts(str);
	printf("Количество гласных букв в предложении: %d",k);
}

void zad4(){
	printf("Написать программу, которая определяет, является ли введенная фраза\nчислом, записанным в двоичной системе счисления(имеющих цифры «0»и «1»)");
	printf("\nВведите строку на русском языке:\n");
	char str[300];
	gets(str);
	gets(str);
	int a=1;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='0'||str[i]=='1');
		else {
			printf("\nфраза числом двоичной системы счисления не является!");
			a=0;
			break;
			}
		}
	if(a) printf("\nфраза является числом двоичной системы счисления!");
	}

void zad5(){
	printf("Написать программу, которая вставляет перед каждой третьей буквой во\nвведенной фразе слог «ку-»\n");
	printf("\nВведите строку на русском языке:\n");
	char str[300],qu[20]="ку-",str1[300];
	gets(str);
	do{
	gets(str);
	if(strlen(str)>30) printf("Строчка слишком длинная введите еще раз:");
	}
	while(strlen(str)>30);
	strcpy(str1,str);
	for(int i=0;i<strlen(str);i++){
		if(str1[i]==' '||str1[i]=='.'||str1[i]==',')
			strcpy(str1+i,str1+i+1);
		}
	strcpy(str,str1);
	int i=1,k=0;
	while(strlen(str1)>strlen("абс")){
		strcpy(str1,str1+strlen("абс"));
		strcpy(str+i*strlen("абс")+k,qu);
		strcat(str,str1);
		i++;
		k+=strlen(qu);
		}
	puts(str);	
	}


void zad6(){
	printf("Написать программу, которая вставляет\nперед каждым словом порядковый\nномер этого слова »\n");
	printf("\nВведите строку на русском языке:\n");
	char str[300],str1[300],Number[50];
	int n,l=1;
	gets(str);
	gets(str);
	strcpy(str1,str);
	if(str[0]!=' ') {
		Number[0]=l+'0';
		Number[1]='\0';
		strcpy(str,Number);
		strcat(str,str1);
		memset(Number,0,sizeof(Number));
		memset(str1,0,sizeof(str1));
		strcpy(str1,str);
		l++;
		}	
	for(int i=0;i<strlen(str);i++){
		if(str[i]==' '&&str[i+1]!=' '&&str[i+1]!='\0'){
			Number[0]=l+'0';
			Number[1]='\0';
			strcpy(str+i+1,Number);
			strcpy(str1,str1+i+1);
			strcat(str,str1);
			memset(Number,0,sizeof(Number));
			memset(str1,0,sizeof(str1));
			strcpy(str1,str);
			l++;
			}
		}
	puts(str);
	}

void zad7(){
	printf("Написать программу, которая заменяет\nвсе цифры во введенной фразе символом «#»\n");
	printf("\nВведите строку:\n");
	char str[300];
	gets(str);
	gets(str);	
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0'){
			str[i]='#';
			}
		}
	puts(str);	
	}


int main(){
	printf("Введите вариант задания на строки");
	int n;
	scanf("%d",&n);
	
	switch(n){
	case 1: zad1(); break;
	case 2: zad2(); break;
	case 3: zad3(); break;
	case 4: zad4(); break;
	case 5: zad5(); break;
	case 6: zad6(); break;
	case 7: zad7(); break;
	}	   
	
	return 0;
	}
