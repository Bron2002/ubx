//
// Created by bronislav on 10/27/22.
//

#ifndef UART_GPS_UBX_H
#define UART_GPS_UBX_H

#include <stdint-gcc.h>

#define UBX_SYNC_1 0xB5
#define UBX_SYNC_2 0x62

typedef struct
{
    uint8_t sync1;
    uint8_t sync2;
    uint8_t class;
    uint8_t id;
    uint16_t payloadLen;
} Ubx_packet_header;

typedef struct
{
    uint8_t ck_a;
    uint8_t ck_b;
} Ubx_packet_checksum;

typedef enum
{
    noFix,
    deadReckoningOnly,
    _2d_fix,
    _3d_fix,
    GNSS_deadReckoningCombined,
    timeFixOnly
} fixType;

typedef struct
{
    uint32_t iTOW;
    uint8_t gpsFIX;
    struct
    {
        uint8_t ;
    } flags;
    struct
    {
        uint8_t ;
    } fixStat;
    struct
    {
        uint8_t ;
    } flags2;
    uint32_t ttff;
    uint32_t msss;
} Ubx_nav_status;

typedef struct
{
    uint32_t iTOW;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    struct
    {
        uint8_t validDate: 1;
        uint8_t validTime: 1;
        uint8_t fullyResolved: 1;
        uint8_t validMag: 1;
        uint8_t : 4;
    } valid;
    uint32_t tAcc;
    int32_t nano;
    uint8_t fixType;
    struct
    {
        uint8_t gnssFixOk: 1;
        uint8_t diffSoln: 1;
        uint8_t psmState: 3;
        uint8_t headVehValid: 1;
        uint8_t carrSoln: 2;
    } flags;
    struct
    {
        uint8_t : 5;
        uint8_t confirmedAvai: 1;
        uint8_t confirmedDate: 1;
        uint8_t confirmedTime: 1;
    } flags2;
    uint8_t numSV;
    int32_t lon;
    int32_t lat;
    int32_t height;
    int32_t hMSL;
    uint32_t hAcc;
    uint32_t vAcc;
    int32_t veIN;
    int32_t veIE;
    int32_t veID;
    int32_t gSpeed;
    int32_t headMot;
    uint32_t sAcc;
    uint32_t headAcc;
    uint16_t pDOP;
    struct
    {
        uint8_t invalidLlh: 1;
        uint8_t lastCorrectionAge: 4;
        uint16_t : 11;
    } flags3;
    uint8_t reserved1[4];
    int32_t headVeh;
    int16_t magDec;
    uint16_t magAcc;
} Ubx_nav_pvt;

int UBX_WriteChecksum(uint8_t *);

#endif //UART_GPS_UBX_H
