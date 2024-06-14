#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice);//prototype declaration for the SDB_action() function

void SDB_APP()
{
    uint8 choice;

    do
     {
        printf("Choose between these options \n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in the database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if an ID exists, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if the database is full, enter 7\n");
        printf("8. To exit, enter 0\n");
        scanf("%hhu", &choice);

        SDB_action(choice);//// Call SDB_action() function
     }
    while (choice != 0);
}

void SDB_action(uint8 choice)
{
    uint32 id;
    uint8 count;
    uint32 list[3];

    switch (choice)
    {
        case 1://check if the data base full or not
            if (SDB_AddEntry())
            {
                printf("Data added successfully.\n");
                printf("\n");
            }
            else
            {
                printf("Data could not be added. Database is full.\n");
                printf("\n");
            }
            break;

        case 2:// Call a function SDB_GetUsedSize() and print the result
            printf("Used size in the database: %hhu\n", SDB_GetUsedSize());
            break;

        case 3://// Read student ID and call SDB_ReadEntry() with the ID
            printf("Enter the student ID: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id))
            {
                printf("Data found.\n");
                printf("\n");
            }
            else
            {
                printf("Data not found.\n");
                printf("\n");
            }
            break;

        case 4:// Call SDB_GetList() to print a list of student IDs
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (uint8 i = 0; i < count; i++)
                {
                printf("%u ", list[i]);
                }
            printf("\n");
            break;

        case 5:// Read student ID and call SDB_IsIdExist() to check if it exists or not
            printf("Enter the student ID ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id))
            {
                printf("ID exists.\n");
                printf("\n");
            }
            else
            {
                printf("ID does not exist.\n");
                printf("\n");
            }
            break;

        case 6:// Read student ID and call SDB_DeleteEntry() with the ID
            printf("Enter the student ID ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            printf("Data deleted successfully.\n");
            break;

        case 7:// Call SDB_IsFull() to check if the database is full or not
            if (SDB_IsFull())
            {
                printf("Database is full.\n");
                printf("\n");
            }
            else
            {
                printf("Database is not full.\n");
                printf("\n");
            }
            break;

        case 0: // Exit
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
