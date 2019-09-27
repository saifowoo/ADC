################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../ADC_PBCfg.c \
../DIO_operations.c \
../Interrupts.c \
../LCD.c \
../Timer0_function.c \
../main.c 

OBJS += \
./ADC.o \
./ADC_PBCfg.o \
./DIO_operations.o \
./Interrupts.o \
./LCD.o \
./Timer0_function.o \
./main.o 

C_DEPS += \
./ADC.d \
./ADC_PBCfg.d \
./DIO_operations.d \
./Interrupts.d \
./LCD.d \
./Timer0_function.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


