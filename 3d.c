#include <stdio.h>
#include <stdlib.h>
#include "LinAlg.c"

typedef struct Shape Shape;
struct Shape {
	Vector **corners;
};

void Shape_Create_Cube(Shape *s)
{
	s->corners = (Vector **)malloc(sizeof(Vector*) * 8);


	double *points[] = {
		(double[]){0,0,0},
		(double[]){0,0,2},
		(double[]){0,2,0},
		(double[]){0,2,2},
		(double[]){2,0,0},
		(double[]){2,0,2},
		(double[]){2,2,0},
		(double[]){2,2,2},
	};

	double *p0 = malloc(sizeof(double) * 4);
	double *p1 = malloc(sizeof(double) * 4);
	double *p2 = malloc(sizeof(double) * 4);
	double *p3 = malloc(sizeof(double) * 4);
	double *p4 = malloc(sizeof(double) * 4);
	double *p5 = malloc(sizeof(double) * 4);
	double *p6 = malloc(sizeof(double) * 4);
	double *p7 = malloc(sizeof(double) * 4);

	int i = 0;
	while (i < 3)
	{
		p0[i] = points[0][i];
		p1[i] = points[1][i];
		p2[i] = points[2][i];
		p3[i] = points[3][i];
		p4[i] = points[4][i];
		p5[i] = points[5][i];
		p6[i] = points[6][i];
		p7[i] = points[7][i];
		i++;
	}
	p0[3], p1[3], p2[3], p3[3], p4[3], p5[3], p6[3], p7[3] = 
		0, 0, 0, 0, 0, 0, 0, 0;

	s->corners[0] = Vector_Create_Array(p0, 4);
	s->corners[1] = Vector_Create_Array(p1, 4);
	s->corners[2] = Vector_Create_Array(p2, 4);
	s->corners[3] = Vector_Create_Array(p3, 4);
	s->corners[4] = Vector_Create_Array(p4, 4);
	s->corners[5] = Vector_Create_Array(p5, 4);
	s->corners[6] = Vector_Create_Array(p6, 4);
	s->corners[7] = Vector_Create_Array(p7, 4);
}

int main(int argc, char *argv[])
{
	Shape *s = (Shape *)malloc(sizeof(Shape));
	Shape_Create_Cube(s);
	if (s != NULL)
	{
		printf("Its not null\n");
	}
	int i = 0;
	while (i < 8)
	{
		printf("%.2f %.2f %.2f\n", s->corners[i]->data[0], s->corners[i]->data[1],s->corners[i]->data[2]);
		i++;
	}
}
