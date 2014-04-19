#ifndef __VIDEO_CONFIG_TAB__
#define __VIDEO_CONFIG_TAB__
/**************************************************************--V1--***********************************************************************/
#ifdef BOARD_V1 // V1
#pragma message("目前硬件版本是：V1")
const u8 Image_Config[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {	0xe9,		0Xf0,		0xf1,		0xf2,		0xf3,		0xf5,		0xf6,		0xf7,	       0xf8,		0xf9,		0xfd,}, //BRIGHTNESS ed
    {	0x40,		0x45,		0x50,		0x5a,		0x65,       	 0x6e,		0x78,		0x85,		0x94,		0x9f,		0xa5,},//CONTRAST 9f
    {	0x81,		0x96,		0xb9,		0xdf,		0xe7,		0xff,		0x0,   		0xa,			0x35,		0x63,		0x7f,},//HUE
    {	0x0,			0x15,		0x30,		0x45,		0x65,		0x7f,		0x95,		0xa5,		0xd5,		0xe0,		0xff,},//SHARPNESS
    {	0x0,			0x15,		0x30,		0x45,		0x65,		0x7f,		0x95,		0xa5,		0xd5,		0xe0,		0xff,},//SHARPNESS
};
static u8 Tw9912_image_global[5][2] =
{
    {0x10, 0xf5}, //BRIGHTNESS
    {0x11, 0x6e}, //CONTRAST

    {0x15, 0xff}, //HUE
    {0x13, 0x7f}, //SHARPNESS
    {0x14, 0x7f}, //SHARPNESS
};
const u8 Image_Config_AUX_BACK[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {	0x15,		0X0f, 		0x09,		0x05,		0x03,		0xff,		0xfa,		0xf0,		0xe9,	       0xe0,		0xc9,}, //BRIGHTNESS
    {	0x39,		0x40,		0x45,		0x50,		0x59,		0x60,		0x65,		0x6a,		0x75,		0x8a,		0x90,},//CONTRAST
    {	0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {	0x30,		0x40,		0x50,		0x60,		0x70,		0x80,		0x90,		0xa0,		0xb0,		0xc0,		0xd0,},//SHARPNESS
    {	0x30,		0x40,		0x50,		0x60,		0x70,		0x80,		0x90,		0xa0,		0xb0,		0xc0,		0xd0,},//SHARPNESS
};
static u8 Tw9912_image_global_AUX_BACK[5][2] =
{
    {0x10, 0xff}, //BRIGHTNESS
    {0x11, 0x60}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0x80}, //SHARPNESS
    {0x14, 0x80}, //SHARPNESS
};
const u8 Image_Config_AUX_BACK_PAL_I[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {	0x15,		0X0f, 		0x09,		0x05,		0x03,		0x05,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {	0x25,		0x30,		0x35,		0x39,		0x40,		0x44,		0x45,		0x50,		0x59,		0x65,		0x6a,},//CONTRAST
    {	0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {	0x50,		0x60,		0x70,		0x80,		0x90,		0xa0,		0xb0,		0xc0,		0xd0,		0xe0,		0xf0,},//SHARPNESS
    {	0x50,		0x60,		0x70,		0x80,		0x90,		0xa0,		0xb0,		0xc0,		0xd0,		0xe0,		0xf0,},//SHARPNESS
};
static u8 Tw9912_image_global_AUX_BACK_PAL_I[5][2] =
{
    {0x10, 0x05}, //BRIGHTNESS
    {0x11, 0x44}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0xa0}, //SHARPNESS
    {0x14, 0xa0}, //SHARPNESS
};
#endif
/**************************************************************--V2--NTSCi***********************************************************************/
#ifdef BOARD_V2// V2
#pragma message("目前硬件版本是：V2")
const u8 Image_Config_AUX_BACK[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x00,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,		0x35,		0x39,		0x40,		0x45,		0x58,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
};

static u8 Tw9912_image_global_AUX_BACK[5][2] =//NTSC_i
{
    {0x10, 0x00}, //BRIGHTNESS
    {0x11, 0x58}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0xb0}, //SHARPNESS
    {0x14, 0xb0}, //SHARPNESS
};

/**************************************************************--V2--PALi***********************************************************************/

