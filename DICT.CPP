#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
struct word
{
	char str[100];
};
struct node
{
	char word[100];
	char def[100];
	struct node *next;
};
struct node *start=NULL;
int check(char w[])
{
	int i;
	struct node *p;
	if(start==NULL)
		i=1;
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(strcmp(p->word,w)==0)
			{
				printf("Word Already Exists.\n");
				i=0;
				break;
			}
			p=p->next;
		}
		if(p==NULL)
			i=1;

	}
	return i;
}
void modify(char w[])
{
	int i;
	char c;
	struct node *p;
	if(start==NULL)
		printf("Underflow, Dictionary Empty.\n:");
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(strcmp(p->word,w)==0)
			{
				printf("Original Definition: %s\nChange Definiton(Y/N):",p->def);
				scanf("%s",&c);
				switch(c)
				{
					case 'Y':
					case 'y':
					printf("Enter New Definition:");
					scanf("%s",&p->def);
					i=0;
					while(p->def[i])
					{
						if(p->def[i]>='a'&&p->def[i]<='z')
							p->def[i]=p->def[i]-32;
						i++;
					}
					printf("Definition Changed.\n");
					break;
					case 'N':
					case 'n':
					printf("\n");
					default:
					printf("Wrong Input.\n");
				}
				break;
			}
			p=p->next;
		}
		if(p==NULL)
			printf("Word Doesnt Exist.\n");
	}
}
void accept(char w[])
{
	int i;
	void dispWord(char w[]);
	char c;
	if(check(w)==0)
	{
		printf("Would You Like To See The Definition(Y/N):");
		scanf("%c",&c);
		switch(c)
		{
			case 'Y':
			case 'y':
			dispWord(w);
			break;
			case 'N':
			case 'n':
			printf("\n");
			break;
			default:
			printf("Wrong Input.\n");
		}
	}
	else
	{
	struct node *p;
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	strcpy(nn->word,w);
	printf("Enter Definition:");
	scanf("%s",&nn->def);
	i=0;
	while(p->def[i])
	{
		if(p->def[i]>='a'&&p->def[i]<='z')
			p->def[i]=p->def[i]-32;
		i++;
	}
	if(start==NULL)
	{
		start=nn;
		nn->next=NULL;
	}
	else
	{
		if(strcmp(start->word,w)>0)
		{
			nn->next=start;
			start=nn;
		}
		else
		{
			p=start;
			while(p->next!=NULL)
			{
				if(strcmp(p->next->word,w)>0)
					break;
				p=p->next;
			}
			nn->next=p->next;
			p->next=nn;
		}
	}
	printf("Word Added.\n");
	}
}
void del(char w[])
{
	struct node *p;
	struct node *q;
	if(start==NULL)
		printf("Underflow, Dictionary Empty.\n");
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(strcmp(p->word,w)==0)
			{
				printf("Word Deleted.\n");
				if(p==start)
				{
					start=start->next;
				}
				else
				{
					q->next=p->next;
					free(p);
				}
				break;
			}
			q=p;
			p=p->next;
		}
		if(p==NULL)
			printf("Word Doesn't Exist.\n");
	}
}
void dispAll()
{
	if(start==NULL)
		printf("Dictionary Empty.\n");
	else
	{
		struct node *p=start;
		char c;
		while(p!=NULL)
		{
			c=p->word[0];
			printf("%c\n",c);
			{
				while(c==p->word[0])
				{
					printf("%s: %s\n",p->word,p->def);
					p=p->next;
					if(p==NULL)
						break;
				}
				printf("\n");
			}
		}
	}
}
void dispAlpha(char c)
{
	int ctr=0;
	struct node *p;
	if(start==NULL)
	{
		printf("Underflow, Dictionary Empty.\n");
	}
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(p->word[0]==c)
			{
				ctr=1;
				printf("%s: %s\n",p->word,p->def);
			}
			p=p->next;
		}
		if(ctr==0)
		{
			printf("No Match Found For Entered String.\n");
		}
	}
}
void dispWord(char w[])
{
	char c;
	struct node *p;
	if(start==NULL)
		printf("Underflow, Dictionary Empty\n");
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(strcmp(p->word,w)==0)
			{
				printf("Meaning: %s\n",p->def);
				break;
			}
			p=p->next;
		}
		if(p==NULL)
		{
			printf("Word Doesn't Exist In Dictionary.\nWould You Like To Add It (Y/N):");
			scanf("%c",&c);
			switch(c)
			{
				case 'Y':
				case 'y':
				accept(w);
				break;
				case 'N':
				case 'n':
				printf("\n");
				break;
				default:
				printf("Wrong Input.\n");
			}
		}
	}
}
void main()
{
	char c;
	int ch,i;
	clrscr();
	do
	{
		struct word *w=(struct word *)malloc(sizeof(struct word));
		printf("Menu\n1.Find Definition\n2.Display All Words\n3.Display All Words Starting With A Particular Letter\n4.Enter A Word Into The Dictionary\n5.Change Definition Of A Word\n6.Delete A Word\n0.Exit\nEnter Choice:");
		scanf("%i",&ch);
		printf("\n");
		if(ch==1||ch==4||ch==5||ch==6)
		{
			printf("Enter Word:");
			scanf("%s",&w->str);
			i=0;
			while(w->str[i])
			{
				if(w->str[i]>='a'&&w->str[i]<='z')
					w->str[i]=w->str[i]-32;
				i++;
			}
		}
		if(ch==3)
		{
			printf("Enter Starting Character:");
			scanf("%s",&w->str);
			c=w->str[0];
		       if(c>='a'&&c<='z')
				c=c-32;
		}
		switch(ch)
		{
			case 1:
			dispWord(w->str);
			break;
			case 2:
			dispAll();
			break;
			case 3:
			dispAlpha(c);
			break;
			case 4:
			accept(w->str);
			break;
			case 5:
			modify(w->str);
			break;
			case 6:
			del(w->str);
			break;
			case 0:
			getch();
			break;
			default:
			printf("Wrong Input.\n");
		}
	printf("\n");
	free(w);
	}while(ch!=0);
}