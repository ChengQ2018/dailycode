#include <stdio.h>

struct Node {
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
        }
        else
        {
            cur->next = NULL;
            printf("plz input the no.%d val :\n", loop);
            scanf("%d", &(cur->val));
            prev->next = cur;
            prev = cur;
        }
    }

    return head;
}

int main()
{
    struct Node *test = NULL, *cur = NULL;
    cur = GetTheList(5);\

    for(cur; cur!=NULL; cur=cur->next)
    {
        printf("the val is : %d\n", cur->val);
    }

}
