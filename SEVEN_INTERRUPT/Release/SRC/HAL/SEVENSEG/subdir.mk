################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/SEVENSEG/SEVENSEG_program.c 

OBJS += \
./SRC/HAL/SEVENSEG/SEVENSEG_program.o 

C_DEPS += \
./SRC/HAL/SEVENSEG/SEVENSEG_program.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/SEVENSEG/%.o: ../SRC/HAL/SEVENSEG/%.c SRC/HAL/SEVENSEG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\eclipse-workspace\SEVEN_INTERRUPT\INC" -I"C:\Users\moham\eclipse-workspace\SEVEN_INTERRUPT\LIB" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


