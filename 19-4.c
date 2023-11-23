#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int* pa; //��������� �� ������. 
int n;
void Load() {
	// �������� �������� �����
	FILE* fin = fopen("c:\\Programs\\in9.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}
	// �������� ������� �� �������� �����
	fscanf(fin, "%d", &n);
	// ��������� ������ ��� ������������ ������
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	// �������� �������� �����
	fclose(fin);
}
void SaveResult() {
	// ���������� �������� ���������������
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
	
		// ���������, ������� ��������� ������ �� ���������������
	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((sa * 0.6) < pa[i]) {
			m++;
		}
	}
	FILE* fout = fopen("c:\\Programs\\out10.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������\n");
		return;
	}

	// ���������� ��������� ������� �� ���������������
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if ((sa * 0.6) < pa[i]) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	// �������� �����
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