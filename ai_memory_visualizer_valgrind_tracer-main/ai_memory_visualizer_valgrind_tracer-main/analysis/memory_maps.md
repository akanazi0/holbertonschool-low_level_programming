# Memory Maps & Analysis

## 1. Analysis: `stack_example.c`

### Execution Point: Deepest Recursion 
**Description:** The state of the stack when `walk_stack()` is at `depth = 3`, right inside the `dump_frame("enter", 3)` function before it returns.

#### Memory State Map
| Memory Region | Variable | Address (Example) | Value | Lifetime Scope |
| :--- | :--- | :--- | :--- | :--- |
| **Stack (main)** | `main` frame | `0x7fffffffde40` | Return address | Entire program run |
| **Stack (walk d=0)** | `marker` | `0x7fffffffde20` | `0` | Until `walk_stack(0)` finishes |
| **Stack (walk d=1)** | `marker` | `0x7fffffffddf0` | `10` | Until `walk_stack(1)` finishes |
| **Stack (walk d=2)** | `marker` | `0x7fffffffddc0` | `20` | Until `walk_stack(2)` finishes |
| **Stack (walk d=3)** | `marker` | `0x7fffffffdd90` | `30` | Until `walk_stack(3)` finishes |
| **Stack (dump_frame)** | `local_int` | `0x7fffffffdd6c` | `103` | Only while `dump_frame` is running |
| **Stack (dump_frame)** | `local_buf` | `0x7fffffffdd50` | `'D'` | Only while `dump_frame` is running |
| **Stack (dump_frame)** | `p_local` | `0x7fffffffdd48` | `0x7fffffffdd6c` | Only while `dump_frame` is running |

### Lifetime & Validity Analysis
- **Stack Behavior:** Every time `walk_stack` calls itself, it pushes a new frame onto the stack. That's why we have multiple different `marker` variables living at different addresses at the same time.
- **The Danger:** When `dump_frame` finishes, its stack frame is popped off. `local_int`, `local_buf`, and `p_local` are technically gone. If we tried to return `p_local` to `walk_stack`, we'd be handing back a dangling pointer pointing to dead stack memory.

---

## 2. Analysis: `aliasing_example.c`

### Execution Point: Right after calling `free(a)`
**Description:** What memory looks like after we free the array, but before we try to illegally read `b[2]` and write to `b[3]`.

#### Memory State Map
| Memory Region | Variable | Address | Held Value (What it points to) | Ownership |
| :--- | :--- | :--- | :--- | :--- |
| **Stack** | `n` | `0x7fffffffde14` | `5` | Local to `main` |
| **Stack** | `a` | `0x7fffffffde08` | `0x5555555592a0` (Freed) | Owner (called `free`) |
| **Stack** | `b` | `0x7fffffffde00` | `0x5555555592a0` (Freed) | Alias (Just a copy) |
| **Heap** | Array of ints | `0x5555555592a0` | Garbage / Unallocated | Given back to the system |

### Aliasing & Ownership Analysis
- **Aliasing:** When we do `b = a`, we aren't copying the array itself. We are just copying the memory address `0x5555555592a0` from one stack variable to another. 
- **Use-After-Free:** `a` is the owner, so we call `free(a)`. This tells the heap we are done with that memory chunk. However, `b` still holds the exact same address. 
- Because `b` still points to that now-freed memory, trying to read `b[2]` or write `b[3] = 1234` is a classic use-after-free bug. We are messing with memory that the heap manager thinks is available.

---

## 3. AI Output Evaluation & Corrections

For this project, I used an AI assistant to help explain what happens during a `free()` when there are aliased pointers. The AI gave me a response that sounded right but was totally wrong about how C actually works under the hood.

### The Flawed AI Explanation
I asked: *"What happens to pointer b when I call free(a)?"*
The AI responded: > *"When you call `free(a)`, the memory chunk is released. To prevent memory corruption, C automatically sets all other pointers that point to that memory, like `b`, to `NULL`. If you try to access `b[2]` afterwards, the program will immediately segmentation fault because the memory is gone."*

### My Correction and Reasoning
1. **C doesn't track aliases:** The AI claimed C sets `b` to `NULL`. This is completely false. C doesn't have a garbage collector or a reference tracker. The `free()` function only gets the memory address `a` points to; it has no idea that `b` even exists on the stack. After `free(a)`, `b` still holds the exact same address it did before. It is now a dangling pointer.
2. **Segfaults aren't guaranteed:** The AI said accessing it will *immediately* cause a segfault. This is also wrong. `free()` just updates the heap manager's metadata to say "this chunk is available." It doesn't usually unmap the memory page from the OS. Reading `b[2]` might just return garbage data, or silently corrupt the heap when we write to `b[3]`, without crashing the program right away. That's exactly why we need Valgrind to catch these silent bugs.

**How to actually fix it:** To be safe, we have to manually set both to NULL ourselves:
```c
free(a);
a = NULL;
b = NULL;