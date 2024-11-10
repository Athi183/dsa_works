#include <stdio.h>
#include <stdlib.h>
struct node *head=NULL;struct node *tail=NULL;
struct node{
	int data;struct node *link;
};

void insert_pos(int ele,int pos){
	int j=1;
	struct node *ptr=head;
	if (head == NULL) {  // Check if the list is empty
        	printf("List is empty\n");
        	return;
    	}
	while (ptr!=NULL && j<pos){
		ptr=ptr->link;
		j++;
	}
	struct node *new=(struct node*)malloc(sizeof(struct node));
	if (pos==0){
	new->data=ele;
	new->link=head;
	head=new;
	}else{
	    new->data=ele;
	    new->link=ptr->link;
	    ptr->link=new;
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
		printf("Enter the element into the list:");int ele;
		scanf("%d",&ele);
		printf("Enter the position:");int pos;
		scanf("%d",&pos);
		insert_pos(ele,pos-1);
		display();
		return 0;
	}
	}
}
