#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

#define DEBUG 0
#define SHOW_NULL 1

/*****************************************
 *
 * Binary Trees
 *
 *****************************************/

/* test code */

tree test_tree()
{
  tree t = NULL;

  t = (tree)malloc(sizeof(struct node));
  t->value = 'a';
  t->left = (tree)malloc(sizeof(struct node));
  t->left->value = 'b';
  t->left->left = NULL;
  t->left->right = NULL;
  t->right = (tree)malloc(sizeof(struct node));
  t->right->value = 'c';
  t->right->left = NULL;
  t->right->right = NULL;

  return t;
}

/* Story 0
 * As a teacher, I want to be able to create a binary tree from a
 * string so my students can create trees for my students to operate
 * on.
 */

tree new_node(char val)
{
  tree temp = NULL;

  temp = (tree)malloc(sizeof(struct node));
  temp->value = val;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}

tree make_tree(tree t, char *tree_rep, int *i)
{
  if (*i > 20) return t;

  if (DEBUG) {
    printf("\nmake_tree(t, %s, %d)\n", tree_rep, *i);
    printf("             ");
    for (int j = 0; j < *i; ++j) printf(" ");
    printf("^ ");
    fflush(stdout);
  }

  switch (tree_rep[*i]) {
  case '\0':
    printf("Error [%s]: incomplete tree representation\n", tree_rep);
    break;
  case '(':
    if (NULL == t) {
      if (DEBUG) printf("empty tree");
      ++*i;
      t = make_tree(t, tree_rep, i);
    } else {
      if (DEBUG) printf("add left child to %c; ", t->value);
      ++*i;
      t->left = make_tree(t->left, tree_rep, i);
      if (DEBUG) printf("add right child to %c; ", t->value);
      ++*i;
      t->right = make_tree(t->right, tree_rep, i);
    }
    break;
  case ')':
    if (DEBUG) {
      if (NULL == t) {
        printf("Finished empty tree");
      } else {
        printf("Finished tree with root %c; ", t->value);
      }
    }
    ++*i;
    break;
  default:
    t = new_node(tree_rep[*i]);
    if (DEBUG) printf("New tree root %c; ", t->value);
    ++*i;
    t = make_tree(t, tree_rep, i);
  }

  return t;
}

int root_value(tree t)
{
  if (NULL == t) {
    printf("Error taking left child of empty tree\n");
    fflush(stdout);
    return 0;
  }
  return t->value;
}

tree left_child(tree t)
{
  if (NULL == t) {
    printf("Error taking left child of empty tree\n");
    fflush(stdout);
    return t;
  }
  return t->left;
}

tree right_child(tree t)
{
  if (NULL == t) {
    printf("Error taking right child of empty tree\n");
    fflush(stdout);
    return t;
  }
  return t->right;
}

void print_spaces(int tabs)
{
  for (int i = 0; i < tabs; i++) {
    printf("  ");
  }
  fflush(stdout);
}

/* Story 1
 * As a programmer, I want to be print a tree, so I see what is is in
 * it.
 */

void pt(tree t)
{
	if(t == NULL) {
	}
	else {
		pt(t -> left);
		printf("%d ",t -> value);
		pt(t ->right);
	}
}

void print_tree(char *msg, tree t)
{
  printf("%s: ", msg);
  fflush(stdout);
  pt(t);
  printf("\n");
}

void print_tree_plus(char *before, tree t, char *after)
{
  printf("%s", before);
  fflush(stdout);
  pt(t);
  printf("%s", after);
  fflush(stdout);
}

/*
 * Story 2
 * As a Programmer, I want a function to print a pre-order traversal
 * of a complete binary tree, to see how it is done.
 */

void print_preorder(tree t)
{
	if(t == NULL) {
	}
	else {
		printf("%c",t->value);
		print_preorder(t->left);
		print_preorder(t->right);
	}
}

/*
 * Story 3
 * As a Programmer, I want a function to print a post-order traversal
 * of a complete binary tree, to see how it is done.
 */

void print_postorder(tree t)
{
	if(t == NULL) {
        }
        else {
                print_postorder(t->left);
                print_postorder(t->right);
		printf("%c",t->value);
        }

}

/*
 * Story 4
 * As a Programmer, I want a function to print a in-order traversal of
 * a complete binary tree, to see how it is done.
 */

void print_inorder(tree t)
{
	if(t == NULL) {
        }
        else {
                print_inorder(t->left);
                printf("%c",t->value);
                print_inorder(t->right);
        }
}

/*****************************************
 *
 * Binary Search Trees
 *
 *****************************************/

char BST_find(tree t, char target)
{/*
	struct node *par=NULL,*loc=NULL;
	struct node *ptr=NULL;
	if(t == NULL) {
		printf("Tree Doesn't Exist");
		loc = NULL;par = NULL;
		exit(0);
	}
	par = NULL;loc = NULL;
	ptr = t;
	while (ptr != NULL) {
      		if (ptr->value == target) {
			loc = ptr;
			printf("%d %d",loc->value, par->value);			
	 		printf("\nThe %d Element is Present", ptr->value);
//			return temp;
			exit(0);
      		}
	//	*parent = temp;
 		else if (ptr->value > target) {
        	 	par = ptr;
			ptr = ptr->left;
      		}
		else {
        		par = ptr;
			ptr = ptr->right;
		}
   	}
	if (loc == NULL) {
		printf("Not Found");
	}
	char a = loc->value;
	return a;
*/
	return target;
}

tree BST_insert(tree t, char value)
{/*
	struct node *loc=NULL,*par=NULL;
	char a = BST_find(t,value);
	if(loc != NULL) {
		printf("Node Exist");
		exit(0);
	}
	struct node new1 = malloc(sizeof (struct node));
	new1 -> info = value;
	new1->left = NULL;new1->right = NULL;
	if(par = NULL) {
		t = new1;
		exit(0);
	}
	else if(new1->info < par->info) {
		par ->left = new1;
		exit(0);
	}
	else {
		par -> right = new1;
		exit(0);
	}
*/
	return t;
}
