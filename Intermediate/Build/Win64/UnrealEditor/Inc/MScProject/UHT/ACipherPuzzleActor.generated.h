// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ACipherPuzzleActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MSCPROJECT_ACipherPuzzleActor_generated_h
#error "ACipherPuzzleActor.generated.h already included, missing '#pragma once' in ACipherPuzzleActor.h"
#endif
#define MSCPROJECT_ACipherPuzzleActor_generated_h

#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_19_DELEGATE \
MSCPROJECT_API void FOnPuzzleSolved_DelegateWrapper(const FMulticastScriptDelegate& OnPuzzleSolved);


#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExitPuzzle); \
	DECLARE_FUNCTION(execSubmitSolution); \
	DECLARE_FUNCTION(execActivatePuzzle);


#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAACipherPuzzleActor(); \
	friend struct Z_Construct_UClass_AACipherPuzzleActor_Statics; \
public: \
	DECLARE_CLASS(AACipherPuzzleActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MScProject"), NO_API) \
	DECLARE_SERIALIZER(AACipherPuzzleActor)


#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AACipherPuzzleActor(AACipherPuzzleActor&&); \
	AACipherPuzzleActor(const AACipherPuzzleActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AACipherPuzzleActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AACipherPuzzleActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AACipherPuzzleActor) \
	NO_API virtual ~AACipherPuzzleActor();


#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_21_PROLOG
#define FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_INCLASS_NO_PURE_DECLS \
	FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MSCPROJECT_API UClass* StaticClass<class AACipherPuzzleActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
