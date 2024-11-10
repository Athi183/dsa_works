#include <stdio.h>
int m,ht[100];int index1;
void insert(int key){
	index1=key%m;
	while (ht[index1]!=-1){
		index1=(index1+1)%m;
		if (index1==key%m){
			printf("FULL!!\n");
			return;
		}
	}
	ht[index1]=key;
	printf("key successfully entered into index:%d\n",index1);
	
}
void display(){
    printf("hash table\n");
    for (int i=0;i<m;i++){
		if (ht[i]!=-1)
		    printf("Index : %d Key : %d\n",i,ht[i]);
		else
		    printf("Index : %d Empty\n",i);
	}
}
int search(int key) {
    index1 = key % m;
    for (int i = 0; i < m; i++) {
        if (ht[index1] == key) {
            printf("Key found at index : %d\n", index1);
            return index1;
        }
        if (ht[index1] == -1) {
            break; // Stop if an empty slot is reached
        }
        index1 = (index1 + 1) % m;
    }
    printf("Key not found\n");
    return -1;
}

void delete(int key) {
    index1 = search(key); // Find the index of the key first
    if (index1 != -1) {
        ht[index1] = -1; // Mark as deleted with a -2
        printf("Deleted element %d from index : %d\n", key, index1);
    }
}
int main(){
	//first size of the table has to asked from the user as m
	
	printf("Enter the size of the hash table");
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		ht[i]=-1;
	}
	
	//number of elements to insert into table as n
	printf("Enter the number of elements");int n;
	scanf("%d",&n);
	
	//inserting elements into the array
	printf("Enter the elements\n");
	for (int i=0;i<n;i++){
		int key;
		printf("Enter the key:");
		scanf("%d",&key);
		insert(key);
	}
	display();
	search(2);
	delete(7);
	display();
	
}
