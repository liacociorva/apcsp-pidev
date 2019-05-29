#include "student.h"
void printStudent(struct Student* student)
{
	printf("The following are the details for student %s %s.\n", student->firstname, student->lastname);
	printf("age: %d\n",student->age);
	printf("student ID: %d\n", student->studentid);
}
