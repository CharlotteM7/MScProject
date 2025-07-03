// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MScProjectCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MSCPROJECT_MScProjectCharacter_generated_h
#error "MScProjectCharacter.generated.h already included, missing '#pragma once' in MScProjectCharacter.h"
#endif
#define MSCPROJECT_MScProjectCharacter_generated_h

#define FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMScProjectCharacter(); \
	friend struct Z_Construct_UClass_AMScProjectCharacter_Statics; \
public: \
	DECLARE_CLASS(AMScProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MScProject"), NO_API) \
	DECLARE_SERIALIZER(AMScProjectCharacter)


#define FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMScProjectCharacter(AMScProjectCharacter&&); \
	AMScProjectCharacter(const AMScProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMScProjectCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMScProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMScProjectCharacter) \
	NO_API virtual ~AMScProjectCharacter();


#define FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_24_PROLOG
#define FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_27_INCLASS_NO_PURE_DECLS \
	FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MSCPROJECT_API UClass* StaticClass<class AMScProjectCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Masters_MScProject_Source_MScProject_MScProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
