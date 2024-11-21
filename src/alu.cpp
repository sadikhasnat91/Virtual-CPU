#include <iostream>
using namespace std;

// ALU (Arithmetic Logic Unit)
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
            default: 
                cout << "Invalid operation" << endl;
                return 0;
        }
    }
};

// General-Purpose Registers
class Registers {
private:
    int reg[4]; // Array of 4 registers
public:
    Registers() {
        for (int i = 0; i < 4; i++) reg[i] = 0;
    }

    void insert(int index, int value) {
        if (index >= 0 && index < 4) 
            reg[index] = value;
        else 
            cout << "Invalid register number" << endl;
    }

    int read(int index) {
        if (index >= 0 && index < 4) 
            return reg[index];
        else {
            cout << "Invalid register number" << endl;
            return 0;
        }
    }
};

// Program Counter (PC)
class ProgramCounter {
private:
    int pc;

    ProgramCounter() : pc(0) 
    {}

    void increment() 
    {
         pc++; 
    }
    void set(int value) 
    { 
        pc = value; 
    }
    int get() 
    { 
        return pc; 
    }
};

// Instruction Register (IR)
class InstructionRegister {
private:
    int instruction;
public:
    InstructionRegister() : instruction(0) {}

    void load(int instr) 
    { 
        instruction = instr; 
    }
    int get() 
    { 
        return instruction; 
    }
};

// Main function demonstrating all components
int main() {
    ALU alu;
    Registers reg;
    ProgramCounter pc;
    InstructionRegister ir;

    // Set initial values in registers
    reg.insert(0, 10); // Register 0 = 10
    reg.insert(1, 20); // Register 1 = 20

    // Perform an addition using ALU
    int result = alu.performOperation(reg.read(0), reg.read(1), '+');
    cout << "ALU Result (10 + 20): " << result << endl;

    // Store result in Register 2
    reg.insert(2, result);
    cout << "Register 2 Value: " << reg.read(2) << endl;

    // // Program Counter (PC) and Instruction Register (IR) example
    // pc.set(100); // Start at instruction 100
    // ir.load(0xA1B2); // Load an instruction
    // cout << "PC: " << pc.get() << ", IR: " << ir.get() << endl;

    // Increment PC
    pc.increment();
    cout << "Next PC: " << pc.get() << endl;

    return 0;
}
