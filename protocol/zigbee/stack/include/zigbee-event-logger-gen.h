/***************************************************************************//**
 * @file
 * @brief Defines for the Zigbee Event Logger component, which describes various
 * events that can be recorded and retrieved for user inspection.
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
//
// *** Generated file. Do not edit! ***
// Generated by: generate-zigbee-logger-files.py -y zigbee_logger.yaml

#ifndef _ZIGBEE_EVENT_LOGGER_GEN_H_

/**
 * @addtogroup zigbee_event_logger_gen
 *
 * This file describes functionality for the Zigbee Event Logger feature. This
 * feature is used to record salient events in the stack and application layer.
 * The system event data is stored in a buffer, with hooks for the application
 * to print and decode the logged data.
 *
 * See zigbee-event-logger-gen.h for source code.
 * @{
 */

/** @brief The version of this feature. */
#define ZIGBEE_EVENT_LOGGER_VERSION 1

#define LOGGER_AREA_BIT_SHIFT 12
#define EMBER_ZIGBEE_LOGGER_AREA (0 << LOGGER_AREA_BIT_SHIFT)

/**
 * @brief A list of identifiers for system events.
 */
typedef enum {
  EMBER_LOGGER_ZIGBEE_BOOT_EVENT_ID = 0,
  EMBER_LOGGER_ZIGBEE_JOIN_NETWORK_ID = 1,
  EMBER_LOGGER_ZIGBEE_TRUST_CENTER_REJOIN_ID = 2,
  EMBER_LOGGER_ZIGBEE_SECURE_REJOIN_ID = 3,
  EMBER_LOGGER_ZIGBEE_LEAVE_WITHOUT_REJOIN_ID = 4,
  EMBER_LOGGER_ZIGBEE_LEAVE_WITH_REJOIN_ID = 5,
  EMBER_LOGGER_ZIGBEE_TRUST_CENTER_LINK_KEY_CHANGE_ID = 6,
  EMBER_LOGGER_ZIGBEE_NETWORK_KEY_SEQUENCE_NUMBER_CHANGE_ID = 7,
  EMBER_LOGGER_ZIGBEE_RESET_ID = 8,
  EMBER_LOGGER_ZIGBEE_CHANNEL_CHANGE_ID = 9,
  EMBER_LOGGER_ZIGBEE_PARENT_CHANGE_ID = 10,
  EMBER_LOGGER_ZIGBEE_DUTY_CYCLE_CHANGE_ID = 11,
  EMBER_LOGGER_ZIGBEE_CHILD_ADDED_ID = 12,
  EMBER_LOGGER_ZIGBEE_CHILD_REMOVED_ID = 13,
  EMBER_LOGGER_ZIGBEE_CHILD_TIMED_OUT_ID = 14,
  EMBER_LOGGER_ZIGBEE_STACK_STATUS_ID = 15,
  EMBER_LOGGER_ZIGBEE_TIME_SYNC_ID = 16,
  EMBER_LOGGER_ZIGBEE_TRUST_CENTER_JOIN_DECISION_ID = 17,
  // Last value. All event IDs should be less than this
  EMBER_LOGGER_ZIGBEE_NULL_ID = 0xFFFF,
} EmberZigbeeLoggerEventTypes;

/**
 * @brief A list of facilities for system events, identifying which layer they occurred in.
 */
typedef enum {
  EMBER_LOGGER_ZIGBEE_FACILITY_BASE = 0,
  EMBER_LOGGER_ZIGBEE_FACILITY_MAC = 1,
  EMBER_LOGGER_ZIGBEE_FACILITY_NETWORK = 2,
  EMBER_LOGGER_ZIGBEE_FACILITY_APS = 3,
  EMBER_LOGGER_ZIGBEE_FACILITY_SECURITY = 4,
  EMBER_LOGGER_ZIGBEE_FACILITY_ZDO = 5,
  EMBER_LOGGER_ZIGBEE_FACILITY_ZCL = 6,
  EMBER_LOGGER_ZIGBEE_FACILITY_BDB = 7,
  EMBER_LOGGER_ZIGBEE_FACILITY_SMART_ENERGY = 8,
} EmberZigbeeLoggerFacilityTypes;

