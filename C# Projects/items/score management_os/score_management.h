#include "stdio.h"
#include "string.h"
#define MAX 1000
#include "stdlib.h"
#include "errno.h"


struct management
{
    int id_number;
    char name[20];
    float math;
    float chinese;
    float english;
};

//成绩管理系统类型
struct managementInfo
{
    struct management manage[MAX]; //存放信息
    int size;    //记录当前已经有的元素个数
};
void InitInfo(struct managementInfo* ps)
{
    memset(ps->manage,0,sizeof(ps->manage));
    ps->size=0;//设置类型大小为0个元素
}
void CreatInfo(struct managementInfo* ps)
{
    int i;
    do
    {
        printf("请输入学号:>");
        scanf("%d",&(ps->manage[ps->size].id_number));
        i = ps->manage[ps->size].id_number;
        if(i==0)
        {
            ps->manage[ps->size].id_number='\0';
            break;
        }
        printf("请输入姓名:>");
        scanf("%s",ps->manage[ps->size].name);
        printf("请输入数学:>");
        scanf("%f",&(ps->manage[ps->size].math));
        printf("请输入语文:>");
        scanf("%f",&(ps->manage[ps->size].chinese));
        printf("请输入英语:>");
        scanf("%f",&(ps->manage[ps->size].english));
        ps->size++;
    } while (1);

}
void ADDInfo(struct managementInfo* ps)
{
    if (ps->size==MAX)
        printf("学生数量已满，需增加\n");
    else
    {
        do{
            printf("请输入学号:>");
            scanf("%d",&(ps->manage[ps->size].id_number));
            printf("请输入姓名:>");
            scanf("%s",ps->manage[ps->size].name);
            printf("请输入数学:>");
            scanf("%f",&(ps->manage[ps->size].math));
            printf("请输入语文:>");
            scanf("%f",&(ps->manage[ps->size].chinese));
            printf("请输入英语:>");
            scanf("%f",&(ps->manage[ps->size].english));
            ps->size++;
            printf("添加成功\n%d",ps->size);
        } while (ps->manage[ps->size].id_number);
    }
}
void SHOW(const struct managementInfo* ps)
{
        if(ps->size==0)
        {
            printf("没有可打印学生\n");
        }
        else
        {
            int i;
            printf("%s  %s  %s    %s    %s\n","学号","姓名","数学","语文","英语");
            for(i=0;i<ps->size;i++)
            {
                printf("%d  %4s   %.1f   %.1f  %.1f\n",ps->manage[i].id_number,
                ps->manage[i].name,
                ps->manage[i].math,
                ps->manage[i].chinese,
                ps->manage[i].english);
            }
        }

}
//删除学生
void DELInfo(struct managementInfo* ps)
{
    int i;   //删除学生的学号
    printf("请输入要删除的学号:>");
    scanf("%d",&i);
    i--;
    int _bool=0;
    for(int j=1;j<ps->size;j++)
    {
        if(i==j)
        {
            for(i=j;i<=ps->size;i++)
            {
                ps->manage[i].id_number=ps->manage[i+1].id_number;
                strcpy(ps->manage[i].name,ps->manage[i+1].name);
                ps->manage[i].math=ps->manage[i+1].math;
                ps->manage[i].chinese=ps->manage[i+1].chinese;
                ps->manage[i].english=ps->manage[i+1].english;
            }
            ps->size--;
            _bool=1;
            break;
        }
    }
    if(_bool==0)
        printf("删除的学生不存在\n");
}
//修改学生信息
void EditInfo(struct managementInfo* ps)
{
    int i,j;
    printf("请输入需要修改的学生的学号:>");
    scanf("%d",&i);
    int _bool=0;
    for(j=0;j<=ps->size;j++)
    {
        if(ps->manage[j].id_number==i)
        {
            _bool=1;
            printf("当前正在修改学号为%d，姓名为%s的学生信息\n",i,ps->manage[j].name);
            printf("请输入学号:>");
            scanf("%d",&(ps->manage[j].id_number));
            printf("请输入姓名:>");
            scanf("%s",ps->manage[j].name);
            printf("请输入数学:>");
            scanf("%f",&(ps->manage[j].math));
            printf("请输入语文:>");
            scanf("%f",&(ps->manage[j].chinese));
            printf("请输入英语:>");
            scanf("%f",&(ps->manage[j].english));
            printf("修改成功\n");
        }
    }
    if(_bool==0)
    {
        printf("查无此人\n");
    }
}
//统计成绩
void CountInfo(struct managementInfo* ps)
{
    if(ps->size==0)
        printf("表单内无人");
    int i,j,sum=0;
    for(i=0;i<ps->size;i++)
    {
        if((ps->manage[i].english>=90)&&(ps->manage[i].chinese>=90)&&(ps->manage[i].math>=90))
        {
            sum++;
        }
    }
    printf("优秀人数为%d\n",sum);
}
//排序
void RankInfo(struct managementInfo* ps)
{
    int i,j,k;
    if(ps->size<=1)
        printf("人数少于2人不做排序\n");
    else
    {
        printf("**********排序菜单***********\n");
        printf("*******1--按学号升序排列******\n");
        printf("*****2--按平均成绩升序排列*****\n");
        printf("**********排序菜单***********\n");
        printf("请输入编号(1~2):>");
        scanf("%d",&k);
        switch (k) {
            case 1:
            {
                for(i=0;i<ps->size;i++)
                {
                    for (j=0; j < ps->size - i; j++)
                    {
                        if ((ps->manage[j].id_number) < (ps->manage[j + 1].id_number))
                        {
                            int id_number,english,math,chinese;
                            char name[20];
                            id_number = ps->manage[j].id_number;
                            ps->manage[j].id_number=ps->manage[j+1].id_number;
                            ps->manage[j+1].id_number=id_number;
                            strcpy(name,ps->manage[j].name);
                            strcpy(ps->manage[j].name,ps->manage[j+1].name);
                            strcpy(ps->manage[j+1].name,name);
                            math = ps->manage[j].math;
                            ps->manage[j].math=ps->manage[j+1].math;
                            ps->manage[j+1].math=math;
                            chinese = ps->manage[j].chinese;
                            ps->manage[j].chinese=ps->manage[j+1].chinese;
                            ps->manage[j+1].chinese=chinese;
                            english = ps->manage[j].english;
                            ps->manage[j].english=ps->manage[j+1].english;
                            ps->manage[j+1].english=english;
                        }
                    }
                }
            }
                break;
            case 2:
            {
                double avg[ps->size],sum;
                for(i=0;i<ps->size;i++)
                {
                    sum=(ps->manage[i].english)+(ps->manage[i].math)+(ps->manage[i].chinese);
                    avg[i]=sum/3.0;
                }
                for(i=0;i<ps->size;i++)
                {
                    for (j = i; j < ps->size - i; j++)
                    {
                        if (avg[j] < avg[j+1])
                        {
                            int id_number,english,math,chinese;
                            char name[20];
                            id_number = ps->manage[j].id_number;
                            ps->manage[j].id_number=ps->manage[j+1].id_number;
                            ps->manage[j+1].id_number=id_number;
                            strcpy(name,ps->manage[j].name);
                            strcpy(ps->manage[j].name,ps->manage[j+1].name);
                            strcpy(ps->manage[j+1].name,name);
                            math = ps->manage[j].math;
                            ps->manage[j].math=ps->manage[j+1].math;
                            ps->manage[j+1].math=math;
                            chinese = ps->manage[j].chinese;
                            ps->manage[j].chinese=ps->manage[j+1].chinese;
                            ps->manage[j+1].chinese=chinese;
                            english = ps->manage[j].english;
                            ps->manage[j].english=ps->manage[j+1].english;
                            ps->manage[j+1].english=english;
                        }
                    }
                }
            }
                break;
            default:
                printf("输入错误\n");
                break;

        }
    }

}
void OutputInfo(struct managementInfo* ps) {
    FILE *pfWrite = fopen("/Users/mrqi/Documents/C_Projects/items/score management_os/Info.txt", "w+");
    if (pfWrite == NULL) {
        printf("%s\n", strerror(errno));
    }
    //写入
    else
    {
        int i = 0;
        for (i = 0; i < ps->size; i++)
        {
            fprintf(pfWrite,"%d    %s   %.2f   %.2f   %.2f\n",ps->manage[i].id_number,ps->manage[i].name,ps->manage[i].chinese,ps->manage[i].math,ps->manage[i].english);
        }
    }

    //关闭文件
    fclose(pfWrite);
    pfWrite = NULL;
}
void LoadInfo(struct managementInfo* ps)
{
    FILE* pfread= fopen("/Users/mrqi/Documents/C_Projects/items/score management_os/Info.txt","r+");
    if(pfread==NULL)
        printf("%s", strerror(errno));
    else
    {
        while (!feof(pfread))
        {
            fscanf(pfread,"%d    %s   %f   %f   %f\n",&ps->manage[ps->size].id_number,ps->manage[ps->size].name,&ps->manage[ps->size].chinese,&ps->manage[ps->size].math,&ps->manage[ps->size].english);
            ps->size++;
        }
    }
    fclose(pfread);
    pfread=NULL;
}
