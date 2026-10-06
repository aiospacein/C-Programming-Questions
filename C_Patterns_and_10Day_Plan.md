# C-Programming-Questions: Master Patterns Sheet + 10-Day Plan

## PART 1 — Every Pattern/Trick You Need (learn these BEFORE coding)

### A. Array Patterns
| Pattern | What it solves | Used in |
|---|---|---|
| **Two-pointer (opposite ends)** | Pair-sum, reversing, partitioning | Target_Sum_Pairs, Positive-Negative_Rearranger, Zero-Mover |
| **Two-pointer (same direction / fast-slow)** | In-place dedup, cycle-style scans | Duplicate_Remover, Zero-Mover_to_Left |
| **Prefix sum / Prefix product** | Range sums, product-except-self | Array_Product_Excluding_Self, Equilibrium_Index |
| **Kadane's Algorithm** | Max/min subarray sum | Minimum_Sum_Subarray, Zero_Sum_Subarray (with hashmap variant) |
| **Floyd's Cycle Detection (applied to array-as-function)** | Find duplicate without extra space | Duplicate_Number_Detector |
| **XOR trick** | Find missing/unique number in O(n) O(1) | Missing_Number_Finder, Single_Number |
| **Moore's Voting Algorithm** | Majority element (>n/2) | Majority_Element_Identifier |
| **Boyer-Moore variant (n/3)** | Multiple majority elements | Multiple_Duplicates_Identifier |
| **Sliding window (fixed/variable)** | Subarray with a condition | Longest_Consecutive_Subsequence (with hashset) |
| **In-place rotation (reversal algorithm)** | Rotate array by k | Array_Right_Rotator |
| **Hashing/frequency map (simulated with arrays in C)** | Counting, duplicates, intersections | Array_Intersection, Two_Repeating_Elements |
| **Quickselect** | Kth largest/smallest without full sort | Kth_Max-Min_Element_Retriever |

### B. Bit Manipulation Tricks
| Trick | Formula | Used for |
|---|---|---|
| Check power of 2 | `n & (n-1) == 0` | Detecting_Power_of_Two |
| Count set bits | Brian Kernighan: `n &= (n-1)` in loop | Count_Set_Bits |
| Isolate rightmost set bit | `n & (-n)` | Isolate_Rightmost_Set_Bit |
| Toggle/set/clear a bit | `n ^ (1<<i)` / `n \| (1<<i)` / `n & ~(1<<i)` | Toggle_3rd_5th_Bits, Mask_Certain_Bits |
| Check opposite signs | `(a ^ b) < 0` | Determine_Opposite_Signs |
| Swap without temp | `a ^= b; b ^= a; a ^= b;` | Reverse_Bits, Swap_Odd_Even_Bits |
| XOR cancels duplicates | `a^a=0, a^0=a` | Single_Number, Find_a_Unique_Number |
| Two uniques (split by set bit) | XOR all, find rightmost set bit, split into 2 groups | Find_Two_Unique_Numbers |
| Multiply/divide by power of 2 | `n << k` / `n >> k` | Calculate_a_power_b |
| Check multiple of 3 (bit trick) | Recursive XOR-based bit counting | Check_if_Multiple_of_3 |
| Generate n-bit combinations | Loop `0` to `2^n - 1` | Generate_All_Combinations_of_n_Bits |

### C. Pointer & String-Handling Fundamentals
| Concept | Key idea |
|---|---|
| Pointer arithmetic | `*(arr+i) == arr[i]`; pointer moves by `sizeof(type)` |
| Array decay | Array name decays to pointer to first element when passed to functions |
| Double pointers (`**`) | Needed for functions that must modify a pointer itself (e.g., resizing) |
| Manual string functions | Rewrite `strlen`, `strcpy`, `strcat`, `strcmp`, `strtok` using pointer walking, not library calls |
| Pointer to function | Used for callback-style dispatch (menu_item_function_pointer, Custom_Signal_Handling) |
| NULL-termination discipline | Every manual string function must respect `\0`, or you get undefined behavior |

### D. String Patterns
| Pattern | Used for |
|---|---|
| Frequency array (size 256 for ASCII) | Anagram check, first unique char, most frequent char |
| Two-pointer palindrome check | Palindrome_Validation |
| Expand-around-center | Longest_Palindromic_Substring |
| Sliding window + hashset/frequency array | Longest_Substring_Without_Repeats |
| Backtracking | Generating_All_Permutations |
| Stack-based matching | Validating_Balanced_Parentheses |
| KMP / Z-function idea (prefix function) | Repeated_Substring_Pattern, Substring_Occurrences |
| DP on substrings | String_Interleaving, Minimizing_Palindromic_Partitions |
| Booth's algorithm (or brute rotation + concatenation trick `s+s`) | Lexicographically_Minimal_Rotation, Verifying_String_Rotations |

