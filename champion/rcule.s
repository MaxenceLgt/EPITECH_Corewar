	.name "Rcule"
	.comment "Cmoa le plu phor"

	sti r1, %:live, %1
	and r1, %0, r1
	fork %:init_forward

	live:	live %1
			zjmp %:live
			fork %:attack


	loader:
			ld		0,		r2
			ld		0 	,			r5
			ld		%318992387,		r3
			ld		%0,				r4
			ld      1, 			r6
			ld      1, 			r7
	init_forward:
			live	%42
			fork	%:loader
			live	%42
			fork	%:attack
			live	%42

	direction:
		add  r6, r7, r6
		zjmp %:init_forward

	attack:
		st		r2,				r6
		st		r3,				-1
		live	%1337
		zjmp %:direction






