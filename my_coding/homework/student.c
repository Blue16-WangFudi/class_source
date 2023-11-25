#include <stdio.h>
struct CourseGrade
{
    char courseName[50];
    int credits;
    float grade;
};
#define MAX_COURSES 10
struct CourseGrade gradeBook[MAX_COURSES];
int numCourses = 0;
// Function to input course grades
void inputGrades()
{
    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);

    for (int i = 0; i < numCourses; i++)
    {
        printf("Enter the name of course %d: ", i + 1);
        scanf("%s", gradeBook[i].courseName);

        printf("Enter the number of credits for course %d: ", i + 1);
        scanf("%d", &gradeBook[i].credits);

        printf("Enter the grade for course %d (0-100): ", i + 1);
        scanf("%f", &gradeBook[i].grade);
    }
}

// Function to calculate GPA (Grade Point Average)
float calculateGPA()
{
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++)
    {
        totalGradePoints += (gradeBook[i].grade * gradeBook[i].credits);
        totalCredits += gradeBook[i].credits;
    }

    if (totalCredits == 0)
    {
        return 0.0;
    }

    return totalGradePoints / totalCredits;
}

// Function to display course grades
void displayGrades()
{
    printf("\nCourse Grades for this Semester:\n");
    for (int i = 0; i < numCourses; i++)
    {
        printf("Course Name: %s\n", gradeBook[i].courseName);
        printf("Credits: %d\n", gradeBook[i].credits);
        printf("Grade: %.2f\n", gradeBook[i].grade);
        printf("\n");
    }
    printf("GPA: %.2f\n", calculateGPA());
}

int main()
{
    inputGrades();
    displayGrades();

    return 0;
}
