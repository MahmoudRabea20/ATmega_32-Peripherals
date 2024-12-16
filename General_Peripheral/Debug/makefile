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
General_Peripheral.lss \

FLASH_IMAGE += \
General_Peripheral.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: General_Peripheral.elf secondary-outputs

# Tool invocations
General_Peripheral.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,General_Peripheral.map -mmcu=atmega32 -o "General_Peripheral.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

General_Peripheral.lss: General_Peripheral.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S General_Peripheral.elf  >"General_Peripheral.lss"
	@echo 'Finished building: $@'
	@echo ' '

General_Peripheral.hex: General_Peripheral.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex General_Peripheral.elf  "General_Peripheral.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: General_Peripheral.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t General_Peripheral.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) General_Peripheral.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
