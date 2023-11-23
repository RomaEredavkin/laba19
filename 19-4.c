#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int* pa; //Указатель на массив. 
int n;
void Load() {
	// Открытие входного файла
	FILE* fin = fopen("c:\\Programs\\in9.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	// Закрытие входного файла
	fclose(fin);
}
void SaveResult() {
	// Вычисление среднего арифметического
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (sa < pa[i]) {
			sa = pa[i];
		}
	}
	
		// Выяснение, сколько элементов больше ср арифметического
	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((sa * 0.6) < pa[i]) {
			m++;
		}
	}
	FILE* fout = fopen("c:\\Programs\\out10.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов больших ср арифметического
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if ((sa * 0.6) < pa[i]) {
			fprintf(fout, "%d ", pa[i]);
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

	free(pa);
}