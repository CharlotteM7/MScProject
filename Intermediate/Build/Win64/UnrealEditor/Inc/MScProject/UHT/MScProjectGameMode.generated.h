// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MScProjectGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MSCPROJECT_MScProjectGameMode_generated_h
#error "MScProjectGameMode.generated.h already included, missing '#pragma once' in MScProjectGameMode.h"
#endif
#define MSCPROJECT_MScProjectGameMode_generated_h

#define FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMScProjectGameMode(); \
	friend struct Z_Construct_UClass_AMScProjectGameMode_Statics; \
public: \
	DECLARE_CLASS(AMScProjectGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/MScProject"), MSCPROJECT_API) \
	DECLARE_SERIALIZER(AMScProjectGameMode)


#define FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMScProjectGameMode(AMScProjectGameMode&&); \
	AMScProjectGameMode(const AMScProjectGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MSCPROJECT_API, AMScProjectGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMScProjectGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMScProjectGameMode) \
	MSCPROJECT_API virtual ~AMScProjectGameMode();


#define FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_9_PROLOG
#define FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MSCPROJECT_API UClass* StaticClass<class AMScProjectGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
