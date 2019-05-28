#include <stdio.h>
#include <string.h>

struct Student {
	char firstname[30];
	char lastname[30];
	int age;
	int studentid;
};

void printStudent(struct Student* student)
{
	printf("The following are the details for student %s %s.\n", student->firstname, student->lastname);
	printf("age: %d\n",student->age);
	printf("student ID: %d\n", student->studentid);
}

int main()
{
	char input[30], firstname[30], lastname[30];
	int numberstudents, age, studentid;
	printf("How many students (up to 50) would you like to store?\n");
	fgets(input, 30, stdin);
	sscanf(input, "%d", &numberstudents);
	struct Student student[50];
	for (int i = 0; i < numberstudents; i++)
	{
		printf("What is your first name?\n");
		fgets(input, 30, stdin);
		sscanf(input, "%s",firstname);
		printf("What is your last name?\n");
		fgets(input, 30, stdin);
		sscanf(input, "%s", lastname);
		printf("What is your age?\n");
		fgets(input, 30, stdin);
		sscanf(input, "%d", &age);
		printf("What is your student ID?\n");
		fgets(input, 30, stdin);
		sscanf(input, "%d", &studentid);
		strcpy(student[i].firstname, firstname);
		strcpy(student[i].lastname, lastname);
		student[i].age = age; 
		student[i].studentid = studentid;
	}
	for (int i = 0; i < numberstudents; i++)
	{
		printStudent(&student[i]);
	}

}
