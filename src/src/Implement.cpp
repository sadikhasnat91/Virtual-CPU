#include <iostream>
using namespace std;

// Keyboard class for input
class Keyboard {
public:
    int getInput() {
        int data;
        cout << "Enter a number (Keyboard Input): ";
        cin >> data;
        return data;
    }
};

// Display class for output
class Display {
public:
    void showOutput(int data) {
        cout << "Display Output: " << data << endl;
    }
};

// Memory class for storing data
class Memory {
private:
    int memory[10]; // Small fixed-size memory

public:
    Memory() {
        for (int i = 0; i < 10; i++) memory[i] = 0;
    }

    void write(int address, int value) {
        if (address >= 0 && address < 10) {
            memory[address] = value;
            cout << "Memory Write: Address " << address << " = " << value << endl;
        } else {
            cout << "Error: Address out of bounds!" << endl;
        }
    }

    int read(int address) {
        if (address >= 0 && address < 10) {
            cout << "Memory Read: Address " << address << " = " << memory[address] << endl;
            return memory[address];
        } else {
            cout << "Error: Address out of bounds!" << endl;
            return -1;
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

        // Get input from keyboard and store in memory
        int input = keyboard.getInput();
        memory.write(0, input); // Store at address 0

        // Read from memory and send to display
        int value = memory.read(0);
        display.showOutput(value);

        cout << "CPU Test Program Completed.\n";
    }
};

int main() {
    CPU cpu;
    cpu.run();
    return 0;
}
