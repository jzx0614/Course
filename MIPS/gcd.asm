INCLUDE	Irvine32.inc
.data	
	value1 SDWORD ?
	value2 SDWORD ?
	temp   SDWORD ?
	
.code
	main PROC
		call ReadInt
		mov value1,eax
		call ReadInt
		mov value2,eax
		call GCD
		exit
	main ENDP
	GCD PROC
		mov eax,value1
		call abs
		mov value1,eax
		mov eax,value2
		call abs
		mov value2,eax
	L1:	
		mov eax,value1
		mov ebx,value2
		mov edx,0
		idiv   ebx
		mov ecx,edx
		mov eax,value2
		mov value1,eax
		mov value2,ecx
		cmp value2,0
		jg     L1
		mov eax,value2
		call WriteInt
		ret
	GCD ENDP
	abs PROC
		cmp eax,0
		jge   L2
		mov temp,eax
		mov eax,0
		sub   eax,temp
	L2:	ret
	abs ENDP
	END main