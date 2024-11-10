#include <stdio.h>
#include <stdlib.h>
struct node *head=NULL;struct node *tail=NULL;
struct node{
	int data;struct node *link;
};
//maximum value
void max(){
  struct node *ptr=head;
  if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    int max_value=ptr->data;
	while (ptr!=NULL){
	      if ((ptr->data)>max_value){
	          max_value=ptr->data;
	      }
		ptr=ptr->link;
	}
	printf("The maximum value is: %d\n",max_value);
}
//even numbers
void even(){
      struct node *ptr=head;
      if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");
        return;
      }
      printf("Even numbered list:");
      while (ptr!=NULL){
            if (ptr->data%2==0){
                printf("%d->",ptr->data);
                
            }
            ptr=ptr->link;
      }printf("\n");
}

//delete last element if its even
void delete(){
      if (tail->data%2==0){
          printf("Deletion of tail node if its even:");
          printf("%d",tail->data);
          struct node *ptr=head;
          while (ptr->link!=tail){
                ptr=ptr->link;
          }
          ptr->link=NULL;
          struct node *temp=tail;
          tail=ptr;
          free(temp);
      }else
          printf("No deletion is possible\n");
}
//minimum value
void min(){
  struct node *ptr=head;
  if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    int min_value=ptr->data;
	while (ptr!=NULL){
	      if ((ptr->data)<min_value){
	          min_value=ptr->data;
	      }
		ptr=ptr->link;
	}
	printf("The minimum value is: %d\n",min_value);
}

//prime numbers in the list
void prime(){
    struct node *ptr=head;
    if (head == NULL) {  // Check if the list is empty
        printf("List is empty\n");
        return;
    }
    while (ptr!=NULL){
        int j=2;int flag=0;
        while (j<ptr->data){
        if (ptr->data%j==0){
            flag=1;
            break;
        }
        j++;
        }if (flag==0){
            printf("%d->",ptr->data);
        }
        ptr=ptr->link;
    }
}

void display(){
	struct node *ptr=head;
	while (ptr!=tail){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\n",tail->data);
}
int main(){
	while (1){
	printf("Do you want to insert element:(y/n)");char ch;
	scanf("%c",&ch);
	if (ch=='y'){
		//create a node new
		printf("Enter the element into the list:");int ele;
		scanf("%d",&ele);
		getchar();
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->data=ele;
		if (head==NULL){
			new->link=NULL;
			head=new;tail=new;
		}else{
			new->link=NULL;
			tail->link=new;
			tail=new;
		}
	}else{
		display();
		max();
		min();
		even();
		prime();
		delete();
		display();
		return 0;
	}
	}
}
