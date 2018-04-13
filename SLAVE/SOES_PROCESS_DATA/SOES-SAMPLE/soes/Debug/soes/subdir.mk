################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../soes/esc.c \
../soes/esc_coe.c \
../soes/esc_eep.c \
../soes/esc_foe.c 

OBJS += \
./soes/esc.o \
./soes/esc_coe.o \
./soes/esc_eep.o \
./soes/esc_foe.o 

C_DEPS += \
./soes/esc.d \
./soes/esc_coe.d \
./soes/esc_eep.d \
./soes/esc_foe.d 


# Each subdirectory must supply rules for building sources it contributes
soes/%.o: ../soes/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F144x2048 -I"$(PROJECT_LOC)/soes/include/sys/gcc" -I"$(PROJECT_LOC)" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

