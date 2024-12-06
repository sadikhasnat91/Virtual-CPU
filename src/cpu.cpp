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
public:
    ProgramCounter() : pc(0) {}

    void increment() { pc++; }
    void set(int value) { pc = value; }
    int get() { return pc; }
};

// Instruction Register (IR)
class InstructionRegister {
private:
    int instruction;
public:
    InstructionRegister() : instruction(0) {}

    void load(int instr) { instruction = instr; }
    int get() { return instruction; }
};

// CPU Class: Handles Fetch-Decode-Execute Cycle
class CPU {
private:
    ALU alu;
    Registers reg;
    ProgramCounter pc;
    InstructionRegister ir;
    int memory[256]; // Fixed-size memory for instructions and data

public:
    CPU() {
        for (int i = 0; i < 256; i++) memory[i] = 0; // Initialize memory with 0
    }

    // Load program into memory
    void loadProgram(const int* program, int size) {
        for (int i = 0; i < size; i++) {
            memory[i] = program[i];
        }
    }

    // Fetch instruction from memory
    void fetch() {
        int address = pc.get();
        ir.load(memory[address]);
        pc.increment();
        cout << "Fetch: Loaded instruction 0x" << hex << memory[address] << " from address " << address << dec << endl;
    }

    // Decode and execute instruction
    void decodeAndExecute() {
        int instruction = ir.get();

        // Instruction Format: [OPCODE(8 bits)][REG1(4 bits)][REG2(4 bits)][REG3(4 bits)]
        int opcode = (instruction >> 24) & 0xFF; // Extract opcode
        int reg1 = (instruction >> 16) & 0x0F;   // Extract first register
        int reg2 = (instruction >> 8) & 0x0F;    // Extract second register
        int reg3 = instruction & 0x0F;           // Extract third register

        cout << "Decode: Opcode=" << opcode << ", Operands R" << reg1 << ", R" << reg2 << ", R" << reg3 << endl;

        switch (opcode) {
            case 1: // ADD: reg1 = reg2 + reg3
                cout << "Execute: R" << reg1 << " = R" << reg2 << " + R" << reg3 << endl;
                reg.insert(reg1, alu.performOperation(reg.read(reg2), reg.read(reg3), '+'));
                break;
            case 2: // SUB: reg1 = reg2 - reg3
                cout << "Execute: R" << reg1 << " = R" << reg2 << " - R" << reg3 << endl;
                reg.insert(reg1, alu.performOperation(reg.read(reg2), reg.read(reg3), '-'));
                break;
            case 3: // MUL: reg1 = reg2 * reg3
                cout << "Execute: R" << reg1 << " = R" << reg2 << " * R" << reg3 << endl;
                reg.insert(reg1, alu.performOperation(reg.read(reg2), reg.read(reg3), '*'));
                break;
            case 4: // DIV: reg1 = reg2 / reg3
                cout << "Execute: R" << reg1 << " = R" << reg2 << " / R" << reg3 << endl;
                reg.insert(reg1, alu.performOperation(reg.read(reg2), reg.read(reg3), '/'));
                break;
            case 5: // LOAD: reg1 = Immediate Value (stored in reg2)
                cout << "Execute: R" << reg1 << " = " << reg2 << endl;
                reg.insert(reg1, reg2);
                break;
            default:
                cout << "Invalid opcode: " << opcode << endl;
                break;
        }
    }

    // Run the CPU
    void run() {
        cout << "Starting CPU Execution..." << endl;
        while (pc.get() < 256 && memory[pc.get()] != 0) { // 0 marks end of program
            fetch();
            decodeAndExecute();
            displayRegisters();
        }
        cout << "CPU Execution Complete." << endl;
    }

    // Display register values
    void displayRegisters() {
        cout << "Registers: ";
        for (int i = 0; i < 4; i++) {
            cout << "R" << i << "=" << reg.read(i) << " ";
        }
        cout << endl;
    }

    // Display memory contents
    void displayMemory() {
        cout << "Memory: ";
        for (int i = 0; i < 256; i++) {
            if (memory[i] != 0) {
                cout << "[" << i << "]: 0x" << hex << memory[i] << dec << " ";
            }
        }
        cout << endl;
    }
};

// Main Function: Test Fetch-Decode-Execute Cycle
int main() {
    CPU cpu;

    // Sample Program (encoded instructions)
    // Format: [OPCODE(8 bits)][REG1(4 bits)][REG2(4 bits)][REG3(4 bits)]
    int program[] = {
        (5 << 24) | (1 << 16) | (10 << 8) | (0), // LOAD R1 = 10
        (5 << 24) | (2 << 16) | (20 << 8) | (0), // LOAD R2 = 20
        (1 << 24) | (0 << 16) | (1 << 8) | (2),  // ADD R0 = R1 + R2
        (2 << 24) | (3 << 16) | (0 << 8) | (1),  // SUB R3 = R0 - R1
        (0) // End program
    };

    // Load program
    cpu.loadProgram(program, sizeof(program) / sizeof(program[0]));

    // Display initial memory
    cpu.displayMemory();

    // Run CPU
    cpu.run();

    // Display final memory state
    cpu.displayMemory();

    return 0;
}
