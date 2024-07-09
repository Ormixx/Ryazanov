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
}