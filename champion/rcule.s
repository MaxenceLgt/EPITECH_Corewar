	.name "Rcule"
	.comment "Cmoa le plu phor"

	sti r1, %:live, %1
	and r1, %0, r1
	fork %:init_forward

	live:	live %1
			zjmp %:live
			fork %:attack


	p1:
			ld		%57672192,		r2
			ld		1 	,			r5
			ld		%318992387,		r3
			ld		%0,				r4	# carry = 1
	init_forward:
			live	%42
			fork	%:p1
			live	%42
			fork	%:attack
			live	%42
			fork	%:p1
			live	%42
			fork	%:attack
			live	%42



	attack:
		st		r2,				15
		st		r3,				-1
		live	%1337
		fork %:attack






