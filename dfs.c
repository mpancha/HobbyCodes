/* 
 * Author: Mitul Panchal
 * Description: Path Finding using Depth First Search
 * 
 * Input:  Size of Graph 
 *            Number of Rows
 *            Number of Colomns
 *         Blocked squares as 0
 *         Allowed squares as 1
 *         Destination square as 2
 * 
 * Output: Path to Destinition from Origin indicated 
 *         by 4
 *
 */

#include <stdio.h>

#define MAX_X		10
#define MAX_Y		10
#define PATH_BLOCKED	0
#define PATH_ALLOWED	1
#define PATH_TARGET	2
#define VISITED		3
#define PATH_TO_DEST	4

int graph[MAX_X][MAX_Y], row_max, col_max;

/****************************
 *  DFS funciton            *
 *  *************************/

int dfs(int row, int col)
{
   /* Break condition NOT LEADING TO DESTINATION*/
   if(row<0 || col <0 || row>row_max || col>col_max)
       return -1;

   /* PATH BLOCKED..OR ALREADY VISITED */
   if(graph[row][col] == PATH_BLOCKED || graph[row][col] == VISITED)
       return -1;

   /* Target reached.. PATH TO DESTINATION FOUND */
   if(graph[row][col] == PATH_TARGET)
       return 0;

   /* Mark this visited */
   graph[row][col] = VISITED;

   /* Go Up */
   if(dfs(row-1, col)==0)
   {
      graph[row][col] = PATH_TO_DEST;
      return 0;
   }

   /* Go Left */
   if(dfs(row, col-1)==0)
   {
      graph[row][col] = PATH_TO_DEST;
      return 0;
   }

   /* Go Down */
   if(dfs(row+1, col)==0)
   {
      graph[row][col] = PATH_TO_DEST;
      return 0;
   }

   /* Go Right */
   if(dfs(row, col+1)==0)
   {
      graph[row][col] = PATH_TO_DEST;
      return 0;
   }

   /* If reached here this is not leading to destination
    * Back track and return
    */

   graph[row][col] = PATH_ALLOWED;
   
   return -1;
}

/****************************
 *  API to fill the graph  *
 *  *************************/

void input_graph()
{
   int row=0,col=0;

   // Obtain number of row and col
   printf("Enter number of Rows in graph:");
   scanf("%d", &row_max);
   printf("Enter number of Colomns in graph:");
   scanf("%d", &col_max);

   // loop for input
   for(row=0; row<row_max; row++)
   {
      printf("[%2d]:",row);
      for(col=0; col<col_max; col++)
      {
         scanf("%d", &graph[row][col]);
      }
   }
}

/****************************
 *  API to print the graph  *
 *  *************************/

void print_graph()
{
   int row=0,col=0;

   printf("     ");
   for(col=0; col<col_max; col++)
      printf("[%2d] ",col);

   printf("\n");
   for(row=0; row<row_max; row++)
   {
      printf("[%2d] ",row);
      for(col=0; col<col_max; col++)
      {
         printf("%4d ", graph[row][col]);
      }
      printf("\n");
   }
}


/* Entry point */

int main()
{
   /* Call graph filling API */
   input_graph();

   /* Call graph dumping API */
   print_graph();

   /* Call DFS to find the path to destination */

   if(dfs(0,0)==0)
      printf("Path FOUND...\n");
   else
      printf("Path NOT FOUND...\n");

   /* Show the path */
   print_graph();
   return 0;
}
