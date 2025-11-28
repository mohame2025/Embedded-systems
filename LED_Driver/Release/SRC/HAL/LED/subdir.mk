################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/LED/LED_program.c 

OBJS += \
./SRC/HAL/LED/LED_program.o 

C_DEPS += \
./SRC/HAL/LED/LED_program.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/LED/%.o: ../SRC/HAL/LED/%.c SRC/HAL/LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\eclipse-workspace\LED_Driver\INC" -I"C:\Users\moham\eclipse-workspace\LED_Driver\LIB" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


