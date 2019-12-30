/*
program : expr.c
Author : Vanshaj Verma
*/

#include "expr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MainString function to concatenate and retrun a pointer to the char pointer
 */
char *makeString(char *s1, char *s2, char *s3) {

  /* Allocation space for the pointer after defining it */
  char *S;
  S = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);

  /* Checking if the string pointer is null */
  if (S == NULL) {
    return S;
  }

  /* implemening the necessary features to the funtion as in copying and
   * concatening the strings */
  strcpy(S, s1);
  strcat(S, s2);
  strcat(S, s3);

  /* returning the pointer to the char pointer after concatenation */
  return S;
}

/* Next function of creating node after taking in the value and assigning some
 * to others */
Node *createNode(char *s, double val) {

  /* defining and allocating space for the node */
  Node *abcd;
  abcd = malloc(sizeof(Node));

  /* performign the required operations */
  abcd->expr_string = s;
  abcd->left = NULL;
  abcd->right = NULL;
  abcd->num_parents = 0;
  abcd->value = val;

  /* returning the node pointer */
  return abcd;
}

/* Next function to create a node and assign its child nodes and performing some
 * operations */
Node *binop(Operation op, Node *a, Node *b) {

  /* Conditional sattement to make it robust */
  if (a->num_parents == 1 || b->num_parents == 1) {
    return NULL;
  }

  /* defining and allocating space for the node */
  Node *new_node;
  new_node = malloc(sizeof(Node));

  /* conditional statement to make it robust */
  if (new_node == NULL) {
    return NULL;
  }

  /* Operations required by the fucntion */
  new_node->left = a;
  new_node->right = b;
  new_node->operation = op;

  a->num_parents++;
  b->num_parents++;

  /* defining some extra pointers to divide up some work */
  char *make1 = makeString("(", a->expr_string, ")");
  char *make2 = makeString("(", b->expr_string, ")");

  /* Conditional statements to required operations according to the situation */
  if (op == addop) {
    new_node->expr_string = makeString(a->expr_string, "+", b->expr_string);
  } else if (op == subop) {
    new_node->expr_string = makeString(a->expr_string, "-", b->expr_string);
  } else if (op == mulop) {
    new_node->expr_string = makeString(make1, "*", make2);
  } else if (op == divop) {
    new_node->expr_string = makeString(make1, "/", make2);
  } else {
    return NULL;
  }

  /* Initialising some uninitialised variables to make the code error free */
  new_node->num_parents = 0;
  new_node->value = 0;

  /* freeing the extra pointers created to save memory */
  free(make1);
  free(make2);

  return new_node;
}

/* Next fucntion to traverse through a binary tree and performing required
 * operations */
double evalTree(Node *root) {
  /* Conditional statement to make the code robust */
  if (root == NULL) {
    return 0;
  }

  /* Conditional statement to make the code robust */
  if (root->left == NULL || root->right == NULL) {
    return root->value;
  }

  /* Recursive calls to traverse through the tree */
  double left = evalTree(root->left);
  double right = evalTree(root->right);

  /* Conditional statemets to perform the required operations according to the
   * situation */
  if (root->operation == addop) {
    root->value = left + right;
  } else if (root->operation == subop) {
    root->value = left - right;
  } else if (root->operation == mulop) {
    root->value = left * right;
  } else if (root->operation == divop) {
    root->value = left / right;
  } else {
    return 0;
  }

  return root->value;
}

/* Next fucntion is to free all the memory allocaation that have been done in
 * the trees and in the duplicate trees */
void freeTree(Node *root) {
  if (root == NULL) {
    return;
  }

  /* Conditional statements to make the code robust and recursing accordingly
   * into the tree */
  if (root->left || root->right) {
    freeTree(root->left);
    freeTree(root->right);
    free(root->expr_string);
  }

  /* finally freeing the root node */
  free(root);
  return;
}

/* Next function to duplicate the already created binary tree with same content
 * and connections */
Node *duplicateTree(Node *root) {
  if (root == NULL) {
    return root;
  }

  /* Creating the partent node for the cuplicate binary tree and copying stuff
   * over */
  Node *dup_node = malloc(sizeof(Node));
  if (root->left || root->right) {
    dup_node->expr_string = makeString("", root->expr_string, "");
  } else {
    dup_node->expr_string = root->expr_string;
  }

  dup_node->operation = root->operation;
  dup_node->value = root->value;
  dup_node->num_parents = root->num_parents;

  /* recursive calls for traversing the tree and duplicating it */
  dup_node->left = duplicateTree(root->left);
  dup_node->right = duplicateTree(root->right);

  return dup_node;
}

/* Final function to print the tree and its contents while traversing throught
 * the nodes */
void printTree(Node *root) {
  /* Required Print commands */
  printf(" Node\n");
  printf("\texpr_string\t= %s\n", root->expr_string);
  printf("\tvalue\t\t= %g\n", root->value);
  printf("\tnum_parents\t= %d\n", root->num_parents);

  /* Conditional statements to make code robust and then traversing through the
   * tree */
  if (root->left != NULL || root->right != NULL) {
    printTree(root->left);
    printTree(root->right);
  }

  return;
}