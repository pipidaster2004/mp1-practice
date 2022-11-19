#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

char* barcodes[N] = { "1234", "2333", "1723", "9673", "5873", "2389", "1239", "2598", "7241", "3692" };
char* products[N] = { "snickers", "milk", "cheeze", "ketchup", "loaf", "beef", "pasta", "rice", "pepper", "salt" };
float price[N] = { 40.0f, 60.0f, 150.0f,  80.0f,  30.0f,  200.0f,  90.0f,  45.0f,  20.0f,  10.0f };
float discount[N] = { 1, 23, 15, 0, 34, 10, 40, 25, 15, 0 };

void scan_barcode(int* array);
void print_check(int* array);

int main() {
	int count[N] = { 0 };
	scan_barcode(count);
	print_check(count);
	return 0;
}

void print_check(int* array) {
	float totalCost = 0;
	printf("Your check\n");
	for (int i = 0; i < N; i++) {
		if (array[i] == 0)
			continue;
		printf("%s, discount price - %.2f, %d units.\n", products[i], (price[i] - (price[i] * (discount[i] / 100))), array[i]);
		totalCost += (price[i] * (1 - (discount[i] / 100))) * array[i];
	}
	printf("Final price - %.2f", totalCost);
}
void scan_barcode(int* array) {
	char* tmp[1];

	printf("Enter barcodes\n");
	while (strcmp(tmp, "q")) {
		gets(tmp);
		if (strcmp(tmp, "q")) {
			for (int i = 0; i < N; i++) {
				if (strcmp(barcodes[i], tmp) == 0) {
					printf("%s, price: %.2f, diccount: %.2f %\n", products[i], price[i], discount[i]);
					array[i] += 1;
				}
			}
		}
	}
}