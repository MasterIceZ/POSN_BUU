#include <bits/stdc++.h>
using namespace std;

struct List{
	struct Node{
		int v;
		Node *l, *r;
	};
	Node* newNode(int v){
		Node *p;
		p = (Node *) malloc(sizeof(Node));
		p->v = v;
		p->l = p->r = NULL;
		return p;
	}
	Node *head, *cur, *last, *use;
	List(){
		head = newNode(999);
		cur = newNode(0);
		last = newNode(0);
		use = newNode(0);
		cur = last = head;
	}
	void front(){
		cur = head;
	}
	void next(){
		if(cur->r != NULL){
			cur = cur->r;
		}
	}
	void back(){
		cur = last;
	}
	void insert(int v){
		use = newNode(v);
		if(cur == last){
			use->l = cur;
			cur->r = use;
			last = use;
		}
		else{
			use->r = cur->r;
			use->l = cur;
			cur->r->l = use;
			cur->r = use;
//			while(last->r != NULL){
//				last = last->r;
//			}
		}
	}
	void pop(){
		if(cur != last){
			use =  cur->r;
			if(use->r != NULL){
				cur->r = use->r;
				cur->r->l = cur;
			}
			else{
				cur->r = NULL;
			}
			for(last=cur; last->r!=NULL; last=last->r);
		}
	}
	int call(){
		return cur->v;
	}
	void show(){
		while(cur->r != NULL){
			printf("%d ", cur->v);
			cur = cur->r;
		}
		printf("%d\n", cur->v);
	}
};

char opr[222];

int main(){
	int n;
	scanf("%d", &n);
	List ls;
	for(int i=1; i<=n; ++i){
		scanf(" %s", opr);
		if(opr[0] == 'h'){
			ls.front();
		}
		else if(opr[0] == 'n'){
			ls.next();
		}
		else if(opr[0] == 't'){
			ls.back();
		}
		else if(opr[0] == 'a'){
			int x;
			scanf("%d", &x);
			ls.insert(x);
		}
		else if(opr[0] == 'r'){
			ls.pop();
		}
		else if(opr[0] == 'c'){
			printf("%d\n", ls.call());
		}
		else{
			ls.show();
		}
	}
	return 0;
}
