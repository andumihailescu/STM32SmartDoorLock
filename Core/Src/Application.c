#include "application.h"
#include "pn532_stm32f1.h"

PN532 pn532;
uint8_t buff[255];
uint8_t uid[MIFARE_UID_MAX_LENGTH];
int32_t uid_len = 0;

void Application_Init()
{
	printf("Welcome to STM32 world!\r\n");
	PN532_I2C_Init(&pn532);
	PN532_GetFirmwareVersion(&pn532, buff);
	if (PN532_GetFirmwareVersion(&pn532, buff) == PN532_STATUS_OK)
	{
		printf("Found PN532 with firmware version: %d.%d\r\n", buff[1], buff[2]);
	}
	PN532_SamConfiguration(&pn532);
	printf("Waiting for RFID/NFC card...\r\n");
}

void ReadNFCTag()
{
	// Check if a card is available to read
	uid_len = PN532_ReadPassiveTarget(&pn532, uid, PN532_MIFARE_ISO14443A, 1000);
	if (uid_len == PN532_STATUS_ERROR)
	{
	  printf("Error...");
	}
	else
	{
	  printf("Found card with UID: ");
	  for (uint8_t i = 0; i < uid_len; i++)
	  {
		printf("%02x ", uid[i]);
	  }
	  printf("\r\n");
	}
}
