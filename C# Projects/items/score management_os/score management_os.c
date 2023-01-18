#include "score_management.h"
void warn()
{
    printf("**********成绩管理系统***********\n");
    printf("**1--创建成绩        2--添加学生**\n");
    printf("**3--编辑学生        4--删除学生**\n");
    printf("**5--统计成绩        6--排序成绩**\n");
    printf("**7--显示成绩        8--文件读入**\n");
    printf("**9--输出文件        0--退出程序**\n");
    printf("**********成绩管理系统***********\n");
    printf("请输入:>");
}

int main()
{
    struct managementInfo Info;
    //初始化
    InitInfo(&Info);
    int input;
    do
    {
        warn();
        scanf("%d",&input);
        switch (input)
        {
            case 0:printf("退出程序\n");
                break;
            case 1:CreatInfo(&Info);
                break;
            case 2:ADDInfo(&Info);
                break;
            case 3:EditInfo(&Info);
                break;
            case 4:DELInfo(&Info);
                break;
            case 5:CountInfo(&Info);
                break;
            case 6:RankInfo(&Info);
                break;
            case 7:SHOW(&Info);
                break;
            case 8:LoadInfo(&Info);
                break;
            case 9:OutputInfo(&Info);
                break;
            default:printf("输入错误,请重新输入\n");
            fflush(stdin);
                break;
        }

    } while (input);


    return 0;
}
