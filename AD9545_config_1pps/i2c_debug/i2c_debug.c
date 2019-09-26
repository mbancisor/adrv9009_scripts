
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

const int16_t eval_regs[970][2] = {
	{0x0200,0x18},
	{0x0201,0x09},
	{0x0202,0x00},
	{0x0203,0x00},
	{0x0204,0xB0},
	{0x0205,0x71},
	{0x0206,0x0B},
	{0x0207,0x32},
	{0x0208,0x00},
	{0x0209,0x00},
	{0x0280,0x00},
	{0x0281,0x00},
	{0x0282,0x00},
	{0x0283,0x00},
	{0x0284,0x00},
	{0x0285,0x00},
	{0x0286,0x00},
	{0x0287,0x00},
	{0x0288,0x00},
	{0x0289,0x00},
	{0x028A,0x00},
	{0x028B,0x00},
	{0x028C,0x00},
	{0x028D,0x00},
	{0x028E,0x00},
	{0x028F,0x00},
	{0x0290,0x00},
	{0x0291,0x00},
	{0x0292,0x00},
	{0x0293,0x00},
	{0x0294,0x00},
	{0x0295,0x00},
	{0x0296,0x00},
	{0x0297,0x00},
	{0x0298,0x00},
	{0x0299,0x00},
	{0x029A,0x00},
	{0x029B,0x00},
	{0x029C,0x00},
	{0x0300,0x10},
	{0x0301,0x01},
	{0x0302,0x40},
	{0x0303,0x40},
	{0x0304,0xA0},
	{0x0305,0x01},
	{0x0306,0x40},
	{0x0307,0x40},
	{0x0400,0x00},
	{0x0401,0x00},
	{0x0402,0x00},
	{0x0403,0x00},
	{0x0404,0x00},
	{0x0405,0x00},
	{0x0406,0x64},
	{0x0407,0xA7},
	{0x0408,0xB3},
	{0x0409,0xB6},
	{0x040A,0xE0},
	{0x040B,0x0D},
	{0x040C,0x40},
	{0x040D,0x42},
	{0x040E,0x0F},
	{0x040F,0x03},
	{0x0410,0x0A},
	{0x0411,0x00},
	{0x0412,0x00},
	{0x0413,0x00},
	{0x0414,0x00},
	{0x0420,0x31},
	{0x0421,0x00},
	{0x0422,0x00},
	{0x0423,0x00},
	{0x0424,0x00},
	{0x0425,0xE8},
	{0x0426,0x76},
	{0x0427,0x48},
	{0x0428,0x17},
	{0x0429,0x00},
	{0x042A,0x00},
	{0x042B,0x00},
	{0x042C,0xA0},
	{0x042D,0x86},
	{0x042E,0x01},
	{0x042F,0x03},
	{0x0430,0x0A},
	{0x0431,0x00},
	{0x0432,0x00},
	{0x0433,0x00},
	{0x0434,0x00},
	{0x0440,0x00},
	{0x0441,0x00},
	{0x0442,0x00},
	{0x0443,0x00},
	{0x0444,0x00},
	{0x0445,0x00},
	{0x0446,0x64},
	{0x0447,0xA7},
	{0x0448,0xB3},
	{0x0449,0xB6},
	{0x044A,0xE0},
	{0x044B,0x0D},
	{0x044C,0xA0},
	{0x044D,0x86},
	{0x044E,0x01},
	{0x044F,0x03},
	{0x0450,0x0A},
	{0x0451,0x00},
	{0x0452,0x00},
	{0x0453,0x00},
	{0x0454,0x00},
	{0x0460,0x00},
	{0x0461,0x00},
	{0x0462,0x00},
	{0x0463,0x00},
	{0x0464,0x00},
	{0x0465,0x00},
	{0x0466,0x64},
	{0x0467,0xA7},
	{0x0468,0xB3},
	{0x0469,0xB6},
	{0x046A,0xE0},
	{0x046B,0x0D},
	{0x046C,0xA0},
	{0x046D,0x86},
	{0x046E,0x01},
	{0x046F,0x03},
	{0x0470,0x0A},
	{0x0471,0x00},
	{0x0472,0x00},
	{0x0473,0x00},
	{0x0474,0x00},
	{0x0800,0xC8},
	{0x0801,0xAF},
	{0x0802,0x00},
	{0x0803,0x51},
	{0x0804,0x32},
	{0x0805,0xC8},
	{0x0806,0xAF},
	{0x0807,0x00},
	{0x0808,0x51},
	{0x0809,0x32},
	{0x080A,0x00},
	{0x080B,0x00},
	{0x080C,0x00},
	{0x080D,0x00},
	{0x080E,0x00},
	{0x080F,0x00},
	{0x0810,0x00},
	{0x0811,0x00},
	{0x0820,0x88},
	{0x0821,0x13},
	{0x0822,0x00},
	{0x0823,0x51},
	{0x0824,0x32},
	{0x0825,0x88},
	{0x0826,0x13},
	{0x0827,0x00},
	{0x0828,0x51},
	{0x0829,0x32},
	{0x082A,0x00},
	{0x082B,0x00},
	{0x082C,0x00},
	{0x082D,0x00},
	{0x082E,0x00},
	{0x082F,0x00},
	{0x0830,0x00},
	{0x0831,0x00},
	{0x0840,0xBC},
	{0x0841,0x02},
	{0x0842,0x00},
	{0x0843,0x0A},
	{0x0844,0x0A},
	{0x0845,0xBC},
	{0x0846,0x02},
	{0x0847,0x00},
	{0x0848,0x0A},
	{0x0849,0x0A},
	{0x084A,0x00},
	{0x084B,0x00},
	{0x084C,0x00},
	{0x084D,0x00},
	{0x084E,0x00},
	{0x084F,0x00},
	{0x0850,0x00},
	{0x0851,0x00},
	{0x0860,0x58},
	{0x0861,0x1B},
	{0x0862,0x00},
	{0x0863,0xC8},
	{0x0864,0xC8},
	{0x0865,0x88},
	{0x0866,0x13},
	{0x0867,0x00},
	{0x0868,0xC8},
	{0x0869,0xC8},
	{0x086A,0x00},
	{0x086B,0x00},
	{0x086C,0x00},
	{0x086D,0x00},
	{0x086E,0x00},
	{0x086F,0x00},
	{0x0870,0x00},
	{0x0871,0x00},
	{0x0880,0xBC},
	{0x0881,0x02},
	{0x0882,0x00},
	{0x0883,0x0A},
	{0x0884,0x0A},
	{0x0885,0xBC},
	{0x0886,0x02},
	{0x0887,0x00},
	{0x0888,0x0A},
	{0x0889,0x0A},
	{0x088A,0x00},
	{0x088B,0x00},
	{0x088C,0x00},
	{0x088D,0x00},
	{0x088E,0x00},
	{0x088F,0x00},
	{0x0890,0x00},
	{0x0891,0x00},
	{0x08A0,0xBC},
	{0x08A1,0x02},
	{0x08A2,0x00},
	{0x08A3,0x0A},
	{0x08A4,0x0A},
	{0x08A5,0xBC},
	{0x08A6,0x02},
	{0x08A7,0x00},
	{0x08A8,0x0A},
	{0x08A9,0x0A},
	{0x08AA,0x00},
	{0x08AB,0x00},
	{0x08AC,0x00},
	{0x08AD,0x00},
	{0x08AE,0x00},
	{0x08AF,0x00},
	{0x08B0,0x00},
	{0x08B1,0x00},
	{0x08C0,0xBC},
	{0x08C1,0x02},
	{0x08C2,0x00},
	{0x08C3,0x0A},
	{0x08C4,0x0A},
	{0x08C5,0xBC},
	{0x08C6,0x02},
	{0x08C7,0x00},
	{0x08C8,0x0A},
	{0x08C9,0x0A},
	{0x08CA,0x00},
	{0x08CB,0x00},
	{0x08CC,0x00},
	{0x08CD,0x00},
	{0x08CE,0x00},
	{0x08CF,0x00},
	{0x08D0,0x00},
	{0x08D1,0x00},
	{0x08E0,0x88},
	{0x08E1,0x13},
	{0x08E2,0x00},
	{0x08E3,0x51},
	{0x08E4,0x32},
	{0x08E5,0xD0},
	{0x08E6,0x07},
	{0x08E7,0x00},
	{0x08E8,0x51},
	{0x08E9,0x32},
	{0x08EA,0x00},
	{0x08EB,0x00},
	{0x08EC,0x00},
	{0x08ED,0x00},
	{0x08EE,0x00},
	{0x08EF,0x00},
	{0x08F0,0x00},
	{0x08F1,0x00},
	{0x0C00,0xC2},
	{0x0C01,0xF0},
	{0x0C02,0xB3},
	{0x0C03,0x55},
	{0x0C04,0xC9},
	{0x0C05,0xFB},
	{0x0C06,0x5C},
	{0x0C07,0xF6},
	{0x0C08,0xCA},
	{0x0C09,0x11},
	{0x0C0A,0xDF},
	{0x0C0B,0xCC},
	{0x0C0C,0xA9},
	{0x0C0D,0xA0},
	{0x0C0E,0xB7},
	{0x0C0F,0xCD},
	{0x0C10,0xDB},
	{0x0C11,0xF3},
	{0x0C12,0x79},
	{0x0C13,0xD4},
	{0x0C14,0xCE},
	{0x0C15,0x4D},
	{0x0C16,0xA7},
	{0x0C17,0xCF},
	{0x1000,0x55},
	{0x1001,0x55},
	{0x1002,0x55},
	{0x1003,0x55},
	{0x1004,0x55},
	{0x1005,0x21},
	{0x1006,0xFF},
	{0x1007,0xFF},
	{0x1008,0xFF},
	{0x1009,0x00},
	{0x100A,0x0A},
	{0x100B,0x00},
	{0x100C,0x00},
	{0x100D,0x00},
	{0x100E,0x38},
	{0x100F,0x00},
	{0x1010,0x00},
	{0x1011,0x00},
	{0x1012,0x00},
	{0x1013,0x00},
	{0x1014,0x06},
	{0x1015,0x00},
	{0x1016,0x00},
	{0x1017,0x00},
	{0x1018,0x00},
	{0x1019,0x00},
	{0x101A,0x00},
	{0x101B,0x00},
	{0x101C,0x00},
	{0x101D,0x00},
	{0x101E,0x00},
	{0x101F,0x00},
	{0x1020,0x00},
	{0x1021,0x00},
	{0x1022,0x00},
	{0x1023,0x00},
	{0x1024,0x00},
	{0x1025,0x00},
	{0x1026,0x00},
	{0x1027,0x00},
	{0x1028,0x00},
	{0x102A,0x00},
	{0x102B,0x00},
	{0x1080,0x94},
	{0x1081,0x08},
	{0x1082,0xE0},
	{0x1083,0x03},
	{0x10C0,0x00},
	{0x10C1,0x00},
	{0x10C2,0x00},
	{0x10C3,0x00},
	{0x10C4,0x53},
	{0x10C5,0x07},
	{0x10C6,0x00},
	{0x10C7,0x00},
	{0x10C8,0x00},
	{0x10C9,0x00},
	{0x10CA,0x00},
	{0x10CB,0x00},
	{0x10CC,0x00},
	{0x10CD,0x00},
	{0x10CE,0x00},
	{0x10CF,0x01},
	{0x10D0,0x00},
	{0x10D1,0x00},
	{0x10D2,0x00},
	{0x10D3,0x00},
	{0x10D4,0x00},
	{0x10D5,0x00},
	{0x10D6,0x00},
	{0x10D7,0x02},
	{0x10D8,0x01},
	{0x10D9,0x01},
	{0x10DA,0x00},
	{0x10DB,0x05},
	{0x10DC,0x00},
	{0x1100,0x0A},
	{0x1101,0x00},
	{0x1102,0x00},
	{0x1103,0x00},
	{0x1104,0x00},
	{0x1105,0x00},
	{0x1106,0x00},
	{0x1107,0x00},
	{0x1108,0x07},
	{0x1109,0x00},
	{0x110A,0x00},
	{0x110B,0x00},
	{0x110C,0x00},
	{0x110D,0x00},
	{0x110E,0x00},
	{0x110F,0x00},
	{0x1110,0x00},
	{0x1111,0x07},
	{0x1112,0x08},
	{0x1113,0x00},
	{0x1114,0x00},
	{0x1115,0x00},
	{0x1116,0x00},
	{0x1117,0x00},
	{0x1118,0x00},
	{0x1119,0x00},
	{0x111A,0x07},
	{0x111B,0x00},
	{0x111C,0x00},
	{0x111D,0x00},
	{0x111E,0x00},
	{0x111F,0x00},
	{0x1120,0x00},
	{0x1121,0x00},
	{0x1122,0x00},
	{0x1123,0x07},
	{0x1124,0x08},
	{0x1125,0x00},
	{0x1126,0x00},
	{0x1127,0x00},
	{0x1128,0x00},
	{0x1129,0x00},
	{0x112A,0x00},
	{0x112B,0x00},
	{0x112C,0x07},
	{0x112D,0x00},
	{0x112E,0x00},
	{0x112F,0x00},
	{0x1130,0x00},
	{0x1131,0x00},
	{0x1132,0x00},
	{0x1133,0x00},
	{0x1134,0x00},
	{0x1135,0x07},
	{0x1200,0x01},
	{0x1201,0x00},
	{0x1202,0x00},
	{0x1203,0x01},
	{0x1204,0x50},
	{0x1205,0xC3},
	{0x1206,0x00},
	{0x1207,0x00},
	{0x1208,0xFF},
	{0x1209,0xFF},
	{0x120A,0x52},
	{0x120B,0x07},
	{0x120C,0xFF},
	{0x120D,0x7F},
	{0x120E,0x4F},
	{0x120F,0x12},
	{0x1210,0x00},
	{0x1211,0x00},
	{0x1212,0x00},
	{0x1213,0x00},
	{0x1214,0x00},
	{0x1215,0x00},
	{0x1216,0x01},
	{0x1217,0x76},
	{0x1220,0x00},
	{0x1221,0x00},
	{0x1222,0x00},
	{0x1223,0x00},
	{0x1224,0x00},
	{0x1225,0x00},
	{0x1226,0x00},
	{0x1227,0x00},
	{0x1228,0xA0},
	{0x1229,0x0F},
	{0x122A,0x00},
	{0x122B,0x00},
	{0x122C,0xA0},
	{0x122D,0x0F},
	{0x122E,0x00},
	{0x122F,0x00},
	{0x1230,0x00},
	{0x1231,0x00},
	{0x1232,0x00},
	{0x1233,0x00},
	{0x1234,0x00},
	{0x1235,0x00},
	{0x1236,0x00},
	{0x1237,0x00},
	{0x1240,0x00},
	{0x1241,0x00},
	{0x1242,0x00},
	{0x1243,0x00},
	{0x1244,0x00},
	{0x1245,0x00},
	{0x1246,0x00},
	{0x1247,0x00},
	{0x1248,0xA0},
	{0x1249,0x0F},
	{0x124A,0x00},
	{0x124B,0x00},
	{0x124C,0xA0},
	{0x124D,0x0F},
	{0x124E,0x00},
	{0x124F,0x00},
	{0x1250,0x00},
	{0x1251,0x00},
	{0x1252,0x00},
	{0x1253,0x00},
	{0x1254,0x00},
	{0x1255,0x00},
	{0x1256,0x00},
	{0x1257,0x00},
	{0x1260,0x00},
	{0x1261,0x00},
	{0x1262,0x00},
	{0x1263,0x00},
	{0x1264,0x00},
	{0x1265,0x00},
	{0x1266,0x00},
	{0x1267,0x00},
	{0x1268,0xA0},
	{0x1269,0x0F},
	{0x126A,0x00},
	{0x126B,0x00},
	{0x126C,0xA0},
	{0x126D,0x0F},
	{0x126E,0x00},
	{0x126F,0x00},
	{0x1270,0x00},
	{0x1271,0x00},
	{0x1272,0x00},
	{0x1273,0x00},
	{0x1274,0x00},
	{0x1275,0x00},
	{0x1276,0x00},
	{0x1277,0x00},
	{0x1280,0x00},
	{0x1281,0x00},
	{0x1282,0x00},
	{0x1283,0x00},
	{0x1284,0x00},
	{0x1285,0x00},
	{0x1286,0x00},
	{0x1287,0x00},
	{0x1288,0xA0},
	{0x1289,0x0F},
	{0x128A,0x00},
	{0x128B,0x00},
	{0x128C,0xA0},
	{0x128D,0x0F},
	{0x128E,0x00},
	{0x128F,0x00},
	{0x1290,0x00},
	{0x1291,0x00},
	{0x1292,0x00},
	{0x1293,0x00},
	{0x1294,0x00},
	{0x1295,0x00},
	{0x1296,0x00},
	{0x1297,0x00},
	{0x12A0,0x00},
	{0x12A1,0x00},
	{0x12A2,0x00},
	{0x12A3,0x00},
	{0x12A4,0x00},
	{0x12A5,0x00},
	{0x12A6,0x00},
	{0x12A7,0x00},
	{0x12A8,0xA0},
	{0x12A9,0x0F},
	{0x12AA,0x00},
	{0x12AB,0x00},
	{0x12AC,0xA0},
	{0x12AD,0x0F},
	{0x12AE,0x00},
	{0x12AF,0x00},
	{0x12B0,0x00},
	{0x12B1,0x00},
	{0x12B2,0x00},
	{0x12B3,0x00},
	{0x12B4,0x00},
	{0x12B5,0x00},
	{0x12B6,0x00},
	{0x12B7,0x00},
	{0x1400,0x8E},
	{0x1401,0xE3},
	{0x1402,0x38},
	{0x1403,0x8E},
	{0x1404,0xE8},
	{0x1405,0x21},
	{0x1406,0xFF},
	{0x1407,0xFF},
	{0x1408,0xFF},
	{0x1409,0x00},
	{0x140A,0x0A},
	{0x140B,0x00},
	{0x140C,0x00},
	{0x140D,0x00},
	{0x140E,0x38},
	{0x140F,0x00},
	{0x1410,0x00},
	{0x1411,0x00},
	{0x1412,0x00},
	{0x1413,0x00},
	{0x1414,0x06},
	{0x1415,0x00},
	{0x1416,0x00},
	{0x1417,0x00},
	{0x1418,0x00},
	{0x1419,0x00},
	{0x141A,0x00},
	{0x141B,0x00},
	{0x141C,0x00},
	{0x141D,0x00},
	{0x141E,0x00},
	{0x141F,0x00},
	{0x1420,0x00},
	{0x1421,0x00},
	{0x1422,0x00},
	{0x1423,0x00},
	{0x1424,0x00},
	{0x1425,0x00},
	{0x1426,0x00},
	{0x1427,0x00},
	{0x1428,0x00},
	{0x142A,0x00},
	{0x142B,0x00},
	{0x1480,0x90},
	{0x1481,0x0C},
	{0x1482,0xE0},
	{0x1483,0x03},
	{0x14C0,0x00},
	{0x14C1,0x00},
	{0x14C2,0x90},
	{0x14C3,0x2F},
	{0x14C4,0x50},
	{0x14C5,0x09},
	{0x14C6,0x00},
	{0x14C7,0x00},
	{0x14C8,0x00},
	{0x14C9,0x00},
	{0x14CE,0x00},
	{0x14CF,0x01},
	{0x14D0,0x00},
	{0x14D2,0x00},
	{0x14D3,0x00},
	{0x14D4,0x00},
	{0x14D6,0x00},
	{0x14D7,0x02},
	{0x14D8,0x02},
	{0x14DA,0x00},
	{0x14DB,0x05},
	{0x14DC,0x00},
	{0x1500,0x0C},
	{0x1501,0x00},
	{0x1502,0x00},
	{0x1503,0x00},
	{0x1504,0x00},
	{0x1505,0x00},
	{0x1506,0x00},
	{0x1507,0x00},
	{0x1508,0x07},
	{0x1509,0x00},
	{0x150A,0x00},
	{0x150B,0x00},
	{0x150C,0x00},
	{0x150D,0x00},
	{0x150E,0x00},
	{0x150F,0x00},
	{0x1510,0x00},
	{0x1511,0x07},
	{0x1512,0x06},
	{0x1513,0x00},
	{0x1514,0x00},
	{0x1515,0x00},
	{0x1516,0x00},
	{0x1517,0x00},
	{0x1518,0x00},
	{0x1519,0x00},
	{0x151A,0x07},
	{0x151B,0x00},
	{0x151C,0x00},
	{0x151D,0x00},
	{0x151E,0x00},
	{0x151F,0x00},
	{0x1520,0x00},
	{0x1521,0x00},
	{0x1522,0x00},
	{0x1523,0x07},
	{0x1600,0x01},
	{0x1601,0x00},
	{0x1602,0x00},
	{0x1603,0x01},
	{0x1604,0x50},
	{0x1605,0xC3},
	{0x1606,0x00},
	{0x1607,0x00},
	{0x1608,0x8F},
	{0x1609,0x2F},
	{0x160A,0x50},
	{0x160B,0x09},
	{0x160C,0x1F},
	{0x160D,0x5F},
	{0x160E,0xA0},
	{0x160F,0x12},
	{0x1610,0x00},
	{0x1611,0x00},
	{0x1612,0x00},
	{0x1613,0x00},
	{0x1614,0x00},
	{0x1615,0x00},
	{0x1616,0x00},
	{0x1617,0x00},
	{0x1620,0x00},
	{0x1621,0x00},
	{0x1622,0x00},
	{0x1623,0x00},
	{0x1624,0x00},
	{0x1625,0x00},
	{0x1626,0x00},
	{0x1627,0x00},
	{0x1628,0xA0},
	{0x1629,0x0F},
	{0x162A,0x00},
	{0x162B,0x00},
	{0x162C,0xA0},
	{0x162D,0x0F},
	{0x162E,0x00},
	{0x162F,0x00},
	{0x1630,0x00},
	{0x1631,0x00},
	{0x1632,0x00},
	{0x1633,0x00},
	{0x1634,0x00},
	{0x1635,0x00},
	{0x1636,0x00},
	{0x1637,0x00},
	{0x1640,0x00},
	{0x1641,0x00},
	{0x1642,0x00},
	{0x1643,0x00},
	{0x1644,0x00},
	{0x1645,0x00},
	{0x1646,0x00},
	{0x1647,0x00},
	{0x1648,0xA0},
	{0x1649,0x0F},
	{0x164A,0x00},
	{0x164B,0x00},
	{0x164C,0xA0},
	{0x164D,0x0F},
	{0x164E,0x00},
	{0x164F,0x00},
	{0x1650,0x00},
	{0x1651,0x00},
	{0x1652,0x00},
	{0x1653,0x00},
	{0x1654,0x00},
	{0x1655,0x00},
	{0x1656,0x00},
	{0x1657,0x00},
	{0x1660,0x00},
	{0x1661,0x00},
	{0x1662,0x00},
	{0x1663,0x00},
	{0x1664,0x00},
	{0x1665,0x00},
	{0x1666,0x00},
	{0x1667,0x00},
	{0x1668,0xA0},
	{0x1669,0x0F},
	{0x166A,0x00},
	{0x166B,0x00},
	{0x166C,0xA0},
	{0x166D,0x0F},
	{0x166E,0x00},
	{0x166F,0x00},
	{0x1670,0x00},
	{0x1671,0x00},
	{0x1672,0x00},
	{0x1673,0x00},
	{0x1674,0x00},
	{0x1675,0x00},
	{0x1676,0x00},
	{0x1677,0x00},
	{0x1680,0x00},
	{0x1681,0x00},
	{0x1682,0x00},
	{0x1683,0x00},
	{0x1684,0x00},
	{0x1685,0x00},
	{0x1686,0x00},
	{0x1687,0x00},
	{0x1688,0xA0},
	{0x1689,0x0F},
	{0x168A,0x00},
	{0x168B,0x00},
	{0x168C,0xA0},
	{0x168D,0x0F},
	{0x168E,0x00},
	{0x168F,0x00},
	{0x1690,0x00},
	{0x1691,0x00},
	{0x1692,0x00},
	{0x1693,0x00},
	{0x1694,0x00},
	{0x1695,0x00},
	{0x1696,0x00},
	{0x1697,0x00},
	{0x16A0,0x00},
	{0x16A1,0x00},
	{0x16A2,0x00},
	{0x16A3,0x00},
	{0x16A4,0x00},
	{0x16A5,0x00},
	{0x16A6,0x00},
	{0x16A7,0x00},
	{0x16A8,0xA0},
	{0x16A9,0x0F},
	{0x16AA,0x00},
	{0x16AB,0x00},
	{0x16AC,0xA0},
	{0x16AD,0x0F},
	{0x16AE,0x00},
	{0x16AF,0x00},
	{0x16B0,0x00},
	{0x16B1,0x00},
	{0x16B2,0x00},
	{0x16B3,0x00},
	{0x16B4,0x00},
	{0x16B5,0x00},
	{0x16B6,0x00},
	{0x16B7,0x00},
	{0x2000,0x00},
	{0x2001,0x0E},
	{0x2002,0x00},
	{0x2003,0x00},
	{0x2004,0x00},
	{0x2005,0x00},
	{0x2006,0x00},
	{0x2007,0x00},
	{0x2008,0x00},
	{0x2009,0x00},
	{0x200A,0x00},
	{0x200B,0x00},
	{0x200C,0x00},
	{0x200D,0x00},
	{0x200E,0x00},
	{0x200F,0x00},
	{0x2010,0x00},
	{0x2011,0x00},
	{0x2012,0x00},
	{0x2013,0x00},
	{0x2014,0x00},
	{0x2100,0x00},
	{0x2101,0x00},
	{0x2102,0x00},
	{0x2103,0x10},
	{0x2104,0x10},
	{0x2105,0x00},
	{0x2106,0x00},
	{0x2107,0x00},
	{0x2200,0x00},
	{0x2201,0x00},
	{0x2202,0x00},
	{0x2203,0x00},
	{0x2205,0x00},
	{0x2206,0x00},
	{0x2207,0x00},
	{0x2800,0x00},
	{0x2801,0x00},
	{0x2802,0x00},
	{0x2803,0x00},
	{0x2804,0x00},
	{0x2805,0x00},
	{0x2806,0x00},
	{0x2807,0x00},
	{0x2808,0x00},
	{0x2809,0x00},
	{0x280A,0x00},
	{0x280B,0x00},
	{0x280C,0x00},
	{0x280D,0x00},
	{0x280E,0x00},
	{0x280F,0x00},
	{0x2810,0x00},
	{0x2811,0x00},
	{0x2812,0x00},
	{0x2813,0x00},
	{0x2814,0x00},
	{0x2815,0x00},
	{0x2816,0x00},
	{0x2817,0x00},
	{0x2818,0x00},
	{0x2819,0x00},
	{0x281A,0x00},
	{0x281B,0x00},
	{0x281C,0x00},
	{0x281D,0x00},
	{0x281E,0x00},
	{0x2840,0x00},
	{0x2841,0x00},
	{0x2842,0x00},
	{0x2843,0x00},
	{0x2844,0x00},
	{0x2845,0x00},
	{0x2846,0x00},
	{0x2847,0x00},
	{0x2848,0x00},
	{0x2849,0x00},
	{0x284A,0x00},
	{0x284B,0x00},
	{0x284C,0x00},
	{0x284D,0x00},
	{0x284E,0x00},
	{0x284F,0x00},
	{0x2850,0x00},
	{0x2851,0x00},
	{0x2852,0x00},
	{0x2853,0x00},
	{0x2854,0x00},
	{0x2855,0x00},
	{0x2856,0x00},
	{0x2857,0x00},
	{0x2858,0x00},
	{0x2859,0x00},
	{0x285A,0x00},
	{0x285B,0x00},
	{0x285C,0x00},
	{0x285D,0x00},
	{0x285E,0x00},
	{0x2900,0x00},
	{0x2901,0x00},
	{0x2902,0x00},
	{0x2903,0x00},
	{0x2904,0x00},
	{0x2905,0x00},
	{0x2906,0x00},
	{0x2A00,0x00},
	{0x2A01,0x00},
	{0x2A02,0x00},
	{0x2A03,0x00},
	{0x2A04,0x00},
	{0x2A05,0x00},
	{0x2A06,0x00},
	{0x2A07,0x00},
	{0x2A08,0x00},
	{0x2A09,0x00},
	{0x2A0A,0x00},
	{0x2A0B,0x00},
	{0x2A0C,0x00},
	{0x2A0D,0x00},
	{0x2A0E,0x00},
	{0x2A0F,0x00},
	{0x2A10,0x00},
	{0x2A11,0x00},
	{0x2A12,0x06},
	{0x2A13,0x07},
	{0x2A14,0x00},
	{0x2A15,0x00},
	{0x2A16,0x00},
	{0x2A17,0x00},
	{0x2E00,0x00},
	{0x2E01,0x00},
	{0x2E02,0x00},
	{0x2E03,0x00},
	{0x2E10,0xFF},
	{0x2E11,0xFF},
	{0x2E12,0xFF},
	{0x2E13,0xFF},
	{0x2E14,0xFF},
	{0x2E15,0xFF},
	{0x2E16,0xFF},
	{0x2E17,0xFF},
	{0x2E18,0xFF},
	{0x2E19,0xFF},
	{0x2E1A,0xFF},
	{0x2E1B,0xFF},
	{0x2E1C,0xFF},
	{0x2E1D,0xFF},
	{0x2E1E,0xFF},
};

