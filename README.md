0x19-Stacks and Queues- C
1. pint
mandatory
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

2. pop
mandatory
Implement the pop opcode.

The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

3. swap
mandatory
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

4. add
mandatory
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

5. nop
mandatory
Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.

Usage: nop
Repo:

GitHub repository: monty

6. sub
#advanced
Implement the sub opcode.

The sub opcode

The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage: sub
If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

7. div
#advanced
Implement the div opcode.

The div opcode

The opcode div divides the second top element of the stack by the top element of the stack.

Usage: div
If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

8. mul
#advanced
Implement the mul opcode.

The mul opcode

The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage: mul
If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

9. mod
#advanced
Implement the mod opcode.

The mod opcode

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: mod
If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

10. comments
#advanced
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

Repo:

GitHub repository: monty

11. pchar
#advanced
Implement the pchar opcode.

The pchar opcode

The opcode pchar prints the char at the top of the stack, followed by a new line.

Usage: pchar
The integer stored at the top of the stack is treated as the ascii value of the character to be printed
If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
