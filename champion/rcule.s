.name "Rcule"
.comment "Cmoa le plu phor"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		ld 1 r3
		fork %:attack
		zjmp %:live

attack:
	add r2, r2, r2
	st r3, r2
	zjmp %:live





