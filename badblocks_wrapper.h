/*
 * badblocks_wrapper.h --- Wrap the over system utility badblocks, is designed
 * to be clear about the options available in the original utility.
 *
 * Copyright (C) 2012 Roman Tereshin.  This file may be
 * redistributed under the terms of the GNU Public License.
 */

#ifndef __BADBLOCKS_WRAPPER_H__
#define __BADBLOCKS_WRAPPER_H__

enum { ReadOnly, NonDestructiveReadWrite, DestructiveReadWrite };
const int DefaultBlock = -1;

int badblocks(const char *device, int mode, int last_block, int first_block);

#endif /* __BADBLOCKS_WRAPPER_H__ */

