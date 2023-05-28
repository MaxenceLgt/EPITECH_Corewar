	.name "Rcule"
	.comment "Cmoa le plu phor"

	ld %2, r4

	loader:
		live %0
	    add r4, r4, r4
	    xor r4, %128, r7
	    zjmp %:attacker
	    fork %:attack_load
	    live %0
	    ld %0, r12
	    zjmp %:loader

	attack_load:
	    add r3, r4, r3
	    ld %0, r12
	    zjmp %:loader

	attacker:
	    st r1, 12
	    ldi %0, r3, r14

	jumper:
	    live %0
	    sti r14, %-700, r3
	    zjmp %-700
