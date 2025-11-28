################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SRC/MCAL/EXTI/subdir.mk
-include SRC/MCAL/DIO/subdir.mk
-include SRC/HAL/stepper_motor/subdir.mk
-include SRC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.lss \

FLASH_IMAGE += \
EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.hex \

EEPROM_IMAGE += \
EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf secondary-outputs

# Tool invocations
EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.map -mmcu=atmega16 -o "EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.lss: EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf  >"EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.lss"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.hex: EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf  "EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.hex"
	@echo 'Finished building: $@'
	@echo ' '

EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.eep: EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf  "EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXTI_Stepper_Motor_Timer_Buzzer_ULN2003A.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
