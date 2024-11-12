#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> instructionMap = {
    {"ADD", "0001"},
    {"SUB", "0010"},
    {"LOAD", "0011"},
    {"STORE", "0100"},
    {"MOV", "0101"}
};

unordered_map<string, string> registerMap = {
    {"R0", "0000"},
    {"R1", "0001"},
    {"R2", "0010"},
    {"R3", "0011"}
};

// Convert an address to an 8-bit binary string
string toBinary(int n, int bits = 8) {
    string result = "";
    for (int i = bits - 1; i >= 0; i--) {
        result += ((n >> i) & 1) ? "1" : "0";
    }
    return result;
}

void assembleInstruction(const string& opcode, const string& reg1, const string& reg2, int address = 0) {
    cout << "Instruction: " << opcode << " " << reg1 << ", " << (opcode == "LOAD" || opcode == "STORE" ? to_string(address) : reg2) << endl;

    string binary = instructionMap[opcode];
    binary += registerMap[reg1];

    if (opcode == "LOAD" || opcode == "STORE") {
        binary += toBinary(address);
    } else {
        binary += registerMap[reg2] + "00000000";
    }

    cout << "Machine Code: " << binary << endl;
}

int main() {
    cout << "Virtual CPU Assembler\n" << endl;

    // Static instructions
    assembleInstruction("ADD", "R1", "R2");
    assembleInstruction("SUB", "R1", "R3");
    assembleInstruction("LOAD", "R2", "0", 10); // Load from address 10 into R2
    assembleInstruction("STORE", "R1", "0", 15); // Store R1 at address 15
    assembleInstruction("MOV", "R2", "R3");

    return 0;
}
