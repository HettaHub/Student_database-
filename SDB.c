#include "SDB.h"

#define MAX_STUDENTS 3


static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull()//check if the database is full or not.
{
    return (usedSize >= MAX_STUDENTS);
}

uint8 SDB_GetUsedSize() //get how many students in your database have added
{
    return usedSize;
}

bool SDB_AddEntry()//When the user chooses to add entry this function asks him for the required data in the database to add one student which is his (id, year, Course1_ID, Course1_grade, Course2_ID,Course3_grade) Course2_grade, Course3_ID, and Course3_grade)and then add to your database.
{
    if (usedSize >= MAX_STUDENTS)
        {
        return false;
        }

    student newStudent;

    printf("Enter the student ID: ");
    scanf("%u", &newStudent.Student_ID);

    printf("Enter the student year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);

    printf("Enter Course 1 grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);

    printf("Enter Course 2 grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);

    printf("Enter Course 3 grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[usedSize] = newStudent;
    usedSize++;

    return true;
}

void SDB_DeleteEntry(uint32 id)  //delete the student data with the given id by Shiftting elements to the left to remove the entry
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
         {
            for (uint8 j = i; j < usedSize - 1; j++)
             {
                database[j] = database[j + 1];
             }
            usedSize--;
            break;
        }
    }
}

bool SDB_ReadEntry(uint32 id) //print the data of the user by searching on his data by the given id
{


    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            printf("Student ID is %u\n", database[i].Student_ID);
            printf("Student year is %u\n", database[i].Student_year);
            printf("Course 1 ID is %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID is %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID is %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return true;
        }
    }
    return false;
}

void SDB_GetList(uint8* count, uint32* list)//it gets the number of ids in the count and the list of all ids in list array that’s you get his base address.
 {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; i++)
    {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id)//Checks if the given id the is exist
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}
