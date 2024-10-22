Btree_ubt_1:Btree_ubt_1.o Btree_ubt_0.o
	gcc  Btree_ubt_1.o Btree_ubt_0.o -o Btree_ubt_1

Btree_ubt_1.o: Btree_ubt_0.h

Btree_ubt_0.o:Btree_ubt_0.c Btree_ubt_0.h

Btree_ubt_2:Btree_ubt_2.o Btree_ubt_0.o
	gcc  Btree_ubt_2.o Btree_ubt_0.o -o Btree_ubt_2

Btree_ubt_2.o: Btree_ubt_0.h

stack_by_array.o:stack_by_array.h
	gcc -g -c stack_by_array.c 

Btree_ubt_4.o:stack_by_array.h

Btree_ubt_4:stack_by_array.o Btree_ubt_4.o
	gcc -g stack_by_array.o Btree_ubt_4.o -o Btree_ubt_4 -lm

test.o:stack_by_array.h test.c
	gcc -g test.c stack_by_array.h  -c test.o

test:test.o stack_by_array.o
	gcc -g test.o stack_by_array.o -o  test -lm
