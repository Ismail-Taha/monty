# Test with valid ASCII value
push 72
pchar

# Test with value out of ASCII range
push 128
pchar

# Test with negative value
push -1
pchar

# Test with empty stack
pchar
