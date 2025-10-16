#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF 9999
int extractMin(int key[], int mstSet[], int n)
{
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void primMST(int G[MAX][MAX], int n, int start)
{
    int dist[MAX], pred[MAX];
    int mstSet[MAX];
    int costAdj[MAX][MAX];
    int totalCost = 0;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        mstSet[i] = 0;
        pred[i] = -1;
        for (int j = 0; j < n; j++)
            costAdj[i][j] = 0;
    }
    dist[start - 1] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = extractMin(dist, mstSet, n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (G[u][v] && mstSet[v] == 0 && G[u][v] < dist[v])
            {
                dist[v] = G[u][v];
                pred[v] = u;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (pred[i] != -1)
        {
            costAdj[i][pred[i]] = costAdj[pred[i]][i] = G[i][pred[i]];
            totalCost += G[i][pred[i]];
        }
    }
    printf("\nCost Adjacency Matrix of Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", costAdj[i][j]);
        printf("\n");
    }
    ("\nTotal Weight of the Spanning Tree: %d\n", totalCost);
}
int main()
{
    int n, start;
    int G[MAX][MAX];
    FILE *fp;
    fp = fopen("inUnAdjMat.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &G[i][j]);
    }
    fclose(fp);
    primMST(G, n, start);
    return 0;
}