/**
* @file pract.c
* @author Веретинский К.М., гр. 515
* @date 30 июня 2021
* @brief Учебная практика
*
* Вариант №34. Числы Армстронга
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define N 10
int main(){
	int a, b, i, n, j;
	int arr[N];
	setlocale(LC_ALL, "rus");
	printf("Введите левую границу:");
	scanf("%i", &a);
	printf("Введите правую границу:");
	scanf("%i", &b);
	if(a>b){
		printf("Неверный диапазон");
		return 1;
	}
	for(i=a; i<=b; i++){
	n = digits(i, arr);	
	if(Arm_digits(i, n, arr, N)){
	printf("%i=", i);
	if(n==0){
		printf("0^1\n");
	}
	else{	
	for(j=(n-1); j>=0; j--){
		if(j==0) printf("%i^%i", arr[j], n);
		else printf("%i^%i + ", arr[j], n);
	}
	printf("\n");
	}
	}
}
	return 0;
}

/**
*	Принимает число и массив, после чего заполняет массив цифрами числа и возвращает количество цифр.
*
*	@param num - целое число, *digits - указатель на массив целых чисел
*	@return difits_count, количество цифр.
*/
int digits(int num, int *digits){
    int digits_count = 0;
    while (num!=0) {
        digits[digits_count++] = num % 10;
        num /= 10;
   }
   return digits_count;
}
/**
*	Принимает  два числа и массив, после чего возводит цифры первого числа(изначальное число) в степень второго числа(количество чисел в числе) и суммирует. Если эти числа равны, то это числа Армстронга.
*
*	@param num, a  - целое число, digits - массив целых чисел, b - размерность массива
*	@return 1, если число - число Армстронга, в ином случае 0.
*/
int Arm_digits(int num, int a, const int digits[], int b){
	int i, sum;
	sum = 0;
	for(i=0; i<a; i++){
		sum = sum + pow(digits[i], a);
	}
	if(num==sum) return 1;
	else return 0;
}
