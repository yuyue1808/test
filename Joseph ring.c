#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 7
typedef struct lnode
{
    int number;
    int key;
    struct lnode *next;
} lnode,*linklist;
int delete_num=0;
linklist creatlist(int a[20],int n)
{
    linklist head=(linklist)malloc(sizeof(lnode));
    head->next=NULL;
    linklist r=head;
    head->number=1;
    head->key=a[0];
    for(int i=1; i<n; i++)
    {
        linklist p=(linklist)malloc(sizeof(lnode));//����һ���ռ�
        p->number=i+1;
        p->key=a[i];
        r->next=p;//���ӽڵ�
        r=p;
    }
    r->next=head;
    return head;

}
linklist linkdelete(linklist head,int i)
{
    if( head->next == head )
    {
        printf("the winer: %d\n", head->number);
        return 0;
    }
    linklist y;
    int j;
    for(j=1, y=head; j<i; j++, y = y->next);
    linklist pre = y;
    while(pre->next != y)
    {
        pre = pre->next;
    }
    pre->next = y->next;
    printf("num;%d����\n", y->number);
    delete_num = y->key;
    free(y);
    return pre->next;
}
/*void print_list(linklist head)
{
    linklist r;
    r = head;
    do
    {
        printf("num = %d; key = %d\n", r->number, r->key);
        r = r->next;
    }
    while(r != head);
}*/
int game(linklist L, int n, int first_m)
{
    linklist b=L;
    int flag=1;
    while(n)
    {
        if(flag)
        {
            b=linkdelete(b,first_m);
            flag=0;
            // print_list(b);
        }
        else
        {
            b=linkdelete(b,delete_num);
            //print_list(b);
        }
        n--;
    }
    return 0;
}
int main()
{
    int c[20],i,first_m;
    linklist L;
    printf("��������Ϸ������:");
    for(i=0; i<N; i++)
    {
        scanf("%d",&c[i]);
    }
    L=creatlist(c,N);
    printf("�������ʼmֵ��");
    scanf("%d",&first_m);
    game(L,N,first_m);
    return 0;
}



