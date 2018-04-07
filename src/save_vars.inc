save_write_len equ 1024

save_file byte "../player.save", 0
save_write_buffer byte save_write_len dup (?), 0
;// first 128 bytes are for character



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

	invoke save_character, addr save_write_buffer, addr save_file ;//  found in save.cpp

	popad
endm

   