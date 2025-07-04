This one took a bit of poking around

The main obstacles are that the kernel loader will
patch the module to solve relocatables, so you need to be careful with the patching,
and that you don't get sys_open, since the sct is overwritten.

My solution was to use the disabled write protections to write directly to the original sys_open_hooked function
change the conditional jump of the result of `strstr` to a nop. 

There are a ton of other ways.

