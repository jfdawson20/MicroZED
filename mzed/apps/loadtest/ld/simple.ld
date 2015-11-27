/* memmap */
MEMORY
{
    ram : ORIGIN = 0x00200000, LENGTH = 0x000F4240
}

SECTIONS
{
    .text    : { *(.text*) } > ram
    .rodata  : { *(.rodata*) } > ram
    .data    : { *(.data*) } > ram
    .bss     : { *(.bss*) } > ram
}
