PRINTCHAR MACRO char
    push ax
    push dx

    mov ah, 02h
    mov dl, char
    int 21h

    pop dx
    pop ax
ENDM

; 換行
NEWLINE MACRO
    PRINTCHAR 13
    PRINTCHAR 10
ENDM

; DOS 印字串
PRINTSTR MACRO msg
    push dx
    push ax

    mov dx, OFFSET msg
    mov ah, 09h
    int 21h

    pop ax
    pop dx
ENDM

; 印字串 + 換行
PRINTLN MACRO msg
    PRINTSTR msg
    NEWLINE
ENDM

; 清螢幕 + 游標歸位
CLS MACRO
    push ax
    push dx
    push cx
    push bx

    mov ax, 0600h
    mov bh, 07h
    mov cx, 0
    mov dx, 184fh
    int 10h
    mov ah, 02h
    mov bh, 0
    mov dh, 0
    mov dl, 0
    int 10h

    pop bx
    pop cx
    pop dx
    pop ax
ENDM

; BIOS 彩色印字元
PRINT_COLOR MACRO char, color

    push ax
    push cx
    push bx
    push dx

    mov al, char
    mov bl, color
    mov ah, 09h
    mov bh, 0
    mov cx, 1
    int 10h

    mov ah, 03h
    int 10h
    mov ah, 02h
    inc dl
    int 10h

    pop dx
    pop bx
    pop cx
    pop ax
ENDM