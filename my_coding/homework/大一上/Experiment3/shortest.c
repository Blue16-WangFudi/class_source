#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 10

// 城市数量和距离矩阵2
int numCities;
int adjacency[MAX_CITIES][MAX_CITIES];

// 存储最佳路径
int bestPath[MAX_CITIES];
int bestDistance = INT_MAX;

// 保存每个城市的访问状态
int visited[MAX_CITIES];

// 计算总距离
int calculatePathDistance(int path[])
{
    int distance = 0;
    for (int i = 0; i < numCities - 1; i++)
    {
        distance += adjacency[path[i]][path[i + 1]];
    }
    distance += adjacency[path[numCities - 1]][path[0]]; // 返回初始城市
    return distance;
}

// 回溯法确定最短路径
void findShortestPath(int currentCity, int depth, int path[])
{
    if (depth == numCities)
    {
        int distance = calculatePathDistance(path);
        if (distance < bestDistance)
        {
            bestDistance = distance;
            for (int i = 0; i < numCities; i++)
            {
                bestPath[i] = path[i];
            }
        }
        return;
    }

    for (int i = 0; i < numCities; i++)
    {
        if (!visited[i] && adjacency[currentCity][i] != 0)
        {
            visited[i] = 1;
            path[depth] = i;
            findShortestPath(i, depth + 1, path);
            visited[i] = 0;
        }
    }
}

int main()
{
    printf("输入要求解的城市数量: ");
    scanf("%d", &numCities);

    printf("输入距离矩阵:\n");
    for (int i = 0; i < numCities; i++)
    {
        for (int j = 0; j < numCities; j++)
        {
            scanf("%d", &adjacency[i][j]);
        }
    }

    int path[MAX_CITIES];
    path[0] = 0; // 初始城市
    visited[0] = 1;
    findShortestPath(0, 1, path);

    printf("最短路径（index从0开始）: ");
    for (int i = 0; i < numCities; i++)
    {
        printf("%d ", bestPath[i]);
    }
    printf("\n最短距离为: %d\n", bestDistance);

    return 0;
}
