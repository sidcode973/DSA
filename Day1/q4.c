#include <stdio.h>


struct Complex {
    float real;
    float imag;
};


struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}


void multiplyComplex(struct Complex *c1, struct Complex *c2, struct Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

void printComplex(struct Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

int main() {
    struct Complex c1, c2, result;
    int choice;

    while (1) {

        printf("Menu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        
        printf("Enter the real and imaginary part of the first complex number: ");
        scanf("%f %f", &c1.real, &c1.imag);
        printf("Enter the real and imaginary part of the second complex number: ");
        scanf("%f %f", &c2.real, &c2.imag);

        switch (choice) {
            case 1:
            
                result = addComplex(c1, c2);
                printf("The sum is: ");
                printComplex(result);
                break;
            case 2:
            
                multiplyComplex(&c1, &c2, &result);
                printf("The product is: ");
                printComplex(result);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}