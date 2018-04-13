################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SSC/Src/XMC_ESC.c \
../SSC/Src/bootmode.c \
../SSC/Src/coeappl.c \
../SSC/Src/ecatappl.c \
../SSC/Src/ecatcoe.c \
../SSC/Src/ecatfoe.c \
../SSC/Src/ecatslv.c \
../SSC/Src/foeappl.c \
../SSC/Src/mailbox.c \
../SSC/Src/objdef.c \
../SSC/Src/sdoserv.c 

OBJS += \
./SSC/Src/XMC_ESC.o \
./SSC/Src/bootmode.o \
./SSC/Src/coeappl.o \
./SSC/Src/ecatappl.o \
./SSC/Src/ecatcoe.o \
./SSC/Src/ecatfoe.o \
./SSC/Src/ecatslv.o \
./SSC/Src/foeappl.o \
./SSC/Src/mailbox.o \
./SSC/Src/objdef.o \
./SSC/Src/sdoserv.o 

C_DEPS += \
./SSC/Src/XMC_ESC.d \
./SSC/Src/bootmode.d \
./SSC/Src/coeappl.d \
./SSC/Src/ecatappl.d \
./SSC/Src/ecatcoe.d \
./SSC/Src/ecatfoe.d \
./SSC/Src/ecatslv.d \
./SSC/Src/foeappl.d \
./SSC/Src/mailbox.d \
./SSC/Src/objdef.d \
./SSC/Src/sdoserv.d 


# Each subdirectory must supply rules for building sources it contributes
SSC/Src/%.o: ../SSC/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4800_F144x2048 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/SSC/Src" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC4800_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

