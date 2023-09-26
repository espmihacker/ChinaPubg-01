#pragma once

#include "cJSON.h"

namespace Offset {

    //Base
    int PointerSize = 0x8;
    int BoxItemSize = 0x38;

    //Class: UObject
    int UObjectToClassPrivate = 0x10;
    int UStructToSuperStruct = 0x30;
    int UObjectToInternalIndex = 0x18;

    //Class: ULevel
    int ULevelToAActors = 0xA0;
    int ULevelToAActorsCount = ULevelToAActors + 0x8;
    int ULevelToLevelActorContainer=0xe0; //LevelActorContainer* ActorCluster;//[Offset: 0xe0, Size: 0x8]

    //class LevelActorContainer
    int ULevelActorContainerToAActors = 0x28; // 	Actor*[] Actors;//[Offset: 0x28, Size: 0x10]

    int ULevelActorContainerToAActorsCount = ULevelActorContainerToAActors + 0x8;

    //Class: FNameEntry
    int FNameEntryToNameString = 0xE - 0x2;

    //Class: UWorld
    int UWorldToPersistentLevel = 0x90; //Level* PersistentLevel;
    int UWorldToNetDriver = 0x98; //NetDriver* NetDriver;
    int UWorldToCurrentLevel = 0x8a8; //Level* CurrentLevel;
    int UWorldToLevels = 0x748; //Level* Levels;

    //Class: PlayerCameraManager
    int dw_CameraCacheEntry = 0x5b0;//CameraCacheEntry CameraCache;

    //Class: CameraCacheEntry
    int dw_MinimalViewInfo = 0x10; //MinimalViewInfo POV;

    //Class: MinimalViewInfo
    int dw_Location = 0x0;//class MinimalViewInfo  Vector Location;
    int dw_Rotation = 0x18; // class MinimalViewInfo Rotator Rotation;
    int dw_FOV = 0x24; //class MinimalViewInfo float FOV;

    //Class: NetDriver
    int NetDriverToServerConnection = 0x88; //NetConnection* ServerConnection;

    //Class: NetConnection
    int ServerConnectionToPlayerController = 0x30; //PlayerController* PlayerController;

    //Class: PlayerController
    int playerCameraManagerOffset = 0x5c8; //PlayerCameraManager* PlayerCameraManager;
    int uMyObjectOffset = 0x5a8; //Pawn* AcknowledgedPawn;

    //Class: Controller
    int controlRotationOffset = 0x568;//Rotator ControlRotation;


    //Class: Actor
    int RoleOffset = 0x1f8;//byte Role;
    int RootComponentOffset = 0x268;//对象坐标指针 SceneComponent* RootComponent;
    int VelocityOffset = 0xe8c;//预判向量 Vector VelocitySafety;
    int RotationAngleOffset = 0x170 + 0x24 + 0x4;//旋转角 RepMovement ReplicatedMovement; + 0x24 + 0x4
    int CoordinateOffset = 0x188;//坐标偏移 K2_GetActorLocation，获取到actor后，观察坐标变化，可以获取到偏移量

    // Class: STExtraCharacter
    int RideVehicleOffset = 0xfa8;//STExtraVehicleBase* CurrentVehicle;
    int StateOffset = 0x1310;//人物状态 PawnStateRepSyncData PawnStateRepSyncData;//[Offset: 0x12c8, Size: 0x20]
    int HealthOffset = 0xda0;//血量 float Health;
    int maxHealthOffset = 0xda8;//最大血量

    //Class: UAECharacter
    int TeamIDOffset = 0xa50;// 队伍 int TeamID;
    int isBotOffset = 0xa6c; //人机 bool bIsAI;
    int PlayerNameOffset = 0x9d0;//人物名字 FString PlayerName;

    //Class: Character.
    int BoneAddrOffset = 0x5c0;//阵列  SkeletalMeshComponent* Mesh;

