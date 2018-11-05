/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016, 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __AUDIO_SPEAKER_H__
#define __AUDIO_SPEAKER_H__

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MOUSE_MAX_COUNT 2
#define HOST_VOLUME_STEP 1
#define HOST_MIN_VOLUME 0
#define HOST_MAX_VOLUME 10

#define EP_TYPE_MASK (0x03)

/*! @brief host app run status */
typedef enum __host_audio_app_runState
{
    kUSB_HostAudioRunIdle = 0,                    /*!< idle */
    kUSB_HostAudioRunSetControlInterface,         /*!< execute set control interface code */
    kUSB_HostAudioRunSetControlInterfaceDone,     /*!<  set control interface done */
    kUSB_HostAudioRunWaitSetControlInterface,     /*!< wait control interface done */
    kUSB_HostAudioRunWaitSetStreamInterface,      /*!< wait steam interface done */
    kUSB_HostAudioRunSetInterfaceDone,            /*!< set interface done */
    kUSB_HostAudioRunWaitGetStreamDescriptor,     /*!< wait get stream descriotor */
    kUSB_HostAudioRunGetStreamDescriptorDone,     /*!< get stream descriotor done */
    kUSB_HostAudioRunWaitAudioGetMinVolume,       /*!< wait get minimum volume command done */
    kUSB_HostAudioRunAudioGetMaxVolume,           /*!< execute get maximum volume command done */
    kUSB_HostAudioRunWaitAudioGetMaxVolume,       /*!< wait get maximum volume command done */
    kUSB_HostAudioRunAudioGetResVolume,           /*!< execute get res volume command done */
    kUSB_HostAudioRunWaitAudioGetResVolume,       /*!< wait get res volume command done */
    kUSB_HostAudioRunAudioConfigChannel,          /*!< execute config audio channel */
    kUSB_HostAudioRunWaitAudioConfigChannel,      /*!< wait config audio channel */
    kUSB_HostAudioRunAudioConfigChannel1Vol,      /*!< execute config audio channel 1*/
    kUSB_HostAudioRunWaitAudioConfigChannel1Vol,  /*!< wait config audio channel 1*/
    kUSB_HostAudioRunAudioConfigChannel2Vol,      /*!< execute config audio channel 2*/
    kUSB_HostAudioRunWaitAudioConfigChannel2Vol,  /*!< wait config audio channel 2*/
    kUSB_HostAudioRunWaitAudioSetCurSamplingFreq, /*!< wait config audio set sampling freq*/
    kUSB_HostAudioRunAudioSetCurSamplingFreq,     /*!< execute audio set current sampling freq*/
    kUSB_HostAudioRunAudioConfigMute,             /*!< execute audio config mute*/
    kUSB_HostAudioRunWaitAudioConfigMute,         /*!< wait audio config mute*/
    kUSB_HostAudioRunAudioDone,                   /*!< audio done */
} host_audio_app_runState_t;

/*! @brief USB host audio instance structure */
typedef struct _audio_speraker_instance
{
    usb_device_handle deviceHandle;              /*!< the audio speaker device handle */
    usb_host_class_handle classHandle;           /*!< the audio speaker class handle */
    usb_host_interface_handle controlIntfHandle; /*!< the audio speaker control interface handle */
    usb_host_interface_handle streamIntfHandle;  /*!< the audio speaker stream interface handle */
    uint8_t devState;                            /*!< device attach/detach status */
    uint8_t prevState;                           /*!< device attach/detach previous status */
    uint8_t runState;                            /*!< audio speaker application run status */
    uint8_t runWaitState;                        /*!< audio speaker application run status */
    uint16_t maxPacketSize;                      /*!< iso max packet size */
    uint8_t dataReceived;                        /*!< data recived  */
    uint8_t deviceIsUsed;                        /*!< device is used or not */
    uint8_t bufCount;                            /*!< audio buffer count*/
} audio_speraker_instance_t;

#endif /* __AUDIO_SPEAKER_H__ */
