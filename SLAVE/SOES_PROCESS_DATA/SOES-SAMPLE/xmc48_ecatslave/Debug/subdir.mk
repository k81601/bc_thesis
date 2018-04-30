################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../esc_hw.c \
../esc_hw_eep.c \
../main.c \
../xmc4800_slave.c \
../xmc4800_slave_objectlist.c \
../xmc4800_slave_objectlist_v1.c \
../xmc4800_slave_v1.c 

OBJS += \
./esc_hw.o \
./esc_hw_eep.o \
./main.o \
./xmc4800_slave.o \
./xmc4800_slave_objectlist.o \
./xmc4800_slave_objectlist_v1.o \
./xmc4800_slave_v1.o 

C_DEPS += \
./esc_hw.d \
./esc_hw_eep.d \
./main.d \
./xmc4800_slave.d \
./xmc4800_slave_objectlist.d \
./xmc4800_slave_objectlist_v1.d \
./xmc4800_slave_v1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F144x2048 -I"C:/Workspaces/SOES-SAMPLE/soes/soes/include/sys/gcc" -I"C:/Workspaces/SOES-SAMPLE/soes/soes" -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

