#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int a[1000]; //массив. 1000 - максимально допустимое количество элементов
int n; // Реальное количество элементов в массиве

void Load() {
	// Открытие входного файла
	FILE* fin = fopen("c:\\Programs\\in7.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}

	// Закрытие входного файла
	fclose(fin);
} 
void SaveResult() {
	// Вычисление среднего арифметического
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	sa = s / n;

	// Выяснение, сколько элементов больше ср арифметического
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			m++;
		}
	} 
	// Открытие выходного файла
	FILE* fout = fopen("c:\\Programs\\out7.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов больших ср арифметического
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (a[i] > sa) {
			fprintf(fout, "%d ", a[i]);
		}
	}
	// Закрытие файла
	fclose(fout);
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task1!\n");

	Load();
	SaveResult();
}