#define SUCCESS		0
#define FAILURE		-1

#define regGlobal				0x2000
#define regAPLL0Calib			0x2100
#define regAPLL1Calib			0x2200

#define regIoUpdate				0x000F

#define regEepromConfifg		0x2E00
#define regEepromSave			0x2E02
#define regEepromLoad			0x2E03
#define regEepromStatus			0x3000

typedef enum {
	LINUX_I2C
} i2c_type;

typedef struct {
	i2c_type	type;
	uint32_t	id;
	char		*pathname;
	uint32_t	max_speed_hz;
	uint8_t		slave_address;
} i2c_init_param;

typedef struct {
	i2c_type	type;
	uint32_t	id;
	int		fd;
	uint32_t	max_speed_hz;
	uint8_t		slave_address;
} i2c_desc;

int32_t i2c_init(i2c_desc **desc,
		 const i2c_init_param *param)
{
	i2c_desc *descriptor;

	descriptor = (i2c_desc *)malloc(sizeof(*descriptor));
	if (!descriptor)
		return FAILURE;

	descriptor->fd = open(param->pathname, O_RDWR);
	if (descriptor->fd < 0) {
		printf("%s: Can't open device\n\r", __func__);
		free(descriptor);
		return FAILURE;
	}

	descriptor->slave_address = param->slave_address;

	*desc = descriptor;

	return SUCCESS;
}

