// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Folder1_ProtoypeTarget : TargetRules
{
	public Folder1_ProtoypeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Folder1_Protoype" } );
	}
}
