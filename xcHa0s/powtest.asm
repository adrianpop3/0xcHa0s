DATA FIRSTNUM
DATA SECONDNUM

MOV X 5
MOV ACC X

MOV Y 10

;6D 94C0
POW Y
STORE X FIRSTNUM
MOV X ACC
STORE X SECONDNUM
LOOP4EVER:
        BRA LOOP4EVER