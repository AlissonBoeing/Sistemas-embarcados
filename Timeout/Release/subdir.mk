################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GPIO.cpp \
../GPIO_Port.cpp \
../Singleton.cpp \
../Timeout.cpp \
../Timer.cpp \
../main.cpp 

OBJS += \
./GPIO.o \
./GPIO_Port.o \
./Singleton.o \
./Timeout.o \
./Timer.o \
./main.o 

CPP_DEPS += \
./GPIO.d \
./GPIO_Port.d \
./Singleton.d \
./Timeout.d \
./Timer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


