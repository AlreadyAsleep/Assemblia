save_write_len equ 4096

save_file byte "../player.save", 0
save_write_buffer byte save_write_len dup (?), 0
;// first 128 bytes are for character
;// remaining bytes are for inventory




_test_save macro
	Local L	
	pushad
	mov esi, offset save_write_buffer
	mov edi, 0
	mov ecx, save_write_len
	mov eax, 060h
while$L:	
	mov [esi][edi], al
	inc edi
	loop while$L

	invoke save_character, addr save_write_buffer, addr save_file
	popad
endm	

_save_char macro
	Local L
	pushad
	
	_write_char_to_buffer ;// found in character.inc
	write_inv_to_buffer	  ;// found in inventory.inc

	invoke save_character, addr save_write_buffer, addr save_file ;//  found in save.cpp

	popad
endm

_load_from_buffer macro
	Local L
	;//load from file into buffer

	invoke load_character, addr save_write_buffer, addr save_file ;// found in save.cpp

	;//write to character and then write to inventory
	_load_char_from_buffer
	load_inv_from_buffer
endm

   