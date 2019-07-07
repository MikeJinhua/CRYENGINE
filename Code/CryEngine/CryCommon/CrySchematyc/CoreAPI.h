// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

// Prerequisite headers.

#include <CryMath/Cry_Math.h>
#include <CrySystem/ISystem.h>
#include <CrySystem/XML/IXml.h>

// Core headers.

#include "CrySchematyc/Action.h"
#include "CrySchematyc/Component.h"
#include "CrySchematyc/FundamentalTypes.h"
#include "CrySchematyc/ICore.h"
#include "CrySchematyc/IObject.h"
#include "CrySchematyc/IObjectProperties.h"
#include "CrySchematyc/ResourceTypes.h"
#include <CrySchematyc/MathTypes.h>

#include "CrySchematyc/Compiler/CompilerContext.h"
#include "CrySchematyc/Compiler/ICompiler.h"
#include "CrySchematyc/Compiler/IGraphNodeCompiler.h"

#include "CrySchematyc/Editor/IQuickSearchOptions.h"

#include "CrySchematyc/Env/EnvContext.h"
#include "CrySchematyc/Env/EnvElementBase.h"
#include "CrySchematyc/Env/EnvPackage.h"
#include "CrySchematyc/Env/EnvUtils.h"
#include "CrySchematyc/Env/IEnvContext.h"
#include "CrySchematyc/Env/IEnvElement.h"
#include "CrySchematyc/Env/IEnvPackage.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"
#include "CrySchematyc/Env/IEnvRegistry.h"

#include "CrySchematyc/Env/Elements/EnvAction.h"
#include "CrySchematyc/Env/Elements/EnvClass.h"
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/Elements/EnvDataType.h"
#include "CrySchematyc/Env/Elements/EnvFunction.h"
#include "CrySchematyc/Env/Elements/EnvInterface.h"
#include "CrySchematyc/Env/Elements/EnvModule.h"
#include "CrySchematyc/Env/Elements/EnvSignal.h"
#include "CrySchematyc/Env/Elements/IEnvAction.h"
#include "CrySchematyc/Env/Elements/IEnvClass.h"
#include "CrySchematyc/Env/Elements/IEnvComponent.h"
#include "CrySchematyc/Env/Elements/IEnvDataType.h"
#include "CrySchematyc/Env/Elements/IEnvFunction.h"
#include "CrySchematyc/Env/Elements/IEnvInterface.h"
#include "CrySchematyc/Env/Elements/IEnvModule.h"
#include "CrySchematyc/Env/Elements/IEnvSignal.h"

#include "CrySchematyc/Network/INetworkObject.h"
#include "CrySchematyc/Network/INetworkSpawnParams.h"

#include "CrySchematyc/Reflection/ActionDesc.h"
#include "CrySchematyc/Reflection/ComponentDesc.h"
#include "CrySchematyc/Reflection/FunctionDesc.h"
#include "CrySchematyc/Reflection/ReflectionUtils.h"
#include "CrySchematyc/Reflection/TypeDesc.h"
#include "CrySchematyc/Reflection/TypeOperators.h"

#include "CrySchematyc/Runtime/IRuntimeClass.h"
#include "CrySchematyc/Runtime/IRuntimeRegistry.h"
#include "CrySchematyc/Runtime/RuntimeGraph.h"
#include "CrySchematyc/Runtime/RuntimeParamMap.h"
#include "CrySchematyc/Runtime/RuntimeParams.h"

#include "CrySchematyc/Script/IScript.h"
#include "CrySchematyc/Script/IScriptElement.h"
#include "CrySchematyc/Script/IScriptExtension.h"
#include "CrySchematyc/Script/IScriptGraph.h"
#include "CrySchematyc/Script/IScriptRegistry.h"
#include "CrySchematyc/Script/IScriptView.h"
#include "CrySchematyc/Script/ScriptDependencyEnumerator.h"
#include "CrySchematyc/Script/ScriptUtils.h"

