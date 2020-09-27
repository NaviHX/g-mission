typedef struct NODE//链表节点
{
    int data;//编号
    struct NODE* next;//后继结点指针
}node,*nodeptr;

typedef struct LINK//链表
{
    nodeptr head;//链表头节点
    int size;//链表大小
}link;

void function1Solve(int n);
void function2Vertify(int n,int x,int y);
int judge(int n,int x,int y);
link createLink(int n);
void deleteNode(nodeptr prev,nodeptr now);
