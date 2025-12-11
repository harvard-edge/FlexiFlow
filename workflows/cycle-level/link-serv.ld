/*
 * Here the stack starts at 8k
 */
__mem   = 0x00000000;
__stack = 0x00200000;

OUTPUT_ARCH("riscv")
ENTRY(_start)

SECTIONS
{
    . = __mem;
    .text : ALIGN(4) {
        *(.text)
    }

    .data : ALIGN(4) {
        *(.sbss)
        *(COMMON)
        *(.bss)
        *(.sdata)
        *(.rodata)
        *(.data*)
        *(.got*)
    }
}
