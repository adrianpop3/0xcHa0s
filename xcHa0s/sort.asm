DATA VECTOR 10
DATA SPATIUGOL 14
DATA N
DATA I
DATA J
DATA MIN_ID
DATA TEMP

;void selectionSort(int arr[], int n)
;{
;    int i, j, min_idx;
; 
;    // One by one move boundary of unsorted subarray
;    for (i = 0; i < n-1; i++)
;    {
;        // Find the minimum element in unsorted array
;        min_idx = i;
;        for (j = i+1; j < n; j++)
;          if (arr[j] < arr[min_idx])
;            min_idx = j;
; 
;        // Swap the found minimum element with the first element
;           if(min_idx != i)
;            swap(&arr[min_idx], &arr[i]);
;    }
;}

MOV X 176
MOV Y 0
STOREB X VECTOR
MOV X 65
MOV Y 1
STOREB X VECTOR
MOV X 113
MOV Y 2
STOREB X VECTOR
MOV X 80
MOV Y 3
STOREB X VECTOR
MOV X 131
MOV Y 4
STOREB X VECTOR
MOV X 193
MOV Y 5
STOREB X VECTOR
MOV X 118
MOV Y 6
STOREB X VECTOR
MOV X 64
MOV Y 7
STOREB X VECTOR
MOV X 72
MOV Y 8
STOREB X VECTOR
MOV X 189
MOV Y 9
STOREB X VECTOR

MOV X 10
STORE X N

JMP SELECTSORT

LOOP4EVER:
    BRA LOOP4EVER

SELECTSORT:
	MOV X 0
	;I=0
	STORE X I
	SORTFOR:
		LOAD Y N
		DEC Y
		LOAD X I
		;I<N-1
		CMP X Y
		BGE OUTSORTFOR
		
		STORE X MIN_ID
		INC X
		;J=I+1
		STORE X J
		SEARCHMIN:
			LOAD Y N
			LOAD X J
			;J<N
			CMP X Y
			BGE OUTSEARCHMIN
			
			;X=J
			;Y=VECTOR[X]
			LOADB Y VECTOR
			STORE Y TEMP
			
			LOAD X MIN_ID
			;Y=VECTOR[MIN_ID]
			LOADB Y VECTOR
			;X=VECTOR[X]
			LOAD X TEMP
			CMP X Y
			BGE NOTLESS
				LOAD X J
				STORE X MIN_ID
			NOTLESS:
			
			;J++
			LOAD X J
			INC X
			STORE X J
			BRA SEARCHMIN
		OUTSEARCHMIN:
		
		;swap
		LOAD X I
		;Y=VECTOR[I]
		LOADB Y VECTOR
		STORE Y TEMP
		
		LOAD X MIN_ID
		;Y=VECTOR[MIN_ID]
		LOADB Y VECTOR
		LOAD X I
		;VECTOR[I] = Y = VECTOR[MIN_ID]
		STOREB Y VECTOR
		
		LOAD X MIN_ID
		LOAD Y TEMP
		;VECTOR[MIN_ID] = Y = TEMP
		STOREB Y VECTOR
		
		;I++
		LOAD X I
		INC X
		STORE X I
		BRA SORTFOR
	OUTSORTFOR:
RET
