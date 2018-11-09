################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithm/ring-sig/LinkableRingSig_Impl.cpp 

OBJS += \
./algorithm/ring-sig/LinkableRingSig_Impl.o 

CPP_DEPS += \
./algorithm/ring-sig/LinkableRingSig_Impl.d 


# Each subdirectory must supply rules for building sources it contributes
algorithm/ring-sig/%.o: ../algorithm/ring-sig/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -std=c++0x -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/cryptopp" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/devcore" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/bbs04" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/ring-sig" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