    //Class: SceneComponent
    int BoneMatrixOffset = 0x19c + 0xC; //基矩阵 Vector RelativeScale3D; + 0xC

    //Class: SkinnedMeshComponent.
    int BoneOffset = 0x6b0; //骨骼 SkeletalMesh* SkeletalMesh;

    //Class: PickUpListWrapperActor
    int BoxAddressOffset = 0x998;//物品地址数组 PickUpItemData[] PickUpDataList;
    int IDNumberOffset = BoxAddressOffset + PointerSize;//盒子物品数量

    //Class: ShootWeaponEntity
    int bulletVelocityOffset = 0x12e4;//枪子弹速度 float BulletFireSpeed;
    int resistanceOffset = 0x1718;//枪口上抬 float AccessoriesVRecoilFactor;

    //Class: STExtraPlayerController
    int fireButtonOffset = 0x3f38; //开火键 bool bIsPressingFireBtn;
    int adsOffset = 0x1480;//开镜 bool bIsGunADS;

    //Class: STExtraBaseCharacter
    int lastUpdateStatusKeyListOffset = 0x2ab8;// AnimStatusKeyList LastUpdateStatusKeyList;

    //Class: AnimStatusKeyList
    int equipWeaponOffset = 0x20; //STExtraWeapon* EquipWeapon; 装备武器

    //Class: STExtraShootWeapon
    int shootModeOffset = 0xfd4; //byte ShootMode; 模式
    int gunOffset = 0x11d8;//射击武器实体 ShootWeaponEntity* ShootWeaponEntityComp;
    int weaponOffset = lastUpdateStatusKeyListOffset + equipWeaponOffset;
    int holdingStateOffset = weaponOffset - 0x14;//手持武器状态

    //Class: STExtraVehicleBase
    int driveStateOffset = 0x9fc;//enum VehicleHealthState;

    //Class: STExtraWeapon
    int weaponIDOffset = 0x9a8;//武器ID int RepWeaponID;

    //Class: STExtraShootWeapon
    int weaponAmmoOffset = 0xfc8;//剩余子弹 int CurBulletNumInClip;
    int weaponClipOffset = weaponAmmoOffset + 0x4;//弹夹 int CurMaxBulletNumInOneClip;
    int ShootWeaponComponentOffset = 0xed0;//STExtraShootWeaponComponent* ShootWeaponComponent;

    // 手找
//    int GNames = 0xB249460;//"ShadowTrackerExtra" 搜索文本
//    int GWorld = 0xB663490;//"g.56" 搜索文本  LogSpawn LogWorld
//    int GActivity = 0xB1FECB0;// 搜索文本 Created event thread
//    int GScreen = 0xB1E36AC;//***** WindowWidth is %d, not using res cache
//    int GObject = 0xB491A20;//ADRL X19, unk_AB0BB50  ObjectHash.EnableShrink //static bool IsValid(const Object* Object);
//    int GMatrix = 0xB641670;// 08 01 ?? ?? 49 09 ?? ?? 4A 01 ?? ?? STR XZR, [X19,#(qword_ACBA2D0 - 0xACBA200)]


    int GNames = 0xCC602B0;//"ShadowTrackerExtra" 搜索文本
    int GWorld = 0xD0EB4E8;// 搜索文本  aANullObjectWas
    int GActivity = 0xCC04C80;// 搜索文本 Created event thread
    int GScreen = 0xCBE0D1C;//***** WindowWidth is %d, not using res cache
    int GObject = 0xCEE9EB0;//ADRL X19, unk_AB0BB50  ObjectHash.EnableShrink //static bool IsValid(const Object* Object);
    int GMatrix = 0xCD18F80;// 08 01 ?? ?? 49 09 ?? ?? 4A 01 ?? ?? STR XZR, [X19,#(qword_ACBA2D0 - 0xACBA200)]
    //搜索 r.ResetViewState
//    int LineOfSightToOffset = 0x7d0a168;
//
//    int GetBoneNameOffset = 0x7e53914;
//    int GetBoneLocationOffset = 0x7e53848;
//    int GetNumBonesOffset = 0x7e53a60;
//    int ProjectWorldLocationToScreenOffset = 0x7e1f660;
//    int K2_GetActorLocationOffset=0x7cac184;

//

