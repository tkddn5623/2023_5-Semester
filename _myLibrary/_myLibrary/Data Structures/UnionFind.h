#ifndef UNION_FIND_H
#define UNION_FIND_H
int* UF_init(int maxsize);
int UF_find(int* roots, int key);
void UF_union(int* roots, int A, int B);
#endif