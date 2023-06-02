/*-- B2C ANTLR visitor --*/
// Error:[ASSIGNMENT](Type conflict occured.):func2
// Error:[Expression] (Type conflict occured.)::b
// Error:[Expression] (Type conflict occured.)::i
// Error:[ASSIGNMENT](Type conflict occured.):func2
// Error:[ASSIGNMENT](Type conflict occured.):func2
// Error:[Expression] (Type conflict occured.)::b
// Error:[Expression] (Type conflict occured.)::i
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string
string c = "global";
int q_ = 555;
void func1(auto , auto );
void func2(void p1);
void func1(void p1, void p2){
printf("glboal c is %d\n", c);
int c = 1;
printf("Now c is %d\n", c);
return (p1 + p2);
}
void func2(void p1){
return (p1 * 10);
}
int five(){
return (5);
}
int global2 = 5;
int main(){
int a;
double b;
int c;
string d;
int W = 5;
bool e;
char f;
//void g;
int E = 7;
//void fv;
a = 5;
b = 2.5;
c = 1;
d = "hello";
e = true;
f = 'c';
fv = five();
printf("%d\n", c);
if ((b > 1.0)) {
double c = 1.7;
int i = 0;
while (i < 10) {
printf("%d ", i);
i = i + 1;
}
printf("\n");
}
printf("c is %d\n", c);
return (0);
}
