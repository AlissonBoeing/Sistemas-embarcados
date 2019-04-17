################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../__MACOSX/GPIO_v1/._GPIO.cpp 

OBJS += \
./__MACOSX/GPIO_v1/._GPIO.o 

CPP_DEPS += \
./__MACOSX/GPIO_v1/._GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
__MACOSX/GPIO_v1/%.o: ../__MACOSX/GPIO_v1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


