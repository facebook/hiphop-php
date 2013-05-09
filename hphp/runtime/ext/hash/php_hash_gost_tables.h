/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
static const unsigned int tables[4][256] = {
	{ /* table 1 */
		0x00072000LU, 0x00075000LU, 0x00074800LU, 0x00071000LU, 0x00076800LU, 0x00074000LU, 0x00070000LU, 0x00077000LU,
		0x00073000LU, 0x00075800LU, 0x00070800LU, 0x00076000LU, 0x00073800LU, 0x00077800LU, 0x00072800LU, 0x00071800LU,
		0x0005A000LU, 0x0005D000LU, 0x0005C800LU, 0x00059000LU, 0x0005E800LU, 0x0005C000LU, 0x00058000LU, 0x0005F000LU,
		0x0005B000LU, 0x0005D800LU, 0x00058800LU, 0x0005E000LU, 0x0005B800LU, 0x0005F800LU, 0x0005A800LU, 0x00059800LU,
		0x00022000LU, 0x00025000LU, 0x00024800LU, 0x00021000LU, 0x00026800LU, 0x00024000LU, 0x00020000LU, 0x00027000LU,
		0x00023000LU, 0x00025800LU, 0x00020800LU, 0x00026000LU, 0x00023800LU, 0x00027800LU, 0x00022800LU, 0x00021800LU,
		0x00062000LU, 0x00065000LU, 0x00064800LU, 0x00061000LU, 0x00066800LU, 0x00064000LU, 0x00060000LU, 0x00067000LU,
		0x00063000LU, 0x00065800LU, 0x00060800LU, 0x00066000LU, 0x00063800LU, 0x00067800LU, 0x00062800LU, 0x00061800LU,
		0x00032000LU, 0x00035000LU, 0x00034800LU, 0x00031000LU, 0x00036800LU, 0x00034000LU, 0x00030000LU, 0x00037000LU,
		0x00033000LU, 0x00035800LU, 0x00030800LU, 0x00036000LU, 0x00033800LU, 0x00037800LU, 0x00032800LU, 0x00031800LU,
		0x0006A000LU, 0x0006D000LU, 0x0006C800LU, 0x00069000LU, 0x0006E800LU, 0x0006C000LU, 0x00068000LU, 0x0006F000LU,
		0x0006B000LU, 0x0006D800LU, 0x00068800LU, 0x0006E000LU, 0x0006B800LU, 0x0006F800LU, 0x0006A800LU, 0x00069800LU,
		0x0007A000LU, 0x0007D000LU, 0x0007C800LU, 0x00079000LU, 0x0007E800LU, 0x0007C000LU, 0x00078000LU, 0x0007F000LU,
		0x0007B000LU, 0x0007D800LU, 0x00078800LU, 0x0007E000LU, 0x0007B800LU, 0x0007F800LU, 0x0007A800LU, 0x00079800LU,
		0x00052000LU, 0x00055000LU, 0x00054800LU, 0x00051000LU, 0x00056800LU, 0x00054000LU, 0x00050000LU, 0x00057000LU,
		0x00053000LU, 0x00055800LU, 0x00050800LU, 0x00056000LU, 0x00053800LU, 0x00057800LU, 0x00052800LU, 0x00051800LU,
		0x00012000LU, 0x00015000LU, 0x00014800LU, 0x00011000LU, 0x00016800LU, 0x00014000LU, 0x00010000LU, 0x00017000LU,
		0x00013000LU, 0x00015800LU, 0x00010800LU, 0x00016000LU, 0x00013800LU, 0x00017800LU, 0x00012800LU, 0x00011800LU,
		0x0001A000LU, 0x0001D000LU, 0x0001C800LU, 0x00019000LU, 0x0001E800LU, 0x0001C000LU, 0x00018000LU, 0x0001F000LU,
		0x0001B000LU, 0x0001D800LU, 0x00018800LU, 0x0001E000LU, 0x0001B800LU, 0x0001F800LU, 0x0001A800LU, 0x00019800LU,
		0x00042000LU, 0x00045000LU, 0x00044800LU, 0x00041000LU, 0x00046800LU, 0x00044000LU, 0x00040000LU, 0x00047000LU,
		0x00043000LU, 0x00045800LU, 0x00040800LU, 0x00046000LU, 0x00043800LU, 0x00047800LU, 0x00042800LU, 0x00041800LU,
		0x0000A000LU, 0x0000D000LU, 0x0000C800LU, 0x00009000LU, 0x0000E800LU, 0x0000C000LU, 0x00008000LU, 0x0000F000LU,
		0x0000B000LU, 0x0000D800LU, 0x00008800LU, 0x0000E000LU, 0x0000B800LU, 0x0000F800LU, 0x0000A800LU, 0x00009800LU,
		0x00002000LU, 0x00005000LU, 0x00004800LU, 0x00001000LU, 0x00006800LU, 0x00004000LU, 0x00000000LU, 0x00007000LU,
		0x00003000LU, 0x00005800LU, 0x00000800LU, 0x00006000LU, 0x00003800LU, 0x00007800LU, 0x00002800LU, 0x00001800LU,
		0x0003A000LU, 0x0003D000LU, 0x0003C800LU, 0x00039000LU, 0x0003E800LU, 0x0003C000LU, 0x00038000LU, 0x0003F000LU,
		0x0003B000LU, 0x0003D800LU, 0x00038800LU, 0x0003E000LU, 0x0003B800LU, 0x0003F800LU, 0x0003A800LU, 0x00039800LU,
		0x0002A000LU, 0x0002D000LU, 0x0002C800LU, 0x00029000LU, 0x0002E800LU, 0x0002C000LU, 0x00028000LU, 0x0002F000LU,
		0x0002B000LU, 0x0002D800LU, 0x00028800LU, 0x0002E000LU, 0x0002B800LU, 0x0002F800LU, 0x0002A800LU, 0x00029800LU,
		0x0004A000LU, 0x0004D000LU, 0x0004C800LU, 0x00049000LU, 0x0004E800LU, 0x0004C000LU, 0x00048000LU, 0x0004F000LU,
		0x0004B000LU, 0x0004D800LU, 0x00048800LU, 0x0004E000LU, 0x0004B800LU, 0x0004F800LU, 0x0004A800LU, 0x00049800LU,
	},
	{ /* table 2 */
		0x03A80000LU, 0x03C00000LU, 0x03880000LU, 0x03E80000LU, 0x03D00000LU, 0x03980000LU, 0x03A00000LU, 0x03900000LU,
		0x03F00000LU, 0x03F80000LU, 0x03E00000LU, 0x03B80000LU, 0x03B00000LU, 0x03800000LU, 0x03C80000LU, 0x03D80000LU,
		0x06A80000LU, 0x06C00000LU, 0x06880000LU, 0x06E80000LU, 0x06D00000LU, 0x06980000LU, 0x06A00000LU, 0x06900000LU,
		0x06F00000LU, 0x06F80000LU, 0x06E00000LU, 0x06B80000LU, 0x06B00000LU, 0x06800000LU, 0x06C80000LU, 0x06D80000LU,
		0x05280000LU, 0x05400000LU, 0x05080000LU, 0x05680000LU, 0x05500000LU, 0x05180000LU, 0x05200000LU, 0x05100000LU,
		0x05700000LU, 0x05780000LU, 0x05600000LU, 0x05380000LU, 0x05300000LU, 0x05000000LU, 0x05480000LU, 0x05580000LU,
		0x00A80000LU, 0x00C00000LU, 0x00880000LU, 0x00E80000LU, 0x00D00000LU, 0x00980000LU, 0x00A00000LU, 0x00900000LU,
		0x00F00000LU, 0x00F80000LU, 0x00E00000LU, 0x00B80000LU, 0x00B00000LU, 0x00800000LU, 0x00C80000LU, 0x00D80000LU,
		0x00280000LU, 0x00400000LU, 0x00080000LU, 0x00680000LU, 0x00500000LU, 0x00180000LU, 0x00200000LU, 0x00100000LU,
		0x00700000LU, 0x00780000LU, 0x00600000LU, 0x00380000LU, 0x00300000LU, 0x00000000LU, 0x00480000LU, 0x00580000LU,
		0x04280000LU, 0x04400000LU, 0x04080000LU, 0x04680000LU, 0x04500000LU, 0x04180000LU, 0x04200000LU, 0x04100000LU,
		0x04700000LU, 0x04780000LU, 0x04600000LU, 0x04380000LU, 0x04300000LU, 0x04000000LU, 0x04480000LU, 0x04580000LU,
		0x04A80000LU, 0x04C00000LU, 0x04880000LU, 0x04E80000LU, 0x04D00000LU, 0x04980000LU, 0x04A00000LU, 0x04900000LU,
		0x04F00000LU, 0x04F80000LU, 0x04E00000LU, 0x04B80000LU, 0x04B00000LU, 0x04800000LU, 0x04C80000LU, 0x04D80000LU,
		0x07A80000LU, 0x07C00000LU, 0x07880000LU, 0x07E80000LU, 0x07D00000LU, 0x07980000LU, 0x07A00000LU, 0x07900000LU,
		0x07F00000LU, 0x07F80000LU, 0x07E00000LU, 0x07B80000LU, 0x07B00000LU, 0x07800000LU, 0x07C80000LU, 0x07D80000LU,
		0x07280000LU, 0x07400000LU, 0x07080000LU, 0x07680000LU, 0x07500000LU, 0x07180000LU, 0x07200000LU, 0x07100000LU,
		0x07700000LU, 0x07780000LU, 0x07600000LU, 0x07380000LU, 0x07300000LU, 0x07000000LU, 0x07480000LU, 0x07580000LU,
		0x02280000LU, 0x02400000LU, 0x02080000LU, 0x02680000LU, 0x02500000LU, 0x02180000LU, 0x02200000LU, 0x02100000LU,
		0x02700000LU, 0x02780000LU, 0x02600000LU, 0x02380000LU, 0x02300000LU, 0x02000000LU, 0x02480000LU, 0x02580000LU,
		0x03280000LU, 0x03400000LU, 0x03080000LU, 0x03680000LU, 0x03500000LU, 0x03180000LU, 0x03200000LU, 0x03100000LU,
		0x03700000LU, 0x03780000LU, 0x03600000LU, 0x03380000LU, 0x03300000LU, 0x03000000LU, 0x03480000LU, 0x03580000LU,
		0x06280000LU, 0x06400000LU, 0x06080000LU, 0x06680000LU, 0x06500000LU, 0x06180000LU, 0x06200000LU, 0x06100000LU,
		0x06700000LU, 0x06780000LU, 0x06600000LU, 0x06380000LU, 0x06300000LU, 0x06000000LU, 0x06480000LU, 0x06580000LU,
		0x05A80000LU, 0x05C00000LU, 0x05880000LU, 0x05E80000LU, 0x05D00000LU, 0x05980000LU, 0x05A00000LU, 0x05900000LU,
		0x05F00000LU, 0x05F80000LU, 0x05E00000LU, 0x05B80000LU, 0x05B00000LU, 0x05800000LU, 0x05C80000LU, 0x05D80000LU,
		0x01280000LU, 0x01400000LU, 0x01080000LU, 0x01680000LU, 0x01500000LU, 0x01180000LU, 0x01200000LU, 0x01100000LU,
		0x01700000LU, 0x01780000LU, 0x01600000LU, 0x01380000LU, 0x01300000LU, 0x01000000LU, 0x01480000LU, 0x01580000LU,
		0x02A80000LU, 0x02C00000LU, 0x02880000LU, 0x02E80000LU, 0x02D00000LU, 0x02980000LU, 0x02A00000LU, 0x02900000LU,
		0x02F00000LU, 0x02F80000LU, 0x02E00000LU, 0x02B80000LU, 0x02B00000LU, 0x02800000LU, 0x02C80000LU, 0x02D80000LU,
		0x01A80000LU, 0x01C00000LU, 0x01880000LU, 0x01E80000LU, 0x01D00000LU, 0x01980000LU, 0x01A00000LU, 0x01900000LU,
		0x01F00000LU, 0x01F80000LU, 0x01E00000LU, 0x01B80000LU, 0x01B00000LU, 0x01800000LU, 0x01C80000LU, 0x01D80000LU,
	},
	{ /* table 3 */
		0x30000002LU, 0x60000002LU, 0x38000002LU, 0x08000002LU, 0x28000002LU, 0x78000002LU, 0x68000002LU, 0x40000002LU,
		0x20000002LU, 0x50000002LU, 0x48000002LU, 0x70000002LU, 0x00000002LU, 0x18000002LU, 0x58000002LU, 0x10000002LU,
		0xB0000005LU, 0xE0000005LU, 0xB8000005LU, 0x88000005LU, 0xA8000005LU, 0xF8000005LU, 0xE8000005LU, 0xC0000005LU,
		0xA0000005LU, 0xD0000005LU, 0xC8000005LU, 0xF0000005LU, 0x80000005LU, 0x98000005LU, 0xD8000005LU, 0x90000005LU,
		0x30000005LU, 0x60000005LU, 0x38000005LU, 0x08000005LU, 0x28000005LU, 0x78000005LU, 0x68000005LU, 0x40000005LU,
		0x20000005LU, 0x50000005LU, 0x48000005LU, 0x70000005LU, 0x00000005LU, 0x18000005LU, 0x58000005LU, 0x10000005LU,
		0x30000000LU, 0x60000000LU, 0x38000000LU, 0x08000000LU, 0x28000000LU, 0x78000000LU, 0x68000000LU, 0x40000000LU,
		0x20000000LU, 0x50000000LU, 0x48000000LU, 0x70000000LU, 0x00000000LU, 0x18000000LU, 0x58000000LU, 0x10000000LU,
		0xB0000003LU, 0xE0000003LU, 0xB8000003LU, 0x88000003LU, 0xA8000003LU, 0xF8000003LU, 0xE8000003LU, 0xC0000003LU,
		0xA0000003LU, 0xD0000003LU, 0xC8000003LU, 0xF0000003LU, 0x80000003LU, 0x98000003LU, 0xD8000003LU, 0x90000003LU,
		0x30000001LU, 0x60000001LU, 0x38000001LU, 0x08000001LU, 0x28000001LU, 0x78000001LU, 0x68000001LU, 0x40000001LU,
		0x20000001LU, 0x50000001LU, 0x48000001LU, 0x70000001LU, 0x00000001LU, 0x18000001LU, 0x58000001LU, 0x10000001LU,
		0xB0000000LU, 0xE0000000LU, 0xB8000000LU, 0x88000000LU, 0xA8000000LU, 0xF8000000LU, 0xE8000000LU, 0xC0000000LU,
		0xA0000000LU, 0xD0000000LU, 0xC8000000LU, 0xF0000000LU, 0x80000000LU, 0x98000000LU, 0xD8000000LU, 0x90000000LU,
		0xB0000006LU, 0xE0000006LU, 0xB8000006LU, 0x88000006LU, 0xA8000006LU, 0xF8000006LU, 0xE8000006LU, 0xC0000006LU,
		0xA0000006LU, 0xD0000006LU, 0xC8000006LU, 0xF0000006LU, 0x80000006LU, 0x98000006LU, 0xD8000006LU, 0x90000006LU,
		0xB0000001LU, 0xE0000001LU, 0xB8000001LU, 0x88000001LU, 0xA8000001LU, 0xF8000001LU, 0xE8000001LU, 0xC0000001LU,
		0xA0000001LU, 0xD0000001LU, 0xC8000001LU, 0xF0000001LU, 0x80000001LU, 0x98000001LU, 0xD8000001LU, 0x90000001LU,
		0x30000003LU, 0x60000003LU, 0x38000003LU, 0x08000003LU, 0x28000003LU, 0x78000003LU, 0x68000003LU, 0x40000003LU,
		0x20000003LU, 0x50000003LU, 0x48000003LU, 0x70000003LU, 0x00000003LU, 0x18000003LU, 0x58000003LU, 0x10000003LU,
		0x30000004LU, 0x60000004LU, 0x38000004LU, 0x08000004LU, 0x28000004LU, 0x78000004LU, 0x68000004LU, 0x40000004LU,
		0x20000004LU, 0x50000004LU, 0x48000004LU, 0x70000004LU, 0x00000004LU, 0x18000004LU, 0x58000004LU, 0x10000004LU,
		0xB0000002LU, 0xE0000002LU, 0xB8000002LU, 0x88000002LU, 0xA8000002LU, 0xF8000002LU, 0xE8000002LU, 0xC0000002LU,
		0xA0000002LU, 0xD0000002LU, 0xC8000002LU, 0xF0000002LU, 0x80000002LU, 0x98000002LU, 0xD8000002LU, 0x90000002LU,
		0xB0000004LU, 0xE0000004LU, 0xB8000004LU, 0x88000004LU, 0xA8000004LU, 0xF8000004LU, 0xE8000004LU, 0xC0000004LU,
		0xA0000004LU, 0xD0000004LU, 0xC8000004LU, 0xF0000004LU, 0x80000004LU, 0x98000004LU, 0xD8000004LU, 0x90000004LU,
		0x30000006LU, 0x60000006LU, 0x38000006LU, 0x08000006LU, 0x28000006LU, 0x78000006LU, 0x68000006LU, 0x40000006LU,
		0x20000006LU, 0x50000006LU, 0x48000006LU, 0x70000006LU, 0x00000006LU, 0x18000006LU, 0x58000006LU, 0x10000006LU,
		0xB0000007LU, 0xE0000007LU, 0xB8000007LU, 0x88000007LU, 0xA8000007LU, 0xF8000007LU, 0xE8000007LU, 0xC0000007LU,
		0xA0000007LU, 0xD0000007LU, 0xC8000007LU, 0xF0000007LU, 0x80000007LU, 0x98000007LU, 0xD8000007LU, 0x90000007LU,
		0x30000007LU, 0x60000007LU, 0x38000007LU, 0x08000007LU, 0x28000007LU, 0x78000007LU, 0x68000007LU, 0x40000007LU,
		0x20000007LU, 0x50000007LU, 0x48000007LU, 0x70000007LU, 0x00000007LU, 0x18000007LU, 0x58000007LU, 0x10000007LU,
	},
	{ /* table 4 */
		0x000000E8LU, 0x000000D8LU, 0x000000A0LU, 0x00000088LU, 0x00000098LU, 0x000000F8LU, 0x000000A8LU, 0x000000C8LU,
		0x00000080LU, 0x000000D0LU, 0x000000F0LU, 0x000000B8LU, 0x000000B0LU, 0x000000C0LU, 0x00000090LU, 0x000000E0LU,
		0x000007E8LU, 0x000007D8LU, 0x000007A0LU, 0x00000788LU, 0x00000798LU, 0x000007F8LU, 0x000007A8LU, 0x000007C8LU,
		0x00000780LU, 0x000007D0LU, 0x000007F0LU, 0x000007B8LU, 0x000007B0LU, 0x000007C0LU, 0x00000790LU, 0x000007E0LU,
		0x000006E8LU, 0x000006D8LU, 0x000006A0LU, 0x00000688LU, 0x00000698LU, 0x000006F8LU, 0x000006A8LU, 0x000006C8LU,
		0x00000680LU, 0x000006D0LU, 0x000006F0LU, 0x000006B8LU, 0x000006B0LU, 0x000006C0LU, 0x00000690LU, 0x000006E0LU,
		0x00000068LU, 0x00000058LU, 0x00000020LU, 0x00000008LU, 0x00000018LU, 0x00000078LU, 0x00000028LU, 0x00000048LU,
		0x00000000LU, 0x00000050LU, 0x00000070LU, 0x00000038LU, 0x00000030LU, 0x00000040LU, 0x00000010LU, 0x00000060LU,
		0x000002E8LU, 0x000002D8LU, 0x000002A0LU, 0x00000288LU, 0x00000298LU, 0x000002F8LU, 0x000002A8LU, 0x000002C8LU,
		0x00000280LU, 0x000002D0LU, 0x000002F0LU, 0x000002B8LU, 0x000002B0LU, 0x000002C0LU, 0x00000290LU, 0x000002E0LU,
		0x000003E8LU, 0x000003D8LU, 0x000003A0LU, 0x00000388LU, 0x00000398LU, 0x000003F8LU, 0x000003A8LU, 0x000003C8LU,
		0x00000380LU, 0x000003D0LU, 0x000003F0LU, 0x000003B8LU, 0x000003B0LU, 0x000003C0LU, 0x00000390LU, 0x000003E0LU,
		0x00000568LU, 0x00000558LU, 0x00000520LU, 0x00000508LU, 0x00000518LU, 0x00000578LU, 0x00000528LU, 0x00000548LU,
		0x00000500LU, 0x00000550LU, 0x00000570LU, 0x00000538LU, 0x00000530LU, 0x00000540LU, 0x00000510LU, 0x00000560LU,
		0x00000268LU, 0x00000258LU, 0x00000220LU, 0x00000208LU, 0x00000218LU, 0x00000278LU, 0x00000228LU, 0x00000248LU,
		0x00000200LU, 0x00000250LU, 0x00000270LU, 0x00000238LU, 0x00000230LU, 0x00000240LU, 0x00000210LU, 0x00000260LU,
		0x000004E8LU, 0x000004D8LU, 0x000004A0LU, 0x00000488LU, 0x00000498LU, 0x000004F8LU, 0x000004A8LU, 0x000004C8LU,
		0x00000480LU, 0x000004D0LU, 0x000004F0LU, 0x000004B8LU, 0x000004B0LU, 0x000004C0LU, 0x00000490LU, 0x000004E0LU,
		0x00000168LU, 0x00000158LU, 0x00000120LU, 0x00000108LU, 0x00000118LU, 0x00000178LU, 0x00000128LU, 0x00000148LU,
		0x00000100LU, 0x00000150LU, 0x00000170LU, 0x00000138LU, 0x00000130LU, 0x00000140LU, 0x00000110LU, 0x00000160LU,
		0x000001E8LU, 0x000001D8LU, 0x000001A0LU, 0x00000188LU, 0x00000198LU, 0x000001F8LU, 0x000001A8LU, 0x000001C8LU,
		0x00000180LU, 0x000001D0LU, 0x000001F0LU, 0x000001B8LU, 0x000001B0LU, 0x000001C0LU, 0x00000190LU, 0x000001E0LU,
		0x00000768LU, 0x00000758LU, 0x00000720LU, 0x00000708LU, 0x00000718LU, 0x00000778LU, 0x00000728LU, 0x00000748LU,
		0x00000700LU, 0x00000750LU, 0x00000770LU, 0x00000738LU, 0x00000730LU, 0x00000740LU, 0x00000710LU, 0x00000760LU,
		0x00000368LU, 0x00000358LU, 0x00000320LU, 0x00000308LU, 0x00000318LU, 0x00000378LU, 0x00000328LU, 0x00000348LU,
		0x00000300LU, 0x00000350LU, 0x00000370LU, 0x00000338LU, 0x00000330LU, 0x00000340LU, 0x00000310LU, 0x00000360LU,
		0x000005E8LU, 0x000005D8LU, 0x000005A0LU, 0x00000588LU, 0x00000598LU, 0x000005F8LU, 0x000005A8LU, 0x000005C8LU,
		0x00000580LU, 0x000005D0LU, 0x000005F0LU, 0x000005B8LU, 0x000005B0LU, 0x000005C0LU, 0x00000590LU, 0x000005E0LU,
		0x00000468LU, 0x00000458LU, 0x00000420LU, 0x00000408LU, 0x00000418LU, 0x00000478LU, 0x00000428LU, 0x00000448LU,
		0x00000400LU, 0x00000450LU, 0x00000470LU, 0x00000438LU, 0x00000430LU, 0x00000440LU, 0x00000410LU, 0x00000460LU,
		0x00000668LU, 0x00000658LU, 0x00000620LU, 0x00000608LU, 0x00000618LU, 0x00000678LU, 0x00000628LU, 0x00000648LU,
		0x00000600LU, 0x00000650LU, 0x00000670LU, 0x00000638LU, 0x00000630LU, 0x00000640LU, 0x00000610LU, 0x00000660LU,
	},
};
