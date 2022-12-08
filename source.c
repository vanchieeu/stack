#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int top = -1;
int size;

//Khởi tạo stack
char *initStack(int size) {
    char *stack = (char *)malloc(size * sizeof(char));
    return stack;
}

//Check stack có full hay không
bool IsFull(int n) {
    if (top == n - 1)
        return true;
    else
        return false;
}

//Check stack có rỗng hay không
bool IsEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}

//Thêm phần tử cho stack
void Push(char *stack, char value, int n) {
    if (IsFull(n) == true) {
        printf("Stack is FULL.\n");
    } else {
        top++;
        stack[top] = value;
    }
}

//Xóa phần từ đầu của stack
void Pop() {
    if (IsEmpty() == true) {
        printf("Stack is empty.\n");
    } else
        top--;
}

//Lấy giá trị của phần tử đầu
char Top(char *stack) {
    return stack[top];
}

//Lấy kích cỡ stack
int sizeStack(char *stack) {
    return top+1;
}

//Lấy giá trị từ file
void getInfo(char *filename, int *size, char *stack) {
    FILE *fptr;
    fptr = fopen(filename, "r");

    fscanf(fptr, "%d", size);
    char c;
    while (fscanf(fptr, "%c", &c) != EOF) {
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
            Push(stack, c, *size);
    }

    fclose(fptr);
}

//Xuất giá trị ra file
void coutFile(char *filename, char *stack) {
    FILE *fptr;
    fptr = fopen(filename, "w");

    while (IsEmpty() != true) {
        fprintf(fptr, "%c", stack[top]);
        Pop();
    }

    fclose(fptr);
}

int main() {
    char *stack = initStack(100);
    getInfo("input.txt", &size, stack);
    coutFile("output.txt", stack);
    return 0;
}