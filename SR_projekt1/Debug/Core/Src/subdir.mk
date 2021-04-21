################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/stm32f3xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f3xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f3xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/stm32f3xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f3xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/adc.o: ../Core/Src/adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/adc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/gpio.o: ../Core/Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/i2c.o: ../Core/Src/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/spi.o: ../Core/Src/spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f3xx_hal_msp.o: ../Core/Src/stm32f3xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f3xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32f3xx_it.o: ../Core/Src/stm32f3xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f3xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32f3xx.o: ../Core/Src/system_stm32f3xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f3xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/tim.o: ../Core/Src/tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F303x8 -DDEBUG -c -I../Core/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Device/ST/STM32F3xx/Include -IC:/Users/clayf/STM32Cube/Repository/STM32Cube_FW_F3_V1.11.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

