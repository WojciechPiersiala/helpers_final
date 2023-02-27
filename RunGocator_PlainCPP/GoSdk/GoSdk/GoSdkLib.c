/**
 * @file    GoSdkLib.c
 *
 * @internal
 * Copyright (C) 2016-2020 by LMI Technologies Inc.
 * Licensed under the MIT License.
 * Redistributed files must retain the above copyright notice.
 */
#include <GoSdk/GoSdkLib.h>
#include <kApi/kApiLib.h>
#include <GoSdk/GoSdk.h>

#define GO_SDK_VERSION  kVersion_Stringify_(GO_SDK_VERSION_MAJOR, GO_SDK_VERSION_MINOR, GO_SDK_VERSION_RELEASE, GO_SDK_VERSION_BUILD)

kBeginAssemblyEx(Go, GoSdk, GO_SDK_VERSION, GO_SDK_VERSION)

    // Dependencies.
    kAddDependency(kApiLib)

    // Values.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoAcceleratorConnectionStatus)
    kAddType(GoAcceleratorMgrAccelEvents)
    kAddType(GoAcceleratorMgrAccelUpdate)
    kAddType(GoAcceleratorMgrSensorEntry)
    kAddType(GoAcceleratorMgrSensorParam)
    kAddType(GoAcceleratorMgrSensorBackup)
    kAddType(GoAcceleratorMgrSensorInfo)
    kAddType(GoAcceleratorMgrWorkerMsg)
    kAddType(GoAccelSensorPortAllocPorts)
    kAddType(GoActiveAreaConfig)
    kAddType(GoAddressInfo)
    kAddType(GoAdvancedType)
    kAddType(GoAlignmentRef)
    kAddType(GoAlignmentState)
    kAddType(GoAlignmentStatus)
    kAddType(GoAlignmentTarget)
    kAddType(GoAlignmentType)
    kAddType(GoAlignmentDegreesOfFreedom)
    kAddType(GoAnalogEvent)
    kAddType(GoAnalogTrigger)
    kAddType(GoAsciiOperation)
    kAddType(GoAsciiStandardFormatMode)
    kAddType(GoBoxAsymmetryType)
    kAddType(GoBrandingType)
    kAddType(GoBuddyInfo)
    kAddType(GoBuddyState)
    kAddType(GoDataMessageType)
    kAddType(GoDataSource)
    kAddType(GoDataStep)
    kAddType(GoDataStream)
    kAddType(GoDataStreamId)
    kAddType(GoDataType)
    kAddType(GoDecision)
    kAddType(GoDecisionCode)
    kAddType(GoDemosaicStyle)
    kAddType(GoDeviceState)
    kAddType(GoDigitalEvent)
    kAddType(GoDigitalPass)
    kAddType(GoDigitalSignal)
    kAddType(GoDiscoveryInfo)
    kAddType(GoDiscoveryInterface)
    kAddType(GoDiscoveryOpMode)
    kAddType(GoDiscoveryProperty)
    kAddType(GoElement32u)
    kAddType(GoElement64f)
    kAddType(GoElementBool)
    kAddType(GoEllipseAsymmetryType)
    kAddType(GoEncoderSpacingMinSource)
    kAddType(GoEncoderTriggerMode)
    kAddType(GoEndianType)
    kAddType(GoEthernetProtocol)
    kAddType(GoIntensitySource)
    kAddType(GoIntensityMode)
    kAddType(GoExposureMode)
    kAddType(GoExtParamFloatOption)
    kAddType(GoExtParamIntOption)
    kAddType(GoExtParamType)
    kAddType(GoExtMeasurementType)
    kAddType(GoExtToolDataOutput)
    kAddType(GoEventType)
    kAddType(GoFamily)
    kAddType(GoFeatureDataType)
    kAddType(GoFeatureOption)
    kAddType(GoFeatureType)
    kAddType(GoFilter)
    kAddType(GoFrameRateMaxSource)
    kAddType(GoGammaType)
    kAddType(GoHealthIndicatorId)
    kAddType(GoImageType)
    kAddType(GoImplicitTriggerOverride)
    kAddType(GoIndicator)
    kAddType(GoInputSource)
    kAddType(GoMaterialType)
    kAddType(GoMeasurementData)
    kAddType(GoMeasurementOption)
    kAddType(GoMeasurementType)
    kAddType(GoMode)
    kAddType(GoMultiplexBank)
    kAddType(GoOcclusionReductionAlg)
    kAddType(GoOrientation)
    kAddType(GoOutputDelayDomain)
    kAddType(GoOutputSource)
    kAddType(GoOutputCompositeSource)
    kAddType(GoPartFrameOfReference)
    kAddType(GoPartHeightThresholdDirection)
    kAddType(GoPartMatchAlgorithm)
    kAddType(GoPatternSequenceType)
    kAddType(GoPixelType)
    kAddType(GoPolygonCornerParameters)
    kAddType(GoPortInfo)
    kAddType(GoProfileAreaType)
    kAddType(GoProfileBaseline)
    kAddType(GoProfileEdgeType)
    kAddType(GoProfileFeatureType)
    kAddType(GoProfileGapAxis)
    kAddType(GoProfileGenerationStartTrigger)
    kAddType(GoProfileGenerationType)
    kAddType(GoProfileGrooveLocation)
    kAddType(GoProfileGrooveSelectType)
    kAddType(GoProfileGrooveShape)
    kAddType(GoProfilePanelSide)
    kAddType(GoProfileRoundCornerDirection)
    kAddType(GoProfileStripBaseType)
    kAddType(GoProfileStripEdgeType)
    kAddType(GoProfileStripLocation)
    kAddType(GoProfileStripSelectType)
    kAddType(GoReplayCombineType)
    kAddType(GoReplayConditionType)
    kAddType(GoReplayMeasurementResult)
    kAddType(GoReplayRangeCountCase)
    kAddType(GoReplayExportSourceType)
    kAddType(GoRole)
    kAddType(GoSecurityLevel)
    kAddType(GoSeekDirection)
    kAddType(GoSelcomFormat)
    kAddType(GoSensorAccelState)
    kAddType(GoSensorAccelStatus)
    kAddType(GoSerialProtocol)
    kAddType(GoSerializerTypeInfo)
    kAddType(GoSpacingIntervalType)
    kAddType(GoSpotSelectionType)
    kAddType(GoStamp)
    kAddType(GoState)
    kAddType(GoStates)
    kAddType(GoSurfaceCountersunkHoleShape)
    kAddType(GoSurfaceEncoding)
    kAddType(GoSurfaceFeatureType)
    kAddType(GoSurfaceGenerationStartTrigger)
    kAddType(GoSurfaceGenerationType)
    kAddType(GoSurfaceLocation)
    kAddType(GoSurfaceOpeningType)
    kAddType(GoSurfacePhaseFilter)
    kAddType(GoSurfaceRivetType)
    kAddType(GoToolDataOutputOption)
    kAddType(GoToolOption)
    kAddType(GoToolType)
    kAddType(GoTracheidEllipse)
    kAddType(GoTransformation)
    kAddType(GoTransformedDataRegion)
    kAddType(GoTrigger)
    kAddType(GoTriggerSource)
    kAddType(GoTriggerUnits)
    kAddType(GoUser)
    kAddType(GoVoltageSetting)

    // Non-Configuration classes. 
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoAccelerator)
    kAddType(GoAcceleratorMgr)
    kAddType(GoAccelSensorPortAlloc)
    kAddType(GoControl)
    kAddType(GoDataSet)
    kAddType(GoDiscovery)
    kAddType(GoDiscoveryExtInfo)
    kAddType(GoReceiver)
    kAddType(GoSensorInfo)
    kAddType(GoSerializer)
    kAddType(GoSystem)

    // Configuration classes.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoAdvanced)
    kAddType(GoAnalog)
    kAddType(GoDigital)
    kAddType(GoEthernet)
    kAddType(GoGeoCal)
    kAddType(GoLayout)
    kAddType(GoOutput)
    kAddType(GoPartDetection)
    kAddType(GoPartMatching)
    kAddType(GoPartModel)
    kAddType(GoPartModelEdge)
    kAddType(GoProfileGeneration)
    kAddType(GoRecordingFilter)
    kAddType(GoReplay)
    kAddType(GoReplayCondition)
    kAddType(GoReplayAnyMeasurement)
    kAddType(GoReplayAnyData)
    kAddType(GoReplayMeasurement)
    kAddType(GoSection)
    kAddType(GoSections)
    kAddType(GoSensor)
    kAddType(GoSerial)
    kAddType(GoSetup)
    kAddType(GoSetupNode)
    kAddType(GoSurfaceGeneration)
    kAddType(GoTracheid)
    kAddType(GoTransform)

    // Message types.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(Go3dTransform64f)
    kAddType(GoAlignMsg)
    kAddType(GoBoundingBoxMatchMsg)
    kAddType(GoCircleFeatureMsg)
    kAddType(GoDataMsg)
    kAddType(GoEdgeMatchMsg)
    kAddType(GoEllipseMatchMsg)
    kAddType(GoExposureCalMsg)
    kAddType(GoEventMsg)
    kAddType(GoFacet32u)
    kAddType(GoGenericMsg)
    kAddType(GoHealthMsg)
    kAddType(GoLineFeatureMsg)
    kAddType(GoMeasurementMsg)
    kAddType(GoMeshMsg)
    kAddType(GoMeshMsgChannel)
    kAddType(GoNullMsg)
    kAddType(GoPlaneFeatureMsg)
    kAddType(GoPointFeatureMsg)
    kAddType(GoProfileIntensityMsg)
    kAddType(GoProfilePointCloudMsg)
    kAddType(GoRangeIntensityMsg)
    kAddType(GoRangeMsg)
    kAddType(GoSectionMsg)
    kAddType(GoSectionIntensityMsg)
    kAddType(GoStampMsg)
    kAddType(GoSurfaceIntensityMsg)
    kAddType(GoSurfacePointCloudMsg)
    kAddType(GoTracheidMsg)
    kAddType(GoUniformProfileMsg)
    kAddType(GoUniformSurfaceMsg)
    kAddType(GoVideoMsg)
    //Deprecated
    //kAddType(GoProfileMsg)
    //kAddType(GoResampledProfileMsg)
    //kAddType(GoSurfaceMsg)

    // Profile measurement related classes.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoProfileEdge)
    kAddType(GoProfileFeature)
    kAddType(GoProfileLineFittingRegion)
    kAddType(GoProfileRegion)

    // Surface measurement related classes.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoCylinderRegion)
    kAddType(GoPointSetRegion)
    kAddType(GoRegion3d)
    kAddType(GoSurfaceFeature)
    kAddType(GoSurfaceRegion2d)

    // Tool list, base tool and measurement classes.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoExtFeature)
    kAddType(GoExtParam)
    kAddType(GoExtParams)
    kAddType(GoExtMeasurement)
    kAddType(GoExtTool)
    kAddType(GoFeature)
    kAddType(GoFeatures)
    kAddType(GoFeaturesNameTypeMapping)
    kAddType(GoMeasurement)
    kAddType(GoMeasurements)
    kAddType(GoMeasurementsNameTypeMapping)
    kAddType(GoTool)
    kAddType(GoTools)

    // Extensible tool parameter classes.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoExtParamBool)
    kAddType(GoExtParamDataInput)
    kAddType(GoExtParamInt)
    kAddType(GoExtParamFeature)
    kAddType(GoExtParamFloat)
    kAddType(GoExtParamPointSetRegion)
    kAddType(GoExtParamProfileRegion)
    kAddType(GoExtParamString)
    kAddType(GoExtParamSurfaceRegion2d)
    kAddType(GoExtParamSurfaceRegion3d)

    // Range tools and measurements.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoRangePosition)
    kAddType(GoRangePositionZ)
    kAddType(GoRangeThickness)
    kAddType(GoRangeThicknessThickness)
    kAddType(GoRangeTool)

    // GoProfile tools and measurements.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoProfileArea)
    kAddType(GoProfileAreaArea)
    kAddType(GoProfileAreaCentroidX)
    kAddType(GoProfileAreaCentroidZ)
    kAddType(GoProfileBox)
    kAddType(GoProfileBoxX)
    kAddType(GoProfileBoxZ)
    kAddType(GoProfileBoxWidth)
    kAddType(GoProfileBoxHeight)
    kAddType(GoProfileBoxGlobalX)
    kAddType(GoProfileBoxGlobalY)
    kAddType(GoProfileBoxGlobalAngle)
    kAddType(GoProfileBridgeValue)
    kAddType(GoProfileBridgeValueAngle)
    kAddType(GoProfileBridgeValueBridgeValue)
    kAddType(GoProfileBridgeValueWindow)
    kAddType(GoProfileBridgeValueStdDev)
    kAddType(GoProfileCircle)
    kAddType(GoProfileCircleRadius)
    kAddType(GoProfileCircleX)
    kAddType(GoProfileCircleZ)
    kAddType(GoProfileCircleStdDev)
    kAddType(GoProfileCircleMinError)
    kAddType(GoProfileCircleMinErrorX)
    kAddType(GoProfileCircleMinErrorZ)
    kAddType(GoProfileCircleMaxError)
    kAddType(GoProfileCircleMaxErrorX)
    kAddType(GoProfileCircleMaxErrorZ)
    kAddType(GoProfileDim)
    kAddType(GoProfileDimCenterX)
    kAddType(GoProfileDimCenterZ)
    kAddType(GoProfileDimDistance)
    kAddType(GoProfileDimHeight)
    kAddType(GoProfileDimWidth)
    kAddType(GoProfileGroove)
    kAddType(GoProfileGrooveDepth)
    kAddType(GoProfileGrooveWidth)
    kAddType(GoProfileGrooveX)
    kAddType(GoProfileGrooveZ)
    kAddType(GoProfileIntersect)
    kAddType(GoProfileIntersectAngle)
    kAddType(GoProfileIntersectX)
    kAddType(GoProfileIntersectZ)
    kAddType(GoProfileLine)
    kAddType(GoProfileLineMaxError)
    kAddType(GoProfileLineMinError)
    kAddType(GoProfileLinePercentile)
    kAddType(GoProfileLineOffset)
    kAddType(GoProfileLineAngle)
    kAddType(GoProfileLineMinErrorX)
    kAddType(GoProfileLineMinErrorZ)
    kAddType(GoProfileLineMaxErrorX)
    kAddType(GoProfileLineMaxErrorZ)
    kAddType(GoProfileLineStdDev)
    kAddType(GoProfilePanel)
    kAddType(GoProfilePanelFlush)
    kAddType(GoProfilePanelGap)
    kAddType(GoProfilePanelLeftFlushX)
    kAddType(GoProfilePanelLeftFlushZ)
    kAddType(GoProfilePanelLeftGapX)
    kAddType(GoProfilePanelLeftGapZ)
    kAddType(GoProfilePanelLeftSurfaceAngle)
    kAddType(GoProfilePanelRightFlushX)
    kAddType(GoProfilePanelRightFlushZ)
    kAddType(GoProfilePanelRightGapX)
    kAddType(GoProfilePanelRightGapZ)
    kAddType(GoProfilePanelRightSurfaceAngle)
    kAddType(GoProfilePosition)
    kAddType(GoProfilePositionX)
    kAddType(GoProfilePositionZ)
    kAddType(GoProfileRoundCorner)
    kAddType(GoProfileRoundCornerX)
    kAddType(GoProfileRoundCornerZ)
    kAddType(GoProfileRoundCornerAngle)
    kAddType(GoProfileStrip)
    kAddType(GoProfileStripHeight)
    kAddType(GoProfileStripWidth)
    kAddType(GoProfileStripX)
    kAddType(GoProfileStripZ)
    kAddType(GoProfileTool)
    kAddType(GoProfileXLine)
    kAddType(GoProfileXLineZ)
    kAddType(GoProfileXLineValidity)

    // Surface tools and measurements.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoSurfaceBox)
    kAddType(GoSurfaceBoxGlobalX)
    kAddType(GoSurfaceBoxGlobalY)
    kAddType(GoSurfaceBoxGlobalZAngle)
    kAddType(GoSurfaceBoxHeight)
    kAddType(GoSurfaceBoxLength)
    kAddType(GoSurfaceBoxWidth)
    kAddType(GoSurfaceBoxX)
    kAddType(GoSurfaceBoxY)
    kAddType(GoSurfaceBoxZ)
    kAddType(GoSurfaceBoxZAngle)
    kAddType(GoSurfaceCountersunkHole)
    kAddType(GoSurfaceCountersunkHoleBevelAngle)
    kAddType(GoSurfaceCountersunkHoleBevelRadius)
    kAddType(GoSurfaceCountersunkHoleDepth)
    kAddType(GoSurfaceCountersunkHoleOuterRadius)
    kAddType(GoSurfaceCountersunkHoleX)
    kAddType(GoSurfaceCountersunkHoleXAngle)
    kAddType(GoSurfaceCountersunkHoleY)
    kAddType(GoSurfaceCountersunkHoleYAngle)
    kAddType(GoSurfaceCountersunkHoleZ)
    kAddType(GoSurfaceCountersunkHoleCounterboreDepth)
    kAddType(GoSurfaceCountersunkHoleAxisTilt)
    kAddType(GoSurfaceCountersunkHoleAxisOrientation)
    kAddType(GoSurfaceDim)
    kAddType(GoSurfaceDimWidth)
    kAddType(GoSurfaceDimHeight)
    kAddType(GoSurfaceDimLength)
    kAddType(GoSurfaceDimDistance)
    kAddType(GoSurfaceDimPlaneDistance)
    kAddType(GoSurfaceDimCenterX)
    kAddType(GoSurfaceDimCenterY)
    kAddType(GoSurfaceDimCenterZ)
    kAddType(GoSurfaceEllipse)
    kAddType(GoSurfaceEllipseMajor)
    kAddType(GoSurfaceEllipseMinor)
    kAddType(GoSurfaceEllipseRatio)
    kAddType(GoSurfaceEllipseZAngle)
    kAddType(GoSurfaceHole)
    kAddType(GoSurfaceHoleRadius)
    kAddType(GoSurfaceHoleX)
    kAddType(GoSurfaceHoleY)
    kAddType(GoSurfaceHoleZ)
    kAddType(GoSurfaceOpening)
    kAddType(GoSurfaceOpeningAngle)
    kAddType(GoSurfaceOpeningLength)
    kAddType(GoSurfaceOpeningWidth)
    kAddType(GoSurfaceOpeningX)
    kAddType(GoSurfaceOpeningY)
    kAddType(GoSurfaceOpeningZ)
    kAddType(GoSurfacePlane)
    kAddType(GoSurfacePlaneXAngle)
    kAddType(GoSurfacePlaneYAngle)
    kAddType(GoSurfacePlaneZOffset)
    kAddType(GoSurfacePlaneStdDev)
    kAddType(GoSurfacePlaneMinError)
    kAddType(GoSurfacePlaneMaxError)
    kAddType(GoSurfacePlaneXNormal)
    kAddType(GoSurfacePlaneYNormal)
    kAddType(GoSurfacePlaneZNormal)
    kAddType(GoSurfacePlaneDistance)
    kAddType(GoSurfacePosition)
    kAddType(GoSurfacePositionX)
    kAddType(GoSurfacePositionY)
    kAddType(GoSurfacePositionZ)
    kAddType(GoSurfaceRivet)
    kAddType(GoSurfaceRivetX)
    kAddType(GoSurfaceRivetY)
    kAddType(GoSurfaceRivetZ)
    kAddType(GoSurfaceRivetTiltAngle)
    kAddType(GoSurfaceRivetTiltDirection)
    kAddType(GoSurfaceRivetRadius)
    kAddType(GoSurfaceRivetTopOffsetMin)
    kAddType(GoSurfaceRivetTopOffsetMax)
    kAddType(GoSurfaceRivetTopOffsetMean)
    kAddType(GoSurfaceRivetTopOffsetStdDev)
    kAddType(GoSurfaceRivetRadialHeightMin)
    kAddType(GoSurfaceRivetRadialHeightMax)
    kAddType(GoSurfaceRivetRadialHeightMean)
    kAddType(GoSurfaceRivetRadialHeightStdDev)
    kAddType(GoSurfaceRivetRadialSlopeMin)
    kAddType(GoSurfaceRivetRadialSlopeMax)
    kAddType(GoSurfaceRivetRadialSlopeMean)
    kAddType(GoSurfaceRivetRadialSlopeStdDev)
    kAddType(GoSurfaceStud)
    kAddType(GoSurfaceStudBaseX)
    kAddType(GoSurfaceStudBaseY)
    kAddType(GoSurfaceStudBaseZ)
    kAddType(GoSurfaceStudRadius)
    kAddType(GoSurfaceStudTipX)
    kAddType(GoSurfaceStudTipY)
    kAddType(GoSurfaceStudTipZ)
    kAddType(GoSurfaceTool)
    kAddType(GoSurfaceVolume)
    kAddType(GoSurfaceVolumeArea)
    kAddType(GoSurfaceVolumeThickness)
    kAddType(GoSurfaceVolumeVolume)
    // Features.
    // Keep these in alphabetical order to make them easier to find.
    kAddType(GoSurfaceBoundingBoxCenterPoint)
    kAddType(GoSurfaceCountersunkHoleCenterPoint)
    kAddType(GoSurfaceDimensionCenterPoint)
    kAddType(GoSurfaceEdgeCenterPoint)
    kAddType(GoSurfaceEdgeEdgeLine)
    kAddType(GoSurfaceEllipseCenterPoint)
    kAddType(GoSurfaceEllipseMajorAxisLine)
    kAddType(GoSurfaceEllipseMinorAxisLine)
    kAddType(GoSurfaceHoleCenterPoint)
    kAddType(GoSurfaceOpeningCenterPoint)
    kAddType(GoSurfacePlanePlane)
    kAddType(GoSurfacePositionPoint)
    kAddType(GoSurfaceStudTipPoint)
    kAddType(GoSurfaceStudBasePoint)

    kAddType(GoProfileAreaCenterPoint)
    kAddType(GoProfileBoundingBoxCenterPoint)
    kAddType(GoProfileBoundingBoxCornerPoint)
    kAddType(GoProfileCircleCenterPoint)
    kAddType(GoProfileDimensionCenterPoint)
    kAddType(GoProfileIntersectBaseLine)
    kAddType(GoProfileIntersectIntersectPoint)
    kAddType(GoProfileIntersectLine)
    kAddType(GoProfileLineLine)
    kAddType(GoProfileLineMaxErrorPoint)
    kAddType(GoProfileLineMinErrorPoint)
    kAddType(GoProfilePanelLeftFlushPoint)
    kAddType(GoProfilePanelLeftGapPoint)
    kAddType(GoProfilePanelRightFlushPoint)
    kAddType(GoProfilePanelRightGapPoint)
    kAddType(GoProfilePositionPoint)
    kAddType(GoProfileRoundCornerCenterPoint)
    kAddType(GoProfileRoundCornerEdgePoint)
    kAddType(GoProfileRoundCornerPoint)

    //Script tool and output
    kAddType(GoScript)
    kAddType(GoScriptOutput)

kEndAssemblyEx()