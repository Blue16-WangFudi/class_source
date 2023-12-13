#include <stdio.h>

//冒泡排序
void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int n;

    printf("输入要排序的数据个数: ");
    scanf("%d", &n);

    int arr[n];

    
    for (int i = 0; i < n; i++)
    {
        printf("输入第%d个整数:", i+1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("排序结果: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