const u8 Image_Config_AUX_BACK_PAL_I[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {	0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x00,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,			0x35,		0x39,		0x40,		0x45,		0x58,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {	0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
};

static u8 Tw9912_image_global_AUX_BACK_PAL_I[5][2] =//PAL_i
{
    {0x10, 0x00}, //BRIGHTNESS
    {0x11, 0x58}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0xb0}, //SHARPNESS
    {0x14, 0xb0}, //SHARPNESS
};

#else// BOARD_V3// V3
#pragma message("目前硬件版本是：V3")

#ifndef BOARD_V3
#pragma message("目前硬件版本是：V3以上，请注意该处的参数设置,是否满足要求")
#endif

const u8 Image_Config_AUX_BACK[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x00,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,		0x35,		0x39,		0x40,		0x45,		0x6a,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xf0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xf0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
};

const u8 Image_Config_CarBacking_Normal[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x00,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,		0x35,		0x39,		0x40,		0x45,		0x61,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
//    {0x00,		0x44,		0x66,		0x88,		0xa5,		0xff, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
//    {0x00,		0x44,		0x66,		0x88,		0xa5,		0xff, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,		0x19,		0x32,		0x4b,		0x64,		0x7d, 		0x96,		0xaf,		0xc8,		0xe1,		0xff,},//SHARPNESS
    {0x00,		0x19,		0x32,		0x4b,		0x64,		0x7d, 		0x96,		0xaf,		0xc8,		0xe1,		0xff,},//SHARPNESS
};

const u8 Image_Config_CarBacking_NewTeana[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x15,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,		0x35,		0x39,		0x40,		0x45,		0x61,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
//    {0x00,		0x44,		0x66,		0x88,		0xa5,		0xff, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
//    {0x00,		0x44,		0x66,		0x88,		0xa5,		0xff, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,		0x19,		0x32,		0x4b,		0x64,		0x7d, 		0x96,		0xaf,		0xc8,		0xe1,		0xff,},//SHARPNESS
    {0x00,		0x19,		0x32,		0x4b,		0x64,		0x7d, 		0x96,		0xaf,		0xc8,		0xe1,		0xff,},//SHARPNESS
};

static u8 Tw9912_image_global_AUX_BACK[5][2] =//NTSC_i
{
    {0x10, 0x00}, //BRIGHTNESS
    {0x11, 0x58}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0xb0}, //SHARPNESS
    {0x14, 0xb0}, //SHARPNESS
};

/**************************************************************--V3--PALi***********************************************************************/

const u8 Image_Config_AUX_BACK_PAL_I[5][11] =
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*.....*//*8*//*......*//*9*//*....*//*10*/
    {	0x2f,		0x20,		0x15,		0X0f, 		0x09,		0x00,		0xfa,		0xf0,		0xe9,	        0xe0,		0xc9,}, //BRIGHTNESS
    {0x33,			0x35,		0x39,		0x40,		0x45,		0x58,		0x92,		0xaa,		0xb2,		0xc2,		0xd2,},//CONTRAST
    {	0xa9,		0xb5,		0xc5,		0xe0,		0xf1,		0x00,		0x20,		0x30,		0x40,		0x50,		0x60,},//HUE
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
    {0x00,			0x44,		0x66,		0x88,		0xa5,		0xb0, 		0xbf,		0xc5,		0xcf,		0xdf,		0xff,},//SHARPNESS
};

static u8 Tw9912_image_global_AUX_BACK_PAL_I[5][2] =//PAL_i
{
    {0x10, 0x00}, //BRIGHTNESS
    {0x11, 0x58}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0xb0}, //SHARPNESS
    {0x14, 0xb0}, //SHARPNESS
};

#endif

/**************************************************************--V2-or-V3--YUV--***********************************************************************/

const u8 Image_Config_separation[5][11] = //DVD separation
{
    /*0*//*.....*//*1*//*......*//*2*//*.....*//*3*//*......*//*4*//*....*//*5*//*......*//*6*//*.....*//*7*//*......*//*8*//*.......*//*9*//*......*//*10*/
    {	0x01,     		0x02,		0x03,		0x04,		0x06,		0x07,		0x0e,		0x0f,		0x10,		0x11,		0x12,},//BRIGHTNESS
    {	0x55,		0x59,		0x5a,		0x60,		0X6a,		0x71,		0x7f,		0x85,		0x89,	       0x8f,		0x95,},//CONTRAST
    {	0xb9,		0xe0,		0xf0,		0xf5,		0xf9,		0x00,		0x05,   		0x10,		0x1f,		0x2f,		0x3f,},//HUE
    {	0x00,		0x22,		0x5f,		0x6f,		0x8f,		0x9e, 		0xaf,		0xbf,		0xdf,		0xcf,		0xff,},//SHARPNESS
    {	0x00,		0x22,		0x5f,		0x6f,		0x8f,		0x9e, 		0xaf,		0xbf,		0xdf,		0xcf,		0xff,},//SHARPNESS
};
static u8 Tw9912_image_global_separation[5][2] = //DVD separation
{
    {0xd9, 0x07}, //BRIGHTNESS
    {0x11, 0x71}, //CONTRAST

    {0x15, 0x00}, //HUE
    {0x13, 0x9e}, //SHARPNESS
    {0x14, 0x9e}, //SHARPNESS
};

#endif

