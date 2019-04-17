################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPIO_v2/GPIO.cpp \
../GPIO_v2/GPIO_Port.cpp \
../GPIO_v2/main.cpp 

OBJS += \
./GPIO_v2/GPIO.o \
./GPIO_v2/GPIO_Port.o \
./GPIO_v2/main.o 

CPP_DEPS += \
./GPIO_v2/GPIO.d \
./GPIO_v2/GPIO_Port.d \
./GPIO_v2/main.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_v2/%.o: ../GPIO_v2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


