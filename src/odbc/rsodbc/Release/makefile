################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

LIBS_PATH := -L../../../pgclient/src/interfaces/libpq/Release -L../../../pgclient/src/port/Release -L../iam/linux/openssl/1.1.1/centos7/gcc5_5/release64/lib  -L../iam/linux/aws-cpp-sdk/1.9.289/centos7/gcc5_5/release64/lib -L ../iam/linux/libcURL/7.78.0_ssl1.1.1_zlib1.2.11_threaded_resolver/centos7/gcc5_5/release64/lib

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: librsodbc64.so

# Tool invocations
librsodbc64.so: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	g++ -std=gnu++17 $(LIBS_PATH) -Wl,--version-script=../exports.list -Wl,--no-undefined -shared -o "librsodbc64.so" $(OBJS) $(USER_OBJS) $(LIBS) $(THIRD_PARTY_LIBS) 
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(CPP_DEPS)$(LIBRARIES) librsodbc64.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