int32_t i2c_remove(i2c_desc *desc)
{
	int ret;

	ret = close(desc->fd);
	if (ret < 0) {
		printf("%s: Can't close device\n\r", __func__);
		return FAILURE;
	}

	free(desc);

	return SUCCESS;
}

int32_t i2c_write(i2c_desc *desc,
		  uint8_t *data,
		  uint8_t bytes_number,
		  uint8_t stop_bit)
{
	int ret;

	ret = ioctl(desc->fd, I2C_SLAVE, desc->slave_address);
	if (ret < 0) {
		printf("%s: Can't select device\n\r", __func__);
		return FAILURE;
	}

	ret = write(desc->fd, data, bytes_number);
	if (ret < 0) {
		printf("%s: Can't write to file\n\r", __func__);
		return FAILURE;
	}

	if (stop_bit) {
	}

	return SUCCESS;
}

int32_t i2c_read(i2c_desc *desc,
		 uint8_t *data,
		 uint8_t bytes_number,
		 uint8_t stop_bit)
{
	int ret;

	ret = ioctl(desc->fd, I2C_SLAVE, desc->slave_address);
	if (ret < 0) {
		printf("%s: Can't select device\n\r", __func__);
		return FAILURE;
	}

	ret = read(desc->fd, data, bytes_number);
	if (ret < 0) {
		printf("%s: Can't read from file\n\r", __func__);
		return FAILURE;
	}

	if (stop_bit) {
	}

	return SUCCESS;
}

