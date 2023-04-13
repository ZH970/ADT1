//ADT����������
//�����������Ĳ��ҡ����롢ɾ��

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
//����
//����ʧ�ܷ���NULL�����ҳɹ�����ָ��ý���ָ��
BiTree SearchBST(BiTree T, ElemType key)
{
	if(!T || key == T->data)    //����ʧ�ܷ���NULL
		return T;
	else if(key < T->data)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}
//����
//����ɹ�����1������ʧ�ܷ���0
int InsertBST(BiTree T, ElemType key)
{
	if(!T)  //����ʧ�ܣ������½��
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
//ɾ��
//ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
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
//ɾ����pΪ���Ķ����������Ľ�㣬���ؽ��������������
int Delete(BiTree p)
{
	BiTree q, s;
	if (p->rchild == NULL)   //ֻ����������������
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)  //ֻ��������
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else    //��������������
	{
		q = p;
		s = p->lchild;
		while (s->rchild)    //ת��Ȼ�������ߵ���ͷ���Ҵ�ɾ����ǰ����
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;  //sָ��ɾ����ǰ��
		if (q != p)
			q->rchild = s->lchild;  //�ؽ�q��������
		else
			q->lchild = s->lchild;  //�ؽ�q��������
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
//�������
int leveltraverseTree(BiTree T) {
	BiTree queue[100];
	int front = 0, rear = 0, size = 1, depth = 0;
	depth = depthOfTree(T);
	if (T) {
		queue[rear++] = T;
		for (int a = 0; front < rear, a < depth; a++) {
			size = rear - front;
			for (int i = 0; i < size; i++) {
				//��ӡһ��
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

// �ж�����ЧԪ�ص���ȣ��սڵ㲻����ЧԪ��
int depthOfTree(BiTree root) {
	// ������ڵ�Ϊ�գ�����0
	if (root == NULL) return 0;
	// ������ڵ�û���ӽڵ㣬����1
	if (root->lchild == NULL && root->rchild == NULL) return 1;
	// �����������������������
	int left = depthOfTree(root->lchild);
	int right = depthOfTree(root->rchild);
	// ���ؽϴ����ȼ�1
	return left > right ? left + 1 : right + 1;
}

//������
Heap createHeap(Heap H) {
	//H = malloc(sizeof(struct heap));
	//��һ������Ϊ�ѵ�Ԫ��
	//H->data = malloc(100 * sizeof(ElemType));

	H->size = 0;
	H->capacity = 100;
	//��һ��Ԫ����Ϊ���Ԫ��
	H->data[0] = -22002072;
	return H;
}

//����Ԫ��
void InsertHeap(Heap H, ElemType item) {
	int i;
	if (H->size == H->capacity) {
		printf("������\n");
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