.extern result
.globl _start
_start:
	la    t0, __mem   # Load base address into t0
	la    t1, __stack # Load stack offset into t1
	#addi a0, a0, 0x1  # Add one to a0, which contains the heartID in spike
	#mul   t1, t1, a0 # Multiply the stack offset with a0 so that each thread has its own stack
	add   sp, t0, t1  # Add the memory base and the stack offset and set it as the stack pointer.
	call  main        # Call the main function

print_res:
	/* Copy return value to be sent via UART */
	la	t0, result
	lb	t0, 0(t0)
	li	a0, 0x40000000

	/* Bitbanged UART loop */
	addi	t0, t0, 0x030
	ori	t0, t0, 0x100
	slli	t0, t0, 1
1:	sb	t0, 0(a0)
	srli	t0, t0, 1

	/*
	 * Adding delay nops to achieve an approximate
	 * baud rate of 57600 at 16MHz
	*/
	nop
	nop
	bnez	t0, 1b

	/* Writing anything to HALT_ADDR will exit simulation */
halt:	li	t0, 0x90000000
	sw	zero, 0(t0)
	/*
	 * Loop to prevent PC from keep reading memory in case
	 * we run on real HW and not in simulation
	*/
	j	halt

