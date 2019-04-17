################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPIO_v1/GPIO.cpp \
../GPIO_v1/main.cpp 

OBJS += \
./GPIO_v1/GPIO.o \
./GPIO_v1/main.o 

CPP_DEPS += \
./GPIO_v1/GPIO.d \
./GPIO_v1/main.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_v1/%.o: ../GPIO_v1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