/** @brief The length of the Boot Event event data. */
#define EMBER_LOGGER_ZIGBEE_BOOT_EVENT_LENGTH 6
/** @brief The length of the Join Network event data. */
#define EMBER_LOGGER_ZIGBEE_JOIN_NETWORK_LENGTH 12
/** @brief The length of the Trust Center Rejoin event data. */
#define EMBER_LOGGER_ZIGBEE_TRUST_CENTER_REJOIN_LENGTH 5
/** @brief The length of the Secure Rejoin event data. */
#define EMBER_LOGGER_ZIGBEE_SECURE_REJOIN_LENGTH 5
/** @brief The length of the Leave Without Rejoin event data. */
#define EMBER_LOGGER_ZIGBEE_LEAVE_WITHOUT_REJOIN_LENGTH 3
/** @brief The length of the Leave With Rejoin event data. */
#define EMBER_LOGGER_ZIGBEE_LEAVE_WITH_REJOIN_LENGTH 3
/** @brief The length of the Trust Center Link Key Change event data. */
#define EMBER_LOGGER_ZIGBEE_TRUST_CENTER_LINK_KEY_CHANGE_LENGTH 0
/** @brief The length of the Network Key Sequence Number Change event data. */
#define EMBER_LOGGER_ZIGBEE_NETWORK_KEY_SEQUENCE_NUMBER_CHANGE_LENGTH 1
/** @brief The length of the Reset event data. */
#define EMBER_LOGGER_ZIGBEE_RESET_LENGTH 2
/** @brief The length of the Channel Change event data. */
#define EMBER_LOGGER_ZIGBEE_CHANNEL_CHANGE_LENGTH 2
/** @brief The length of the Parent Change event data. */
#define EMBER_LOGGER_ZIGBEE_PARENT_CHANGE_LENGTH 10
/** @brief The length of the Duty Cycle Change event data. */
#define EMBER_LOGGER_ZIGBEE_DUTY_CYCLE_CHANGE_LENGTH 7
/** @brief The length of the Child Added event data. */
#define EMBER_LOGGER_ZIGBEE_CHILD_ADDED_LENGTH 10
/** @brief The length of the Child Removed event data. */
#define EMBER_LOGGER_ZIGBEE_CHILD_REMOVED_LENGTH 10
/** @brief The length of the Child Timed Out event data. */
#define EMBER_LOGGER_ZIGBEE_CHILD_TIMED_OUT_LENGTH 10
/** @brief The length of the Stack Status event data. */
#define EMBER_LOGGER_ZIGBEE_STACK_STATUS_LENGTH 1
/** @brief The length of the Time Sync event data. */
#define EMBER_LOGGER_ZIGBEE_TIME_SYNC_LENGTH 8
/** @brief The length of the Trust Center Join Decision event data. */
#define EMBER_LOGGER_ZIGBEE_TRUST_CENTER_JOIN_DECISION_LENGTH 3

/** @brief Records an event indicating that the device has booted.
 * @param bootCount  The number of times the device has booted.
 * @param resetType  A reset cause. See micro.h and reset-def.h.
 * @note This API only works on SoC. It does not work on host or NCP.
 */
void emberAfPluginZigBeeEventLoggerAddBootEvent(uint32_t bootCount, uint16_t resetType)
;
/** @brief Records an event indicating that a network was successfully joined.
 * @param panId  The PAN ID of the network.
 * @param channelNumber  The channel of the network.
 * @param page  The page of the network joined.
 * @param extendedPanId  The extended PAN ID of the network.
 */
void emberAfPluginZigBeeEventLoggerAddJoinNetwork(EmberPanId panId, uint8_t channelNumber, uint8_t page, uint8_t *extendedPanId)
;
/** @brief Records an event indicating that a trust center rejoin was attempted.
 * @param channelMask  The channel mask used when searching for the network.
 * @param reason  An EmberRejoinReason enumeration, indicating why the rejoin was initiated.
 * @note This event only indicates that a rejoin was attempted, not that it was successful. A Join Network event, following this event, indicates success. */
void emberAfPluginZigBeeEventLoggerAddTrustCenterRejoin(uint32_t channelMask, EmberRejoinReason reason)
;
/** @brief Records an event indicating that a secure rejoin was attempted.
 * @param channelMask  The channel mask used when searching for the network.
 * @param reason  An EmberRejoinReason enumeration, indicating why the rejoin was initiated.
 * @note This event only indicates that a rejoin was attempted, not that it was successful. A Join Network event, following this event, indicates success. */
void emberAfPluginZigBeeEventLoggerAddSecureRejoin(uint32_t channelMask, EmberRejoinReason reason)
;
/** @brief Records an event indicating that a device has left-without-rejoin.
 * @param sourceNode  The node ID of the device leaving.
 * @param reason  An EmberLeaveReason enumeration, indicating why the device left.
 */
