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
		*(.isr_vector)
		*(.text)
		*(.rodata)
		*(.bss)
		end_of_text = .;

	} > FLASH

	.data :
	{
		start_of_data = 0x20000000;
		*(.data)

	} > SRAM AT> FLASH


}

