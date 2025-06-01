## Syscall writeup

We find our `task_struct` in memory using arbitrary read (literally dump the memory and look for a string 
that matches our process name). We do the same for some root process (linuxrc was used in the exploit).

Then write the root process's cred pointer as our own using the arbitrary write primitive.

Writing the cred pointer may fail if the addresses have a 0 byte in them, that's why the user is prompted.

