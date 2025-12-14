;---------------------------------------------------------
; Program: Fibonacci Sequence (first 10 numbers)
; Architecture: AMD EPYC (x86_64)
; Platform: Linux (NASM syntax)
; Compatible with: OneCompiler Assembly (NASM mode)
;---------------------------------------------------------

section .data
    msg db "Fibonacci sequence (first 10 numbers):", 10, 0
    fmt db "%d ", 0
    newline db 10, 0

section .bss
    a resd 1
    b resd 1
    temp resd 1
    count resd 1

section .text
    global main
    extern printf

main:
    ; Print header
    lea rdi, [rel msg]
    xor eax, eax
    call printf

    ; Initialize values
    mov dword [a], 0      ; a = 0
    mov dword [b], 1      ; b = 1
    mov dword [count], 10 ; print 10 numbers

print_loop:
    ; Print current Fibonacci number (a)
    mov eax, [a]          ; move a into eax
    mov esi, eax          ; 2nd argument = a
    lea rdi, [rel fmt]    ; 1st argument = "%d "
    xor eax, eax
    call printf

    ; temp = a + b
    mov eax, [a]
    add eax, [b]
    mov [temp], eax

    ; a = b
    mov eax, [b]
    mov [a], eax

    ; b = temp
    mov eax, [temp]
    mov [b], eax

    ; Decrement and loop
    dec dword [count]
    cmp dword [count], 0
    jne print_loop

    ; Print newline
    lea rdi, [rel newline]
    xor eax, eax
    call printf

    ; Exit
    mov eax, 0
    ret
