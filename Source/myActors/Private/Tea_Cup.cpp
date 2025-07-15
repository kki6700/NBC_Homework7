// Fill out your copyright notice in the Description page of Project Settings.


#include "Tea_Cup.h"


DEFINE_LOG_CATEGORY(LogSparta);
// Sets default values
ATea_Cup::ATea_Cup()
{
	//신 컴포넌트 생성한다
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	//루트컴포넌트로 루트 컴포넌트를 설정한다.
	SetRootComponent(SceneRoot);

	//스테틱 메쉬 컴포넌트를 생성한다.
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	// 스테틱 메쉬 컴포넌트를 신루트 컴포넌트 아래에 붙힌다.
	StaticMeshComp->SetupAttachment(SceneRoot);

	
	//텍스트에 쓰여진 경로로가서 스태틱 메쉬 가져오기
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Props/Teas_Cup.Teas_Cup"));
	//메쉬 성공적으로 불러와졌는지 검증
	/*
	if (MeshAsset.Succeeded()) 
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	*/
	//Text에 쓰여진 경로로 가서 질감 찾기
	//static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Resources/Materials/M_Wood_Floor_Walnut_Worn.M_Wood_Floor_Walnut_Worn"));
	//질감 성공적으로 불러와졌는지 검증
	/*if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);

	}
	*/
	PrimaryActorTick.bCanEverTick = true;

	//RotationSpeed = 90.0f;



}
void ATea_Cup::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(FVector(300.0f, 300.0f, 300.0f));
	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	//SetActorScale3D(FVector(2.0f));

	//FVector NewLocation(300.0f, 300.0f, 300.0f);
	//FRotator newRotation(0.0f, 90.0f, 0.0f);
	//FVector NewScale(2.0f);
	//FTransform newTransform(newRotation, NewLocation, NewScale);
	//SetActorTransform(newTransform);

}

void ATea_Cup::Tick(float DeltaTime)
{
	//프레임이 사용자 환경마다 달라서 좋지않다.
	//120 프레임 -1초에 120번 호출 1/120 =DeltaTime
	//30 프레임 - 1초에 30번 호출 1/30 = DeltaTime
	//1초에 90도 씩 회전하고싶다
	// 90도 / 120
	// 90도 / 30
	// 1초 = 90도
	// 즉 어느 프레임에서도 1초마다 동일하게 돌게 된다.
	Super::Tick(DeltaTime);
	FRotator RotationDelta = FRotator(PitchSpeed * DeltaTime, YawSpeed * DeltaTime, RollSpeed * DeltaTime);

	
	AddActorLocalRotation(RotationDelta);
	
	
	
}



