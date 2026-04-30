#include <stdio.h>
#include <string.h>

#define SIZE 8 

struct c_buf {
    char data[SIZE];
    int h;       
    int t;         
    int n;          
};

//تابع لتهيئة المخزن 
void init(struct c_buf *b) {
    b->h = 0;
    b->t = 0;
    b->n = 0;
}

// تابع للتحقق: هل المخزن ممتلئ؟
int isFull(struct c_buf *b) {
    return b->n == SIZE;
}

// تابع للتحقق: هل المخزن فارغ؟
int isEmpty(struct c_buf *b) {
    return b->n == 0;
}

// تابع للكتابة داخل المخزن
void write(struct c_buf *b, char val) {
    if (isFull(b)) {
        // حالة المخزن ممتلئ، لا يمكن إضافة المزيد من العناصر
        printf("Warning: Buffer Full! can't add '%c'\n", val);
    } else {
        b->data[b->h] = val;        
        b->h = (b->h + 1) % SIZE;  
        b->n++;                  
    }
}

// تابع للقراءة من المخزن
char read(struct c_buf *b) {
    if (isEmpty(b)) {
        printf("\n[Error]: Buffer is empty\n");
        return '\0';
    } else {
        char val = b->data[b->t];  
        b->t = (b->t + 1) % SIZE; 
        b->n--;                 
        return val;
    }
}

int main() {
    printf("========================================\n");
    printf("   Circular Buffer System - By name   \n");
    printf("========================================\n\n");

    struct c_buf b;
    init(&b); 

    char name[50];
    
    printf("Please enter your name: ");
    scanf("%s", name); // استقبال الاسم من المستخدم

    strcat(name, "CE-ESY"); // إضافة نص إضافي للاسم
    printf("\nProcessing Full Text: %s\n", name);
    printf("----------------------------------------\n");

    printf("Status log:\n");
    //لتخزين كل حرف من الاسم داخل المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(&b, name[i]);
    }

    printf("\nOutput from Circular Buffer: ");
    printf("\"");
    //  لقراءة وطباعة الحروف من المخزن حتى يفرغ
    while (!isEmpty(&b)) {
        printf("%c", read(&b));
    }
    printf("\"\n");

    if (isEmpty(&b))
        printf("\nFinal Status: Buffer is now empty. Operation Successful.\n");
    
    printf("----------------------------------------\n");
    return 0;
}