; NAME : PRATIK KUMAR MUDULI
; REGD NO : 2241013372

;MOV AX,5000H
;MOV DS,AX
; ADDITION
MOV AX,0009H
MOV CX,AX
MOV BX,0002H
ADD AX,BX
MOV [5000H],AX

; SUBTRATION
MOV AX,CX
SUB AX,BX
MOV [5002H],AX

; MULTIPICATION
MOV AX,CX
MUL BX
MOV [5004H],AX  ; LOWER BIT
MOV [5006H],DX  ; HIGHER BIT

; DIVITION
MOV DX,0000H
MOV AX,CX
DIV BX
MOV [5008H],AX  ; LOWER BIT
MOV [500AH],DX  ; HIGHER BIT
HLT