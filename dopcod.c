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