#include <stdio.h>
#include <stdlib.h>

// Data structures
typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct queue
{
  struct node *begin;
  struct node *end;
} queue;

// Forward declarations
node *create_node(int x);
queue *create_queue();
int is_empty(queue *q);
void enque(queue *q, int x);
void deque(queue *q);
void print_queue(queue *q);

int main(int argc, char const *argv[])
{
  queue *q = create_queue();

  for (int i = 1; i <= 10; i++)
  {
    enque(q, i);
  }

  print_queue(q);

  for (int i = 0; i < 10; i++)
  {
    deque(q);
  }

  print_queue(q);

  return 0;
}

node *create_node(int x)
{
  node *nd = (node *)malloc(sizeof(node));
  nd->next = NULL;
  nd->data = x;
  return nd;
}

queue *create_queue()
{
  queue *q = (queue *)malloc(sizeof(queue));
  q->begin = NULL;
  q->end = NULL;
  return q;
}

int is_empty(queue *q)
{
  return q->begin == q->end && q->end == NULL;
}

void enque(queue *q, int x)
{
  node *nd = create_node(x);

  if (is_empty(q))
  {
    q->begin = nd;
    q->end = q->begin;
    return;
  }

  q->end->next = nd;
  q->end = nd;
}

void deque(queue *q)
{
  if (q->end == NULL)
  {
    printf("Empty queue!\n");
    exit(1);
  }

  if (q->end == q->begin)
  {
    free(q->end);
    q->begin = NULL;
    q->end = NULL;
    return;
  }

  node *temp = q->begin;
  q->begin = temp->next;
  free(temp);
}

void print_queue(queue *q)
{
  for (node *temp = q->begin; temp != NULL; temp = temp->next)
  {
    printf("%d ", temp->data);
  }

  printf("\n");
}