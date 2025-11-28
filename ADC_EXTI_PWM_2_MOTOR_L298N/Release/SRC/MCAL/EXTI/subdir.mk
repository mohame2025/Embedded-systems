################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/EXTI/EXTI.c 

OBJS += \
./SRC/MCAL/EXTI/EXTI.o 

C_DEPS += \
./SRC/MCAL/EXTI/EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/EXTI/%.o: ../SRC/MCAL/EXTI/%.c SRC/MCAL/EXTI/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\moham\eclipse-workspace\ADC_EXTI_PWM_2_MOTOR_L298N\INC" -I"C:\Users\moham\eclipse-workspace\ADC_EXTI_PWM_2_MOTOR_L298N\LIB" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


