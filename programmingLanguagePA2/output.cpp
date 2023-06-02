/*-- B2C ANTLR visitor --*/
// it return name asmain
// it return name ass
// it return name asi
// it return name asx
// it return name asx
// it return name ass
// it return name ass
// it return name asi
// it return name asi
// it return name asi
// it return name asx
// it return name asi
// it return name aslast
// it return name asprintf
// it return name aslast
// it return name ass
// it return name ass
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string
auto main(){
auto s ,i ,x ,last = 100;
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
// scope{1}, [last], (30)
