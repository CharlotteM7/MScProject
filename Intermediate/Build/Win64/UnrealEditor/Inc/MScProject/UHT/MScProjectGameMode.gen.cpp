// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MScProject/MScProjectGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMScProjectGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
MSCPROJECT_API UClass* Z_Construct_UClass_AMScProjectGameMode();
MSCPROJECT_API UClass* Z_Construct_UClass_AMScProjectGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_MScProject();
// End Cross Module References

// Begin Class AMScProjectGameMode
void AMScProjectGameMode::StaticRegisterNativesAMScProjectGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMScProjectGameMode);
UClass* Z_Construct_UClass_AMScProjectGameMode_NoRegister()
{
	return AMScProjectGameMode::StaticClass();
}
struct Z_Construct_UClass_AMScProjectGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MScProjectGameMode.h" },
		{ "ModuleRelativePath", "MScProjectGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMScProjectGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMScProjectGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_MScProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMScProjectGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMScProjectGameMode_Statics::ClassParams = {
	&AMScProjectGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMScProjectGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AMScProjectGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMScProjectGameMode()
{
	if (!Z_Registration_Info_UClass_AMScProjectGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMScProjectGameMode.OuterSingleton, Z_Construct_UClass_AMScProjectGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMScProjectGameMode.OuterSingleton;
}
template<> MSCPROJECT_API UClass* StaticClass<AMScProjectGameMode>()
{
	return AMScProjectGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMScProjectGameMode);
AMScProjectGameMode::~AMScProjectGameMode() {}
// End Class AMScProjectGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMScProjectGameMode, AMScProjectGameMode::StaticClass, TEXT("AMScProjectGameMode"), &Z_Registration_Info_UClass_AMScProjectGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMScProjectGameMode), 3429953877U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_60753488(TEXT("/Script/MScProject"),
	Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Masters_MScProject_Source_MScProject_MScProjectGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
