#include <iostream>
using namespace std;

// Function to convert integer to binary (stored in an array)
void intToBinary(int num, int binary[]) {
    for (int i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
}

// Function to convert binary (array) to integer
int binaryToInt(const int binary[]) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        num = num * 2 + binary[i];
    }
    return num;
}

// Keyboard class for input
class Keyboard {
public:
    int getInput() {
        string input;
        cout << "Enter a number or character (Keyboard Input): ";
        cin >> input;

        // Check if input is a single character
        if (input.length() == 1) {
            return static_cast<int>(input[0]); // Convert character to ASCII value
        }

        // Otherwise, treat as an integer input
        try {
            return stoi(input); // Convert string to integer
        } catch (...) {
            cout << "Invalid input! Defaulting to 0." << endl;
            return 0; // Default value if input is invalid
        }
    }
};

// Display class for output
class Display {
public:
    void showOutput(int data) {
        // Check if the data corresponds to a printable ASCII character
        if (data >= 32 && data <= 126) {
            cout << "Display Output (Character): " << static_cast<char>(data) << endl;
        } else {
            cout << "Display Output (Integer): " << data << endl;
        }
    }
};

// Memory class for storing binary data
class Memory {
private:
    int memory[10][8]; // Memory: 10 addresses, each holding 8 bits (binary)

public:
    Memory() {
        // Initialize memory to all zeros
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                memory[i][j] = 0;
            }
        }
    }

    void write(int address, const int binaryData[]) {
        if (address >= 0 && address < 10) {
            for (int i = 0; i < 8; i++) {
                memory[address][i] = binaryData[i];
            }
            cout << "Memory Write: Address " << address << " = ";
            for (int i = 0; i < 8; i++) {
                cout << memory[address][i];
            }
            cout << endl;
        } else {
            cout << "Error: Address out of bounds!" << endl;
        }
    }

    void read(int address, int binaryData[]) {
        if (address >= 0 && address < 10) {
            for (int i = 0; i < 8; i++) {
                binaryData[i] = memory[address][i];
            }
            cout << "Memory Read: Address " << address << " = ";
            for (int i = 0; i < 8; i++) {
                cout << binaryData[i];
            }
            cout << endl;
        } else {
            cout << "Error: Address out of bounds!" << endl;
        }
    }
};

// CPU class to control everything
class CPU {
private:
    Memory memory;
    Keyboard keyboard;
    Display display;

public:
    void run() {
        cout << "CPU Test Program Starting...\n";

        // Get input from keyboard
        int input = keyboard.getInput();

        // Convert to binary and store in memory
        int binaryInput[8];
        intToBinary(input, binaryInput);
        memory.write(0, binaryInput); // Store at address 0

        // Read binary from memory, convert back to integer, and display
        int binaryValue[8];
        memory.read(0, binaryValue);
        int value = binaryToInt(binaryValue);
        display.showOutput(value);

        cout << "CPU Test Program Completed.\n";
    }
};

int main() {
    CPU cpu;
    cpu.run();
    return 0;
}
