#include <stdio.h>

// 一个学生的结构体
struct StudentGrade {
    char name[50];
    float grade;
};

// 计算平均成绩
float calculateAverage(struct StudentGrade grades[], int numStudents) {
    float total = 0.0;

    for (int i = 0; i < numStudents; ++i) {
        total += grades[i].grade;
    }

    return total / numStudents;
}

// 计算最高成绩
float findMaximum(struct StudentGrade grades[], int numStudents) {
    float maximum = grades[0].grade;

    for (int i = 1; i < numStudents; ++i) {
        if (grades[i].grade > maximum) {
            maximum = grades[i].grade;
        }
    }

    return maximum;
}

// 计算最低成绩
float findMinimum(struct StudentGrade grades[], int numStudents) {
    float minimum = grades[0].grade;

    for (int i = 1; i < numStudents; ++i) {
        if (grades[i].grade < minimum) {
            minimum = grades[i].grade;
        }
    }

    return minimum;
}

int main() {
    int numStudents;

    printf("输入学生个数: ");
    scanf("%d", &numStudents);

    // 存储所有学生成绩，使用刚才定义的结构体
    struct StudentGrade grades[numStudents];

    // 导入学生数据
    for (int i = 0; i < numStudents; ++i) {
        printf("输入第 %d 个学生名称: ", i + 1);
        scanf("%s", grades[i].name);
        printf("输入 %s 的成绩: ", grades[i].name);
        scanf("%f", &grades[i].grade);
    }

    // 输出每个人的成绩
    printf("班级学生成绩:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("%s: %.2f\n", grades[i].name, grades[i].grade);
    }

    // 输出平均成绩
    printf("平均成绩: %.2f\n", calculateAverage(grades, numStudents));

    // 输出最高成绩
    printf("最高成绩: %.2f\n", findMaximum(grades, numStudents));

    // 输出最低成绩
    printf("最低成绩: %.2f\n", findMinimum(grades, numStudents));

    return 0;
}
