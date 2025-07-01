// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMScProject_init() {}
	MSCPROJECT_API UFunction* Z_Construct_UDelegateFunction_MScProject_OnClueFound__DelegateSignature();
	MSCPROJECT_API UFunction* Z_Construct_UDelegateFunction_MScProject_OnClueFoundSignature__DelegateSignature();
	MSCPROJECT_API UFunction* Z_Construct_UDelegateFunction_MScProject_OnObjectiveUpdated__DelegateSignature();
	MSCPROJECT_API UFunction* Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MScProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MScProject()
	{
		if (!Z_Registration_Info_UPackage__Script_MScProject.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_MScProject_OnClueFound__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MScProject_OnClueFoundSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MScProject_OnObjectiveUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MScProject_OnPuzzleSolved__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MScProject",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x54766CE5,
				0x77CD0B21,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MScProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MScProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MScProject(Z_Construct_UPackage__Script_MScProject, TEXT("/Script/MScProject"), Z_Registration_Info_UPackage__Script_MScProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x54766CE5, 0x77CD0B21));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
