# 调试分析报告

## 调试过程中的问题

### 1.访问无效内存

```c++
while(cnt<y-1 || cur->data==0)
{
    cnt++;
    if(cur->data!=0)
        cnt++;
    cur = cur->next; //访问无效内存
    pre = pre->next;
}
```

gdb调试发现该处访问无效内存,查看cur值发现为NULL,判断为没有在链表尾部添加指回头节点的指针,添加后正确执行

### 2.边界条件错误

```c++
    {
        int i,j;
        for(i=1;i<=n;i++)
-           for(j=2;j<=n;j++)
+           for(j=1;j<=n;j++)
                if(judge(n,i,j))
                    printf("使得加里森留到最后的x,y值为(%d,%d)\n", i, j);
    }
```

测试发现当n=9时,程序并没有输出x=1,y=2的解,调整边界条件即可

### 3.头节点参与报数导致答案错误

```c++
-       while(cnt<y)
+       while(cnt<y-1 || cur->data==0)
        {
-           cnt++;
+           if(cur->data!=0)
+               cnt++;
            cur = cur->next;
            pre = pre->next;
        }
```

gdb调试发现程序会删除作为头结点的0号节点,添加了判断是否为0号节点决定是否跳过报数的条件


