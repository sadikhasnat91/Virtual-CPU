
# Building the ALU, General-Purpose Registers, Program Counter, and Instruction Register

## Overview
This guide covers implementing a simple ALU (Arithmetic Logic Unit), general-purpose registers, a program counter, and an instruction register for a basic virtual CPU. The implementation is done in C++.

---

## 1. Arithmetic Logic Unit (ALU)
The ALU performs arithmetic and logical operations. It takes two inputs (`A` and `B`) and an operation code (`op`) to produce an output.

### Code for ALU:
```cpp
#include <iostream>
using namespace std;

class ALU {
public:
    int performOperation(int A, int B, char op) {
        switch (op) {
            case '+': return A + B;
            case '-': return A - B;
            case '&': return A & B;
            case '|': return A | B;
            case '^': return A ^ B;
            case '*': return A * B;
            case '/': return (B != 0) ? A / B : 0; // Handle division by zero
            default: cout << "Invalid operation" << endl; return 0;
        }
    }
};
```

---

## 2. General-Purpose Registers
The CPU uses general-purpose registers to store temporary data. For simplicity, we will implement 4 registers.

### Code for Registers:
```cpp
class Registers {
private:
    int reg[4]; // Array of 4 registers
public:
    Registers() {
        for (int i = 0; i < 4; i++) reg[i] = 0;
    }

    void write(int regNum, int value) {
        if (regNum >= 0 && regNum < 4) reg[regNum] = value;
        else cout << "Invalid register number" << endl;
    }

    int read(int regNum) {
        if (regNum >= 0 && regNum < 4) return reg[regNum];
        else {
            cout << "Invalid register number" << endl;
            return 0;
        }
    }
};
```

---

## 3. Program Counter (PC) and Instruction Register (IR)
The program counter keeps track of the address of the next instruction, and the instruction register holds the currently executing instruction.

### Code for PC and IR:
```cpp
class ProgramCounter {
private:
    int pc;
public:
    ProgramCounter() : pc(0) {}

    void increment() { pc++; }
    void set(int value) { pc = value; }
    int get() { return pc; }
};

class InstructionRegister {
private:
    int instruction;
public:
    InstructionRegister() : instruction(0) {}

    void load(int instr) { instruction = instr; }
    int get() { return instruction; }
};
```

---

## 4. Main Function
Combining all components into a simple simulation.

### Full Example:
```cpp
int main() {
    ALU alu;
    Registers reg;
    ProgramCounter pc;
    InstructionRegister ir;

    // Set initial values
    reg.write(0, 10); // Register 0 = 10
    reg.write(1, 20); // Register 1 = 20

    // Perform an addition using ALU
    int result = alu.performOperation(reg.read(0), reg.read(1), '+');
    cout << "ALU Result (10 + 20): " << result << endl;

    // Store result in Register 2
    reg.write(2, result);
    cout << "Register 2 Value: " << reg.read(2) << endl;

    // PC and IR example
    pc.set(100); // Start at instruction 100
    ir.load(0xA1B2); // Load an instruction
    cout << "PC: " << pc.get() << ", IR: " << ir.get() << endl;

    // Increment PC
    pc.increment();
    cout << "Next PC: " << pc.get() << endl;

    return 0;
}
```

---

## Summary
1. **ALU**: Handles basic arithmetic and logical operations.
2. **Registers**: Provides temporary storage for data.
3. **Program Counter (PC)**: Tracks the instruction sequence.
4. **Instruction Register (IR)**: Holds the current instruction.

This modular approach can be extended to build a more complex CPU.
