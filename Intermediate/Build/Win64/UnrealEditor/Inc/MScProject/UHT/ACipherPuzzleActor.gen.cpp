// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MScProject/ACipherPuzzleActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeACipherPuzzleActor() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
MSCPROJECT_API UClass* Z_Construct_UClass_AACipherPuzzleActor();
MSCPROJECT_API UClass* Z_Construct_UClass_AACipherPuzzleActor_NoRegister();
MSCPROJECT_API UFunction* Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_MScProject();
// End Cross Module References

// Begin Delegate FOnPuzzleSolved
struct Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MScProject, nullptr, "OnPuzzleSolved__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPuzzleSolved_DelegateWrapper(const FMulticastScriptDelegate& OnPuzzleSolved)
{
	OnPuzzleSolved.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnPuzzleSolved

// Begin Class AACipherPuzzleActor Function ActivatePuzzle
struct Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACipherPuzzleActor, nullptr, "ActivatePuzzle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACipherPuzzleActor::execActivatePuzzle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ActivatePuzzle();
	P_NATIVE_END;
}
// End Class AACipherPuzzleActor Function ActivatePuzzle

// Begin Class AACipherPuzzleActor Function ExitPuzzle
struct Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACipherPuzzleActor, nullptr, "ExitPuzzle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACipherPuzzleActor::execExitPuzzle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExitPuzzle();
	P_NATIVE_END;
}
// End Class AACipherPuzzleActor Function ExitPuzzle

// Begin Class AACipherPuzzleActor Function SubmitSolution
struct Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics
{
	struct ACipherPuzzleActor_eventSubmitSolution_Parms
	{
		FString PlayerInput;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerInput_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerInput;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::NewProp_PlayerInput = { "PlayerInput", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACipherPuzzleActor_eventSubmitSolution_Parms, PlayerInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerInput_MetaData), NewProp_PlayerInput_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::NewProp_PlayerInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AACipherPuzzleActor, nullptr, "SubmitSolution", nullptr, nullptr, Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::PropPointers), sizeof(Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::ACipherPuzzleActor_eventSubmitSolution_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::Function_MetaDataParams), Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::ACipherPuzzleActor_eventSubmitSolution_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AACipherPuzzleActor::execSubmitSolution)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PlayerInput);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SubmitSolution(Z_Param_PlayerInput);
	P_NATIVE_END;
}
// End Class AACipherPuzzleActor Function SubmitSolution

// Begin Class AACipherPuzzleActor
void AACipherPuzzleActor::StaticRegisterNativesAACipherPuzzleActor()
{
	UClass* Class = AACipherPuzzleActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ActivatePuzzle", &AACipherPuzzleActor::execActivatePuzzle },
		{ "ExitPuzzle", &AACipherPuzzleActor::execExitPuzzle },
		{ "SubmitSolution", &AACipherPuzzleActor::execSubmitSolution },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AACipherPuzzleActor);
UClass* Z_Construct_UClass_AACipherPuzzleActor_NoRegister()
{
	return AACipherPuzzleActor::StaticClass();
}
struct Z_Construct_UClass_AACipherPuzzleActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ACipherPuzzleActor.h" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EncodedMessage_MetaData[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorrectSolution_MetaData[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CipherWidgetClass_MetaData[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSolved_MetaData[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorToDestroy_MetaData[] = {
		{ "Category", "Cipher" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CipherWidgetInstance_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSolved_MetaData[] = {
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPuzzleUIActive_MetaData[] = {
		{ "ModuleRelativePath", "ACipherPuzzleActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_EncodedMessage;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CorrectSolution;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CipherWidgetClass;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSolved;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToDestroy;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CipherWidgetInstance;
	static void NewProp_bIsSolved_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSolved;
	static void NewProp_bPuzzleUIActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPuzzleUIActive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AACipherPuzzleActor_ActivatePuzzle, "ActivatePuzzle" }, // 330071915
		{ &Z_Construct_UFunction_AACipherPuzzleActor_ExitPuzzle, "ExitPuzzle" }, // 224126483
		{ &Z_Construct_UFunction_AACipherPuzzleActor_SubmitSolution, "SubmitSolution" }, // 1305035887
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AACipherPuzzleActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_EncodedMessage = { "EncodedMessage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, EncodedMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EncodedMessage_MetaData), NewProp_EncodedMessage_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CorrectSolution = { "CorrectSolution", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, CorrectSolution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorrectSolution_MetaData), NewProp_CorrectSolution_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CipherWidgetClass = { "CipherWidgetClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, CipherWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CipherWidgetClass_MetaData), NewProp_CipherWidgetClass_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_OnSolved = { "OnSolved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, OnSolved), Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSolved_MetaData), NewProp_OnSolved_MetaData) }; // 2516885031
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_ActorToDestroy = { "ActorToDestroy", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, ActorToDestroy), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorToDestroy_MetaData), NewProp_ActorToDestroy_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CipherWidgetInstance = { "CipherWidgetInstance", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AACipherPuzzleActor, CipherWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CipherWidgetInstance_MetaData), NewProp_CipherWidgetInstance_MetaData) };
void Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bIsSolved_SetBit(void* Obj)
{
	((AACipherPuzzleActor*)Obj)->bIsSolved = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bIsSolved = { "bIsSolved", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AACipherPuzzleActor), &Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bIsSolved_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSolved_MetaData), NewProp_bIsSolved_MetaData) };
void Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bPuzzleUIActive_SetBit(void* Obj)
{
	((AACipherPuzzleActor*)Obj)->bPuzzleUIActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bPuzzleUIActive = { "bPuzzleUIActive", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AACipherPuzzleActor), &Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bPuzzleUIActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPuzzleUIActive_MetaData), NewProp_bPuzzleUIActive_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AACipherPuzzleActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_EncodedMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CorrectSolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CipherWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_OnSolved,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_ActorToDestroy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_CipherWidgetInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bIsSolved,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AACipherPuzzleActor_Statics::NewProp_bPuzzleUIActive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AACipherPuzzleActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AACipherPuzzleActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MScProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AACipherPuzzleActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AACipherPuzzleActor_Statics::ClassParams = {
	&AACipherPuzzleActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AACipherPuzzleActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AACipherPuzzleActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AACipherPuzzleActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AACipherPuzzleActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AACipherPuzzleActor()
{
	if (!Z_Registration_Info_UClass_AACipherPuzzleActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AACipherPuzzleActor.OuterSingleton, Z_Construct_UClass_AACipherPuzzleActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AACipherPuzzleActor.OuterSingleton;
}
template<> MSCPROJECT_API UClass* StaticClass<AACipherPuzzleActor>()
{
	return AACipherPuzzleActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AACipherPuzzleActor);
AACipherPuzzleActor::~AACipherPuzzleActor() {}
// End Class AACipherPuzzleActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AACipherPuzzleActor, AACipherPuzzleActor::StaticClass, TEXT("AACipherPuzzleActor"), &Z_Registration_Info_UClass_AACipherPuzzleActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AACipherPuzzleActor), 2560967648U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_1308152066(TEXT("/Script/MScProject"),
	Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_ACipherPuzzleActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
