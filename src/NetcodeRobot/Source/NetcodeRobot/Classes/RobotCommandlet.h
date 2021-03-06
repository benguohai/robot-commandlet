// Copyright 2016 Seasun Games, Inc. All Rights Reserved.

#pragma once

#include "Commandlets/Commandlet.h"

#include "RobotCommandlet.generated.h"

/**
 * A commandlet for running ROG2 Game Robot, without having to launch the game client.
 *
 * Usage:
 *	"UE4Editor.exe $GameProjectPath -run=NetcodeRobot.RobotCommandlet
 *
 * Parameters:
 *	-RobotTestServer=127.0.0.1:5050
 *		- SAdds additional commandline parameters to robot test server (Addr:Port)
 *
 *	-RobotTestMap="Robot test server's map"
 *		- Sets the default map for the robot test
 */

UCLASS()
class URobotCommandlet : public UCommandlet
{
    GENERATED_UCLASS_BODY()

    static FWorldDelegates::FWorldInitializationEvent::FDelegate OnWorldCreatedDelegate;
    static FDelegateHandle OnWorldCreatedDelegateHandle;

public:
    virtual int32 Main(const FString& Params) override;

    virtual void CreateCustomEngine(const FString& Params) override;

    static void OnWorldCreated(UWorld* UnrealWorld, const UWorld::InitializationValues IVS);
    static void NotifyPostLoadMap();

protected:
    void OnTimer();

    static UGameInstance* GRobotGameInstance;
    static URobotCommandlet* GRobotCommandletInstance;
    static FTimerHandle TriggerTimerHandle;
};
