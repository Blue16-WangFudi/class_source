#include <stdio.h>
struct Student
{
    char name[20];
    int id;
    int age;
    double score;
};

// 定义输入函数
void input(struct Student stu[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("请输入第 %d 个学生的信息： ", i + 1);
        scanf("%s %d %d %lf", stu[i].name, &stu[i].id, &stu[i].age, &stu[i].score);
    }
}

// 定义输出函数
void output(struct Student stu[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("第 %d 个学生的信息： ", i + 1);
        printf("姓名：%s, 学号：%d, 年龄：%d, 成绩：%.2lf ", stu[i].name, stu[i].id, stu[i].age, stu[i].score);
    }
}

int main()
{
    struct Student stu[3]; // 假设有3个学生信息需要输入
    input(stu, 3);         // 调用输入函数
    output(stu, 3);        // 调用输出函数
    return 0;
}