void emberAfPluginZigBeeEventLoggerAddLeaveWithoutRejoin(EmberNodeId sourceNode, EmberLeaveReason reason)
;
/** @brief Records an event indicating that a device has left-with-rejoin.
 * @param sourceNode  The node ID of the device leaving-and-rejoining.
 * @param reason  An EmberLeaveReason enumeration, indicating why the device left.
 */
void emberAfPluginZigBeeEventLoggerAddLeaveWithRejoin(EmberNodeId sourceNode, EmberLeaveReason reason)
;
/** @brief Records an event indicating that an attempt was made to update the trust center link key.
 */
void emberAfPluginZigBeeEventLoggerAddTrustCenterLinkKeyChange(void)
;
/** @brief Records an event indicating that the network key sequence number has changed.
 * @param sequence  The new network key sequence number.
 */
void emberAfPluginZigBeeEventLoggerAddNetworkKeySequenceChange(uint8_t sequence)
;
/** @brief Records an event indicating that the local device has reset.
 * @param resetCode  The reset code. See reset-def.h.
 * @param extendedReason  The extended reset reason. See reset-def.h.
 */
void emberAfPluginZigBeeEventLoggerAddReset(uint8_t resetCode, uint8_t extendedReason)
;
/** @brief Records an event indicating that the network's channel has changed.
 * @param page  The new page number.
 * @param channel  The new channel number.
 */
void emberAfPluginZigBeeEventLoggerAddChannelChange(uint8_t page, uint8_t channel)
;
/** @brief Records an event indicating that the local device's parent has changed.
 * @param parentNodeId  The new parent's short address.
 * @param parentEui64  The new parent's long address.
 */
void emberAfPluginZigBeeEventLoggerAddParentChange(EmberNodeId parentNodeId, EmberEUI64 parentEui64)
;
/** @brief Records an event indicating that the duty cycle has changed.
 * @param state  An EmberDutyCycleState state.
 * @param limitThreshold  An EmberDutyCycleHectoPct limit.
 * @param criticalThreshold  An EmberDutyCycleHectoPct critical threshold.
 * @param suspendedLimit  An EmberDutyCycleHectoPct suspend limit.
 */
void emberAfPluginZigBeeEventLoggerAddDutyCycleChange(EmberDutyCycleState state, EmberDutyCycleHectoPct limitThreshold, EmberDutyCycleHectoPct criticalThreshold, EmberDutyCycleHectoPct suspendedLimit)
;
/** @brief Records an event indicating that a child device has joined the local device.
 * @param childNodeId  The child's short address.
 * @param childEui64  The child's long address.
 */
void emberAfPluginZigBeeEventLoggerAddChildAdded(EmberNodeId childNodeId, EmberEUI64 childEui64)
;
/** @brief Records an event indicating that a child device has been removed from the local device.
 * @param childNodeId  The child's short address.
 * @param childEui64  The child's long address.
 */
void emberAfPluginZigBeeEventLoggerAddChildRemoved(EmberNodeId childNodeId, EmberEUI64 childEui64)
;
/** @brief Records an event indicating that a child device has been timed out by the local device.
 * @param childNodeId  The child's short address.
 * @param childEui64  The child's long address.
 */
void emberAfPluginZigBeeEventLoggerAddChildTimedOut(EmberNodeId childNodeId, EmberEUI64 childEui64)
;
/** @brief Records an event indicating that the stack status has changed.
 * @param status  An EmberStatus value indicating the change.
 */
void emberAfPluginZigBeeEventLoggerAddStackStatus(EmberStatus status)
;
/** @brief Records an event indicating that the clock time has been synchronized.
 * @param utcTime  The updated UTC time.
 * @param secondsSinceBoot  The number of seconds that have elapsed since boot.
 */
void emberAfPluginZigBeeEventLoggerAddTimeSync(uint32_t utcTime, uint32_t secondsSinceBoot)
;
/** @brief Records an event indicating that a device has attempted to join or rejoin the network.
 * @param nodeId  The short address of the device attempting to join or rejoin.
 * @param decision  The join or rejoin decision taken by the local device.
 * @note This event is only recorded on a trust center device. */
void emberAfPluginZigBeeEventLoggerAddTrustCenterJoinDecision(EmberNodeId nodeId, uint8_t decision)
;

/** @} END addtogroup */

#endif  // #ifndef _ZIGBEE_EVENT_LOGGER_GEN_H_