void ad9542_set_reg_value(i2c_desc *desc,
		uint16_t reg_addr,
		uint8_t reg_val)
{
	uint8_t buffer[3];

	buffer[0] = (reg_addr >> 8) & 0xFF;
	buffer[1] = (reg_addr >> 0) & 0xFF;
	buffer[2] = reg_val;

	i2c_write(desc, buffer, 3, 1);
}

void ad9542_get_reg_value(i2c_desc *desc,
		uint16_t reg_addr,
		uint8_t *reg_val)
{
	uint8_t buffer[2];

	buffer[0] = (reg_addr >> 8) & 0xFF;
	buffer[1] = (reg_addr >> 0) & 0xFF;
	
	i2c_write(desc, buffer, 2, 0);
	i2c_read(desc, reg_val, 1, 1);
}

void ad9542_reset (i2c_desc *desc)
{
	ad9542_set_reg_value(desc, 0x0000, 0x81);
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
	
	ad9542_set_reg_value(desc, 0x0000, 0x00);	
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
}	

int main(void)
{
	const i2c_init_param init_param = {
		LINUX_I2C,
		0,
		"/dev/i2c-1",
		0,
		0x4a,
	};

	const i2c_init_param init_param1 = {
		LINUX_I2C,
		0,
		"/dev/i2c-1",
		0,
		0x70,
	};

	i2c_desc *desc;
	i2c_desc *desc1;
	uint16_t i;
	uint8_t val;
	
	int32_t configState = SUCCESS;

	printf("Hello\n");

	i2c_init(&desc, &init_param);
	i2c_init(&desc1, &init_param1);

	//reset AD9542
	//ad9542_reset (desc);
	sleep (1);

	printf ("Write all regs \n");
	for(i = 0; i < 970; i++)	{
		ad9542_set_reg_value(desc, eval_regs[i][0], eval_regs[i][1]);
		//usleep (1000);
	}
	
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
	//Calibrate ALL
	ad9542_set_reg_value(desc, 0x2000, 0x02);
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
	ad9542_set_reg_value(desc, 0x2000, 0x00);
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);

	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
	//Calibrate ALL
	ad9542_set_reg_value(desc, 0x2000, 0x02);
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);
	ad9542_set_reg_value(desc, 0x2000, 0x00);
	// IO Update
	ad9542_set_reg_value(desc, regIoUpdate, 0x01);

	//Verify reg
	printf("Verify regs.");
	for(i = 0; i < 970; i++) {
		ad9542_get_reg_value(desc, eval_regs[i][0], &val);
		if (val != eval_regs[i][1]) {
			printf("[0x%x]: 0x%x != 0x%x\n",
				eval_regs[i][0], val, eval_regs[i][1]);
			configState = FAILURE;
		}
	}	
	
	if (configState == SUCCESS) { 
		printf ("CONFIGURATION SUCCESS \n");
	}
	else {
		printf ("CONFIGURATION FAILED \n");
		return FAILURE;
	}

	uint8_t en_read_status = 0;
	uint8_t val1 = 0;
	uint16_t u16_val=0;
	int i16_val = 0;
	float f_val = 0;

	if(en_read_status)
	{

		while(1)
		{
			// IO Update
			ad9542_set_reg_value(desc, regIoUpdate, 0x01);

			ad9542_get_reg_value(desc, 0x3001, &val);
			printf("0x3001 SYSCLK and PLL status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3002, &val);
			printf("0x3002 MISC status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3003, &val);
			ad9542_get_reg_value(desc, 0x3004, &val1);

			u16_val = 0;
			u16_val = val1 << 8;
			u16_val = u16_val | val;
			f_val = (int)u16_val/128;
			printf("INT Temperature: %f \n", f_val );

			ad9542_get_reg_value(desc, 0x3005, &val);
			printf("0x3005 REFA status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3009, &val);
			printf("0x3009 DPLL0 active profile: %x \n", val );

			ad9542_get_reg_value(desc, 0x300A, &val);
			printf("0x300A DPLL1 active profile: %x \n", val );

			ad9542_get_reg_value(desc, 0x300B, &val);
			printf("0x300B SYSCLK status: %x \n", val );

			ad9542_get_reg_value(desc, 0x300C, &val);
			printf("0x300C AUXDPLL status: %x \n", val );

			ad9542_get_reg_value(desc, 0x300D, &val);
			printf("0x300D REFA status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3010, &val);
			printf("0x3010 DPLL0 Lock status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3014, &val);
			printf("0x3014 APLL0 status: %x \n", val );

			ad9542_set_reg_value(desc, regIoUpdate, 0x01);

			ad9542_get_reg_value(desc, 0x3100, &val);
			printf("0x3100 DPLL0 Lock status: %x \n", val );
			
			ad9542_get_reg_value(desc, 0x3101, &val);
			printf("0x3101 DPLL0 Operation status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3102, &val);
			printf("0x3102 DPLL0 State status: %x \n", val );

			u16_val = 0;
			
			ad9542_get_reg_value(desc, 0x3109, &val);
			ad9542_get_reg_value(desc, 0x310A, &val1);
			u16_val = val1 & 0x000F;
			u16_val = u16_val << 8;
			u16_val = u16_val | val;
			printf("hex %x \n", u16_val);
			printf("decimal %d \n", u16_val);
	//		i16_val = (u16_val & 0x07FF) - 2048;
			if((u16_val & 0x0800) != 0){
				i16_val = u16_val - 4095;
			}
			else{
				i16_val = u16_val;
			}
			printf("DPLL0 Phase Lock Tup: %d \n", i16_val);

			u16_val = 0;
			ad9542_get_reg_value(desc, 0x310B, &val);
			ad9542_get_reg_value(desc, 0x310C, &val1);
			u16_val = val1 << 8;
			u16_val = u16_val | val;
			printf("hex %x \n", u16_val);
			printf("decimal %d \n", u16_val);
			if((u16_val & 0x0800) != 0){
				i16_val = u16_val - 4095;
			}
			else{
				i16_val = u16_val;
			}

			printf("DPLL0 Frequency Lock Tup: %d \n", i16_val);
			
			printf("------------------------------------------------- \n");


			ad9542_get_reg_value(desc, 0x3200, &val);
			printf("0x3200 DPLL1 Lock status: %x \n", val );
			
			ad9542_get_reg_value(desc, 0x3201, &val);
			printf("0x3201 DPLL1 Operation status: %x \n", val );

			ad9542_get_reg_value(desc, 0x3202, &val);
			printf("0x3202 DPLL1 State status: %x \n", val );

			u16_val = 0;
			
			ad9542_get_reg_value(desc, 0x3209, &val);
			ad9542_get_reg_value(desc, 0x320A, &val1);
			u16_val = val1 & 0x000F;
			u16_val = u16_val << 8;
			u16_val = u16_val | val;
			printf("hex %x \n", u16_val);
			printf("decimal %d \n", u16_val);
			if((u16_val & 0x0800) != 0){
				i16_val = u16_val - 4095;
			}
			else{
				i16_val = u16_val;
			}
			printf("DPLL1 Phase Lock Tup: %d \n", i16_val);

			u16_val = 0;
			ad9542_get_reg_value(desc, 0x320B, &val);
			ad9542_get_reg_value(desc, 0x320C, &val1);
			u16_val = val1 << 8;
			u16_val = u16_val | val;
			printf("hex %x \n", u16_val);
			printf("decimal %d \n", u16_val);
			if((u16_val & 0x0800) != 0){
				i16_val = u16_val - 4095;
			}
			else{
				i16_val = u16_val;
			}

			printf("DPLL1 Frequency Lock Tup: %d \n", i16_val);

			printf("------------------------------------------------- \n");

			sleep(5);
		}

	}

	i2c_remove(desc);

	printf("Bye\n");

	return SUCCESS;
}
