//
// Created by bronislav on 10/27/22.
//
#include "ubx.h"

int UBX_WriteChecksum(uint8_t *packet)
{
    Ubx_packet_header *header = (Ubx_packet_header *) packet;
    Ubx_packet_checksum *checksum = (Ubx_packet_checksum *) (packet + sizeof(Ubx_packet_header) + header->payloadLen);
    uint8_t *payload = packet + sizeof(Ubx_packet_header);

    if (header->sync1 != UBX_SYNC_1 || header->sync2 != UBX_SYNC_2)
        return -1;

    checksum->ck_a = checksum->ck_b = 0;
    for (int i = 0; i < header->payloadLen; ++i)
    {
        checksum->ck_a += payload[i];
        checksum->ck_b += checksum->ck_a;
    }

    return 0;
}