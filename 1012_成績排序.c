#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int number;
    int grade;
}student_t,*pstudent_t;

void BubbleSort(pstudent_t stu,int n);

int main()
{
    int n;
    while(scanf("%d ",&n) != EOF)
    {
        student_t stu[100];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&stu[i].number,&stu[i].grade);
        }
        BubbleSort(stu,n);
        for(i=0;i<n;i++)
        {
            printf("%d %d\n",stu[i].number,stu[i].grade);
        }
    }

    return 0;
}

void BubbleSort(pstudent_t stu,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            int temp;
            if(stu[j].grade > stu[j+1].grade)
            {
                temp            = stu[j].grade;
                stu[j].grade    = stu[j+1].grade;
                stu[j+1].grade  = temp;
                temp            = stu[j].number;
                stu[j].number   = stu[j+1].number;
                stu[j+1].number = temp;
            }
        }
    }
}

