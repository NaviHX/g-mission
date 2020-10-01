# 详细设计

void function1Solve(int n)  
将编号为1-n的敢死队员加入到循环链表中,构造二重循环遍历x,y的值(1<=x<=n,2<=y<=n),调用judge()判断是否符合条件

```c++
void function1Solve(int n)
{
    if(n<2)
        printf("输入非法\n");
    else
    {
        int i,j;
        //二重循环遍历x,y
        {
            if(judge())
                //输出一组解
        }
    }
}
```

void function2Vertify(int n, int x, int y)  
将编号为1-n的敢死队员加入到循环链表中,验证(n,x,y)是否符合条件

```c++
void function2Vertify(int n, int x, int y)
{
    //检查输入是否非法
    else
    {
        if(judge(n,x,y))
            //输出该组值符合条件
        else
            //输出不符合条件
    }
}
```

link createLink(int n)  
创建一个空链表头,以头插法将值为n~1的结点插入到空链表中

```c++
link createLink(int n)
{
    //创建空表头
    //初始化链表大小
    while(n!=0)
    {
        //头插新节点
    }
}
```

void deleteNode(nodeptr prev, nodeptr now)  
删除除表头结点外的节点

```c++
void deleteNode(nodeptr prev, nodeptr now)
{
    prev->next=now->next;
    free(now);
}
```

int judge(int n, int x, int y)  
判断(n,x,y)是否符合条件  
首先创建一个含有n个元素的链表
以模拟报数的方式,从x开始开始报数,用一个计数器保存报数的值,每次报到y时删除当前节点直到仅剩一个节点时,返回剩下的节点是否为1号节点的布尔值

```c++
int judge(int n, int x, int y)
{
    link list=createLink(n);//创建链表
    int cnt;
    nodeptr cur,pre;
    //将cur移动到起始位置x,pre移动到x前驱位置
    while(list.size>1)
    {
        cnt=0;
        while(cnt<y)
        {
            //将cur,pre移动到将要删除的位置
        }
        nodeptr temp=cur;
        cur=cur->next;
        deleteNode(pre,temp);
        list.size--;
    }
    return list.head->next->data==1;
}
```
