Buddy Memory Management System
CSCE 313 (adapted from assignment)

System of memory management that break blocks of
memory down such that the total memory is a power
of two times the basic block size. System is
tested using the Ackerman recursive function.

en.wikipedia.org/wiki/Buddy_memory_allocation
en.wikipedia.org/wiki/Ackermann_function.

Run using ./memtest or ./memtestOutput.
-b flag specifies basic block size (bytes).
-s flag specifies total memory size (bytes).
run the ./memtestOutput to get output on the
allocator's actions (runs slower)

Basic block size is 128 bytes by default.
Total memory size is 128 KB by default.

Runs Ackerman with combinations of n and m.