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
Watch_Dog_Timer.lss \

FLASH_IMAGE += \
Watch_Dog_Timer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Watch_Dog_Timer.elf secondary-outputs

# Tool invocations
Watch_Dog_Timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Watch_Dog_Timer.map -mmcu=atmega32 -o "Watch_Dog_Timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Watch_Dog_Timer.lss: Watch_Dog_Timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Watch_Dog_Timer.elf  >"Watch_Dog_Timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

Watch_Dog_Timer.hex: Watch_Dog_Timer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Watch_Dog_Timer.elf  "Watch_Dog_Timer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Watch_Dog_Timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Watch_Dog_Timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Watch_Dog_Timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
