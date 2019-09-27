################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADC_TEMP_PWM_MOTOR.lss \

FLASH_IMAGE += \
ADC_TEMP_PWM_MOTOR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ADC_TEMP_PWM_MOTOR.elf secondary-outputs

# Tool invocations
ADC_TEMP_PWM_MOTOR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_TEMP_PWM_MOTOR.map -mmcu=atmega32 -o "ADC_TEMP_PWM_MOTOR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_TEMP_PWM_MOTOR.lss: ADC_TEMP_PWM_MOTOR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_TEMP_PWM_MOTOR.elf  >"ADC_TEMP_PWM_MOTOR.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC_TEMP_PWM_MOTOR.hex: ADC_TEMP_PWM_MOTOR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ADC_TEMP_PWM_MOTOR.elf  "ADC_TEMP_PWM_MOTOR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_TEMP_PWM_MOTOR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ADC_TEMP_PWM_MOTOR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADC_TEMP_PWM_MOTOR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
