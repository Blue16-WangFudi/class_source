#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算阶乘的函数
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// 计算距离矩阵的函数（模拟）
int getDistance(char *city1, char *city2) {
    // 模拟从百度地图检索距离
    // 用实际实现替换
    return rand() % 100 + 1;  // 模拟1到100之间的距离
}

// 使用TSP找到最优路径的函数
void findOptimalPath(char **cities, int n) {
    int *permutation = (int *)malloc(n * sizeof(int));
    int *minPermutation = (int *)malloc(n * sizeof(int));
    int minDistance = INT_MAX;  // 初始设为最大可能值

    // 初始化排列
    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }

    // 枚举所有排列
    do {
        int currentDistance = 0;

        // 计算当前排列的总距离
        for (int i = 0; i < n - 1; i++) {
            currentDistance += getDistance(cities[permutation[i]], cities[permutation[i + 1]]);
        }
        currentDistance += getDistance(cities[permutation[n - 1]], cities[permutation[0]]);

        // 更新最小距离和最优排列
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            memcpy(minPermutation, permutation, n * sizeof(int));
        }
    } while (next_permutation(permutation, permutation + n));

    // 输出最优路径和总距离
    printf("Optimal Path: ");
    for (int i = 0; i < n; i++) {
        printf("%s -> ", cities[minPermutation[i]]);
    }
    printf("%s\n", cities[minPermutation[0]]);
    printf("Total Distance: %d\n", minDistance);

    // 释放内存
    free(permutation);
    free(minPermutation);
}

int main() {
    // 使用4个城市的示例
    char *cities[] = {"城市A", "城市B", "城市C", "城市D"};
    int numCities = sizeof(cities) / sizeof(cities[0]);

    // 计算排列的阶乘
    int numPermutations = factorial(numCities);

    // 找到最优路径
    findOptimalPath(cities, numCities);

    return 0;
}
