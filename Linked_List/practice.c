#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
// Number of flats (vertices)
#define V 9

//function to find minimum path
int minDistance(int dist[], bool visited[])
{
	int min = INT_MAX, min_index;
	for (int k = 0; k < V; k++)
		if (visited[k] == false && dist[k] <= min)
			min = dist[k], min_index = k;
	return min_index;
}

int display(int dist[])
{
	printf("Flats \t\t Distance from source\n");
	for (int i = 0+65; i < V+65; i++)
		printf("%c \t\t %d\n", i, dist[i-65]);
}

void dijkstra(int safety[V][V], int safe_place) // index number of safe place in tne building
{
	int dist[V]; // array dist[i] will hold the shortest distance from safest place to other flats
	bool visited[V];// holds true for the vertex(flats) which are visited

	// Initialize all distances as INFINITE and visited array  as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, visited[i] = false;

	dist[safe_place] = 0; 	// Distance of source vertex from itself is  0

	// Find shortest path for all (vertices)flats
	for (int count = 0; count < V - 1; count++) {
        // select the minimum distance vertices(flats ) which  are not
        // yet visited
        int c = minDistance(dist, visited);

        // Mark the visited vertex as true
        visited[c] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int k = 0; k < V; k++)

            // Update dist[k] only if is not visited and
            if (!visited[k] && safety[c][k] && dist[c] != INT_MAX
                && dist[c] + safety[c][k] < dist[k])
                dist[k] = dist[c] + safety[c][k];
    }
	display(dist);
}

// driver program to test above function
int main()
{
    int choice;
     printf("SAFEST PLACE \n");
     printf("1.RECEPTION HALL (A)\n");
     printf("2.SEMINAR HALL (B)\n");
     printf("-----------**************-------------");
     scanf("%d",&choice);
    // adjacency matrix representation
	//sample matrix taken for building the structure for flats and the space between them (corridors)
	int safety[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 15, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 20 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 10, 6 },
						{ 8, 15, 0, 0, 0, 0, 10, 0, 0 },
						{ 0, 0, 20, 0, 0, 0, 6, 0, 0 } };

	dijkstra(safety, choice-1);// index number of safe place in flat
	return 0;
}