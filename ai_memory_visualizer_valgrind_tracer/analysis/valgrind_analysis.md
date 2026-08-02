# Valgrind & Memory Trace Analysis

## 1. Program: `aliasing_example.c`

### Command Executed
```bash
valgrind --leak-check=full --show-leak-kinds=all ./aliasing_example

Valgrind Output Captured
==12345== Invalid read of size 4
==12345==    at 0x1091F8: main (aliasing_example.c:45)
==12345==  Address 0x4a58048 is 8 bytes inside a block of size 20 free'd
==12345==    at 0x483CA3F: free (vg_replace_malloc.c:663)
==12345==    by 0x1091DC: main (aliasing_example.c:41)
==12345==  Block was alloc'd at
==12345==    at 0x483B7F3: malloc (vg_replace_malloc.c:307)
==12345==    by 0x109165: make_numbers (aliasing_example.c:12)
==12345==    by 0x1091B1: main (aliasing_example.c:33)
==12345==
==12345== Invalid write of size 4
==12345==    at 0x109210: main (aliasing_example.c:47)
==12345==  Address 0x4a5804c is 12 bytes inside a block of size 20 free'd
==12345==    at 0x483CA3F: free (vg_replace_malloc.c:663)
==12345==    by 0x1091DC: main (aliasing_example.c:41)