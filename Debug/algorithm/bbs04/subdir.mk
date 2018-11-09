################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithm/bbs04/GroupSig_BBS.cpp \
../algorithm/bbs04/GroupSig_BBS_Impl.cpp 

OBJS += \
./algorithm/bbs04/GroupSig_BBS.o \
./algorithm/bbs04/GroupSig_BBS_Impl.o 

CPP_DEPS += \
./algorithm/bbs04/GroupSig_BBS.d \
./algorithm/bbs04/GroupSig_BBS_Impl.d 


# Each subdirectory must supply rules for building sources it contributes
algorithm/bbs04/%.o: ../algorithm/bbs04/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -std=c++0x -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/cryptopp" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/devcore" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/bbs04" -I"/home/wzx/Code/cplusplus/FISCO-BCOS-GR-Sig/algorithm/ring-sig" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


