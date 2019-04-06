
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

struct node 
{ 
	long aadhno; 
	char name[50];
	struct node *left, *right; 
}*curr_node; 

struct node *newNode(int item,char iname[50]) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->aadhno = item; 
	strcpy(temp->name,iname);
	temp->left = temp->right = NULL; 
	return temp; 
} 
int search(struct node* root,long val)
{
    curr_node=root;
    int steps=0;
    while(1)
    {
		if(curr_node->aadhno==val)
		{
			steps++;
			return curr_node;
		}
		else if(curr_node->aadhno>val)
		{
			steps++;
			if(curr_node->left==NULL)
            {
                return 0;
            }
            else if(curr_node->left->aadhno==val)
            {
                steps++;
                printf("%d\n",steps);
                printf("Name: %s \n",curr_node->left->name);


                return curr_node->left;
            }
				steps++;
                curr_node=curr_node->left;
			
		}
		else if(curr_node->aadhno<val)
		{
			steps++;
			if(curr_node->right==NULL)
            {
                return 0;
            }
            else if(curr_node->right->aadhno==val)
            {
                steps++;
                printf("%d\n",steps);
                printf("Name: %s \n",curr_node->right->name);


                return curr_node->right;
            }
            
				steps++;
                curr_node=curr_node->right;
			
		}
	}
};

struct node* insert(struct node* node, long key, char iname[50]) 
{ 
	if (node == NULL) return newNode(key,iname); 

	if (key < node->aadhno) 
		node->left = insert(node->left,key,iname); 
	else if (key > node->aadhno) 
		node->right = insert(node->right,key,iname); 

	return node; 
} 

int main() 
{ int i,n;
	struct node *q;
	int flag=0;
	char a[50];
    struct node *root1 = NULL;
	FILE *ptr_file;
    		char buf[1000];

    		ptr_file =fopen("randno.txt","r");
    		if (!ptr_file)
    		{
				printf("No such File\n");
        		return 1;
			}

		
 
      for(i=0;i<40000;i++)
    {
		if(flag==0)
		{
		  fscanf(ptr_file,"%d %[^\n]s",&n,a);
			root1=insert(root1,n,a);
			flag=1;
		}
		
		else
		{
			fscanf(ptr_file, "%d %[^\n]s",&n,a);
			insert(root1,n,a);
		flag++;
		//printf("if dont wnna continue press 0");
		//scanf("%d",&p);
		}
		
		
	}
	printf("Data Added to BST\n");
	fclose(ptr_file);
	int p;
	printf("Enter Number:");
	scanf("%d",&p);
	clock_t begin=clock();
    q=search(root1,p);
    if(q==0){printf("Not Found in BST\n");}
    else
	{
		printf("Found");
	}
	clock_t end=clock();
	double time_taken = ((double)(end - begin)/CLOCKS_PER_SEC);
  
    printf("BST took %f seconds to execute \n", time_taken);
 

   
    return 0; 
}

