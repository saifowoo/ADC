################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../ADC_PBCfg.c \
../DIO_operations.c \
../Interrupts.c \
../LCD.c \
../main.c \
../Timer0_function.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
ADC_PBCfg.o \
DIO_operations.o \
Interrupts.o \
LCD.o \
main.o \
Timer0_function.o

OBJS_AS_ARGS +=  \
ADC.o \
ADC_PBCfg.o \
DIO_operations.o \
Interrupts.o \
LCD.o \
main.o \
Timer0_function.o

C_DEPS +=  \
ADC.d \
ADC_PBCfg.d \
DIO_operations.d \
Interrupts.d \
LCD.d \
main.d \
Timer0_function.d

C_DEPS_AS_ARGS +=  \
ADC.d \
ADC_PBCfg.d \
DIO_operations.d \
Interrupts.d \
LCD.d \
main.d \
Timer0_function.d

OUTPUT_FILE_PATH +=ADC_TEMP_Auto_Trigger.elf

OUTPUT_FILE_PATH_AS_ARGS +=ADC_TEMP_Auto_Trigger.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\program files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "E:\program files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ADC_TEMP_Auto_Trigger.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "E:\program files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ADC_TEMP_Auto_Trigger.elf" "ADC_TEMP_Auto_Trigger.hex"
	"E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ADC_TEMP_Auto_Trigger.elf" "ADC_TEMP_Auto_Trigger.eep" || exit 0
	"E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ADC_TEMP_Auto_Trigger.elf" > "ADC_TEMP_Auto_Trigger.lss"
	"E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ADC_TEMP_Auto_Trigger.elf" "ADC_TEMP_Auto_Trigger.srec"
	"E:\program files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "ADC_TEMP_Auto_Trigger.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ADC_TEMP_Auto_Trigger.elf" "ADC_TEMP_Auto_Trigger.a" "ADC_TEMP_Auto_Trigger.hex" "ADC_TEMP_Auto_Trigger.lss" "ADC_TEMP_Auto_Trigger.eep" "ADC_TEMP_Auto_Trigger.map" "ADC_TEMP_Auto_Trigger.srec" "ADC_TEMP_Auto_Trigger.usersignatures"
	