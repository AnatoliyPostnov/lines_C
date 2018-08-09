#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Программа просит ввести строки, количество которых задает пользователь
 * Программа сортирует строки в порядке возрастания количества слов в строке*/

//Ввод массива строк
void Array_scanf(char Array[][30],int n){
	gets(Array[0]);
	for(int i=0;i<n;i++)
		gets(Array[i]);
	}
//вывод массива строк
void Array_printf(char Array[][30],int n){
	printf("\nТекущий массив строк:\n");
	for(int i=0;i<n;i++)
		puts(Array[i]);
	}
//Вывод массива воличества слов	Word[line]	

void Word_printf(int Word[],int n){
	printf("\nКоличество слов в кажой строке:\n");
	for(int i=0;i<n;i++) printf("%d",Word[i]);
}
//Подсчет количесва слов в каждой строке массива и запись в массив Word[line]
void Array_word(char Array[][30],int Word[],int n){
	for(int i=0;i<n;i++) Word[i]=0;
	for(int i=0;i<n;i++){
		if(Array[i][0]!=' ') Word[i]++;
		for(int j=0;j<30;j++){
			if(Array[i][j]==' ' && Array[i][j+1]!=' '){
				if(Array[i][j+1]=='\0') break;
				Word[i]++;
				}
			}
		}
	}
//Сортировка массива строк в порядке убывания количества слов в строке
void Array_sort(char Array[][30],int Word[],int n){
	char Arr[30];
	int c,flag;
	for(int j=0;j<n-1;j++){
		flag=1;
		for(int i=0;i<n-1;i++){
			if(Word[i]>Word[i+1]){
				memset(Arr,0,sizeof(Arr));
				if(strlen(Array[i])>strlen(Array[i+1])){
					strcpy(Arr,Array[i]);
					strcpy(Array[i],Array[i+1]);
					memset(Array[i+1],0,sizeof(Array[i+1]));
					strcpy(Array[i+1],Arr);
					}
				else {
					strcpy(Arr,Array[i+1]);
					strcpy(Array[i+1],Array[i]);
					memset(Array[i],0,sizeof(Array[i]));
					strcpy(Array[i],Arr);
					}
				c=Word[i+1];
				Word[i+1]=Word[i];
				Word[i]=c;
				flag=0;	
				}
			}	
		if(flag==1) break;
		}
	}


int main (){
int line;
printf("Введите количество строк в тексте, который хотите ввести:");
scanf("%d",&line);
char Array[line][30];
int Word[line];
Array_scanf(Array,line);
Array_printf(Array,line);
Array_word(Array,Word,line);
Word_printf(Word,line);
Array_sort(Array,Word,line);
Array_printf(Array,line);
Word_printf(Word,line);
return 0;
}

