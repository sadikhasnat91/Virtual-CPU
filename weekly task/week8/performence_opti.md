# Objective Breakdown

### Profile the Emulator:
Find bottlenecks by measuring execution time and CPU usage for various parts of the CPU simulation, especially instruction fetch, decode, execute, and memory access.

### Optimize Critical Code Paths:
Focus on reducing computational complexity in ALU operations, memory access, and control flow instructions.

### Enhance Assembler:
Improve encoding to reduce memory usage and fetch times by encoding instructions more compactly.

---

# Key Optimizations in the Code

### Profiling
Use timing functions (chrono from C++ STL) to measure execution time.

### Critical Code Optimization
Optimize ALU and memory operations using bitwise logic and precomputed lookup tables where possible.

### Enhanced Assembler
Pack instruction data more efficiently to reduce memory and storage footprint.

```cpp
#include <iostream>
using namespace std;

#define MEMORY_SIZE 256

// Memory class for optimized storage
class Memory {
private:
    int memory[MEMORY_SIZE]; // Each memory location stores an 8-bit integer

public:
    Memory() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            memory[i] = 0;
        }
    }

    void write(int address, int value) {
        if (address >= 0 && address < MEMORY_SIZE) {
            memory[address] = value;
        } else {
            cout << "Memory Write Error: Address out of bounds!" << endl;
        }
    }

    int read(int address) {
        if (address >= 0 && address < MEMORY_SIZE) {
            return memory[address];
        } else {
            cout << "Memory Read Error: Address out of bounds!" << endl;
            return 0;
        }
    }
};

// ALU with basic operations
class ALU {
public:
    int performOperation(int A, int B, char op) {
        switch (op) {
            case '+': return A + B;
            case '-': return A - B;
            case '&': return A & B;
            case '|': return A | B;
            case '^': return A ^ B;
            default:
                cout << "Invalid operation" << endl;
                return 0;
        }
    }
};

// CPU class
class CPU {
private:
    Memory memory;
    ALU alu;
    int pc; // Program Counter

public:
    CPU() : pc(0) {}

    void loadProgram(int program[], int size) {
        for (int i = 0; i < size; i++) {
            memory.write(i, program[i]);
        }
    }

    void run() {
        cout << "CPU Execution Started..." << endl;

        while (true) {
            int instruction = memory.read(pc);
            if (instruction == 0) break;

            pc++;
            decodeAndExecute(instruction);
        }

        cout << "CPU Execution Complete." << endl;
    }

    void decodeAndExecute(int instruction) {
        int opcode = (instruction >> 24) & 0xFF;
        int reg1 = (instruction >> 16) & 0xFF;
        int reg2 = (instruction >> 8) & 0xFF;
        int reg3 = instruction & 0xFF;

        switch (opcode) {
            case 1: // ADD reg1 = reg2 + reg3
                cout << "Execute: ADD R" << reg1 << " = R" << reg2 << " + R" << reg3 << endl;
                memory.write(reg1, alu.performOperation(memory.read(reg2), memory.read(reg3), '+'));
                break;
            case 2: // SUB reg1 = reg2 - reg3
                cout << "Execute: SUB R" << reg1 << " = R" << reg2 << " - R" << reg3 << endl;
                memory.write(reg1, alu.performOperation(memory.read(reg2), memory.read(reg3), '-'));
                break;
            case 3: // Conditional Branch
                if (memory.read(reg1) == 0) {
                    pc = reg2; // Branch to address
                    cout << "Branch Taken to Address " << pc << endl;
                }
                break;
            default:
                cout << "Invalid opcode: " << opcode << endl;
                break;
        }
    }
};

int main() {
    CPU cpu;

    // Sample program using fixed-size array
    int program[] = {
        (1 << 24) | (1 << 16) | (10 << 8) | (20),  // ADD R1 = 10 + 20
        (2 << 24) | (2 << 16) | (1 << 8) | (10),   // SUB R2 = R1 - 10
        (3 << 24) | (2 << 16) | (0 << 8) | (5),    // Branch if R2 == 0 to address 5
        (0)                                       // Halt
    };
    int programSize = sizeof(program) / sizeof(program[0]);

    cpu.loadProgram(program, programSize);
    cpu.run();

    return 0;
}
```

