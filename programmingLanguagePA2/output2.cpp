/*-- B2C ANTLR visitor --*/
// it return name asfunc1
// it return name asfunc2
// it return name asp1
// it return name asfunc1
// it return name asp1
// it return name asp2
// it return name asprintf
// it return name asc
// it return name asprintf
// it return name asc
// it return name asp1
// it return name asp2
// it return name asfunc2
// it return name asp1
// it return name asp1
// it return name asfive
// it return name asmain
// it return name asa
// it return name asb
// it return name asc
// it return name asd
// it return name ase
// it return name asf
// it return name asfv
// it return name asfive
// it return name asprintf
// it return name asc
// it return name asb
// it return name asi
// it return name asprintf
// it return name asi
// it return name asi
// it return name asi
// it return name asprintf
// it return name asprintf
// it return name asc
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string
auto c = "global";
auto q_ = 555;
auto func1(auto , auto );
auto func2(auto p1);
auto func1(auto p1, auto p2){
printf("glboal c is %d\n", c);
auto c = 1;
printf("Now c is %d\n", c);
return (p1 + p2);
}
auto func2(auto p1){
return (p1 * 10);
}
auto five(){
return (5);
}
auto global2 = 5;
auto main(){
auto a ,b ,c ,d ,W = 5 ,e ,f ,g ,E = 7 ,fv;
a = 5;
b = 2.5;
c = 1;
d = "hello";
e = true;
f = 'c';
fv = five();
printf("%d\n", c);
if ((b > 1.0)) {
auto c = 1.7;
auto i = 0;
while (i < 10) {
printf("%d ", i);
i = i + 1;
}
printf("\n");
}
printf("c is %d\n", c);
return (0);
}
// scope{0}, [c], (32)
// scope{0}, [global2], (30)
// scope{0}, [q_], (30)
// scope{1}, [c], (30)
// scope{4}, [E], (30)
// scope{4}, [W], (30)
// scope{5}, [c], (31)
// scope{5}, [i], (30)
