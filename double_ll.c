#include <stdio.h>
#include <stdlib.h>
struct node *p=NULL;struct node *q=NULL;
struct node{
	int data;struct node *l,*r;
};

void sort(struct node *ptr){
    int swapped;
    if (ptr == NULL) {
        return;
    }
    else{
    do {
        swapped = 0;
        struct node *start=ptr;
        while (ptr->r != NULL) {
            if (ptr->data > ptr->r->data) {
                // Swap data between the current node and the next node
                int temp = ptr->data;
                ptr->data = ptr->r->data;
                ptr->r->data = temp;
                swapped = 1;
            }
            ptr = ptr->r;
        }
        ptr=start;
    } while (swapped);
    }
}

void merge_sort(){
      struct node *ptr=p;
      while (ptr->r!=NULL){
		ptr=ptr->r;
      }
      ptr->r=q;
      q->l=ptr;
}
void display(struct node *point){
	struct node *ptr=point;
	while (ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->r;
	}
	printf("\n");
}

void display_reverse(struct node *point){
	struct node *ptr=point;
	while (ptr->r!=NULL){
		ptr=ptr->r;
	}
	while (ptr!=NULL){
	      printf("%d->",ptr->data);
	      ptr=ptr->l;
	}
	printf("\n");
}
struct node * read(struct node *head){
  while (1){
	printf("Do you want to insert element:(y/n)");char ch;
	scanf(" %c",&ch);
	if (ch=='y'){
		//create a node new
		printf("Enter the element into the list:");int ele;
		scanf("%d",&ele);
		getchar();
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->data=ele;
		if (head==NULL){
			new->l=NULL;new->r=NULL;
		        head=new;
		}else{
			new->r=NULL;
			struct node *ptr=head;
			while (ptr->r!=NULL)
				ptr=ptr->r;
			ptr->r=new;
			new->l=ptr;
		}
	}else{
		display(head);
		return head;
	}
      }
}


int main(){
	printf("enter the elements into list 1\n");
	p=read(p);
	printf("enter the elements into list 2\n");
	q=read(q);
	printf("Sorting 1\n");sort(p);display(p);
	printf("Sorting 2\n");sort(q);display(q);
	printf("Merging\n");
	merge_sort();sort(p);display(p);
	display_reverse();
}
