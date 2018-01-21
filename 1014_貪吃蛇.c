#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct snake{
    int HeadX[20];
    int HeadY[20];
    int Type;
    char Collision;
    // 0 Safe
    // 1 itself
    // 2 board
}snake_t,*psnake_t;

void NextMove(char Order,psnake_t MySnake);
int CheckCollision(snake_t MySnake);
void PrintSnake(psnake_t MySnake);

int main()
{
    int n;
    while(scanf("%d",&n) && n != 0)
    {
        snake_t MySnake;
        MySnake.Type = 0;
        int i;
        for(i=0; i<20; i++)
        {
            MySnake.HeadX[i] = 25-1;
            MySnake.HeadY[i] = 11-1+i;
        }
        char move[100];
        scanf("%s",move);
        MySnake.Collision = 'W';
        for(i=0; i<strlen(move); i++)
        {
            if(MySnake.Collision == move[i])
            {
                MySnake.Type = 1;
            }
            else
            {
                NextMove(move[i],&MySnake);
                // PrintSnake(&MySnake);
                if(CheckCollision(MySnake) == 1)
                {
                    MySnake.Type = 1;
                }
            }
            if(MySnake.Type == 1)
            {
                printf("The worm ran into itself on move %d.\n",i+1);
                break;
            }
            else if(MySnake.Type == 2)
            {
                printf("The worm ran off the board on move %d.\n",i+1);
                break;
            }


        }
        if(MySnake.Type == 0)
        {
            printf("The worm successfully made all %d moves.\n",i);
        }
    }

    return 0;
}

void NextMove(char Order,psnake_t MySnake)
{
    int i;
    for(i=0; i<19; i++)
    {
        MySnake->HeadX[i] = MySnake->HeadX[i+1];
        MySnake->HeadY[i] = MySnake->HeadY[i+1];
    }

    if(Order == 'E')
    {
        MySnake->HeadY[19] = MySnake->HeadY[19]+1;
        MySnake->Collision = 'W';
    }
    if(Order == 'W')
    {
        MySnake->HeadY[19] = MySnake->HeadY[19]-1;
        MySnake->Collision = 'E';
    }
    if(Order == 'S')
    {
        MySnake->HeadX[19] = MySnake->HeadX[19]+1;
        MySnake->Collision = 'N';
    }
    if(Order == 'N')
    {
        MySnake->HeadX[19] = MySnake->HeadX[19]-1;
        MySnake->Collision = 'S';
    }

    int HeadPointX,HeadPointY;
    HeadPointX = MySnake->HeadX[19];
    HeadPointY = MySnake->HeadY[19];
    if( HeadPointX > 49 || HeadPointX < 0 || HeadPointY > 49 || HeadPointY < 0 )
    {
        MySnake->Type = 2;
    }
}

int CheckCollision(snake_t MySnake)
{
    int i;
    for(i=0; i<19; i++)
    {
        if( MySnake.HeadX[i] == MySnake.HeadX[19] && MySnake.HeadY[i] == MySnake.HeadY[19] )
        {
            return 1;
        }
    }
    return 0;
}

void PrintSnake(psnake_t MySnake)
{
    int i;
    for(i=0; i<20; i++)
    {
        printf("%d %d | ",MySnake->HeadX[i],MySnake->HeadY[i]);
    }
    printf("\n");
}

