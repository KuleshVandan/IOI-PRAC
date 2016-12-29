#include <stdio.h>
#include <stdlib.h>


struct parent
{
  struct child *right;
};

struct child
{
  int value;
  struct child *right;
};

void initParent(struct parent *adjList[]);
void addNode(struct parent *adjList[], int u, int v);

const int SIZE  = 8;
const int EDGES = 10;

int main(void)
{
  struct parent *adjList[SIZE];
  initParent(adjList);

  for(int i = 0, u, v; i < EDGES; i++)
  {
    scanf("%d %d", &u, &v);

    addNode(adjList, u, v);
    addNode(adjList, v, u);   // comment this line if graph is directed
  }

  for(int i = 0; i < SIZE; i++)
  {
    printf("%d ->", i);

    struct child *node = adjList[i]->right;
    while(node != NULL)
    {
      printf(" %d", node->value);
      node = node->right;
    }
    printf("\n");
  }

  return 0;
}

void initParent(struct parent *adjList[SIZE])
{
  for(int i = 0; i < SIZE; i++)
  {
    adjList[i] = malloc(sizeof(struct parent));
    adjList[i]->right = NULL;
  }
}

/* Attach v right after parent u and attach the remaining
   list to the tail of v */

void addNode(struct parent *adjList[SIZE], int u, int v)
{
  struct child *newChild = malloc(sizeof(struct child));

  newChild->value = v;
  newChild->right = adjList[u]->right;

  adjList[u]->right = newChild;
}
