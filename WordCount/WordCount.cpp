#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void Count(char* file);
int Charcount = 0;
int Wordcount = 0;
int Hangcount = 0;

int main(int argc, char* argv[])               //argv[1]保存指令，argv[2]保存文件路径
{
    FILE* fp;
    Count(argv[2]);
    while (1)
    {
        if ((fp = fopen(argv[2], "r")) == NULL)
        {
            printf("该文件不存在！\n\n\n");
            scanf("%s%s%s", argv[0], argv[1], argv[2]);
            continue;
        }
        else if (strcmp(argv[1], "-c") == 0)                   //统计文件字符数
            printf("文件%s字符数为:%d\n", argv[2], Charcount);
        else if (strcmp(argv[1], "-w") == 0)                   //统计文件单词数
            printf("文件%s单词数为:%d\n", argv[2], Wordcount);
        else if (strcmp(argv[1], "-e") == 0)
        {
            printf("程序结束!\n");
            break;
        }
        else
            printf("该指令不存在，请重新输入\n");
        printf("\n\n");
        scanf("%s%s%s", argv[0], argv[1], argv[2]);
    }
    return 0;

}


void Count(char* file)
{
    FILE* fp;
    char a;
    int breakp = 1;
    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("读文件失败！\n");
        exit(-1);
    }
    while (!feof(fp))
    {
        a = fgetc(fp);

        Charcount++;
        if (a == ' ' || a == ','|| a=='\n' || a=='.')
        {
            breakp=1;
        }
        if ((('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')) && (breakp == 1)) {
            Wordcount++;
            breakp = 0;
        }
    }
    Charcount--;          //at end of the file,Charcount will add
    fclose(fp);
}