//ADT二叉排序树
//二叉排序树的查找、插入、删除

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int ElemType;

//typedef struct Bitnode
//{
//	int data;
//	struct BiTNode *lchild, *rchild;
//}BiTNode;

typedef struct Bitree {
	ElemType data;
	struct Bitree *lchild, *rchild;
}*BiTree;

typedef struct heap {
	ElemType data[100];
	int size;
	int capacity;
}*Heap;
//查找
//查找失败返回NULL，查找成功返回指向该结点的指针
BiTree SearchBST(BiTree T, ElemType key)
{
	if(!T || key == T->data)    //查找失败返回NULL
		return T;
	else if(key < T->data)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}
//插入
//插入成功返回1，插入失败返回0
int InsertBST(BiTree T, ElemType key)
{
	if(!T)  //查找失败，插入新结点
	{
		T = (BiTree)malloc(sizeof(struct Bitree));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (T->data == 0) {
		T->data = key;
		return 0;
	}
	else if (key == T->data) {
		return 0;
	}
	else if (key < T->data) {
		if (T->lchild == NULL) {
			T->lchild = (BiTree)malloc(sizeof(struct Bitree));
			T->lchild->data = key;
			T->lchild->lchild = T->lchild->rchild = NULL;
			return InsertBST(T->lchild, key);
		}
		else
			return InsertBST(T->lchild, key);
	}
	else {
		if (T->rchild == NULL) {
			T->rchild = (BiTree)malloc(sizeof(struct Bitree));
			T->rchild->data = key;
			T->rchild->lchild = T->rchild->rchild = NULL;
			return InsertBST(T->rchild, key);
		}
		else
			return InsertBST(T->rchild, key);
	}
}
//删除
//删除成功返回1，删除失败返回0
int DeleteBST(BiTree T, ElemType key)
{
	if(!T)
		return 0;
	else
	{
		if(key == T->data)
			return Delete(T);
		else if(key < T->data)
			return DeleteBST(T->lchild, key);
		else
			return DeleteBST(T->rchild, key);
	}
}
//删除以p为根的二叉排序树的结点，并重接它的左或右子树
int Delete(BiTree p)
{
	BiTree q, s;
	if (p->rchild == NULL)   //只有左子树或无子树
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)  //只有右子树
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else    //左右子树均存在
	{
		q = p;
		s = p->lchild;
		while (s->rchild)    //转左，然后向右走到尽头（找待删结点的前驱）
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;  //s指向被删结点的前驱
		if (q != p)
			q->rchild = s->lchild;  //重接q的右子树
		else
			q->lchild = s->lchild;  //重接q的左子树
		free(s);
	}
	return 1;
}

//
int middletraverseTree(BiTree T) {
	if (T) {
		printf("%d ", T->data);
		middletraverseTree(T->lchild);
		middletraverseTree(T->rchild);
	}
	return 0;
}

int lefttraverseTree(BiTree T) {
	if (T) {
		lefttraverseTree(T->lchild);
		printf("%d ", T->data);
		lefttraverseTree(T->rchild);
	}
	return 0;
}

int righttraverseTree(BiTree T) {
	if (T) {
		righttraverseTree(T->lchild);
		righttraverseTree(T->rchild);
		printf("%d ", T->data);
	}
	return 0;
}
//层序遍历
int leveltraverseTree(BiTree T) {
	BiTree queue[100];
	int front = 0, rear = 0, size = 1, depth = 0;
	depth = depthOfTree(T);
	if (T) {
		queue[rear++] = T;
		for (int a = 0; front < rear, a < depth; a++) {
			size = rear - front;
			for (int i = 0; i < size; i++) {
				//打印一行
				T = queue[front++];
				if (T) {
					printf("%d ", T->data);
					if (T->lchild) {
						queue[rear++] = T->lchild;
					}
					else {
						queue[rear++] = NULL;
					}
					if (T->rchild) {
						queue[rear++] = T->rchild;
					}
					else {
						queue[rear++] = NULL;
					}
				}
				else {
					printf("N ");
					queue[rear++] = NULL;
					queue[rear++] = NULL;
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

// 判断树有效元素的深度，空节点不算有效元素
int depthOfTree(BiTree root) {
	// 如果根节点为空，返回0
	if (root == NULL) return 0;
	// 如果根节点没有子节点，返回1
	if (root->lchild == NULL && root->rchild == NULL) return 1;
	// 计算左子树和右子树的深度
	int left = depthOfTree(root->lchild);
	int right = depthOfTree(root->rchild);
	// 返回较大的深度加1
	return left > right ? left + 1 : right + 1;
}

//创建堆
Heap createHeap(Heap H) {
	//H = malloc(sizeof(struct heap));
	//第一个不作为堆的元素
	//H->data = malloc(100 * sizeof(ElemType));

	H->size = 0;
	H->capacity = 100;
	//第一个元素作为标记元素
	H->data[0] = -22002072;
	return H;
}

//插入元素
void InsertHeap(Heap H, ElemType item) {
	int i;
	if (H->size == H->capacity) {
		printf("堆已满\n");
		return;
	}
	i = ++H->size;
	if (H->data[0] == -22002072) { 
		H->data[0] = item;
		return;
	}
	for (; H->data[i / 2] < item && i != 0; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = item;
}

void main() {
	char elem[50] = { 0 };
	char mod = "0";
	ElemType n;
	Heap H = (Heap)malloc(sizeof(struct heap));
	struct Bitree* T = (BiTree)malloc(sizeof(struct Bitree));
	T->data = 0;
	T->lchild = NULL; T->rchild = NULL;
	printf("Please input mod(M:middle(default),L:left,R:right,H:heap):\n");
	scanf_s("%c", &mod);
	printf("Please input nums:(Input any key that isn't nums to exit)\n");
	
	if (mod == 'H' || mod == 'h') {
		createHeap(H);
		while (gets_s(elem, 50)) {
			if (elem[0] == '\0') { continue; }
			if (strcmp(elem, "*") == 0) {
				break;
			}
			else if (strcmp(elem, "\n") == 0) {
				continue;
			}
			for (int i = 0; i < strlen(elem); i++) {
				if (elem[i] < '0' || elem[i] > '9') {
					printf("Input error!\n");
					return;
				}
			}
			n = atoi(&elem);
			InsertHeap(H, n);
		}
		printf("Output:\nHeap:");
		for (int a = 0; a < H->size; a++) {
			printf("%d ", H->data[a]);
		}
	}
	else if (mod == 'M' || mod == 'm' || mod == 'L' || mod == 'l' || mod == 'R' || mod == 'r' ){
		while (gets_s(elem, 50)) {
			if (strcmp(elem, "*") == 0) {
				break;
			}
			else if (strcmp(elem, "\n") == 0) {
				continue;
			}
			for (int i = 0; i < strlen(elem); i++) {
				if (elem[i] < '0' || elem[i] > '9') {
					printf("Input error!\n");
					return;
				}
			}
			n = atoi(&elem);
			InsertBST(T, n);
		}

		int depth = depthOfTree(T);
		printf("Depth of tree is %d\n", depth);
		printf("Output:\n");
		leveltraverseTree(T);
		if (mod == 'M' || mod == 'm') {
			printf("The tree's middle treverse:");
			middletraverseTree(T);
		}
		else if (mod == 'L' || mod == 'l') {
			printf("The tree's left treverse:");
			lefttraverseTree(T);
		}
		else if (mod == 'R' || mod == 'r') {
			printf("The tree's right treverse:");
			righttraverseTree(T);
		}
	}
	else { printf("Input invaid!\n"); return; }

	


}