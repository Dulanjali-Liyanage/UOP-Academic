	.file	"ex2.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
	cbi 42-32,2
	sbi 36-32,0
	lds r24,105
	ori r24,lo8(2)
	sts 105,r24
	lds r24,105
	andi r24,lo8(-2)
	sts 105,r24
/* #APP */
 ;  15 "ex2.c" 1
	sei
 ;  0 "" 2
/* #NOAPP */
	sbi 61-32,0
.L2:
	rjmp .L2
	.size	main, .-main
.global	__vector_1
	.type	__vector_1, @function
__vector_1:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
	push r25
/* prologue: Signal */
/* frame size = 0 */
	in r24,37-32
	ldi r25,lo8(1)
	eor r24,r25
	out 37-32,r24
/* epilogue start */
	pop r25
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_1, .-__vector_1
