#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#define string std::string

auto c = "global";
auto q_ = 555;
auto func1(auto p1, auto p2){
    printf("glboal c is %d\n", c);
    auto c = 1;
    printf("Now c is %d\n", c);
    return p1 + p2;
}
auto func2(auto p1){
    return p1 * 10;
}
auto main() {
    auto a, b, c, d, e, f, g;
    a = 5;
    b = 2.5;
    c = 1;
    d = "hello";
    e = true;
    f = 'c';
    // g = (char)65;
    // auto r = func1(a, b);
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
    return 0; 
}