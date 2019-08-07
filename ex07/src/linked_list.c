#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



node_t  *list_create(void *data)
{
  node_t *tmp;
  tmp=malloc((sizeof(node_t)));
  tmp->data=data;
  tmp->next=NULL;
  return tmp;
}
void list_destroy(node_t **head, void (*fp)(void *data))
	{
	 if ((*head) == NULL)
	     return;
	 fp((*head)->data);
	 node_t *next;
	 for (node_t *current =(*head); current; current = next)
	    {
	        next = current->next;
          free(current);
	    }
	 (*head) = NULL;
	 }


void    list_push(node_t *head, void *data)
{
  node_t *tmp=head;
  for(;tmp->next!=NULL;tmp=tmp->next);
  tmp->next=malloc(sizeof(node_t));
  tmp->next->data=data;
  tmp->next->next=NULL;

}
void    list_unshift(node_t **head, void *data)
{
   node_t *new_node = malloc(sizeof(node_t));
	  new_node->data = data;
   new_node->next =(*head);
   (*head) = new_node;
}

void *list_pop(node_t **head)
	{
	  node_t *tmp = *head;
	  if((*head)->next == NULL)
	  {
	    free(*head);
	    *head = NULL;
	    return NULL;
	  }

    tmp=tmp->next;
	  while(tmp->next->next != NULL)
	  {
	    tmp = tmp->next;
	  }
    void *data = tmp->data;

	  free(tmp->next);
    tmp->next = NULL;
    return data;
}

void *list_shift(node_t **head)
	{
	  node_t *tmp = *head;
	  *head = tmp->next;
    void *data = tmp->data;
	  free(tmp);
    return data;
	}

void list_print(node_t *head)
    {
      node_t   *tmp = head;
      while(tmp !=  NULL)
      {
        printf("%p", tmp->data);
        tmp = tmp->next;
      }
   }


	void *list_remove(node_t **head, int pos)
	{
	  node_t   *tmp = *head;
	  node_t   *tmp2 = *head;
	  tmp2 = tmp2->next;
	  for(int i = 0; i < pos-1; i++){
	     tmp = tmp->next;
	     tmp2 = tmp2->next;
	  }
    void *data = tmp->data;
	  tmp->next = tmp2->next;
	  free(tmp2);
    return data;
	}


 void list_visitor(node_t *head, void(*fp)(void *data))
	{
	  if(head->next != NULL)
    list_visitor(head->next, fp);
    fp(head->data);
}