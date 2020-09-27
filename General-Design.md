# 概要设计

## 功能一思路

先判断n的值是否合理,在n合理的情况下,将编号为1-n的敢死队员加入到循环链表中,构造二重循环遍历x,y的值(1<=x<=n,2<=y<=n),将指针移动到x号节点处,模拟报数的方式,利用一个计数器保存报数的值,每次报数到y时删除当前节点直到加里森留到最后一个或者加里森去执行任务.如果加里森留到最后一个,则输出当前x,y的值作为一个解,否则不输出

## 功能二思路

先判断用户给定的n,x,y的值是否合理,如果合理,将编号为1-n的敢死队员加入到循环链表中,将指针移动到x号节点处,模拟报数的方式,利用一个计数器保存报数的值,每次报数到y时删除当前节点直到加里森留到最后一个或者加里森去执行任务.如果加里森留到最后一个,则输出"加里森可以留到最后一个而不用执行任务",否则输出"加里森不能留到最后一个"

## 数据结构类型定义

```c++
typedef struct NODE//链表节点
{
    int data;//编号
    struct NODE* next;//后继结点指针
}node *nodeptr;

typedef struct LINK//链表
{
    nodeptr head;//链表头节点
    int size;//链表大小
}link;
```

## 主程序流程

```c++
int main()
{
    int arg;

    printf("功能列表\n");
    printf("1.输入n求解x,y\n");
    printf("2.验证n,x,y\n");
    printf("0.退出程序\n");

    do
    {
        printf("请输入功能选项:");
        scanf("%d",&arg);
        /*
        执行相应功能
        */
    }while(arg!=0)

    return 0;
}
```

## 函数调用关系

main()调用function1Solve()和function2Vertify(),function1Solve()和function2Vertify()调用createLink()和judge(),judge()调用deleteNode()
