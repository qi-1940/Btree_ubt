Btree_ubt_1:Btree_ubt_1.o Btree_ubt_0.o
	gcc  Btree_ubt_1 Btree_ubt_1.o Btree_ubt_0.o -o Btree_ubt_1
Btree_ubt_1.o:Btree_ubt_1.c Btree_ubt_0.h
	gcc  Btree_ubt_1.c -c Btree_ubt_1.o
Btree_ubt_0.o:Btree_ubt_0.c Btree_ubt_0.h
	gcc  Btree_ubt_0.c -c Btree_ubt_0.o
Btree_ubt_2:Btree_ubt_2.o Btree_ubt_0.o
	gcc  Btree_ubt_2.o Btree_ubt_0.o -o Btree_ubt_2
Btree_ubt_2.o:Btree_ubt_2.c Btree_ubt_0.h
	gcc  Btree_ubt_2.c -c Btree_ubt_2.o