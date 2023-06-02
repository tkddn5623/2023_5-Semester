/*-- B2C ANTLR visitor --*/
// Error:[Expression] (Type conflict occured.)::i
// Error:[Expression] (Type conflict occured.)::i
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string
double main(){
double s;
int i;
bool x;
int last = 100;
s = 0.0;
i = 1;
x = true;
while (x == true) {
s = s + i;
i = i + 1;
x = i < last;
}
printf("sum(%d) = %f\n", last, s);
return (s);
}
