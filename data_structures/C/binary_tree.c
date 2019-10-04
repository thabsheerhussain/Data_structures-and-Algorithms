#include <stdio.h>
#include <stdlib.h>

// Data structures
typedef struct node
{
  struct node *left;
  struct node *right;
  int data;
} node;

node *create(int x)
{
  node *nd = (node *)malloc(sizeof(node));
  nd->left = NULL;
  nd->right = NULL;
  nd->data = x;
  return nd;
}

void add(node **nd, int x)
{
  if (*nd == NULL)
  {
    *nd = create(x);
    return;
  }

  if (x > (*nd)->data)
  {
    return add(&(*nd)->right, x);
  }

  if (x < (*nd)->data)
  {
    return add(&(*nd)->left, x);
  }
}

node *find_min_value(node *nd)
{
  node *temp = nd;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }

  return temp;
}

node *remove_node(node **nd, int x)
{
  if (nd == NULL)
  {
    return NULL;
  }

  if (x < (*nd)->data)
  {
    (*nd)->left = remove_node(&(*nd)->left, x);
    return *nd;
  }

  if (x > (*nd)->data)
  {
    (*nd)->right = remove_node(&(*nd)->right, x);
    return *nd;
  }

  if ((*nd)->left == NULL && (*nd)->right == NULL)
  {
    return NULL;
  }

  if ((*nd)->left == NULL)
  {
    *nd = (*nd)->right;
    return *nd;
  }

  if ((*nd)->right == NULL)
  {
    *nd = (*nd)->left;
    return *nd;
  }

  node *aux = find_min_value(*nd);
  (*nd)->data = aux->data;
  (*nd)->right = remove_node(&(*nd)->right, aux->data);
  return *nd;
}

void print_tree_aux(node *nd)
{
  if (nd == NULL)
  {
    return;
  }

  print_tree_aux(nd->left);
  print_tree_aux(nd->right);
  printf("%d ", nd->data);
}

void print_tree(node *nd)
{
  print_tree_aux(nd);
  printf("\n");
}

int main(int argc, char const *argv[])
{
  node *tree = NULL;
  add(&tree, 20);
  add(&tree, 30);
  add(&tree, 10);
  add(&tree, 5);
  add(&tree, 100);
  add(&tree, 2);
  add(&tree, -10);
  add(&tree, 7);
  print_tree(tree);
  remove_node(&tree, 10);
  remove_node(&tree, 7);
  print_tree(tree);
  return 0;
}