#include<stdio.h>
#include<stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    double **mat;
} matrix_t;


matrix_t *mat_new(int r, int c){
    matrix_t *m = malloc (sizeof (struct matrix));
    m->rows = r;
    m->cols = c;
    m->mat = malloc(r*sizeof(*m->mat));
    for(int i=0;i<c;++i)
        m->mat[i] = calloc(c, sizeof(**m->mat));
    return m;
}

matrix_t *mat_frd(char* fname){
    int r = 0, c = 0;
    matrix_t *mfile = NULL;
    FILE * matrix_file = fopen(fname, "r");
    fscanf(matrix_file, "%d %d", &r, &c);
    mfile = mat_new(r, c);
    for(r = 0; r < mfile->rows; ++r)
        for(c = 0; c< mfile->cols; ++c)
           fscanf(matrix_file, "%lf", &mfile->mat[r][c]);

    fclose(matrix_file);

    return mfile;
}

int main(void){
    int r, c;
    matrix_t *m = mat_frd("data.txt");
    if (!m) {
        fprintf (stderr,"\n  mat_frd() returned NULL, read failed\n\n");
    }

    for(r = 0; r < m->rows; ++r){
        for(c = 0; c < m->cols; ++c)
            printf("%5.1f ", m->mat[r][c]);
        printf("\n");
    }

    mat_delete(m);
    return 0;
}