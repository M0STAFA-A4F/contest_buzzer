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
_3Buttons_int.lss \

FLASH_IMAGE += \
_3Buttons_int.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: _3Buttons_int.elf secondary-outputs

# Tool invocations
_3Buttons_int.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,_3Buttons_int.map -mmcu=atmega32 -o "_3Buttons_int.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

_3Buttons_int.lss: _3Buttons_int.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S _3Buttons_int.elf  >"_3Buttons_int.lss"
	@echo 'Finished building: $@'
	@echo ' '

_3Buttons_int.hex: _3Buttons_int.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex _3Buttons_int.elf  "_3Buttons_int.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: _3Buttons_int.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 _3Buttons_int.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) _3Buttons_int.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
