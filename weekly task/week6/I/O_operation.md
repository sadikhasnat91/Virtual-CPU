## **Objective:**
Enable basic input/output (I/O) operations in the virtual CPU.

## **Tasks:**

### 1. Implement Simulated I/O Devices (Keyboard, Display)

#### **Keyboard Simulation:**
- Use a buffer or variable to mimic the behavior of a keyboard.
- Input values can be read from the user (e.g., `std::cin` in C++ or `input()` in Python).
- Store these inputs into a memory-mapped I/O location in your simulated memory.

#### **Display Simulation:**
- Use the console to simulate a display.
- When the CPU writes to a specific memory-mapped I/O location, print the value to the screen to represent output.

#### **Memory-Mapped I/O:**
- Assign specific addresses in your memory space for I/O operations.
  - Example: Address `0xFF00` for keyboard input, `0xFF01` for display output.

### 2. Create I/O Instructions and Integrate Them with the CPU

#### **New I/O Instructions:**
- **Input Instruction:** `IN reg, address`
  - Reads from the I/O device (e.g., keyboard) into a register.
- **Output Instruction:** `OUT reg, address`
  - Writes the value from a register to an I/O device (e.g., display).

#### **CPU Integration:**
- Modify the CPU’s instruction execution loop to recognize `IN` and `OUT` instructions.
- For an `IN` instruction:
  - Fetch the value from the keyboard buffer and store it in the specified register.
- For an `OUT` instruction:
  - Write the value from the register to the display.

### 3. Test with I/O-Intensive Programs

Write small test programs to verify I/O functionality:

#### **Example Program 1: Input and Output Test**
- Input a number, double it, and output the result.

#### **Example Program 2: Character Echo Program**
- Continuously read a character from the keyboard and display it on the screen.

---

## **Implementation Steps**

### 1. Simulate I/O Devices

#### **Keyboard Input**
```cpp
int keyboardInput() {
    int input;
    cout << "Enter a value: ";
    cin >> input;
    return input;
}
```

#### **Display Output**
```cpp
void displayOutput(int value) {
    cout << "Output: " << value << endl;
}
```

### 2. Integrate with CPU

Add instructions for I/O operations in the instruction set:

```cpp
void executeInstruction(int opcode, int reg, int address) {
    switch (opcode) {
        case INSTRUCTION_IN:
            registers[reg] = keyboardInput(); // Input into a register
            break;
        case INSTRUCTION_OUT:
            displayOutput(registers[reg]); // Output from a register
            break;
        default:
            // Handle other instructions
            break;
    }
}
```

### 3. Test Programs

#### **Example Program: Input and Output**
```cpp
// Pseudocode
MOV R1, 0xFF00  // Map keyboard to R1
IN R1, 0xFF00   // Read input into R1
ADD R1, R1, R1  // Double the value
OUT R1, 0xFF01  // Output result
```

#### **Expected Result:**
- Input: 5
- Output: 10

---

## **Testing**
- Verify memory-mapped I/O works:
  - Check if input values are correctly fetched.
  - Check if output values are correctly displayed.
