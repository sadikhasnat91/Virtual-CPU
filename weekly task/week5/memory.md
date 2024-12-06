
# Simulated Memory with Segmentation

This program implements a **simulated memory space** with basic read/write operations, memory segmentation, and address mapping. It demonstrates how a memory system can be structured for educational or simulation purposes.

---

## Features
1. **Fixed-Size Memory**:
   - Memory is represented as an array with 256 addresses.

2. **Memory Segmentation**:
   - Supports up to 10 memory segments.
   - Each segment is defined by a start address and size.

3. **Memory Read/Write**:
   - Direct addressing (`write` and `read` methods).
   - Segment-relative addressing (`segmentWrite` and `segmentRead` methods).

4. **Error Handling**:
   - Out-of-bounds addresses or undefined segments are handled with descriptive error messages.

5. **Debugging Tools**:
   - Displays non-zero memory content for easy debugging.

---

## Code

```cpp
#include <iostream>
using namespace std;

// Memory Class
class Memory {
private:
    int memory[256];            // Fixed-size memory (256 addresses)
    int segmentStart[10];       // Start addresses of up to 10 segments
    int segmentSize[10];        // Sizes of up to 10 segments

public:
    Memory() {
        // Initialize memory and segments
        for (int i = 0; i < 256; i++) memory[i] = 0;
        for (int i = 0; i < 10; i++) {
            segmentStart[i] = -1;
            segmentSize[i] = 0;
        }
    }

    // Write data to a specific address
    void write(int address, int value) {
        if (address >= 0 && address < 256) {
            memory[address] = value;
            cout << "Memory Write: Address " << address << " = " << value << endl;
        } else {
            cout << "Error: Address out of bounds." << endl;
        }
    }

    // Read data from a specific address
    int read(int address) {
        if (address >= 0 && address < 256) {
            cout << "Memory Read: Address " << address << " = " << memory[address] << endl;
            return memory[address];
        } else {
            cout << "Error: Address out of bounds." << endl;
            return -1;
        }
    }

    // Define a memory segment
    void defineSegment(int segmentID, int startAddress, int size) {
        if (segmentID >= 0 && segmentID < 10 && startAddress >= 0 && startAddress + size <= 256) {
            segmentStart[segmentID] = startAddress;
            segmentSize[segmentID] = size;
            cout << "Segment Defined: ID=" << segmentID 
                 << ", Start=" << startAddress 
                 << ", Size=" << size << endl;
        } else {
            cout << "Error: Segment definition out of bounds." << endl;
        }
    }

    // Write to a segment
    void segmentWrite(int segmentID, int offset, int value) {
        if (segmentID >= 0 && segmentID < 10 && segmentStart[segmentID] != -1) {
            int startAddress = segmentStart[segmentID];
            int size = segmentSize[segmentID];

            if (offset >= 0 && offset < size) {
                write(startAddress + offset, value);
            } else {
                cout << "Error: Offset out of bounds for segment " << segmentID << endl;
            }
        } else {
            cout << "Error: Segment " << segmentID << " not defined." << endl;
        }
    }

    // Read from a segment
    int segmentRead(int segmentID, int offset) {
        if (segmentID >= 0 && segmentID < 10 && segmentStart[segmentID] != -1) {
            int startAddress = segmentStart[segmentID];
            int size = segmentSize[segmentID];

            if (offset >= 0 && offset < size) {
                return read(startAddress + offset);
            } else {
                cout << "Error: Offset out of bounds for segment " << segmentID << endl;
                return -1;
            }
        } else {
            cout << "Error: Segment " << segmentID << " not defined." << endl;
            return -1;
        }
    }

    // Display memory content (for debugging)
    void displayMemory() {
        cout << "Memory Content: ";
        for (int i = 0; i < 256; i++) {
            if (memory[i] != 0) { // Show non-zero values only
                cout << "[" << i << "]: " << memory[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Memory mem;

    // Define memory segments
    mem.defineSegment(0, 0, 64);  // Segment 0: Start at 0, size 64
    mem.defineSegment(1, 64, 32); // Segment 1: Start at 64, size 32

    // Write to memory
    mem.write(10, 50); // Direct write to address 10
    mem.segmentWrite(0, 5, 100); // Write to segment 0 at offset 5
    mem.segmentWrite(1, 10, 200); // Write to segment 1 at offset 10

    // Read from memory
    mem.read(10); // Direct read from address 10
    mem.segmentRead(0, 5); // Read from segment 0 at offset 5
    mem.segmentRead(1, 10); // Read from segment 1 at offset 10

    // Display memory content
    mem.displayMemory();

    return 0;
}
```

---

## Example Output

**Actions**:
- Define two segments.
- Write data directly and via segments.
- Read data directly and via segments.

**Output**:
```
Segment Defined: ID=0, Start=0, Size=64
Segment Defined: ID=1, Start=64, Size=32
Memory Write: Address 10 = 50
Memory Write: Address 5 = 100
Memory Write: Address 74 = 200
Memory Read: Address 10 = 50
Memory Read: Address 5 = 100
Memory Read: Address 74 = 200
Memory Content: [5]: 100 [10]: 50 [74]: 200 
```
