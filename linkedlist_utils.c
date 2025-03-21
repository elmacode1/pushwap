#include "pushswap.h"

t_list  *lstnew(int content)
{
        t_list *new;
        new = malloc(sizeof(t_list));
        if(!new)
                return NULL;
        new->content = content;
        new->next = NULL;
        return new;
}
t_list  *lstlast(t_list *head)
{
        if(!head)
                return NULL;
        while(head->next)
        {
            head = head->next;
        }
        return head;
}
size_t  lstsize(t_list *head)
{
        int i;

        i = 0;
        if(!head)
                return 0;
        while(head)
        {
                head = head->next;
                i++;
        }
        return i;
}
void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	lstlast(lst)->next = new;
}

int main()
{
        t_list *head=NULL;

        int tab[5]={1,-8,0,12,7};
        head= lstnew(tab[3]);
        ft_lstadd_back(head,lstnew(tab[0]));
        ft_lstadd_back(head,lstnew(tab[1]));

        while(head){
                printf("%d,", head->content);
                head = head->next;
        }
}