### E. Searching Patterns
| Pattern | Used for |
|---|---|
| **Binary search (vanilla)** | Search_sorted_array |
| **Binary search on answer / modified condition** | Search_bitonic_array, Search_sorted_rotated_array, Find_peak_element |
| **Binary search for first/last occurrence** | Find_first_last_occurrence, Count_number_occurrences |
| **Exponential search** | Search_unknown_length_array (no upper bound known) |
| **Interpolation search** | Uniformly distributed sorted data — probes proportionally, not just midpoint |
| **Fibonacci search** | Alternative to binary search using Fibonacci numbers, avoids division |
| **Ternary search** | Unimodal function optimization |
| **Sentinel search** | Linear search with a sentinel value to skip bound-checking |
| **2D matrix search (staircase search)** | Search_sorted_matrix — start top-right or bottom-left corner |
| **Two-sum via sort + two-pointer OR hashmap** | Two_numbers_sum_N |

### F. Sorting — know these by category, not as 24 separate algorithms
| Category | Algorithms | Core Idea |
|---|---|---|
| Simple/comparison (O(n²)) | Bubble, Cocktail, Gnome, Comb, Odd-Even | All repeatedly compare adjacent/gapped elements and swap |
| Divide & Conquer (O(n log n)) | Merge Sort, Quick Sort (iterative + recursive), Tim Sort | Split, solve, combine |
| Heap-based | Heap Sort | Build max-heap, repeatedly extract max |
| Non-comparison (O(n+k)) | Counting Sort, Radix Sort, Bucket Sort, Pigeonhole Sort | Use value ranges/digits instead of comparisons |
| Novelty (understand, don't over-invest) | Bogo Sort, Sleep Sort, Stooge Sort | Learn concept in 5 min each, they're not used in production |
| Special-case | Cycle Sort (min writes), Patience Sort (uses stacks, longest increasing subsequence), Bitonic Sort (parallel-friendly) | Niche but interview-favorite |

**Rule:** learn merge sort + quicksort + heap sort deeply (these recur everywhere). The rest are variations you can derive once you know swap-based vs. merge-based logic.

### G. Stacks & Queues Patterns
| Pattern | Used for |
|---|---|
| Stack for matching/validation | Balanced_Parentheses, Expression_Validator |
| Two stacks → Queue (and vice versa) | Queue_from_Stacks |
| Monotonic stack | Min-Element_Stack (track min alongside top) |
| Stack-based expression evaluation (Shunting Yard / postfix eval) | Stack-based_Calculator |
| Circular buffer indexing (`(head+1) % size`) | Circular_Queue |
| Recursion ↔ explicit stack conversion | Recursive_to_Iterative_Converter, Post-order_Traversal_Stack |
| Queue-based sliding window / rate limiting | Queue-based_Cache, Queue_Two_Priorities |

### H. Linked List Patterns
| Pattern | Used for |
|---|---|
| **Fast-slow pointer (Floyd's)** | Detect_Cycle, Find_Middle_Element, Linked_List_Is_Palindrome |
| **Dummy node technique** | Partition_Linked_List, Remove_Nodes_of_Value (avoids special-casing head) |
| **Iterative + recursive reversal** | Reverse_Linked_List (both versions) |
| **Merge technique** | Merge_Two_Sorted_Lists, Merge_Sort_on_Linked_List |
| **Hashmap for deep copy** | Clone_Linked_List_With_Random_Pointer |
| **Runner technique for Nth-from-end** | Find_Nth_Node_From_End |
| **In-place node relinking** | Pairwise_Swap, Segregate_Even_Odd, Move_Last_To_Front |

### I. Structures & Unions Concepts (theory-heavy, not algorithmic)
- **Struct padding & alignment** — compiler adds padding for word-alignment; understand `sizeof` mismatches (structure_memory_optimization).
- **Bitfields** — `unsigned int flag : 1;` for packing multiple small values into one int (device_config_bitfields).
- **Unions** — all members share memory; used for type-punning, e.g., viewing 4 bytes as either an int or 4 chars (endianness_conversion, 32bit_value_access).
- **Endianness** — big-endian vs little-endian byte order; test using a union or pointer cast.
- **Function pointers inside structs** — building simple "vtables"/menus in C (menu_item_function_pointer).
- **Nested structs & typedef** — composing complex records (employee_address, vehicle_extended_structure).

### J. Memory Management Concepts
- `malloc`/`calloc`/`realloc`/`free` internals and common bugs (double-free, use-after-free, memory leaks).
- **Free list / linked-list-based allocators** (Segmented_Memory_Allocator, Slab_Allocator).
- **Memory pools** — pre-allocate a big block, hand out fixed-size chunks (fast, avoids fragmentation).
- **Fragmentation** — internal vs external; Memory_Defragmenter deals with compacting used blocks.
- **Custom heap metadata** — tracking block size/status via a header struct before each allocation (Heap_Metadata_Inspector).
- **Garbage collection basics** — reference counting or mark-and-sweep simulation.

### K. Linux Internals Concepts
- **Process management** — `fork()`, `wait()`, `exec()` family, zombie/orphan processes.
- **Threading** — `pthread_create/join`, mutexes (`pthread_mutex_t`), condition variables, semaphores (`sem_t`).
- **Producer-Consumer problem** — classic semaphore synchronization pattern.
- **Priority inversion** — what it is and priority inheritance as the fix.
- **Signals** — `signal()`/`sigaction()`, custom handlers for SIGINT etc.
- **File I/O syscalls** — `open/read/write/close`, `opendir/readdir` for traversal.
- **Reimplementing shell utilities** — parse `argv`, use syscalls directly instead of library shortcuts (tail, chmod, ping, whois, watch).
- **IPC concepts** — pipes/shared memory basics for user-space↔kernel-space communication problems.

---

## PART 2 — Topic-wise vs. Mixed-Category: My Recommendation

**Total problems ≈ 273, spread almost evenly across 11 folders (~24-25 each).** That means: no matter how you slice the calendar, you're doing **~27 problems/day** for 10 days. Grouping doesn't reduce work — it only changes *mental fatigue and pattern-retention*.

Here's the honest trade-off:

| Approach | Pros | Cons |
|---|---|---|
| **Pure topic-wise** (1 folder/day) | Deep pattern immersion, easy to track, matches how most course syllabi are structured | Heavy topics (Memory Mgmt, Linux Internals) become brutal single-day slogs; light/fun topics (Bit Manipulation, Sorting) end early leaving unused time |
| **Mixed (2 lighter categories/day)** | Balances a "heavy theory" topic with a "quick pattern" topic so you don't burn out; keeps energy/variety up | Slightly more context-switching; you must track 2 pattern sets per day |

**My recommendation as a planner: go mixed, but pair *conceptually related* topics, not random ones.** Pairing related topics (e.g., Pointers + Strings, or Stacks + Linked Lists) means the second topic reinforces the first instead of competing for separate brain space. This is what I've done below — it's the same total workload as before, just resequenced for better retention and energy balance.

---

## PART 3 — Revised 10-Day Plan (Mixed, Paired by Concept)

| Day | Morning Topic | Afternoon Topic | Why paired | Problems | Key patterns to nail first |
|---|---|---|---|---|---|
| **1** | Arrays (25) | — (solo, foundation day) | Everything downstream (pointers, searching, sorting) builds on array fluency | 25 | Two-pointer, prefix sum, Kadane's, XOR-missing-number |
| **2** | Bit Manipulation (24) | — (solo, fast-paced) | Self-contained, quick wins to build momentum after a dense Day 1 | 24 | Bit masks, Brian Kernighan, XOR uniqueness |
| **3** | Pointers (13) | Strings (12) | Manual string functions ARE pointer exercises — do them back to back | 25 | Pointer arithmetic, manual strcpy/strtok, frequency arrays |
| **4** | Strings (remainder, 13) | Searching (12) | Both use two-pointer/window-style scanning logic | 25 | Sliding window, binary search variants |
| **5** | Searching (remainder, 12) | Sorting (13) | Many searches assume sorted data — natural bridge into sorting | 25 | Binary search on rotated/bitonic arrays, merge/quicksort |
| **6** | Sorting (remainder, 11) | Stacks & Queues (14) | Merge sort's recursion pairs well with stack/recursion-conversion problems | 25 | Heap sort, monotonic stack, postfix evaluation |
| **7** | Stacks & Queues (remainder, 10) | Linked List (15) | Stack-based reversal logic transfers directly into linked list reversal | 25 | Fast-slow pointer, dummy node, iterative reversal |
| **8** | Linked List (remainder, 9) | Structures & Unions (16) | Linked lists ARE self-referential structs — natural continuation | 25 | Struct padding, unions/type-punning, bitfields |
| **9** | Structures & Unions (remainder, 8) | Memory Management (17) | Structs/unions are the building blocks memory allocators manage | 25 | malloc internals, memory pools, fragmentation |
| **10** | Memory Management (remainder, 7) | Linux Internals (24) | Crunch day — pick core representative problems per sub-theme rather than all 24 verbatim (see note below) | ~31 | fork/pthread/semaphore basics, syscall-based utilities |

**Day 10 reality check:** Linux Internals alone is 24 problems of OS-course depth. On a crunch day, prioritize solving one problem fully per sub-theme (process, threading, signals, one shell-utility reimplementation, one IPC problem) — about 12-14 problems done rigorously — then rapid-pattern-match the rest using the same skeleton code. If it spills into a Day 11 morning, that's a completely normal outcome for this specific folder, not a planning failure.

---

## Daily Rhythm (same as before, applies to every day above)
1. **1–1.5 hr**: Read/learn the pattern(s) for the day's topic(s) from Part 1 above.
2. **3 hr**: Solve problems batch 1.
3. **30 min break**
4. **3 hr**: Solve problems batch 2.
5. **30–45 min**: Review tricky ones, update a running `patterns.md` cheat sheet.

