.586
.MODEL FLAT,STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
MB_OK	 EQU 0
dw1      dword 2d
dw2      dword 4d
STR1	 DB	   "Сложение двух чисел", 0
STR2	 DB	   "Результат сложения: ", 0
HW	     DD ?

.CODE

main PROC
START:
		MOV eax, dw1
		MOV ebx, dw2
		ADD eax, ebx
		ADD al, '0'
		MOV ebx, lengthof STR2 - 1
		MOV [STR2 + ebx], al
		PUSH MB_OK
		PUSH OFFSET STR1
		PUSH OFFSET STR2
		PUSH HW
		CALL MessageBoxA

			push  -1
	CALL ExitProcess
main ENDP

end main