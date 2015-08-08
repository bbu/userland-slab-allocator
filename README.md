Carefully optimised slab allocator for userspace. Relies on anonymous mmap(2) 
page allocations, or occassionally on posix_memalign(3) for larger objects.

Bit-vectors are used to indicate whether the corresponding slots are free
and that makes the allocations and deallocations very quick most of the time.
A 64-bit unsigned integer is scanned for its first set/unset bit (this
usually translates to a single BSF instruction on x86).

![alt tag](https://raw.github.com/bbu/userland-slab-allocator/master/screenshot.png)
