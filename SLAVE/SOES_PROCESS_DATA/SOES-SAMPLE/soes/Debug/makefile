################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include soes/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

LIST_FILES = $(addsuffix .o.lst, $(basename $(OBJS))) 
MAP_FILE = "soes.map"

TOOLCHAIN_ROOT=C:/DAVEv4-64Bit/DAVE-4.3.2/eclipse/ARM-GCC-49
PROJECT_LOC=C:/Workspaces/SOES-SAMPLE/soes

# All Target
all: libsoes.a

# Tool invocations
libsoes.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC Archiver'
	$(file >objects.rsp,$(OBJS))
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-ar" -r "libsoes.a" "@objects.rsp"
	@echo 'Finished building target: $@'
	@echo.
# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) libsoes.a $(LIST_FILES) $(MAP_FILE) objects.rsp
	-@echo.
.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
