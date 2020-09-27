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
            for(j=2;j<=n;j++)
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
    ret.head->next = NULL;
    while(n)
    {
        temp = (nodeptr)malloc(sizeof(node));
        temp->next = ret.head->next;
        ret.head->next = temp;
        n--;
    }
    return ret;
}
