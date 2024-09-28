Btree_ubt_1:Btree_ubt_1.o Btree_ubt_0.o
	gcc  Btree_ubt_1.o Btree_ubt_0.o -o Btree_ubt_1

Btree_ubt_1.o: Btree_ubt_0.h

Btree_ubt_0.o:Btree_ubt_0.c Btree_ubt_0.h

Btree_ubt_2:Btree_ubt_2.o Btree_ubt_0.o
	gcc  Btree_ubt_2.o Btree_ubt_0.o -o Btree_ubt_2

Btree_ubt_2.o: Btree_ubt_0.h

stack_by_array.o:stack_by_array.h

Btree_ubt_4.o:stack_by_array.h

Btree_ubt_4:stack_by_array.o Btree_ubt_4.o
	gcc stack_by_array.o Btree_ubt_4.o -o Btree_ubt_4
