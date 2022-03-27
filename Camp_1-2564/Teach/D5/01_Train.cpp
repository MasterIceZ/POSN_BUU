#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int num;
	struct node *left,*right;
} node;

node *head,*run,*last,*use;

node* newnode(int num){
	node *p;
	p = (node *)malloc(sizeof(node));
	p->num=num;
	p->left = p->right = NULL;
	return p;
}

void HEAD() {
	run = head;
}

void NEXT() {
	if(run->right!=NULL)
		run = run->right;
}
void TAIL() {
	run = last;
}
void ADD() {
	int num;
	scanf("%d",&num);
	if(run == last) {
		use = newnode(num);
		use -> left = run;
		run -> right = use;
		last = use;
	}
	else {
		use = newnode(num);
		run->right->left = use;
		use->right = run->right;
		run->right=use;
		use->left=run;
	}
}
void REMOVE() {
	if(run==last) return;
	use=run->right;
	if(use->right!=NULL){
		run->right = use->right;
		run->right->left=run;
	}
	else {
		run->right=NULL;
		last=run;
	}
	free(use);
}
void CALL() {
	printf("%d\n", run->num);
}
void LIST() {
	while(run->right!=NULL) {
		printf("%d ",run->num);
		run=run->right;
	}
	printf("%d\n",run->num);
}
int main() {
    int n,i;
	char a[100];
    scanf("%d",&n);
	head = newnode(999);
	run = newnode(0);
	last = newnode(0);
	use = newnode(0);
	run = last = head;
	for(i=0;i<n;i++){
		scanf(" %s",a);
		if(!strcmp(a,"head"))
			HEAD();
		else if(!strcmp(a,"next"))
			NEXT();
		else if(!strcmp(a,"tail"))
			TAIL();
		else if(!strcmp(a,"add"))
			ADD();
		else if(!strcmp(a,"remove"))
			REMOVE();
		else if(!strcmp(a,"call"))
			CALL();
		else if(!strcmp(a,"list"))
			LIST();
	}
    return 0;
}

