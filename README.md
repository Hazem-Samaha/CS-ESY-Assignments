Circular Buffer Implementation (C Language)
This project provides a robust implementation of a Circular Buffer (Ring Buffer) data structure in C. It is optimized for scenarios where fixed-size memory management is required, such as in Embedded Systems.

💡 Overview
The implementation uses a fixed-size array to handle data in a circular manner. When the pointer reaches the end of the buffer, it wraps around to the beginning using the modulo operator.

🛠 Core Features
Static Memory: Uses a predefined SIZE to ensure predictable memory usage.

Status Tracking: Includes built-in functions to check for isFull and isEmpty states.

Safety: Prevents data overflow by notifying the user when the buffer is at maximum capacity.

String Processing: Demonstrates buffer operations by processing user input concatenated with the "CE-ESY" tag.

🚀 How to Run
1. Compile the code using any C compiler (e.g., GCC):

gcc main.c -o circular_buffer

2. Execute the program:

./circular_buffer

3. Input: Enter a name when prompted to see the buffer in action.