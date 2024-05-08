; NAME : PRATIK KUMAR MUDULI
; REGD. NO.: 2241013372

MOV AX,0000H
MOV BX,[1000H]
MOV DX,[1002H]
MOV CX,0000H

BACK: ADD AX,BX  
      JNC NEXT     ; JUMP IF NO CARRY TO LABEL "NEXT"
      INC CX     ; IF CARRY THEN INCREMENT THE CARRY REGISTER  
      
NEXT: DEC DX     ; DECREMENT THE COUNTER BY 1
      JNZ BACK     ; IF COUNTER != 0, JUMP TO LABEL "BACK"
      
      MOV [1004H],AX  ; STORES THE RESULT
      MOV [1006H],CX  ; STORES THE CARRY
      HLT