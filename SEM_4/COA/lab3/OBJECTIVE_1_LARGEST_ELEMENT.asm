; NAME : PRATIK KUMAR MUDULI
; REGD. NO.: 2241013372

.DATA
    COUNT DB 04H
    VALUE DB 09H,10H,05H,03H
    LARGESTNUMBER DB 0
.CODE
MAIN PROC
    
    ; LARGEST ELEMENT IN THE ARRAY
    MOV AX,DATA
    MOV DS,AX
    MOV CL,COUNT
    LEA SI,VALUE
    
    MOV AL,[SI]
    DEC CL
    INC SI
    
    L1: CMP AL,[SI]
        JNC L2
        MOV AL,[SI]
        
    L2: INC SI
        DEC CL
        JNZ L1
    
    MOV LARGESTNUMBER,AL    

END MAIN