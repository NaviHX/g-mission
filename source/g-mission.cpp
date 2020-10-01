#include "g-mission.h"
#include <stdio.h>
#include <stdlib.h>

void function1Solve(int n)
{
    if(n<2)
        printf("输入非法\n");
    else
    {
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(judge(n,i,j))
                    printf("使得加里森留到最后的x,y值为(%d,%d)\n", i, j);
    }
}

void function2Vertify(int n,int x,int y)
{
    if(n<2 || x<0 || y<0)
        printf("输入非法\n");
    else
    {
        if(judge(n,x,y))
            printf("加里森可以留到最后一个而不用执行任务\n");
        else
            printf("加里森不能留到最后一个");
    }
}

link createLink(int n)
{
    link ret;
    nodeptr temp = NULL;
    ret.size = n;
    ret.head = (nodeptr)malloc(sizeof(node));
    ret.head->data = 0;
    ret.head->next = ret.head;
    while(n)
    {
        temp = (nodeptr)malloc(sizeof(node));
        temp->next = ret.head->next;
        temp->data = n;
        ret.head->next = temp;
        n--;
    }
    return ret;
}

void deleteNode(nodeptr prev, nodeptr now)
{
    prev->next = now->next;
    free(now);
}

int judge(int n,int x,int y)
{
    link list = createLink(n);
    int cnt;
    nodeptr cur=list.head->next, pre=list.head;
    while(cur->data!=x)
    {
        cur = cur->next;
        pre = pre->next;
    }
    while(list.size>1)
    {
        cnt = 0;
        while(cnt<y-1 || cur->data==0)
        {
            if(cur->data!=0)
                cnt++;
            cur = cur->next;
            pre = pre->next;
        }
        nodeptr temp = cur;
        cur = cur->next;
        deleteNode(pre, temp);
        list.size--;
    }
    return list.head->next->data == 1;
}
