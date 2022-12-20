#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <profileapi.h>
#define _FAMOUNT_H

void merge(unsigned long* a, int lr, int rr, int* ind, int* tmp_ind)
{
	int mid = (lr + rr) / 2;
	int k = 0, i = lr, j = mid + 1;
	unsigned long* arr = (unsigned long*)malloc(rr * sizeof(unsigned long));
	while ((i < mid + 1) && (j <= rr))
	{
		if (a[i] < a[j])
		{
			tmp_ind[k] = ind[i];
			arr[k++] = a[i++];
		}
		else
		{
			tmp_ind[k] = ind[j];
			arr[k++] = a[j++];
		}
	}
	while (i < mid + 1)
	{
		tmp_ind[k] = ind[i];
		arr[k++] = a[i++];
	}
	while (j <= rr)
	{
		tmp_ind[k] = ind[j];
		arr[k++] = a[j++];
	}
	for (i = 0; i < k; i++)
	{
		ind[lr + i] = tmp_ind[i];
		a[lr + i] = arr[i];
	}
}
void merge_sort(unsigned long* a, int l, int r, int* ind, int* tmp_ind)
{
	if (l < r)
	{
		merge_sort(a, l, (l + r) / 2, ind, tmp_ind);
		merge_sort(a, (l + r) / 2 + 1, r, ind, tmp_ind);
		merge(a, l, r, ind, tmp_ind);
	}
}
void InsertSort(unsigned long* arr, int size, int* ind)
{
	int newElement, location, nind;
	for (int i = 1; i < size; i++)
	{
		nind = ind[i];
		newElement = arr[i];
		location = i - 1;
		while (location >= 0 && arr[location] > newElement)
		{
			arr[location + 1] = arr[location];
			ind[location + 1] = ind[location];
			location = location - 1;
		}
		arr[location + 1] = newElement;
		ind[location + 1] = nind;
	}
}
void bubble(unsigned long* arr, int size, int* ind)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				int nind = ind[j + 1];
				ind[j + 1] = ind[j];
				ind[j] = nind;
			}
		}
	}

}
void copychar(char firstarray[], wchar_t secondarray[]);
int filesAmount(char path[], HANDLE hf, WIN32_FIND_DATA FindFileData)
{
	int count = 0;
	hf = FindFirstFileA(path, &FindFileData);
	do {
		if (wcscmp(FindFileData.cFileName, L".") != 0 && wcscmp(FindFileData.cFileName, L"..") != 0)
			count++;
	} while (FindNextFile(hf, &FindFileData) != 0);
	return count;
}

HANDLE hf;
WIN32_FIND_DATA FindFileData;

int main() {
	int i = 0, count, num, start, end;
	char directory[260];;
	gets(directory);
	strcat(directory, "/*");
	hf = FindFirstFileA(&directory, &FindFileData);
	count = filesAmount(directory, hf, FindFileData);
	char** names = (char**)malloc(count * sizeof(char*));
	unsigned long* ASizes = (unsigned long*)malloc(count * sizeof(unsigned long));
	int* tmp_ind = (int*)malloc(count * sizeof(int));
	int* ind = (int*)malloc(count * sizeof(int));
A:	for (int j = 0; j <= count; j++)
	{
		ind[j] = j;
	}
	while ((FindNextFile(hf, &FindFileData) != 0) && (i <= count)) {
		names[i] = (char*)malloc(10 * sizeof(char));
		copychar(names[i], FindFileData.cFileName);
		if ((strcmp(&names, "..") != 0) && (strcmp(&names, ".") != 0)) {
			ASizes[i] = FindFileData.nFileSizeLow;
		}
		printf("%s\t%ld\n", names[i], ASizes[i]);
		i++;
	}
	printf("count of file =%d\n", count);
	printf("enter sort number -> 1-bubble sort, 2 - insert sort, 3 - merge sort\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1: start = clock();
		bubble(ASizes, count, ind);
		end = clock();
	case 2: start = clock();
		InsertSort(ASizes, count, ind);
		end = clock();
	case 3: start = clock();
		merge_sort(ASizes, 0, count, ind, tmp_ind);
		end = clock();
	}
	for (int i = 0; i <= count; i++)
	{
		int tmp = ind[i];
		printf("%s\t%ld\n", names[tmp], ASizes[i]);
	}
	printf("time = %lf\n", (end - start) / (CLOCKS_PER_SEC));
	printf("choose a different sorting method ? 1 - yes, 0 - no\n");
	int choise;
	scanf("%d", &choise);
	if (choise == 1)
	goto A;
	return 0;
}

void copychar(char firstarray[], wchar_t secondarray[]) {
	int i = 0;
	while (strcmp(&secondarray[i], "\0") != 0) {
		firstarray[i] = secondarray[i];
		i++;
	}
	strcpy(&firstarray[i], "\0");
}
