/* drivers/input/touchscreen/gt813_827_828.h
 * 
 * 2010 - 2012 Goodix Technology.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be a reference 
 * to you, when you are integrating the GOODiX's CTP IC into your system, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * General Public License for more details.
 * 
 * Version:1.0
 *      V1.0:2012/08/31,first release.
 */

#ifndef _LINUX_GOODIX_TOUCH_H
#define	_LINUX_GOODIX_TOUCH_H

#include <linux/kernel.h>
#include <linux/hrtimer.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <asm/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <mach/gpio.h>
#include <linux/earlysuspend.h>
#include <asm/gpio.h>
#include <linux/device.h>
#include <linux/platform_device.h>
//#include <plat/gpio-cfg.h>
//#include <plat/gpio-bank-l.h>
//#include <plat/gpio-bank-f.h>
#include <linux/irq.h>
//adding head files
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/spinlock.h>

struct goodix_ts_data 
    {spinlock_t irq_lock;
    struct i2c_client *client;
    struct input_dev  *input_dev;
    struct hrtimer timer;
    struct work_struct  work;
    struct early_suspend early_suspend;
    s32 irq_is_disable;
    s32 use_irq;
    u16 abs_x_max;
    u16 abs_y_max;
    u8  max_touch_num;
    u8  int_trigger_type;
    u8  green_wake_mode;
    u8  chip_type;
    u8  enter_update;
    u8  gtp_is_suspend;
    u8  gtp_rawdiff_mode;
    u8  gtp_cfg_len;
};

extern u16 show_len;
extern u16 total_len;

//***************************PART1:ON/OFF define*******************************
#define GTP_CUSTOM_CFG        0
#define GTP_DRIVER_SEND_CFG   1 
#define GTP_HAVE_TOUCH_KEY    0
#define GTP_POWER_CTRL_SLEEP  1
#define GTP_AUTO_UPDATE       0
//#define GTP_CHANGE_X2Y       1
#define GTP_ESD_PROTECT       1
#define GTP_CREATE_WR_NODE    1
#ifdef BOARD_V2
#define GTP_ICS_SLOT_REPORT   0
	
#else
#define GTP_ICS_SLOT_REPORT   1
#endif

#define GUP_USE_HEADER_FILE   0

#define GTP_DEBUG_ON          0
#define GTP_DEBUG_ARRAY_ON    0
#define GTP_DEBUG_FUNC_ON     0

