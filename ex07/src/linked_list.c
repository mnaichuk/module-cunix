#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node_t *list_create(void *data)
{
   node_t *current;
   current = malloc(sizeof(node_t));
   current->data = data;
   current->next = NULL;
   return current;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
 if ((*head) == NULL)
     return;
 fp((*head)->data);
 node_t *next;
 for (node_t *current =(*head); current; current = next)
    {
        next = current->next; //save adress of next before deleting
        free(current);// remove current, now next become current
    }
 (*head) = NULL;
 }


void list_push(node_t *head, void *data)
{
 node_t *current = head;
 while(current->next != NULL)//going to the last node
 {
     current = current->next;
 }
 current->next = malloc(sizeof(node_t));
 current->next->data = data;
 current->next->next = NULL;
}

 void list_unshift(node_t **head, void *data)
{ // to the begining
  
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next =(*head);
  (*head) = new_node;
}

void *list_pop(node_t **head)
{
  node_t *temp = *head;
  node_t *cur = *head;

  if((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;
    return NULL;
  }

  cur = cur->next;
  
  while(cur->next != NULL)
  {
    cur = cur->next;
    temp = temp->next;
  }
  
  void *data = cur->data;
  free(temp->next);
  temp->next = NULL;
  return data;
}


void *list_shift(node_t **head)
{
  node_t *cur = *head;
  *head = cur->next;
  void *data = cur->data;
  free(cur);
  return data;
}

void *list_remove(node_t **head, int pos)
{
  node_t   *cur = *head;
  node_t   *temp = *head;
  cur = cur->next;
  for(int i = 0; i < pos-1; i++){
     cur = cur->next;
     temp = temp->next;
  }
  void *data = cur->data;
  temp->next = cur->next;
  free(cur);
  return data;
}

void list_print(node_t *head)
{
  node_t   *cur = head;
  
  while(cur !=  NULL)
  {
    printf("%p", cur->data);
    cur = cur->next;
  }
}

void list_visitor(node_t *head, void(*fp)(void *data))
{
  if(head->next != NULL)
    list_visitor(head->next, fp);
  fp(head->data);
}
