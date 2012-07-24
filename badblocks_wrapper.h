#ifndef __BADBLOCKS_WRAPPER_H__
#define __BADBLOCKS_WRAPPER_H__

enum { ReadOnly, NonDestructiveReadWrite, DestructiveReadWrite };
const int DefaultBlock = -1;

int badblocks(const char *device, int mode, int last_block, int first_block);

#endif /* __BADBLOCKS_WRAPPER_H__ */

