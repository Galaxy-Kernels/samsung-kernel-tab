/*
 * linux/drivers/media/video/samsung/mfc5x/mfc_mem.h
 *
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com/
 *
 * Memory manager for Samsung MFC (Multi Function Codec - FIMV) driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __MFC_MEM_H_
#define __MFC_MEM_H_ __FILE__

#include "mfc.h"
#include "mfc_dev.h"

#ifdef CONFIG_S5P_VMEM
#include <linux/dma-mapping.h>

extern unsigned int s5p_vmem_vmemmap(size_t size, unsigned long va_start,
		unsigned long va_end);
extern void s5p_vfree(unsigned int cookie);
extern unsigned int s5p_getcookie(void *addr);
extern void s5p_vmem_dmac_map_area(const void *start_addr,
		unsigned long size, int dir);
#endif

int mfc_mem_count(void);
unsigned int mfc_mem_base(int port);
unsigned char *mfc_mem_addr(int port);
unsigned int mfc_mem_data_base(int port);
unsigned int mfc_mem_data_size(int port);
unsigned int mfc_mem_data_ofs(unsigned int addr, int contig);
unsigned int mfc_mem_base_ofs(unsigned int addr);

void mfc_mem_cache_clean(const void *start_addr, unsigned long size);
void mfc_mem_cache_inv(const void *start_addr, unsigned long size);

int mfc_init_mem_mgr(struct mfc_dev *dev);
void mfc_final_mem_mgr(struct mfc_dev *dev);

#endif /* __MFC_MEM_H_ */
