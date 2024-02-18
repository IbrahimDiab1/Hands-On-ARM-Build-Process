ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx) : ORIGIN = 0x08000000    ,LENGTH = 64k	 
	SRAM(rwx) : ORIGIN = 0x20000000    ,LENGTH = 20k 
}

SECTIONS
{

	.isr_vector :
	{
		*(.isr_vector)
	}>FLASH
	
	.text :
	{
		. = ALIGN(4) ;
		_stext = . ;
		*(.text)	
		. = ALIGN(4) ;			
		_etext = . ;
		
	}>FLASH
	
	.rodata :
	{
		. = ALIGN(4) ;
		_srodata = . ;		
		*(.rodata)
		. = ALIGN(4) ;		
		_erodata = . ;
		
	}>FLASH

	.data :
	{
		. = ALIGN(4) ;
		_sdata = . ;		
		*(.data)
		. = ALIGN(4) ;		
		_edata = . ;	
		
	}>SRAM AT> FLASH
	
	.bss :
	{
		. = ALIGN(4) ;
		_sbss = . ;		
		*(.bss)
		. = ALIGN(4) ;		
		_ebss = . ;
		
	}>SRAM
}