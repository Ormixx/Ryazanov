matrix_t *mat_frd(char* fname){
    int r = 0, c = 0;
    matrix_t *mfile = NULL;
    FILE * matrix_file = fopen(fname, "r");
    fscanf(matrix_file, "%d %d", &r, &c);
    mfile = mat_new(r, c);
    for(r = 0; r < mfile->rows; ++r)
        for(c = 0; c< mfile->cols; ++c)
            fscanf(matrix_file, "%" SCN_MAT, &mfile->mat[r][c]);

    fclose(matrix_file);

    return mfile;

int main(void){
    int r, c;
    matrix_t *m = mat_frd("data.txt");
    if (!m) {
        fprintf (stderr,"\n  mat_frd() returned NULL, read failed\n\n");
        return 1;
    }

    for(r = 0; r < m->rows; ++r){
        for(c = 0; c < m->cols; ++c)
            printf("%5.1" PRN_MAT " ", m->mat[r][c]);
        printf("\n");
    }

    return 0;
}