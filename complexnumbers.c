#include<stdio.h>

typedef struct complex_number {
    float real;
    float imag;
} complex_n;



complex_n sum(complex_n num1, complex_n num2) {
    complex_n result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return (result);
}



int main(){

float a = 1;
float b = 1;
float c = 2;
float d = 2;
complex_n mynum1= {a, b};
complex_n mynum2= {c, d};

printf("%f", sum(mynum1, mynum2));



  return 0;
}
