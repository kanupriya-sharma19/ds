
#include <stdio.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];

int delete();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);

int main()
{
    int n, i, s, ch, j;
    int c, dummy;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The Adjacency Matrix is: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

  do
{
    for (i = 1; i <= n; i++)
        vis[i] = 0;

    printf("\nMenu");
    printf("\n1. B.F.S");
    printf("\n2. D.F.S");
    printf("\nEnter the choice: ");
    scanf("%d", &ch);
    printf("Enter the source vertex: ");
    scanf("%d", &s);

    if (s < 1 || s > n)
    {
        printf("Invalid source vertex.\n");
        continue;
    }

    switch (ch)
    {
    case 1:
        bfs(s, n);
        break;
    case 2:
        dfs(s, n);
        break;
    default:
        printf("Invalid choice.\n");
    }

    printf("\nDo you want to continue? Press 3 for Yes: ");
    scanf("%d", &c);

} while (c == 3);


    return 0;
}

void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if (p != 0)
        printf(" %d", p);

    while (p != 0)
    {
        for (i = 1; i <= n; i++)
        {
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        }

        p = delete();
        if (p != 0)
            printf(" %d", p);
    }

    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item)
{
    if (rear == 19)
        printf("Queue full..");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}

int delete()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}


void dfs(int s, int n)
{int i;
   
        printf(" %d ", s);
   vis[s] = 1; 
 
        for (i = 1; i <= n; i++)
        {
            if (a[s][i]==1&&(vis[i] == 0))
            {
              dfs(i,n);
            }
        }

   
}
