#include "g-mission.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arg;

#ifdef DEBUG

    int n, x, y;
    freopen("./testdata/test.in", "r", stdin);
    scanf("%d", &n);
    printf("建立链表测试\n");
    link th = createLink(n);
    for (nodeptr i = th.head->next; i != th.head;i=i->next)
        printf("%d ", i->data);
    printf("\n功能一测试\n");
    function1Solve(n);
    scanf("%d %d %d", &n, &x, &y);
    printf("功能二测试\n");
    function2Vertify(n, x, y);
    return 0;

#else

    printf("功能列表\n");
    printf("1.输入n求解x,y\n");
    printf("2.验证n,x,y\n");
    printf("0.退出程序\n");
    int n, x, y;
    do
    {
        printf("请输入功能选项:");
        scanf("%d",&arg);
        switch(arg)
        {
            case 0:
                printf("感谢使用\n");
                break;
            case 1:
                printf("请输入n:");
                scanf("%d", &n);
                function1Solve(n);
                break;
            case 2:
                printf("请输入n,x,y:");
                scanf("%d %d %d", &n, &x, &y);
                function2Vertify(n, x, y);
                break;
            default:
                printf("Invalid Arg!\n");
                break;
        }
    } while (arg != 0);

    return 0;

#endif

}


