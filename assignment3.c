//3. Create array of 5 students(rollno, name, marks) and sort students by their marks. 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// struct person with 3 fields 
struct Student { 
	char* name; 
	int roll_no; 
	int marks; 
}; 
int comparator(const void* p, const void* q) 
{ 
	return (((struct Student*)p)->marks - ((struct Student*)q)->marks); 
} 


int main() 
{ 
	int i = 0, n = 5; 

	struct Student arr[n]; 
	arr[0].roll_no = 1; 
	arr[0].name = "sayali"; 
	arr[0].marks = 12; 

	arr[1].roll_no = 2; 
	arr[1].name = "manish"; 
	arr[1].marks = 10; 

	arr[2].roll_no = 3; 
	arr[2].name = "jay"; 
	arr[2].marks = 8; 

	arr[3].roll_no = 4; 
	arr[3].name = "jeet"; 
	arr[3].marks = 9; 

	arr[4].roll_no = 5; 
	arr[4].name = "rakesh"; 
	arr[4].marks = 10; 

	
	printf("Unsorted Student Records:\n"); 
	for (i = 0; i < n; i++) { 
		printf("roll_no = %d, Name = %s, marks = %d \n", 
			arr[i].roll_no, arr[i].name, arr[i].marks); 
	} 
	
	
	qsort(arr, n, sizeof(struct Student), comparator); 

	
	printf("\n\nStudent Records sorted by marks:\n"); 
	for (i = 0; i < n; i++) { 
		printf("roll_no = %d, Name = %s, marks = %d \n", 
			arr[i].roll_no, arr[i].name, arr[i].marks); 
	} 

	return 0; 
} 
