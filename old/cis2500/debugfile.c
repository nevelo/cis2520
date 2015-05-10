int debugFile(unsigned char * state)
{
    *(state+99) = *(state+99) + 1;
    FILE * log;
    int i;
    char fname[10];
    
    sprintf(fname, "data/log/log.%d", *(state+99));
    log = fopen(fname, "w+");
    if (log == NULL) return 1;
    for (i = 0; i < MEMORY_REQ; i++)
    {
        fprintf(log, "%3d: %3d  ", i, (int)*(state+i));
        if (((i+1)%8) == 0) fprintf(log, "\n");
    }
    fprintf(log, "\n");
    fprintf(log, "%s\n", (state+41));
    fprintf(log, "%s\n", (state+57));
    fclose(log);
    return 0;
}
