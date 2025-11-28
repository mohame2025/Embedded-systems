################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/LCD/LCD.c 

OBJS += \
./SRC/HAL/LCD/LCD.o 

C_DEPS += \
./SRC/HAL/LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/LCD/%.o: ../SRC/HAL/LCD/%.c SRC/HAL/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\eclipse-workspace\LCD_Drivers\INC" -I"C:\Users\moham\eclipse-workspace\LCD_Drivers\LIB" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