    int PawnOffset;//Class: Controller.Actor.Object Pawn* Pawn;//[Offset: 0x538, Size: 0x8]

    int LineOfSightToOffset = 0x63272D8;
    int GetBoneNameOffset = 0x7747664;
    int GetBoneLocationOffset = 0x774951C;
    int GetNumBonesOffset = 0x774764C;
    int ProjectWorldLocationToScreenOffset = 0x7B8634C;
    int ResetRotation=0x41B3928;
    int AddYawInputOffset ;
    int AddPitchInputOffset;

    void china64Offset() {
        //Base
//        PointerSize = 0x8;
//        BoxItemSize = 0x38;
//
//        //Class: UObject
//        UObjectToClassPrivate = 0x10;
//        UStructToSuperStruct = 0x30;
//        UObjectToInternalIndex = 0x18;
//
//        //Class: ULevel
//        //ULevelToAActors = 0xA0;
//        //ULevelToAActorsCount = ULevelToAActors + 0x8;
//
//        //Class: FNameEntry
//        FNameEntryToNameString = 0xE - 0x2;
//
//        //Class: UWorld
//        UWorldToPersistentLevel = 0x90; //Level* PersistentLevel;
//        UWorldToNetDriver = 0x98; //NetDriver* NetDriver;
//
//        //Class: PlayerCameraManager
//        dw_CameraCacheEntry = 0x580;//CameraCacheEntry CameraCache;
//
//        //Class: CameraCacheEntry
//        dw_MinimalViewInfo = 0x10; //MinimalViewInfo POV;
//
//        //Class: MinimalViewInfo
//        dw_Location = 0x0;//class MinimalViewInfo  Vector Location;
//        dw_Rotation = 0x18; // class MinimalViewInfo Rotator Rotation;
//        dw_FOV = 0x24; //class MinimalViewInfo float FOV;
//
//        //Class: NetDriver
//        NetDriverToServerConnection = 0x78; //NetConnection* ServerConnection;
//
//        //Class: NetConnection
//        ServerConnectionToPlayerController = 0x30; //PlayerController* PlayerController;
//
//        //Class: PlayerController
//        playerCameraManagerOffset = 0x5a0; //PlayerCameraManager* PlayerCameraManager;
//        uMyObjectOffset = 0x580; //Pawn* AcknowledgedPawn;
//
//        //Class: Controller
//        controlRotationOffset = 0x540;//Rotator ControlRotation;
//
//        //Class: Actor
//        RoleOffset = 0x1f0;//byte Role;
//        RootComponentOffset = 0x258;//对象坐标指针 SceneComponent* RootComponent;
//        VelocityOffset = 0xddc;//预判向量 Vector VelocitySafty;
//        RotationAngleOffset = 0x170 + 0x24 + 0x4;//旋转角 RepMovement ReplicatedMovement; + 0x24 + 0x4
//        CoordinateOffset = 0x1C0;//坐标偏移 K2_GetActorLocation
//
//        // Class: STExtraCharacter
//        RideVehicleOffset = 0xe98;//STExtraVehicleBase* CurrentVehicle;
//        StateOffset = 0xf70;//人物状态 PawnStateRepSyncData PawnStateRepSyncData;
//        HealthOffset = 0xcf0;//血量 float Health;
//        maxHealthOffset = 0xcf8;//最大血量
//
//        //Class: UAECharacter
//        TeamIDOffset = 0x9f8;// 队伍 int TeamID;
//        isBotOffset = 0xa14; //人机 bool bIsAI;
//        PlayerNameOffset = 0x988;//人物名字 FString PlayerName;
//
//        //Class: Character.
//        BoneAddrOffset = 0x598;//阵列  SkeletalMeshComponent* Mesh;
//
//        //Class: SceneComponent
//        BoneMatrixOffset = 0x19c + 0xC; //基矩阵 Vector RelativeScale3D; + 0xC
//
//        //Class: SkinnedMeshComponent.
//        BoneOffset = 0x6d0; //骨骼 SkeletalMesh* SkeletalMesh;
//
//        //Class: PickUpListWrapperActor
//        BoxAddressOffset = 0x978;//物品地址数组 PickUpItemData[] PickUpDataList;
//        IDNumberOffset = BoxAddressOffset + PointerSize;//盒子物品数量
//
//        //Class: ShootWeaponEntity
//        bulletVelocityOffset = 0xc4c;//枪子弹速度 float BulletFireSpeed;
//        resistanceOffset = 0xfd8;//枪口上抬 float AccessoriesVRecoilFactor;
//
//        //Class: STExtraPlayerController
//        fireButtonOffset = 0x3478; //开火键 bool bIsPressingFireBtn;
//        adsOffset = 0x1008;//开镜 bool bIsGunADS;
//
//        //Class: STExtraBaseCharacter
//        lastUpdateStatusKeyListOffset = 0x2930;// AnimStatusKeyList LastUpdateStatusKeyList;
//
//        //Class: AnimStatusKeyList
//        equipWeaponOffset = 0x20; //STExtraWeapon* EquipWeapon; 装备武器
//
//        //Class: STExtraShootWeapon
//        shootModeOffset = 0xefc; //byte ShootMode; 模式
//        gunOffset = 0x1100;//射击武器实体 ShootWeaponEntity* ShootWeaponEntityComp;
//        weaponOffset = lastUpdateStatusKeyListOffset + equipWeaponOffset;
//        holdingStateOffset = weaponOffset - 0x14;//手持武器状态
//
//        //Class: STExtraVehicleBase
//        driveStateOffset = 0x9bc;//enum VehicleHealthState;
//
//        //Class: STExtraWeapon
//        weaponIDOffset = 0x918;//武器ID int RepWeaponID;
//
//        //Class: STExtraShootWeapon
//        weaponAmmoOffset = 0xef0;//剩余子弹 int CurBulletNumInClip;
//        weaponClipOffset = weaponAmmoOffset + 0x4;//弹夹 int CurMaxBulletNumInOneClip;
//        ShootWeaponComponentOffset = 0xed0;//STExtraShootWeaponComponent* ShootWeaponComponent;
//
//        // 手找
//        GNames = 0xB249460;//"ShadowTrackerExtra" 搜索文本
//        GWorld = 0xB663490;//"g.56" 搜索文本  LogSpawn LogWorld
//        GActivity = 0xB1FECB0;// 搜索文本 Created event thread
//        GScreen = 0xB1E36AC;//***** WindowWidth is %d, not using res cache
//        GObject = 0xB491A20;//ADRL X19, unk_AB0BB50  ObjectHash.EnableShrink //static bool IsValid(const Object* Object);
//        GMatrix = 0xB641670;// 08 01 ?? ?? 49 09 ?? ?? 4A 01 ?? ?? STR XZR, [X19,#(qword_ACBA2D0 - 0xACBA200)]
//        //搜索 r.ResetViewState
//
//        LineOfSightToOffset = 0x66929a4;
//
//        GetBoneNameOffset = 0x665FF94;
//        GetBoneLocationOffset = 0x6661E4C;
//        GetNumBonesOffset = 0x665FF7C;
//        ProjectWorldLocationToScreenOffset = 0x6A75C70;
        
    }

    void setOffset(cJSON* cjson) {
       // china64Offset();
  
    }
};

/*if ( dword_A87C43C <= 8 ) WindowWidth
{
sub_4A76448(L"***** WindowWidth is %d, not using res cache");
 A87C440
}*/
