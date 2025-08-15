#include "utils.h"

u32 kcrc[256];
u32 crc32_tab[256];
u32 idx;

#define OP_1 0xadd
#define OP_2 0xde1

i32 __fastcall kwrite(u8 __user* buf, u32 len) {
    i32 ret, v2, v3;
    u32 v5, v6, v7;
    i32 *i;
    u8 v9;
    i32 v10;
    u32 op;
    i32 *ptr;
    u32 l;

    ret = -1;
    if (len != 12)
        return ret;
    // buf needs to be 12, 4 bytes for op, ptr & l respecively.
    v2 = copy_from_user(&op, buf, 4);
    v3 = copy_from_user(&ptr, buf+4, 4) + v2;
    if (copy_from_user(&l, buf+8, 4) + v3)
        return ret;
    if (op == OP_1) {
        if (idx != 256) {
            v6 = l;
            v7 = -1;
            for (i = ptr; v6 != 0; --v6) {
                v9 = *(u8 *)i;
                i = (i32 *)((u8 *)i + 1);
                v7 = crc32_tab[(u8)(v7 ^ v9)] ^ (v7 >> 8);
            }
            v10 = ~v7;
            ret = 1;
            kcrc[idx] = v10;
            printk("crc generated! %x\n", v10);
            ++idx;
        }
        return ret;
    }
    if (op != 3553)
        return 0;
    v5 = idx;
    if (!idx)
        return ret;
    --idx;
    kcrc[v5 - 1] = 0;
    return 0;
}
