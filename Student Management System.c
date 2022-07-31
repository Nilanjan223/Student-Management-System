#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;

}* head=NULL;
void insert(int rollnumber, char* name, char* phone, float percentage)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
}
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Roll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Percentage: %f\n", temp->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(int rollnumber)
{

    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL){

        if(temp1->rollnumber==rollnumber){
            printf("Record with roll number %d Found !!!\n", rollnumber);
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("Record Successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);

}
void display()
{
    struct Student *temp = head;
    if(head==NULL)
    {
        printf("List is Empty!!!\n");
    }
    else{
    while(temp!=NULL){

        printf("Roll Number\tName\tPhone\tPercentage\n");
        printf("%d         \t%s  \t%s   \t%f\n", temp->rollnumber, temp->name, temp->phone, temp->percentage);
        temp = temp->next;
    }
    }
}

void sorting()
{
    if(head==NULL)
    {
        printf("Sorting not possible.List is empty!!\n");
    }
    else{
struct Student *ptr1,*ptr2;
int temp1,temp2;
char temp3[100];
char temp4[100];
ptr1 = head;
while(ptr1 -> next != NULL)
{
ptr2 = ptr1 -> next;
while(ptr2 != NULL)
{
if(ptr1 -> percentage > ptr2 -> percentage)
{
temp1 = ptr1 -> percentage;
ptr1 -> percentage = ptr2 -> percentage;
ptr2 -> percentage = temp1;
temp2 = ptr1 -> rollnumber;
ptr1 -> rollnumber = ptr2 -> rollnumber;
ptr2 ->rollnumber = temp2;
strcpy(temp3,ptr1->name);
strcpy(ptr1->name,ptr2->name);
strcpy(ptr2->name,temp3);
strcpy(temp4,ptr1->phone);
strcpy(ptr1->phone,ptr2->phone);
strcpy(ptr2->phone,temp4);
}
ptr2 = ptr2 -> next;
}
ptr1 = ptr1 -> next;
}
printf("Sorting Completed!!\n");
    }
}

int main()
{

    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details\n6 to sort student details\n7 to exit\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                insert(rollnumber, name, phone, percentage);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
            case 6:
                sorting();
                break;
            case 7:
                break;
            default:
                printf("Invalid choice!!\n");
                break;
        }

    } while (choice != 7);
}