//***************************PART2:TODO define**********************************
//STEP_1(REQUIRED):Change config table.
/*TODO: puts the config info corresponded to your TP here, the following is just 
a sample config, send this config should cause the chip cannot work normally*/
//default or float
//#define CTP_CFG_GROUP1      {0x42,0xE0,0x01,0x20,0x03,0x05,0x11,0x01,0x02,0x08,0x19,0x00,0x50,0x28,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x00,0x0A,0x48,0x00,0xF3,0x0D,0x00,0x00,0x00,0x9A,0x02,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x96,0x94,0x85,0x42,0x08,0x00,0x00,0xC1,0x11,0x1A,0xB3,0x15,0x1C,0xE6,0x1B,0x1C,0x0B,0x1E,0x1E,0x8D,0x20,0x21,0x00,0x00,0x10,0x28,0x48,0x00,0x5F,0x50,0x30,0xFF,0xFF,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x96,0x64,0x0F,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x0A,0x0C,0x0E,0x10,0x12,0x14,0x16,0x18,0x1A,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x05,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x22,0x24,0x28,0x29,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x1E,0x28,0x28,0x32,0x3C,0x3C,0x3C,0x50,0x50,0x50,0x32,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDB,0x01}
//#define CTP_CFG_GROUP1  {0x43,0xE0,0x01,0x20,0x03,0x05,0x34,0x80,0x01,0x3F,0x19,0x09,0x50,0x3C,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x18,0x1A,0x1E,0x14,0x87,0x28,0x0A,0x26,0x24,0xC1,0x11,0x00,0x00,0x00,0x03,0x02,0x25,0x00,0x01,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x64,0x96,0x94,0x05,0x02,0x08,0x00,0x00,0xA9,0x13,0x29,0x39,0x15,0x29,0xD5,0x14,0x2A,0x9D,0x15,0x30,0x9D,0x15,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC7,0x01}
//#define CTP_CFG_GROUP1   {0x43,0xE0,0x01,0x20,0x03,0x05,0x35,0x80,0x01,0x3F,0x19,0x09,0x50,0x3C,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x18,0x1A,0x1E,0x14,0x87,0x28,0x0A,0x26,0x24,0xC1,0x11,0x00,0x00,0x00,0x03,0x02,0x25,0x00,0x01,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x64,0x96,0x94,0x05,0x02,0x08,0x00,0x00,0xA9,0x13,0x29,0x39,0x15,0x29,0xD5,0x14,0x2A,0x9D,0x15,0x30,0x9D,0x15,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC6,0x01}
//#define  CTP_CFG_GROUP1  {0x43,0x58,0x02,0x00,0x04,0x05,0x35,0x80,0x01,0x3F,0x19,0x09,0x50,0x3C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x18,0x1A,0x1E,0x14,0x87,0x28,0x0A,0x26,0x24,0xC1,0x11,0x00,0x00,0x00,0x03,0x02,0x25,0x00,0x01,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x64,0x96,0x94,0x05,0x02,0x08,0x00,0x00,0xA9,0x13,0x29,0x39,0x15,0x29,0xD5,0x14,0x2A,0x9D,0x15,0x30,0x9D,0x15,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xCB,0x01}
//#define  CTP_CFG_GROUP1  {0x44,0x58,0x02,0x00,0x04,0x05,0x34,0x80,0x01,0x08,0x19,0x0F,0x50,0x3C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x87,0x28,0x0A,0x26,0x23,0xC1,0x11,0x00,0x00,0x00,0x03,0x02,0x25,0x00,0x01,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x64,0x96,0x94,0x05,0x02,0x08,0x00,0x00,0xA9,0x13,0x29,0x39,0x15,0x29,0xD5,0x14,0x2A,0x9D,0x15,0x30,0x9D,0x15,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA9,0x01}
//#define  CTP_CFG_GROUP1{0x45,0x58,0x02,0x00,0x04,0x05,0x34,0x00,0x03,0x2F,0x19,0x0F,0x64,0x3C,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x87,0x28,0x0A,0x26,0x24,0xC1,0x11,0x00,0x00,0x00,0x03,0x02,0x25,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x64,0x96,0x94,0x85,0x02,0x08,0x00,0x00,0xA9,0x13,0x29,0xD5,0x14,0x2A,0x9D,0x15,0x2C,0x71,0x14,0x2B,0x39,0x15,0x35,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x28,0x01}
#define  CTP_CFG_GROUP1{0x00,0x58,0x02,0x00,0x04,0x05,0x34,0x00,0x01,0x08,0x19,0x06,0x47,0x37,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8B,0x2B,0x0D,0x39,0x3D,0xC2,0x0F,0x00,0x00,0x00,0x98,0x03,0x2D,0x00,0x00,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x46,0xFA,0x94,0x85,0x02,0x07,0x00,0x00,0x69,0x0D,0x2E,0x89,0x10,0x30,0xA9,0x13,0x34,0x65,0x16,0x3C,0x91,0x17,0x49,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x35,0x01}
//TODO puts your group2 config info here,if need.
//VDDIO
#define CTP_CFG_GROUP2 {0x00,0x58,0x02,0x00,0x04,0x05,0x34,0x00,0x01,0x08,0x19,0x06,0x32,0x26,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8C,0x2D,0x0E,0x2E,0x32,0x88,0x13,0x00,0x00,0x00,0x9A,0x03,0x1D,0x00,0x00,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x46,0xAF,0x94,0x85,0x02,0x07,0x00,0x00,0x05,0x0D,0x2E,0x5D,0x0F,0x2F,0x51,0x11,0x32,0xA9,0x13,0x35,0x9D,0x15,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0x28,0x29,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x31,0x01 }
//TODO puts your group3 config info here,if need.
//GND
#define  CTP_CFG_GROUP3{0x00,0x58,0x02,0x00,0x04,0x05,0x04,0x00,0x01,0x08,0x19,0x0A,0x5A,0x32,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0x2E,0x0E,0x24,0x26,0x06,0x0F,0x00,0x00,0x01,0x9B,0x03,0x1D,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x4E,0x94,0x05,0x02,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x2A,0x29,0x28,0x26,0x24,0x22,0x21,0x20,0x1F,0x1E,0x1D,0x1C,0x18,0x16,0x14,0x13,0x12,0x10,0x0F,0x0C,0x0A,0x08,0x06,0x04,0x02,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x41,0x01}
//efine  CTP_CFG_GROUP4{0x00,0x58,0x02,0x00,0x04,0x05,0x34,0x00,0x01,0x08,0x14,0x06,0x37,0x28,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0x2C,0x0E,0x4A,0x45,0x31,0x0D,0x00,0x00,0x02,0xB9,0x02,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0x28,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6A,0x01}
#define CTP_CFG_GROUP4 {0x00,0x58,0x02,0x00,0x04,0x0A,0x34,0x00,0x01,0x0F,0x28,0x0F,0x50,0x3C,0x03,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8C,0x2B,0x0E,0x26,0x2A,0x6A,0x0D,0x00,0x00,0x00,0x01,0x03,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0x28,0x29,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x92,0x01 }

