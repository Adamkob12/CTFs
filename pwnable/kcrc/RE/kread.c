#include "utils.h"

u32 kcrc[256];

// As far as I can tell, just copies the bytes over in a cumbersome way.
// Ignores len completely, always copies 1024 bytes.
usize __usercall kread(u8 *buf, usize len) {
    // Some cursor in kcrc (cursor)
    u32 *cursor;
    // Bytes until end of kcrc (v3)
    u32 bytes_left;
    i32 v4;
    u8 *v5;
    u32 *v6;
    u16 v8;

    cursor = kcrc;
    bytes_left = 1024;

    // If buf is not 2 bytes aligned, copy over 1 byte and align it.
    if (((u8)buf & 1) != 0) {
        // Note that v1 points to the u32 at offset 1 byte
        cursor = (u32 *)((u8 *)kcrc + 1);
        *buf++ = kcrc[0];
        bytes_left = 1023;
    }
    // -- Now buf is guaranteed to be 2 bytes aligned.
    // If buf is not 4 bytes aligned, copy over 2 bytes and align it.
    if (((u8)buf & 2) != 0) {
        v8 = *(u16 *)cursor;
        bytes_left -= 2;
        cursor = (u32 *)((u8 *)cursor + 2);
        *(u16 *)buf = v8;
        buf += 2;
    }
    // -- Now buf is guaranteed to be 4 bytes aligned.
    v4 = 0;
    // Copy the amount of bytes left, rounded down to be 4 bytes aligned.
    // (if bytes left is 1003, only 1000 will be copied)
    qmemcpy(buf, cursor, 4 * (bytes_left >> 2));
    // points to start of area in kcrc that wasn't copied.
    v6 = &cursor[bytes_left >> 2];
    // points to start of area in buffer that wasn't copied from kcrc.
    v5 = &buf[4 * (bytes_left >> 2)];
    if ((bytes_left & 2) != 0) {
        *(u16 *)v5 = *(u16 *)v6;
        v4 = 2;
    }
    if ((bytes_left & 1) != 0)
        v5[v4] = *((u8 *)v6 + v4);
    return 1024;
}
