#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure.
typedef struct {
    char name[50];
    char roll_number[20];
    float cgpa;
} Student;

// Comparison function for qsort.
int compare_students(const void *a, const void *b) {
    return (*(Student*)b).cgpa - (*(Student*)a).cgpa;
}

// Function to sort students based on CGPA.
void sort_students(Student *students, int num_students) {
    qsort(students, num_students, sizeof(Student), compare_students);
}

int main() {
    // Sample list of students.
    Student students[] = {
        {"Alice", "A101", 3.7},
        {"Bob", "B102", 3.5},
        {"Charlie", "C103", 3.9},
        {"David", "D104", 3.2},
    };

    int num_students = sizeof(students) / sizeof(Student);

    // Sort the students based on CGPA.
    sort_students(students, num_students);

    // Print the sorted list.
    printf("Sorted Students by CGPA (Descending Order):\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll Number: %s, CGPA: %.2f\n", students[i].name, students[i].roll_number, students[i].cgpa);
    }

    return 0;
}
