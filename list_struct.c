#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int roll_no;
    char name[50];
    int marks;
} student;
student stud[100];
int n=0;
void addstud()
{
    printf("Enter roll no: ");
    scanf("%d",&stud[n].roll_no);

    printf("Enter name: ");
    scanf(" %[^\n]",stud[n].name);

    printf("Enter marks: ");
    scanf("%d",&stud[n].marks);

    n++;

    printf("\nStudent added successfully!\n");
    return;
}
void viewstud()
{
    int rn,i;
    printf("Enter the roll no: ");
    scanf("%d", &rn);
    for(i=0;i<n;i++)
    {
     if(stud[i].roll_no==rn)
        {
            printf("\n Match found!\n ");
            printf("Roll No: %d \n Name: %s \n Marks: %d \n", stud[i].roll_no, stud[i].name, stud[i].marks);
            printf("\n------------------------------------------------------------------------------------------------------------------------------------\n");
            continue;
        }
        else
        {
            printf("\n Match Not Found! \n");
        }
    }
}
void viewall()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Detail of student %d \n", n+1);
        printf("Roll No: %d \n Name: %s \n Marks: %d \n", stud[i].roll_no, stud[i].name, stud[i].marks);
        printf("\n---------------------------------------------------------------------------------------------------------------------------------------------------\n");

    }
}
int main()
{
    while (true)
    {
        int ch;
        printf("1. Add student \n 2. View student \n 3. View all student \n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
         addstud();
        }
        else if(ch==2)
        {
         viewstud();
        }
        else if(ch==3)
        {
            viewall();
        }
        else if(ch==4)
        {
            printf("\n Thank you!");
            break;
        }
        else
        {
            printf("\n Invalid choice! \n Try Again!");
        }
    }
    return 0;

}