#include "CrySchematyc/Script/Elements/IScriptActionInstance.h"
#include "CrySchematyc/Script/Elements/IScriptBase.h"
#include "CrySchematyc/Script/Elements/IScriptClass.h"
#include "CrySchematyc/Script/Elements/IScriptComponentInstance.h"
#include "CrySchematyc/Script/Elements/IScriptConstructor.h"
#include "CrySchematyc/Script/Elements/IScriptEnum.h"
#include "CrySchematyc/Script/Elements/IScriptFunction.h"
#include "CrySchematyc/Script/Elements/IScriptInterface.h"
#include "CrySchematyc/Script/Elements/IScriptInterfaceFunction.h"
#include "CrySchematyc/Script/Elements/IScriptInterfaceImpl.h"
#include "CrySchematyc/Script/Elements/IScriptInterfaceTask.h"
#include "CrySchematyc/Script/Elements/IScriptModule.h"
#include "CrySchematyc/Script/Elements/IScriptRoot.h"
#include "CrySchematyc/Script/Elements/IScriptSignal.h"
#include "CrySchematyc/Script/Elements/IScriptSignalReceiver.h"
#include "CrySchematyc/Script/Elements/IScriptState.h"
#include "CrySchematyc/Script/Elements/IScriptStateMachine.h"
#include "CrySchematyc/Script/Elements/IScriptStruct.h"
#include "CrySchematyc/Script/Elements/IScriptTimer.h"
#include "CrySchematyc/Script/Elements/IScriptVariable.h"

#include "CrySchematyc/SerializationUtils/ContainerSerializationUtils.h"
#include "CrySchematyc/SerializationUtils/ISerializationContext.h"
#include "CrySchematyc/SerializationUtils/IValidatorArchive.h"
#include "CrySchematyc/SerializationUtils/MultiPassSerializer.h"
#include "CrySchematyc/SerializationUtils/SerializationQuickSearch.h"
#include "CrySchematyc/SerializationUtils/SerializationToString.h"
#include "CrySchematyc/SerializationUtils/SerializationUtils.h"

#include "CrySchematyc/Services/ILog.h"
#include "CrySchematyc/Services/ILogRecorder.h"
#include "CrySchematyc/Services/ISettingsManager.h"
#include "CrySchematyc/Services/ITimerSystem.h"
#include "CrySchematyc/Services/IUpdateScheduler.h"
#include "CrySchematyc/Services/LogMetaData.h"
#include "CrySchematyc/Services/LogStreamName.h"

#include "CrySchematyc/Utils/Any.h"
#include "CrySchematyc/Utils/AnyArray.h"
#include "CrySchematyc/Utils/Array.h"
#include "CrySchematyc/Utils/Assert.h"
#include "CrySchematyc/Utils/CryLinkUtils.h"
#include "CrySchematyc/Utils/Delegate.h"
#include "CrySchematyc/Utils/EnumFlags.h"
#include "CrySchematyc/Utils/GUID.h"
#include "CrySchematyc/Utils/HybridArray.h"
#include "CrySchematyc/Utils/IGUIDRemapper.h"
#include "CrySchematyc/Utils/IInterfaceMap.h"
#include "CrySchematyc/Utils/IString.h"
#include "CrySchematyc/Utils/PreprocessorUtils.h"
#include "CrySchematyc/Utils/RingBuffer.h"
#include "CrySchematyc/Utils/Rotation.h"
#include "CrySchematyc/Utils/ScopedConnection.h"
#include "CrySchematyc/Utils/Scratchpad.h"
#include "CrySchematyc/Utils/SharedString.h"
#include "CrySchematyc/Utils/Signal.h"
#include "CrySchematyc/Utils/StackString.h"
#include "CrySchematyc/Utils/STLUtils.h"
#include "CrySchematyc/Utils/StringHashWrapper.h"
#include "CrySchematyc/Utils/StringUtils.h"
#include "CrySchematyc/Utils/Transform.h"
#include "CrySchematyc/Utils/TypeName.h"
#include "CrySchematyc/Utils/TypeUtils.h"
#include "CrySchematyc/Utils/UniqueId.h"
#include "CrySchematyc/Utils/Validator.h"
