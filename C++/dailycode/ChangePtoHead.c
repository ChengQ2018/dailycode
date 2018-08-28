#include <stdio.h>

struct Node {
    struct Node *prior;
    int val;
    struct Node *next;
};

struct Node *GetTheList(int num)
{
    struct Node *cur=NULL, *prev=NULL, *head=NULL;
    int loop;
    for(loop=0; loop<num; loop++)
    {
        cur = (struct Node*)malloc(sizeof(struct Node));
        if(head == NULL)
        {
            head = cur;
            printf("plz input the head val :\n");
            scanf("%d", &(head->val));
            head->next = NULL;
            prev = head;
            head->prior = NULL;
        }
        else
        {
            cur->next = NULL;
            printf("plz input the no.%d val :\n", loop);
            scanf("%d", &(cur->val));
            cur->prior = prev;
            prev->next = cur;
            prev = cur;
        }
    }

    return head;
}

struct Node *ChangePtoHead(struct Node *p)
{
    struct Node *cur=NULL, *head=NULL, *tail=NULL;

    if(p == NULL)
        return NULL;

    for(cur=p; cur!=NULL; cur=cur->prior)
        head = cur;

    for(cur=p; cur!=NULL; cur=cur->next)
        tail = cur;

    head->prior = tail;
    tail->next = head;

    p->prior->next = NULL;
    p->prior = NULL;

    return p;
}

int main()
{
    struct Node *p = NULL, *cur = NULL, *test=NULL;
    int count = 0;
    cur = GetTheList(5);

    for(cur; cur!=NULL; cur=cur->next)
    {
        count++;
        if(count == 3)
        {
            p = cur;
            break;
        }
        //printf("prior = %p,  cur = %p,  next = %p,  val = %d\n", cur->prior, cur, cur->next, cur->val);
    }
    printf("prior = %p,  cur = %p,  next = %p,  val = %d\n", cur->prior, cur, cur->next, cur->val);
    test = ChangePtoHead(p);

    for(test; test!=NULL; test=test->next)
    {
        printf("prior = %p,  cur = %p,  next = %p,  val = %d\n", test->prior, test, test->next, test->val);
    }

    return 0;
}
