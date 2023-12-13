#include <stdio.h>
#include <stdbool.h>

// 定义棋盘大小11+2
#define SIZE 13
#define MAX 11

bool checkSequence(int *arr, int arr_size, int *sequence, int sequence_size)
{
    // 遍历数组arr，查找是否存在和sequence相匹配的子串
    for (int i = 0; i <= arr_size - sequence_size; ++i)
    {
        bool match = true;

        // 检查arr中的当前位置开始的子串是否和sequence匹配
        for (int j = 0; j < sequence_size; ++j)
        {
            if (arr[i + j] != sequence[j])
            {
                match = false;
                break;
            }
        }

        // 如果找到匹配的子串，返回true
        if (match)
        {
            return true;
        }
    }

    // 如果遍历完整个数组都没有找到匹配的子串，返回false
    return false;
}

bool isActivity3(int arr[], int arr_size) // 判断一个排列是否为活三
{
    /*是否是活三
    “活3”：
    01110
    011010
    010110
    */
    int activity3_1[5] = {0, 1, 1, 1, 0};
    int activity3_2[3][6] = {
        {0, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 1, 0},
    };
    bool isTrue = false;
    for (int i = 0; i < 2; i++)
    {
        
        // 检查 activity3_1
        if (checkSequence(arr, arr_size, activity3_1, 5))
        {
            return true;
        }
        // 检查 activity3_2
        for (int i = 0; i < 2; i++)
        {
            if (checkSequence(arr, arr_size, activity3_2[i], 6))
            {
                return true;
            }
        }
    }
    return false;
}
bool isSleep4(int arr[], int arr_size)
{
    int sleep4_1[2][6] = {
        // 2 1 0 1 1 1 0
        {2, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 2},
    };
    int sleep4_2[6][7] = {
        {0, 1, 0, 1, 1, 1, 2},
        {0, 1, 1, 0, 1, 1, 2},
        {0, 1, 1, 1, 0, 1, 2},
        {2, 1, 0, 1, 1, 1, 0},
        {2, 1, 1, 0, 1, 1, 0},
        {2, 1, 1, 1, 0, 1, 0},
    };
    // 检查 sleep4_1
    for (int i = 0; i < 2; i++)
    {
        if (checkSequence(arr, arr_size, sleep4_1[i], 6))
        {
            return true;
        }
    }
    // 检查 sleep4_2
    for (int i = 0; i < 6; i++)
    {
        if (checkSequence(arr, arr_size, sleep4_2[i], 7))
        {
            return true;
        }
    }
    return false;
}

bool isThreatening(int chessBoard[SIZE][SIZE])
{
    // 检查每一行
    for (int i = 0; i < SIZE; i++)
    {
        if (isActivity3(chessBoard[i], SIZE) || isSleep4(chessBoard[i], SIZE))
        {
            return true;
        }
    }
    // 检查每一列，先取出每一列的数据
    // i表示列数，j表示行数
    for (int i = 0; i < SIZE; i++)
    {
        // 第i列的数据
        int col[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            col[j] = chessBoard[j][i];
        }
        if (isActivity3(col, SIZE) || isSleep4(col, SIZE))
        {
            return true;
        }
    }
    // 检查主对角线平行的(两个坐标方向)
    int rows = SIZE;
    int cols = SIZE;
    // 提取主对角线平行的数字串
    for (int k = 0; k < rows + cols - 1; k++)
    {
        int temp[SIZE];
        for (int i = 0; i < rows; i++)
        {
            int j = k - i;
            if (j >= 0 && j < cols)
            {
                temp[i] = chessBoard[i][j];
            }
        }
        if (isActivity3(temp, SIZE) || isSleep4(temp, SIZE))
        {
            return true;
        }
    }

    // 提取副对角线平行的数字串
    for (int k = 0; k < rows + cols - 1; k++)
    {
        int temp[SIZE];
        for (int i = 0; i < rows; i++)
        {

            int j = k - (rows - 1 - i);
            if (j >= 0 && j < cols)
            {
                temp[i] = chessBoard[i][j];
            }
        }
        if (isActivity3(temp, SIZE) || isSleep4(temp, SIZE))
        {
            return true;
        }
    }
    return false;
}
// 添加外边框的函数实现
void addBorder(int cheesBoard[MAX][MAX], int chessBoard1[MAX + 2][MAX + 2]) {
    // 将内部元素复制到带有外边框的矩阵中
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            chessBoard1[i + 1][j + 1] = cheesBoard[i][j];
        }
    }

    // 将外边框的元素赋值为2
    for (int i = 0; i < MAX + 2; i++) {
        chessBoard1[i][0] = 2;
        chessBoard1[i][MAX + 1] = 2;
    }

    for (int j = 0; j < MAX + 2; j++) {
        chessBoard1[0][j] = 2;
        chessBoard1[MAX + 1][j] = 2;
    }
}
int main()
{

    int arr_test[8] = {0, 1, 1, 0, 1, 1, 0, 0};
    int seq_test[6] = {0, 1, 1, 0, 1, 0}; // 活三
    // printf("isActivity3 = %d", isSleep4(arr_test, 8));
    //  读取棋盘矩阵,考虑到边界处理
    int chessBoard[MAX][MAX];
    int chessBoard1[SIZE][SIZE];
    printf("军师分析：请汇报当前局势情况（输入棋盘矩阵）：\n");
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d", &chessBoard[i][j]);
        }
    }

    // 添加边缘，处理边界情况
    addBorder(chessBoard, chessBoard1);

    //  判断是否构成先手威胁
    if (isThreatening(chessBoard1))
    {
        printf("军师建议：构成先手威胁,快速速解决\n");
    }
    else
    {
        printf("军师建议：没有构成先手威胁，放心放心\n");
    }

    return 0;
}