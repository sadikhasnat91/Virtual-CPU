<<<<<<< HEAD

# Fetch, Decode, Execute Tracing, and Test Program Execution

## Overview

This document describes the process and output of the virtual CPU's Fetch-Decode-Execute cycle, along with the test program execution. The outputs are detailed to trace each step of the CPU's execution process, making it easier to debug and understand the functionality.

---

## Fetch, Decode, Execute Tracing

### Process
1. **Fetch**: The Program Counter (PC) retrieves the instruction from memory and loads it into the Instruction Register (IR).  
   - Output: Displays the instruction fetched and its memory address.

2. **Decode**: The CPU decodes the instruction by extracting its opcode and operand registers.  
   - Output: Displays the opcode and operands involved.

3. **Execute**: The CPU performs the operation using the ALU and updates the destination register.  
   - Output: Shows the operation performed and the result.

### Sample Output
```
Starting CPU Execution...
Fetch: Loaded instruction 0x5010000 from address 0
Decode: Opcode=5, Operands R1, 10, 0
Execute: R1 = 10
Registers: R0=0 R1=10 R2=0 R3=0 

Fetch: Loaded instruction 0x5020000 from address 1
Decode: Opcode=5, Operands R2, 20, 0
Execute: R2 = 20
Registers: R0=0 R1=10 R2=20 R3=0 

Fetch: Loaded instruction 0x10012 from address 2
Decode: Opcode=1, Operands R0, R1, R2
Execute: R0 = R1 + R2
Registers: R0=30 R1=10 R2=20 R3=0 

Fetch: Loaded instruction 0x20013 from address 3
Decode: Opcode=2, Operands R3, R0, R1
Execute: R3 = R0 - R1
Registers: R0=30 R1=10 R2=20 R3=20 
```

---

## Test Program Execution

### Program Description
The test program demonstrates the use of LOAD, ADD, and SUB operations, ensuring that the Fetch-Decode-Execute cycle works as expected.

### Instructions (Encoded)
- **Instruction Format**: [OPCODE (8 bits)][REG1 (4 bits)][REG2 (4 bits)][REG3 (4 bits)]
- Program:
    - `(5 << 24) | (1 << 16) | (10 << 8) | (0)` → Load value `10` into Register 1 (R1).
    - `(5 << 24) | (2 << 16) | (20 << 8) | (0)` → Load value `20` into Register 2 (R2).
    - `(1 << 24) | (0 << 16) | (1 << 8) | (2)` → Add R1 and R2, store result in R0.
    - `(2 << 24) | (3 << 16) | (0 << 8) | (1)` → Subtract R1 from R0, store result in R3.

### Expected Register Updates
- **After Instruction 1**: R1 = 10
- **After Instruction 2**: R2 = 20
- **After Instruction 3**: R0 = 30 (R1 + R2)
- **After Instruction 4**: R3 = 20 (R0 - R1)

---

## Memory State

### Initial Memory
```
[0]: 0x5010000
[1]: 0x5020000
[2]: 0x10012
[3]: 0x20013
[4]: 0x0 (End of program)
```

### Final Memory
Memory remains unchanged since instructions modify only the registers.

---

## Conclusion

This detailed trace of the Fetch-Decode-Execute cycle demonstrates the proper functioning of the virtual CPU. The test program successfully executes basic arithmetic operations, with all changes accurately reflected in the registers.
=======

# Fetch, Decode, Execute Tracing, and Test Program Execution

## Overview

This document describes the process and output of the virtual CPU's Fetch-Decode-Execute cycle, along with the test program execution. The outputs are detailed to trace each step of the CPU's execution process, making it easier to debug and understand the functionality.

---

## Fetch, Decode, Execute Tracing

### Process
1. **Fetch**: The Program Counter (PC) retrieves the instruction from memory and loads it into the Instruction Register (IR).  
   - Output: Displays the instruction fetched and its memory address.

2. **Decode**: The CPU decodes the instruction by extracting its opcode and operand registers.  
   - Output: Displays the opcode and operands involved.

3. **Execute**: The CPU performs the operation using the ALU and updates the destination register.  
   - Output: Shows the operation performed and the result.

### Sample Output
```
Starting CPU Execution...
Fetch: Loaded instruction 0x5010000 from address 0
Decode: Opcode=5, Operands R1, 10, 0
Execute: R1 = 10
Registers: R0=0 R1=10 R2=0 R3=0 

Fetch: Loaded instruction 0x5020000 from address 1
Decode: Opcode=5, Operands R2, 20, 0
Execute: R2 = 20
Registers: R0=0 R1=10 R2=20 R3=0 

Fetch: Loaded instruction 0x10012 from address 2
Decode: Opcode=1, Operands R0, R1, R2
Execute: R0 = R1 + R2
Registers: R0=30 R1=10 R2=20 R3=0 

Fetch: Loaded instruction 0x20013 from address 3
Decode: Opcode=2, Operands R3, R0, R1
Execute: R3 = R0 - R1
Registers: R0=30 R1=10 R2=20 R3=20 
```

---

## Test Program Execution

### Program Description
The test program demonstrates the use of LOAD, ADD, and SUB operations, ensuring that the Fetch-Decode-Execute cycle works as expected.

### Instructions (Encoded)
- **Instruction Format**: [OPCODE (8 bits)][REG1 (4 bits)][REG2 (4 bits)][REG3 (4 bits)]
- Program:
    - `(5 << 24) | (1 << 16) | (10 << 8) | (0)` → Load value `10` into Register 1 (R1).
    - `(5 << 24) | (2 << 16) | (20 << 8) | (0)` → Load value `20` into Register 2 (R2).
    - `(1 << 24) | (0 << 16) | (1 << 8) | (2)` → Add R1 and R2, store result in R0.
    - `(2 << 24) | (3 << 16) | (0 << 8) | (1)` → Subtract R1 from R0, store result in R3.

### Expected Register Updates
- **After Instruction 1**: R1 = 10
- **After Instruction 2**: R2 = 20
- **After Instruction 3**: R0 = 30 (R1 + R2)
- **After Instruction 4**: R3 = 20 (R0 - R1)

---

## Memory State

### Initial Memory
```
[0]: 0x5010000
[1]: 0x5020000
[2]: 0x10012
[3]: 0x20013
[4]: 0x0 (End of program)
```

### Final Memory
Memory remains unchanged since instructions modify only the registers.

---

## Conclusion

This detailed trace of the Fetch-Decode-Execute cycle demonstrates the proper functioning of the virtual CPU. The test program successfully executes basic arithmetic operations, with all changes accurately reflected in the registers.
>>>>>>> a4f1f297e249b202a821b22b82114e6dd706cf11
