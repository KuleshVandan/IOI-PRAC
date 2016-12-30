#include <stdio.h>
#include <stdlib.h>

#define  MAXQ  100    // RESIZE the queue stack to your needs

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

void BFS(struct parent adjList[], int parentNode);

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

  BFS(adjList, 1);

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

int queue[MAXQ];
int start = 0;
int end = 0;

int isQEmpty(void)
{
  return start == end;
}

void enqueue(int x)
{
  queue[start] = x;
  start = (start + 1) % MAXQ;
}

int dequeue(void)
{
  int rVal = queue[end];
  end = (end + 1) % MAXQ;
  return rVal;
}

void BFS(struct parent adjList[], int parentNode)
{
  adjList[parentNode].dist = 0;
  adjList[parentNode].visited = 1;

  enqueue(parentNode);

  while(!isQEmpty())
  {
    int u = dequeue();

    struct child *nChild = adjList[u].right;
    while(nChild != NULL)
    {
      if(!adjList[nChild->value].visited)
      {
        adjList[nChild->value].visited = 1;
        adjList[nChild->value].dist = adjList[u].dist + 1;

        enqueue(nChild->value);
      }
      nChild = nChild->right;
    }
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

// How much would it have costed to include a dynamic array?

void insertChild(struct parent adjList[], int u, int v)
{
  struct child *newChild = malloc(sizeof(struct child));
  newChild->value = v;
  newChild->right = adjList[u].right;

  adjList[u].right = newChild;
}
