#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

// Define the number of cities
int numCities;
int adjacency[MAX_CITIES][MAX_CITIES];

// Variables to keep track of the best path
int bestPath[MAX_CITIES];
int bestDistance = INT_MAX;

// Array to keep track of visited cities
int visited[MAX_CITIES];

// Function to calculate the total distance of a path
int calculatePathDistance(int path[])
{
    int distance = 0;
    for (int i = 0; i < numCities - 1; i++)
    {
        distance += adjacency[path[i]][path[i + 1]];
    }
    distance += adjacency[path[numCities - 1]][path[0]]; // Return to the starting city
    return distance;
}

// Function to find the shortest path using backtracking
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
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < numCities; i++)
    {
        for (int j = 0; j < numCities; j++)
        {
            scanf("%d", &adjacency[i][j]);
        }
    }

    int path[MAX_CITIES];
    path[0] = 0; // Starting city
    visited[0] = 1;
    findShortestPath(0, 1, path);

    printf("Shortest path: ");
    for (int i = 0; i < numCities; i++)
    {
        printf("%d ", bestPath[i]);
    }
    printf("\nShortest distance: %d\n", bestDistance);

    return 0;
}
