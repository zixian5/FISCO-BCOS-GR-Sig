################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include devcore/subdir.mk
-include algorithm/ring-sig/subdir.mk
-include algorithm/bbs04/subdir.mk
-include algorithm/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FISCO-BCOS-GR-Sig

# Tool invocations
FISCO-BCOS-GR-Sig: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/cryptopp" -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/devcore" -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/cryptopp/lib" -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm" -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/bbs04" -L"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/ring-sig" -o "FISCO-BCOS-GR-Sig" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) FISCO-BCOS-GR-Sig
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
