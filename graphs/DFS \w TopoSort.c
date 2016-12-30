#include <stdio.h>
#include <stdlib.h>

#define  MAXQ  100

struct child
{
  int value;
  struct child *right;
};

struct parent
{
  int dist;
  int visited;
  struct child *right;
};

void initParents(struct parent adjList[], int NODES);
void insertChild(struct parent adjList[], int u, int v);

void DFS(struct parent adjList[], int parentNode, int depth);

int main(void)
{
  int NODES, EDGES;
  scanf("%d %d", &NODES, &EDGES);

  struct parent adjList[NODES];
  initParents(adjList, NODES);

  for(int i = 0, u, v; i < EDGES; i++)
  {
    scanf("%d %d", &u, &v);

    insertChild(adjList, u, v);
    insertChild(adjList, v, u);
  }

  DFS(adjList, 1, 0);

  for(int i = 0; i < NODES; i++)
  {
    printf("%d %d ->", i, adjList[i].dist);

    struct child *nChild = adjList[i].right;
    while(nChild != NULL)
    {
      printf(" %d", nChild->value);
      nChild = nChild->right;
    }
    printf("\n");
  }

  return 0;
}

void DFS(struct parent adjList[], int parentNode, int depth)
{
  printf("%d\n", parentNode);

  adjList[parentNode].dist = depth;
  adjList[parentNode].visited = 1;

  struct child *fChild = adjList[parentNode].right;

  while(fChild != NULL)
  {
    if(!adjList[fChild->value].visited)
    {
      DFS(adjList, fChild->value, depth + 1);
    }
    fChild = fChild->right;
  }
}

void initParents(struct parent adjList[], int NODES)
{
  for(int i = 0; i < NODES; i++)
  {
    adjList[i].dist = -1;
    adjList[i].visited = 0;
    adjList[i].right = NULL;
  }
}

// How much would it have costed to have C dynamic array

void insertChild(struct parent adjList[], int u, int v)
{
  struct child *newChild = malloc(sizeof(struct child));
  newChild->value = v;
  newChild->right = adjList[u].right;

  adjList[u].right = newChild;
}
