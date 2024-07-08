#include<stdio.h>
#include<stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    double **mat;
} matrix_t;
#define SCN_MAT "lf"
#define PRN_MAT "f"

matrix_t *mat_new(int r, int c){
    matrix_t *m = malloc (sizeof (struct matrix));
    m->rows = r;
    m->cols = c;
    m->mat = malloc(r*sizeof(*m->mat));
    for(int i=0;i<c;++i)
        m->mat[i] = calloc(c, sizeof(**m->mat));
    return m;
}