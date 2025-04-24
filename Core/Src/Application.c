#include "application.h"
#include "pn532_stm32f1.h"

PN532 pn532;
uint8_t buff[255];
uint8_t uid[MIFARE_UID_MAX_LENGTH];
int32_t uid_len = 0;

void Application_Init(void)
{
	printf("Welcome to STM32 world!\r\n");
	PN532_I2C_Init(&pn532);
	if (PN532_GetFirmwareVersion(&pn532, buff) == PN532_STATUS_OK)
	{
		printf("Found PN532 with firmware version: %d.%d\r\n", buff[1], buff[2]);
	}
	PN532_SamConfiguration(&pn532);
	printf("Waiting for RFID/NFC card...\r\n");
}

char* ReadNFCTag(void)
{
    static char msg[32]; // Enough space for UID (7 bytes max -> 14 chars + null terminator)
    uint8_t uid[7];
    int8_t uid_len;

    uid_len = PN532_ReadPassiveTarget(&pn532, uid, PN532_MIFARE_ISO14443A, 1000);

    if (uid_len != PN532_STATUS_ERROR)
    {
        for (uint8_t i = 0; i < uid_len; i++)
        {
            // Convert each byte to 2 hex characters
            uint8_t byte = uid[i];
            msg[i * 2]     = "0123456789ABCDEF"[byte >> 4];
            msg[i * 2 + 1] = "0123456789ABCDEF"[byte & 0x0F];
        }
        msg[uid_len * 2] = '\0'; // Null terminator
    }
    else
    {
        msg[0] = '\0'; // Empty string on error
    }

    return msg;
}
