#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int Count(char* file, int choice);

int main(int argc, char* argv[])               //argv[1]保存指令，argv[2]保存文件路径
{
    FILE* fp;
    while (1)
    {
        if (strcmp(argv[1], "-e") == 0)
        {
            printf("程序结束!\n");
            break;
        }
        else {
            if ((fp = fopen(argv[2], "r")) == NULL)
            {
                printf("该文件不存在！\n\n\n");
                scanf("%s%s", argv[1], argv[2]);
                continue;
            }
            else if (strcmp(argv[1], "-c") == 0)                   //统计文件字符数
                printf("文件%s字符数为:%d\n", argv[2], Count(argv[2], 0));
            else if (strcmp(argv[1], "-w") == 0)                   //统计文件单词数
                printf("文件%s单词数为:%d\n", argv[2], Count(argv[2], 1));
            else
                printf("该指令不存在，请重新输入\n");
            printf("\n\n");
            scanf("%s%s", argv[1], argv[2]);
        }
    }
    return 0;

}


int Count(char* file, int choice)
{
    FILE* fp;
    char a;
    int Charcount = 0;
    int Wordcount = 0;
    int breakp = 1;
    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("读文件失败！\n");
        exit(-1);
    }
    if (choice == 0){
        while (!feof(fp))
        {
            a = fgetc(fp);

            Charcount++;
        }
        fclose(fp);
        return Charcount - 1;
    }
    else if (choice == 1) {
        while (!feof(fp))
        {   
            a = fgetc(fp);
            if (a == ' ' || a == ',' || a == '\n' || a == '.')
            {
                breakp = 1;
            }
            if ((('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')) && (breakp == 1)) {
                Wordcount++;
                breakp = 0;
            }
        }
        fclose(fp);
        return Wordcount;
    }
//    Charcount--;          //at end of the file,Charcount will add
}