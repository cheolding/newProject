#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 7

typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; // ���� ����
	int cols; // ���� ����
	int terms; // ���� ����
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix* a)
{
	SparseMatrix b;
	int bindex; // ��� b���� ���� ���� ��ġ
	b.rows = a->rows;
	b.cols = a->cols;
	b.terms = a->terms;
	if (a->terms > 0) {
		bindex = 0;
		for (int c = 0; c < a->cols; c++) {
			for (int i = 0; i < a->terms; i++) {
				if (a->data[i].col == c) {
					b.data[bindex].row = a->data[i].col;
					b.data[bindex].col = a->data[i].row;
					b.data[bindex].value = a->data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}
void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("%d %d %d \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}
int main(void)
{
	int row, col, term;
	printf("Enter the size of rows and colums,the number of non-zero terms :");
	scanf("%d %d %d", &row, &col, &term);
	SparseMatrix* m = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	m->rows = row;
	m->cols = col;
	m->terms = term;

	printf("Enter row colume ,and value pairs in order\n");
	for (int i = 0; i < m->terms; i++)
	{
		scanf("%d %d %d", &m->data[i].row, &m->data[i].col, &m->data[i].value);
	}
	SparseMatrix  result;
	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}