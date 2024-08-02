// Copyright Pedro Nortes


#include "Actor/EffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/MasterAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AEffectActor::AEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>( "Mesh" );
	SetRootComponent( Mesh );

	Sphere = CreateDefaultSubobject<USphereComponent>( "Sphere" );
	Sphere->SetupAttachment( GetRootComponent( ) );
}

void AEffectActor::OnOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 OtherBodyIndex, bool bFromSwepp, const FHitResult& SweepResult ) {
	// TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if ( IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>( OtherActor ) ) {
		const UMasterAttributeSet* MasterAttributeSet = Cast<UMasterAttributeSet>( 
			ASCInterface->GetAbilitySystemComponent( )->GetAttributeSet( UMasterAttributeSet::StaticClass( ) ) );
		//check( MasterAttributeSet );
		UMasterAttributeSet* MutableMasterAttributeSet = const_cast< UMasterAttributeSet* >( MasterAttributeSet );
		MutableMasterAttributeSet->SetHealth( MasterAttributeSet->GetHealth( ) + 25.f );
		Destroy( );
	}
}

void AEffectActor::EndOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex ) {

}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic( this, &AEffectActor::OnOverlap );
	Sphere->OnComponentEndOverlap.AddDynamic( this, &AEffectActor::EndOverlap );
}