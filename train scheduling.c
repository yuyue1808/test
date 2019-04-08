#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
struct stack
{
    int data[maxsize];
    int top;
};
int n;
void push(struct stack *ptrs,int item)
{
    ptrs->top++;
    ptrs->data[ptrs->top]=item;
}
int pop(struct stack *ptrs)
{
    int a;
    a=ptrs->data[ptrs->top];
    ptrs->top--;
    return a;
}
void schedule(struct stack *ptrs,int x,int line[n],int y)
{
    int i,m;
    if(x<n)
    {
        push(ptrs,x+1);
        schedule(ptrs,x+1,line,y);
        pop(ptrs);
    }
    if(ptrs->top!=0)
    {
        m=pop(ptrs);
        line[y]=m;
        y++;
        schedule(ptrs,x,line,y);
        push(ptrs,m);
    }
    if(x==n&&ptrs->top==0)
    {
        for(i=0; i<y; i++)
        {
            printf("%d\t",line[i]);
        }
        printf("\n");
    }
}
int main()
{
    int outline[maxsize];
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=0;
    printf("请输入要调度车厢总数n=");
    scanf("%d",&n);
    push(s,1);
    printf("所有输出序列：\n");
    schedule(s,1,outline,0);
    return 0;
}