#define CTP_CFG_GROUP5 { 0x00,0x58,0x02,0x00,0x04,0x0A,0x34,0x00,0x01,0x0F,0x19,0x0F,0x54,0x42,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8C,0x2A,0x0D,0x2E,0x32,0x88,0x13,0x00,0x00,0x00,0x99,0x03,0x1D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x34,0x01}
#define CTP_CFG_GROUP6 {0x00,0x58,0x02,0x00,0x04,0x0A,0x34,0x00,0x01,0x0F,0x28,0x0F,0x50,0x3C,0x03,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8C,0x2D,0x0E,0x26,0x2A,0x6A,0x0D,0x00,0x00,0x00,0x01,0x03,0x2D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x24,0x26,0x28,0x29,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x4E,0x01 }
//STEP_2(REQUIRED):Change I/O define & I/O operation mode.
#define GTP_RST_PORT   27  //S5PV210_GPJ3(6)
#define GTP_INT_PORT    48
#define GTP_INT_IRQ     MSM_GPIO_TO_INT(GTP_INT_PORT)
//#define GTP_INT_CFG     S3C_GPIO_SFN(0xF)

#define GTP_GPIO_AS_INPUT(pin)          do{\
                                            gpio_tlmm_config(GPIO_CFG(pin, 0, GPIO_CFG_INPUT, GPIO_CFG_NO_PULL, GPIO_CFG_8MA), GPIO_CFG_ENABLE);\
                                            gpio_direction_input(pin);\						
                                        }while(0)
/*#define GTP_GPIO_AS_INT(pin)            do{\
                                            GTP_GPIO_AS_INPUT(pin);\
                                            s3c_gpio_cfgpin(pin, GTP_INT_CFG);\
                                        }while(0)*/
#define GTP_GPIO_GET_VALUE(pin)         gpio_get_value(pin)
#define GTP_GPIO_OUTPUT(pin,level)      gpio_direction_output(pin,level)
#define GTP_GPIO_REQUEST(pin, label)    gpio_request(pin, label)
#define GTP_GPIO_FREE(pin)              gpio_free(pin)
#define GTP_IRQ_TAB                     {IRQ_TYPE_EDGE_RISING, IRQ_TYPE_EDGE_FALLING, IRQ_TYPE_LEVEL_LOW, IRQ_TYPE_LEVEL_HIGH}

