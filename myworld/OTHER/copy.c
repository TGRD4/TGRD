

void flush()    
{
    FILE* fp;
    char filename[100];
    int i, k = 0;
    printf("请输入需要刷新的文件名：\n");
    getchar();
    gets(filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for (i = 0; i < N; i++)
    {
        if (fread(&stu[i], sizeof(struct STU), 1, fp) == 1)
            k++;
    }
    n = k;
    if (k == 0) printf("刷新失败！\n");
    else printf("刷新成功！\n");
    fclose(fp);
    system("pause");
}


