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
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
GPIO_v3_progmem.lss \

FLASH_IMAGE += \
GPIO_v3_progmem.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: GPIO_v3_progmem.elf secondary-outputs

# Tool invocations
GPIO_v3_progmem.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,GPIO_v3_progmem.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega2560 -o "GPIO_v3_progmem.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GPIO_v3_progmem.lss: GPIO_v3_progmem.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GPIO_v3_progmem.elf  >"GPIO_v3_progmem.lss"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_v3_progmem.hex: GPIO_v3_progmem.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex GPIO_v3_progmem.elf  "GPIO_v3_progmem.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GPIO_v3_progmem.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 GPIO_v3_progmem.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) GPIO_v3_progmem.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