//STEP_3(optional):Custom set some config by themself,if need.
#if GTP_CUSTOM_CFG
  #define GTP_MAX_HEIGHT   800
  #define GTP_MAX_WIDTH    480
  #define GTP_INT_TRIGGER  0    //0:Rising 1:Falling
#else
  #define GTP_MAX_HEIGHT   4096
  #define GTP_MAX_WIDTH    4096
  #define GTP_INT_TRIGGER  1
#endif
#define GTP_MAX_TOUCH         5
#define GTP_ESD_CHECK_CIRCLE  2000

//STEP_4(optional):If this project have touch key,Set touch key config.                                    
#if GTP_HAVE_TOUCH_KEY
    #define GTP_KEY_TAB	 {KEY_MENU, KEY_HOME, KEY_BACK, KEY_SEND}
#endif

//***************************PART3:OTHER define*********************************
#define GTP_DRIVER_VERSION    "V1.2<2012/10/25>"
#define GTP_I2C_NAME          "ft5x06_ts"
#define GTP_POLL_TIME         10
#define GTP_ADDR_LENGTH       2
#define GTP_CONFIG_MAX_LENGTH 240
#define FAIL                  0
#define SUCCESS               1

//Register define
#define GTP_READ_COOR_ADDR    0x814E
#define GTP_REG_SLEEP         0x8040
#define GTP_REG_SENSOR_ID     0x814A
#define GTP_REG_CONFIG_DATA   0x8047
#define GTP_REG_VERSION       0x8140

#define RESOLUTION_LOC        3
#define TRIGGER_LOC           8

//Log define
#define GTP_INFO(fmt,arg...)           printk("<<-GTP-INFO->> "fmt"\n",##arg)
#define GTP_ERROR(fmt,arg...)          printk("<<-GTP-ERROR->> "fmt"\n",##arg)
#define GTP_DEBUG(fmt,arg...)          do{\
                                         if(GTP_DEBUG_ON)\
                                         printk("<<-GTP-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                       }while(0)
#define GTP_DEBUG_ARRAY(array, num)    do{\
                                         s32 i;\
                                         u8* a = array;\
                                         if(GTP_DEBUG_ARRAY_ON)\
                                         {\
                                            printk("<<-GTP-DEBUG-ARRAY->>\n");\
                                            for (i = 0; i < (num); i++)\
                                            {\
                                                printk("%02x   ", (a)[i]);\
                                                if ((i + 1 ) %10 == 0)\
                                                {\
                                                    printk("\n");\
                                                }\
                                            }\
                                            printk("\n");\
                                        }\
                                       }while(0)
#define GTP_DEBUG_FUNC()               do{\
                                         if(GTP_DEBUG_FUNC_ON)\
                                         printk("<<-GTP-FUNC->> Func:%s@Line:%d\n",__func__,__LINE__);\
                                       }while(0)
#define GTP_SWAP(x, y)                 do{\
                                         typeof(x) z = x;\
                                         x = y;\
                                         y = z;\
                                       }while (0)

//****************************PART4:UPDATE define*******************************
//Error no
#define ERROR_NO_FILE           2   //ENOENT
#define ERROR_FILE_READ         23  //ENFILE
#define ERROR_FILE_TYPE         21  //EISDIR
#define ERROR_GPIO_REQUEST      4   //EINTR
#define ERROR_I2C_TRANSFER      5   //EIO
#define ERROR_NO_RESPONSE       16  //EBUSY
#define ERROR_TIMEOUT           110 //ETIMEDOUT

//*****************************End of Part III********************************

#endif /* _LINUX_GOODIX_TOUCH_H */
