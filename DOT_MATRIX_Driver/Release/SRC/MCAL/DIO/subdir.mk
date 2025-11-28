################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/DIO/DIO.c 

OBJS += \
./SRC/MCAL/DIO/DIO.o 

C_DEPS += \
./SRC/MCAL/DIO/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/DIO/%.o: ../SRC/MCAL/DIO/%.c SRC/MCAL/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\eclipse-workspace\DOT_MATRIX_Driver\INC" -I"C:\Users\moham\eclipse-workspace\DOT_MATRIX_Driver\LIB" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


