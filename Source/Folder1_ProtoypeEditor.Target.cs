// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Folder1_ProtoypeEditorTarget : TargetRules
{
	public Folder1_ProtoypeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Folder1_Protoype" } );
	}
}
