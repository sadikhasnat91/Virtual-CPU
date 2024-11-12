
# Virtual CPU Instruction Set

This document defines the basic instructions for the virtual CPU's Instruction Set Architecture (ISA).

## Basic Instructions

### 1. ADD (Addition)
- **Mnemonic**: `ADD`
- **Description**: Adds the contents of two registers and stores the result in the first register.
- **Format**: `ADD R1, R2`
- **Operation**: `R1 = R1 + R2`

### 2. SUB (Subtraction)
- **Mnemonic**: `SUB`
- **Description**: Subtracts the contents of the second register from the first register and stores the result in the first register.
- **Format**: `SUB R1, R2`
- **Operation**: `R1 = R1 - R2`

### 3. LOAD (Load from Memory)
- **Mnemonic**: `LOAD`
- **Description**: Loads data from a specified memory address into a register.
- **Format**: `LOAD R1, address`
- **Operation**: `R1 = Memory[address]`

### 4. STORE (Store to Memory)
- **Mnemonic**: `STORE`
- **Description**: Stores the data from a register into a specified memory address.
- **Format**: `STORE R1, address`
- **Operation**: `Memory[address] = R1`

### 5. MOV (Move Data)
- **Mnemonic**: `MOV`
- **Description**: Moves data from one register to another.
- **Format**: `MOV R1, R2`
- **Operation**: `R1 = R2`
