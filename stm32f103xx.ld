ENTRY(Reset_handler)

MEMORY
{

	FLASH(rx): ORIGIN = 0x08000000 , LENGTH = 64K
	SRAM(rwx): ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{

	.text : 
	{
			_stext = .;
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
			_etext = .;

	} > FLASH

	.data :
	{
			_sdata = .;
		*(.data)
		. = ALIGN(4);
			_edata = .;

	} > SRAM AT> FLASH

	.bss :
	{
			_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
			_ebss = .;

	} > SRAM


}

