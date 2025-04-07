section .data
    title db "Sigmoid Result",0
    message db "Sigmoid(1976) = 1.0000",0

section .text
global _start
extern MessageBoxA
extern ExitProcess

_start:
    push 0
    push title
    push message
    push 0
    call [MessageBoxA]
    push 0
    call [ExitProcess]
