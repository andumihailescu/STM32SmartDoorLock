################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/PN532/pn532.c \
../Drivers/PN532/pn532_stm32f1.c 

OBJS += \
./Drivers/PN532/pn532.o \
./Drivers/PN532/pn532_stm32f1.o 

C_DEPS += \
./Drivers/PN532/pn532.d \
./Drivers/PN532/pn532_stm32f1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/PN532/%.o Drivers/PN532/%.su Drivers/PN532/%.cyclo: ../Drivers/PN532/%.c Drivers/PN532/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C031xx -c -I../Core/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -I"D:/School/SmartDoorLock/Drivers/PN532" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-PN532

clean-Drivers-2f-PN532:
	-$(RM) ./Drivers/PN532/pn532.cyclo ./Drivers/PN532/pn532.d ./Drivers/PN532/pn532.o ./Drivers/PN532/pn532.su ./Drivers/PN532/pn532_stm32f1.cyclo ./Drivers/PN532/pn532_stm32f1.d ./Drivers/PN532/pn532_stm32f1.o ./Drivers/PN532/pn532_stm32f1.su

.PHONY: clean-Drivers-2f-PN532

