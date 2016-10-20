/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc
 *
 * @file    saiacl.h
 *
 * @brief   This module defines SAI ACL interface
 */

#if !defined (__SAIACL_H_)
#define __SAIACL_H_

#include <saitypes.h>

/**
 * @defgroup SAIACL SAI - ACL specific API definitions
 *
 * @{
 */

/**
 * @brief Attribute data for SAI_ACL_TABLE_ATTR_STAGE
 */
typedef enum _sai_acl_stage_t
{
    /** Ingress Stage */
    SAI_ACL_STAGE_INGRESS,

    /** Egress Stage */
    SAI_ACL_STAGE_EGRESS,

} sai_acl_stage_t;

/**
 * @brief Attribute data for SAI_ACL_TABLE_ATTR_BIND_POINT
 */
typedef enum _sai_acl_bind_point_t
{
    /** Port Bind Point */
    SAI_ACL_PORT_BIND_POINT,

    /** LAG Bind Point */
    SAI_ACL_LAG_BIND_POINT,

    /** VLAN Bind Point */
    SAI_ACL_VLAN_BIND_POINT,

    /** RIF Bind Point */
    SAI_ACL_ROUTER_INTF_BIND_POINT,

    /** SWITCH Bind Point */
    SAI_ACL_SWITCH_BIND_POINT

    //TODO: once available add bridge interface based binding point.

} sai_acl_bind_point_t;

/**
 * @brief ACL IP Type
 */
typedef enum _sai_acl_ip_type_t
{
    /** Don't care */
    SAI_ACL_IP_TYPE_ANY,

    /** IPv4 and IPv6 packets */
    SAI_ACL_IP_TYPE_IP,

    /** Non-Ip packet */
    SAI_ACL_IP_TYPE_NON_IP,

    /** Any IPv4 packet */
    SAI_ACL_IP_TYPE_IPv4ANY,

    /** Anything but IPv4 packets */
    SAI_ACL_IP_TYPE_NON_IPv4,

    /** IPv6 packet */
    SAI_ACL_IP_TYPE_IPv6ANY,

    /** Anything but IPv6 packets */
    SAI_ACL_IP_TYPE_NON_IPv6,

    /** ARP/RARP */
    SAI_ACL_IP_TYPE_ARP,

    /** ARP Request */
    SAI_ACL_IP_TYPE_ARP_REQUEST,

    /** ARP Reply */
    SAI_ACL_IP_TYPE_ARP_REPLY

} sai_acl_ip_type_t;

/**
 * @brief ACL IP Fragment
 */
typedef enum _sai_acl_ip_frag_t
{
    /** Any Fragment of Fragmented Packet */
    SAI_ACL_IP_FRAG_ANY,

    /** Non-Fragmented Packet */
    SAI_ACL_IP_FRAG_NON_FRAG,

    /** Non-Fragmented or First Fragment */
    SAI_ACL_IP_FRAG_NON_FRAG_OR_HEAD,

    /** First Fragment of Fragmented Packet */
    SAI_ACL_IP_FRAG_HEAD,

    /** Not the First Fragment */
    SAI_ACL_IP_FRAG_NON_HEAD

} sai_acl_ip_frag_t;

/**
 * @brief ACL Action Type
 */
typedef enum _sai_acl_action_type_t
{
    /** Set Redirect */
    SAI_ACL_ACTION_TYPE_REDIRECT,

    /** Redirect Packet to a list of destination which can be a port list */
    SAI_ACL_ACTION_TYPE_REDIRECT_LIST,

    /** Drop Packet */
    SAI_ACL_ACTION_TYPE_PACKET_ACTION,

    /** Flood Packet on Vlan domain */
    SAI_ACL_ACTION_TYPE_FLOOD,

    /** Attach/detach counter id to the entry */
    SAI_ACL_ACTION_TYPE_COUNTER,

    /** Ingress Mirror */
    SAI_ACL_ACTION_TYPE_MIRROR_INGRESS,

    /** Egress Mirror */
    SAI_ACL_ACTION_TYPE_MIRROR_EGRESS,

    /** Assosiate with policer (policer id) */
    SAI_ACL_ACTION_TYPE_SET_POLICER,

    /** Decrement TTL */
    SAI_ACL_ACTION_TYPE_DECREMENT_TTL,

    /** Set Class-of-Service */
    SAI_ACL_ACTION_TYPE_SET_TC,

    /** Set Packet Color */
    SAI_ACL_ACTION_TYPE_SET_COLOR,

    /** Set Packet Inner Vlan-Id */
    SAI_ACL_ACTION_TYPE_SET_INNER_VLAN_ID,

    /** Set Packet Inner Vlan-Priority */
    SAI_ACL_ACTION_TYPE_SET_INNER_VLAN_PRI,

    /** Set Packet Outer Vlan-Id */
    SAI_ACL_ACTION_TYPE_SET_OUTER_VLAN_ID,

    /** Set Packet Outer Vlan-Priority */
    SAI_ACL_ACTION_TYPE_SET_OUTER_VLAN_PRI,

    /** Set Packet Src MAC Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_MAC,

    /** Set Packet Dst MAC Address */
    SAI_ACL_ACTION_TYPE_SET_DST_MAC,

    /** Set Packet Src IPv4 Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_IP,

    /** Set Packet Src IPv4 Address */
    SAI_ACL_ACTION_TYPE_SET_DST_IP,

    /** Set Packet Src IPv6 Address */
    SAI_ACL_ACTION_TYPE_SET_SRC_IPv6,

    /** Set Packet Src IPv6 Address */
    SAI_ACL_ACTION_TYPE_SET_DST_IPv6,

    /** Set Packet DSCP */
    SAI_ACL_ACTION_TYPE_SET_DSCP,

    /** Set Packet ECN */
    SAI_ACL_ACTION_TYPE_SET_ECN,

    /** Set Packet L4 Src Port */
    SAI_ACL_ACTION_TYPE_SET_L4_SRC_PORT,

    /** Set Packet L4 Src Port */
    SAI_ACL_ACTION_TYPE_SET_L4_DST_PORT,

    /** Set ingress packet sampling */
    SAI_ACL_ACTION_TYPE_INGRESS_SAMPLEPACKET_ENABLE,

    /** Set egress packet sampling */
    SAI_ACL_ACTION_TYPE_EGRESS_SAMPLEPACKET_ENABLE,

    /** Set CPU Queue for CPU bound traffic */
    SAI_ACL_ACTION_TYPE_SET_CPU_QUEUE,

    /** Set Meta Data to carry forward to next ACL Stage */
    sai_acl_action_type_set_acl_meta_data,

    /** egress block port list */
    sai_acl_action_type_egress_block_port_list,

    /** set user defined trap id */
    sai_acl_action_type_set_user_trap_id,

} sai_acl_action_type_t;

/**
 * @brief Attribute Id for sai_acl_table_group
 */
typedef enum _sai_acl_table_group_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_TABLE_GROUP_ATTR_START,

    /**
     * @brief ACL stage
     *
     * @type sai_acl_stage_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_GROUP_ATTR_STAGE = SAI_ACL_TABLE_GROUP_ATTR_START,

    /**
     * @brief List of ACL bind points where this group will be applied
     *
     * @type sai_acl_bind_point_t sai_object_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_GROUP_ATTR_BIND_POINT_LIST

    /**
     * @brief Priority
     *
     * Value must be in the range defined in
     * [SAI_SWITCH_ATTR_ACL_TABLE_GROUP_MINIMUM_PRIORITY,
     * SAI_SWITCH_ATTR_ACL_TABLE_GROUP_MAXIMUM_PRIORITY]
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_GROUP_ATTR_PRIORITY,

    /**
     * @brief End of attributes
     */
    SAI_ACL_TABLE_GROUP_ATTR_END

    /**
     * @brief Custom range base value start
     */
    SAI_ACL_GROUP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /**
     * @brief End of Custom range base
     */
    SAI_ACL_GROUP_ATTR_CUSTOM_RANGE_END

} sai_acl_table_group_attr_t;

/**
 * @brief ACL User Defined Field Attribute ID Range
 */
#define SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE 0xFF

/**
 * @brief Attribute Id for sai_acl_table
 */
typedef enum _sai_acl_table_attr_t
{
    /**
     * @brief Table attributes start
     */
    SAI_ACL_TABLE_ATTR_START,

    /**
     * @brief ACL stage
     *
     * @type sai_acl_stage_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_STAGE = SAI_ACL_TABLE_ATTR_START,

    /**
     * @brief List of ACL bind point where this ACL can be applied
     *
     * @type sai_acl_bind_point_t sai_object_list_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_BIND_POINT_LIST

    /**
     * @brief Priority
     *
     * Value must be in the range defined in
     * [SAI_SWITCH_ATTR_ACL_TABLE_MINIMUM_PRIORITY,
     * SAI_SWITCH_ATTR_ACL_TABLE_MAXIMUM_PRIORITY]
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_PRIORITY,

    /**
     * @brief Table size
     *
     * (default = 0) - Grow dynamically till MAX ACL TCAM Size
     * By default table can grow upto maximum ACL TCAM space.
     * Supported only during Table Create for now until NPU
     * supports Dynamic adjustment of Table size post Table creation
     *
     * The table size refers to the number of ACL entries. The number
     * of entries that get's allocated when we create a table with a
     * specific size would depend on the ACL CAM Arch of the NPU. Some
     * NPU supports different blocks, each may have same or different
     * size and what gets allocated can depend on the block size or other
     * factors. So internally what gets allocated when we do a table
     * create would be based on the NPU CAM Arch and size may be more
     * than what is requested. As an example the NPU may support blocks of
     * 128 entries. When a user creates a table of size 100, the actual
     * size that gets allocated is 128. Hence its recommended that the user
     * does a get_attribute(#SAI_ACL_TABLE_ATTR_SIZE) to query the actual
     * table size on table create so the user knows the ACL CAM space
     * allocated and able to do ACL CAM Carving accurately.
     *
     * @type sai_uint32_t
     * @flags CREATE_ONLY
     * @default 0
     */
    SAI_ACL_TABLE_ATTR_SIZE,

    /**
     * @brief Table Group Id
     *
     * By default, if the attribute is not present during table creation, SAI
     * will internally allocate a unique group id which can be used to group
     * tables which are created later. User would perform get operation for the
     * already created ACL Table to fetch the group id created by SAI and use
     * it for grouping the next table at the time of its creation.
     * Group Id will be deleted from SAI once all the ACL Tables referencing
     * the group are removed.
     *
     * In case none of the tables require grouping, SAI will assign unique group
     * ids equal to the number of ACL Tables created and all will be independently
     * looked up.
     *
     * User should always use the group id returned by SAI in the get operation
     * to group the tables else Invalid attribute value error code will be returned.
     *
     * The ACL Table lookup could be done serially or in parallel. In both the
     * cases there could be a need to group multiple tables so that only single
     * ACL rule entry actions are performed.
     *
     * Within one ACL group, only one ACL entry will be hit which is based on the
     * table priority as well as ACL entry priority within the table. Every ACL
     * Table is associated to a priority which is a mandatory attribute needed at
     * the time of table creation. The order of lookup within the ACL table group
     * will be based on individual table priority. Action(s) from the ACL entry
     * residing in the higher priority table within the group will be performed.
     *
     * Across the ACL groups, one hit ACL entry from each group will be selected
     * and all non-conflicting actions from them will be performed.
     *
     * Without grouping, all non-conflicting actions from different ACL entry
     * hits across the tables will be performed.
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_ACL_TABLE_GROUP
     * @flags CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_GROUP_ID,

    /**
     * @brief End of ACL Table attributes
     */
    SAI_ACL_TABLE_ATTR_END,

    /*
     * Match fields [bool]
     * Mandatory to pass at least one field during ACL Table creation.
     * Match fields cannot be changed after the table is created.
     */

    /**
     * @brief Start of Table Match Field
     */
    SAI_ACL_TABLE_ATTR_FIELD_START = 0x00001000,

    /**
     * @brief Src IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IPv6 = SAI_ACL_TABLE_ATTR_FIELD_START,

    /**
     * @brief Dst IPv6 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IPv6,

    /**
     * @brief Src MAC Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_MAC,

    /**
     * @brief Dst MAC Address
     *
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_MAC,

    /**
     * @brief Src IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_IP,

    /**
     * @brief Dst IPv4 Address
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DST_IP,

    /**
     * @brief In-Ports
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IN_PORTS,

    /**
     * @brief Out-Ports
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUT_PORTS,

    /**
     * @brief In-Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IN_PORT,

    /**
     * @brief Out-Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUT_PORT,

    /**
     * @brief Source Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_SRC_PORT,

    /**
     * @brief Outer Vlan-Id
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_ID,

    /**
     * @brief Outer Vlan-Priority
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_PRI,

    /**
     * @brief Outer Vlan-CFI
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_OUTER_VLAN_CFI,

    /**
     * @brief Inner Vlan-Id
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_ID,

    /**
     * @brief Inner Vlan-Priority
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_PRI,

    /**
     * @brief Inner Vlan-CFI
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_INNER_VLAN_CFI,

    /**
     * @brief L4 Src Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_L4_SRC_PORT,

    /**
     * @brief L4 Dst Port
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_L4_DST_PORT,

    /**
     * @brief EtherType
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ETHER_TYPE,

    /**
     * @brief IP Protocol
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_PROTOCOL,

    /**
     * @brief Ip Dscp
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_DSCP,

    /**
     * @brief Ip Ecn
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ECN,

    /**
     * @brief Ip Ttl
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TTL,

    /**
     * @brief Ip Tos
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TOS,

    /**
     * @brief Ip Flags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_FLAGS,

    /**
     * @brief Tcp Flags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TCP_FLAGS,

    /**
     * @brief Ip Type
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_TYPE,

    /**
     * @brief Ip Frag
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IP_FRAG,

    /**
     * @brief IPv6 Flow Label
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_IPv6_FLOW_LABEL,

    /**
     * @brief Class-of-Service (Traffic Class)
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_TC,

    /**
     * @brief ICMP Type
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMP_TYPE,

    /**
     * @brief ICMP Code
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ICMP_CODE,

    /**
     * @brief Vlan Tags
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_VLAN_TAGS,

    /* User Based Meta Data [bool] */

    /**
     * @brief FDB DST user meta data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_FDB_DST_USER_META,

    /**
     * @brief ROUTE DST User Meta data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ROUTE_DST_USER_META,

    /**
     * @brief Neighbor DST User Meta Data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_NEIGHBOR_DST_USER_META,

    /**
     * @brief Port User Meta Data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_PORT_USER_META,

    /**
     * @brief Vlan User Meta Data
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_VLAN_USER_META,

    /**
     * @brief Meta Data carried from previous ACL Stage
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ACL_USER_META,

    /* NPU Based Meta Data [bool] */

    /**
     * @brief DST MAC address match in FDB
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_FDB_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in neighbor table
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_NEIGHBOR_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in Route table
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_TABLE_ATTR_FIELD_ROUTE_NPU_META_DST_HIT,

    /**
     * @brief User Defined Field Groups [sai_object_id_t]
     * (CREATE_ONLY, default to #SAI_NULL_OBJECT_ID)
     *
     * @ignore
     */
    SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MIN,

    /**
     * @brief User Defined Field Groups end
     *
     * @ignore
     */
    SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MAX = SAI_ACL_TABLE_ATTR_USER_DEFINED_FIELD_GROUP_MIN + SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE,

    /**
     * @brief Range type defined
     *
     * @type sai_acl_range_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_TABLE_ATTR_FIELD_RANGE,

    /**
     * @brief List of actions in sai_acl_table_action_list_t [sai_s32_list_t]
     *
     * Based on the ACL capability per stage obtained from the switch
     * attribute #SAI_SWITCH_ATTR_ACL_CAPABILITY application should
     * pass the action list if its mandatory per stage.
     * If its not mandatory application can either pass the action list
     * or ignore it.
     *
     * @ignore
     */
    SAI_ACL_TABLE_ATTR_ACTION_LIST,

    /**
     * @brief End of ACL Table Match Field
     */
    SAI_ACL_TABLE_ATTR_FIELD_END = SAI_ACL_TABLE_ATTR_ACTION_LIST,

    /**
     * @brief Custom range base value start
     */
    SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /**
     * @brief End of Custom range base
     */
    SAI_ACL_TABLE_ATTR_CUSTOM_RANGE_END

} sai_acl_table_attr_t;

/**
 * @brief Attribute Id for sai_acl_entry
 */
typedef enum _sai_acl_entry_attr_t
{
    /**
     * @brief Start of ACL Entry attributes
     */
    SAI_ACL_ENTRY_ATTR_START,

    /**
     * @brief SAI ACL table object id
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_ACL_TABLE
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_ENTRY_ATTR_TABLE_ID = SAI_ACL_ENTRY_ATTR_START,

    /**
     * @brief Priority
     *
     * Value must be in the range defined in
     * \[#SAI_SWITCH_ATTR_ACL_ENTRY_MINIMUM_PRIORITY,
     * #SAI_SWITCH_ATTR_ACL_ENTRY_MAXIMUM_PRIORITY\]
     * (default = #SAI_SWITCH_ATTR_ACL_ENTRY_MINIMUM_PRIORITY)
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_ENTRY_ATTR_PRIORITY,

    /**
     * @brief Admin state
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default true
     */
    SAI_ACL_ENTRY_ATTR_ADMIN_STATE,

    /**
     * @brief End of ACL Entry attributes
     */
    SAI_ACL_ENTRY_ATTR_END,

    /*
     * Match fields [sai_acl_field_data_t]
     * - Mandatory to pass at least one field during ACL Rule creation.
     * - Unless noted specificially, both data and mask are required.
     * - When bit field is used, only those least significent bits are valid for
     * matching.
     */

    /**
     * @brief Start of Rule Match Fields
     */
    SAI_ACL_ENTRY_ATTR_FIELD_START = 0x00001000,

    /**
     * @brief Src IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IPv6 = SAI_ACL_ENTRY_ATTR_FIELD_START,

    /**
     * @brief Dst IPv6 Address
     *
     * @type sai_acl_field_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IPv6,

    /**
     * @brief Src MAC Address
     *
     * @type sai_acl_field_data_t sai_mac_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_MAC,

    /**
     * @brief Dst MAC Address
     *
     * @type sai_acl_field_data_t sai_mac_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_MAC,

    /**
     * @brief Src IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_IP,

    /**
     * @brief Dst IPv4 Address
     *
     * @type sai_acl_field_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DST_IP,

    /**
     * @brief In-Ports (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IN_PORTS,

    /**
     * @brief Out-Ports (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUT_PORTS,

    /**
     * @brief In-Port (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IN_PORT,

    /**
     * @brief Out-Port (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUT_PORT,

    /**
     * @brief Source port which could be a physical or lag port
     * (mask is not needed)
     *
     * @type sai_acl_field_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_SRC_PORT,

    /**
     * @brief Outer Vlan-Id (12 bits)
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_ID,

    /**
     * @brief Outer Vlan-Priority (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_PRI,

    /**
     * @brief Outer Vlan-CFI (1 bit)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_OUTER_VLAN_CFI,

    /**
     * @brief Inner Vlan-Id (12 bits)
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_ID,

    /**
     * @brief Inner Vlan-Priority (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_PRI,

    /**
     * @brief Inner Vlan-CFI (1 bit)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_INNER_VLAN_CFI,

    /**
     * @brief L4 Src Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_L4_SRC_PORT,

    /**
     * @brief L4 Dst Port
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_L4_DST_PORT,

    /**
     * @brief EtherType
     *
     * @type sai_acl_field_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ETHER_TYPE,

    /**
     * @brief IP Protocol
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_PROTOCOL,

    /**
     * @brief Ip Dscp (6 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_DSCP,

    /**
     * @brief Ip Ecn (2 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ECN,

    /**
     * @brief Ip Ttl
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TTL,

    /**
     * @brief Ip Tos
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TOS,

    /**
     * @brief Ip Flags (3 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_FLAGS,

    /**
     * @brief Tcp Flags (6 bits)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TCP_FLAGS,

    /**
     * @brief Ip Type (field mask is not needed)
     *
     * @type sai_acl_field_data_t sai_acl_ip_type_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_TYPE,

    /**
     * @brief Ip Frag (field mask is not needed)
     *
     * @type sai_acl_field_data_t sai_acl_ip_frag_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IP_FRAG,

    /**
     * @brief IPv6 Flow Label (20 bits)
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_IPv6_FLOW_LABEL,

    /**
     * @brief Class-of-Service (Traffic Class)
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_TC,

    /**
     * @brief ICMP Type
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMP_TYPE,

    /**
     * @brief ICMP Code
     *
     * @type sai_acl_field_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ICMP_CODE,

    /**
     * @brief Number of VLAN Tags
     *
     * @type sai_acl_field_data_t sai_packet_vlan_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_VLAN_TAGS,

    /* User Based Meta Data */

    /**
     * @brief DST MAC address match user meta data in FDB
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_FDB_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_FDB_DST_USER_META,

    /**
     * @brief DST IP address match user meta data in Route Table
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_ROUTE_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ROUTE_DST_USER_META,

    /**
     * @brief DST IP address match user meta data in Neighbor Table
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_NEIGHBOR_DST_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_NEIGHBOR_DST_USER_META,

    /**
     * @brief Port User Meta Data
     * Value must be in the range defined in
     * SAI_SWITCH_ATTR_PORT_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_PORT_USER_META,

    /**
     * @brief Vlan User Meta Data
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_VLAN_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_VLAN_USER_META,

    /**
     * @brief Meta Data carried from previous ACL Stage.
     * When an ACL entry set the meta data, the ACL meta data
     * form previous stages are overriden.
     * Value must be in the range defined in
     * #SAI_SWITCH_ATTR_ACL_USER_META_DATA_RANGE
     *
     * @type sai_acl_field_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ACL_USER_META,

    /* NPU Based Meta Data [bool] */

    /**
     * @brief DST MAC address match in FDB
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_FDB_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in neighbor Table
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_NEIGHBOR_NPU_META_DST_HIT,

    /**
     * @brief DST IP address match in Route Table
     *
     * @type sai_acl_field_data_t bool
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_ROUTE_NPU_META_DST_HIT,

    /**
     * @brief User Defined Field data for the UDF Groups in ACL Table
     *
     * @ignore
     */
    SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_MIN,

    /**
     * @brief User Defined Field data max
     *
     * @ignore
     */
    SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_MAX = SAI_ACL_ENTRY_ATTR_USER_DEFINED_FIELD_MIN + SAI_ACL_USER_DEFINED_FIELD_ATTR_ID_RANGE,

    /**
     * @brief Range Type defined in sai_acl_range_type_t
     * List of SAI ACL Range Object Id
     *
     * @type sai_acl_field_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_ACL_RANGE
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_FIELD_RANGE,

    /**
     * @brief End of Rule Match Fields
     */
    SAI_ACL_ENTRY_ATTR_FIELD_END = SAI_ACL_ENTRY_ATTR_FIELD_RANGE,

    /*
     * Actions [sai_acl_action_data_t]
     * - To enable an action, parameter is needed unless noted specifically.
     * - To disable an action, parameter is not needed.
     */

    /**
     * @brief Start of Rule Actions
     */
    SAI_ACL_ENTRY_ATTR_ACTION_START = 0x00002000,

    /**
     * @brief Redirect Packet to a destination which can be a port,
     * lag, nexthop, nexthopgroup
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_LAG, SAI_OBJECT_TYPE_NEXT_HOP, SAI_OBJECT_TYPE_NEXT_HOP_GROUP
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_REDIRECT = SAI_ACL_ENTRY_ATTR_ACTION_START,

    /**
     * @brief Redirect Packet to a list of destination which can be
     * a port list.
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_LAG, SAI_OBJECT_TYPE_NEXT_HOP, SAI_OBJECT_TYPE_NEXT_HOP_GROUP
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_REDIRECT_LIST,

    /**
     * @brief Drop Packet
     *
     * @type sai_acl_action_data_t sai_packet_action_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_PACKET_ACTION,

    /**
     * @brief Flood Packet on Vlan domain (parameter is not needed)
     *
     * @type sai_acl_action_data_t sai_int32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_FLOOD,

    /**
     * @brief Attach/detach counter id to the entry
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_ACL_COUNTER
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_COUNTER,

    /**
     * @brief Ingress Mirror (mirror session id list)
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_MIRROR_SESSION
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_MIRROR_INGRESS,

    /**
     * @brief Egress Mirror (mirror session id list)
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_MIRROR_SESSION
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_MIRROR_EGRESS,

    /**
     * @brief Assosiate with policer (policer id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_POLICER
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_POLICER,

    /**
     * @brief Decrement TTL (enable/disable) (parameter is not needed)
     *
     * @type sai_acl_action_data_t sai_int32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_DECREMENT_TTL,

    /**
     * @brief Set Class-of-Service (Traffic Class)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_TC,

    /**
     * @brief Set packet color
     *
     * @type sai_acl_action_data_t sai_packet_color_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_COLOR,

    /**
     * @brief Set Packet Inner Vlan-Id (12 bits)
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_INNER_VLAN_ID,

    /**
     * @brief Set Packet Inner Vlan-Priority (3 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_INNER_VLAN_PRI,

    /**
     * @brief Set Packet Outer Vlan-Id (12 bits)
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_OUTER_VLAN_ID,

    /**
     * @brief Set Packet Outer Vlan-Priority (3 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_OUTER_VLAN_PRI,

    /**
     * @brief Set Packet Src MAC Address
     *
     * @type sai_acl_action_data_t sai_mac_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_MAC,

    /**
     * @brief Set Packet Dst MAC Address
     *
     * @type sai_acl_action_data_t sai_mac_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_MAC,

    /**
     * @brief Set Packet Src IPv4 Address
     *
     * @type sai_acl_action_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_IP,

    /**
     * @brief Set Packet Src IPv4 Address
     *
     * @type sai_acl_action_data_t sai_ip4_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_IP,

    /**
     * @brief Set Packet Src IPv6 Address
     *
     * @type sai_acl_action_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_SRC_IPv6,

    /**
     * @brief Set Packet Src IPv6 Address
     *
     * @type sai_acl_action_data_t sai_ip6_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DST_IPv6,

    /**
     * @brief Set Packet DSCP (6 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_DSCP,

    /**
     * @brief Set Packet ECN (2 bits)
     *
     * @type sai_acl_action_data_t sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ECN,

    /**
     * @brief Set Packet L4 Src Port
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_L4_SRC_PORT,

    /**
     * @brief Set Packet L4 Src Port
     *
     * @type sai_acl_action_data_t sai_uint16_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_L4_DST_PORT,

    /**
     * @brief Set ingress packet sampling (samplepacket session id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_SAMPLEPACKET
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_INGRESS_SAMPLEPACKET_ENABLE,

    /**
     * @brief Set egress packet sampling (samplepacket session id)
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_SAMPLEPACKET
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_EGRESS_SAMPLEPACKET_ENABLE,

    /**
     * @brief Set CPU Queue for CPU bound traffic
     *
     * Action can be used whenever packet is destined to CPU such as
     * when packet action specifies the packet needs to be punted
     * to CPU (Trap/Log) or the destination port points to CPU.
     *
     * @type sai_acl_action_data_t sai_object_id_t
     * @objects SAI_OBJECT_TYPE_QUEUE
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_CPU_QUEUE,

    /**
     * @brief Set Meta Data to carry forward to next ACL Stage
     * Value Range #SAI_SWITCH_ATTR_ACL_USER_META_DATA_RANGE
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_ACL_META_DATA,

    /**
     * @brief Egress block port list
     * Packets matching the ACL entry and egressing out of the ports in the
     * given port list will be dropped.
     *
     * @type sai_acl_action_data_t sai_object_list_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_EGRESS_BLOCK_PORT_LIST,

    /**
     * @brief Set User Defined Trap ID
     *
     * Copy packet action mandatory to be present (Copy/Trap/Log)
     * Value Range #SAI_SWITCH_ATTR_ACL_USER_TRAP_ID_RANGE
     *
     * @type sai_acl_action_data_t sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_ACL_ENTRY_ATTR_ACTION_SET_USER_TRAP_ID,

    /**
     * @brief End of Rule Actions
     */
    SAI_ACL_ENTRY_ATTR_ACTION_END = SAI_ACL_ENTRY_ATTR_ACTION_SET_USER_TRAP_ID

} sai_acl_entry_attr_t;

/**
 * @brief Attribute Id for sai_acl_counter
 */
typedef enum _sai_acl_counter_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_COUNTER_ATTR_START,

    /**
     * @brief SAI ACL table object id
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_ACL_TABLE
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_COUNTER_ATTR_TABLE_ID = SAI_ACL_COUNTER_ATTR_START,

    /*
     * By default Byte Counter would be created and following
     * use of the below attributes would result in an error.
     *
     * - Both packet count and byte count set to disable
     * - Only Byte count used which is set to disable
     */

    /**
     * @brief Enable/disable packet count
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_COUNTER_ATTR_ENABLE_PACKET_COUNT,

    /**
     * @brief Enable/disable byte count
     *
     * @type bool
     * @flags CREATE_ONLY
     * @default false
     */
    SAI_ACL_COUNTER_ATTR_ENABLE_BYTE_COUNT,

    /**
     * @brief Get/set packet count
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_COUNTER_ATTR_PACKETS,

    /**
     * @brief Get/set byte count
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_ACL_COUNTER_ATTR_BYTES,

    /**
     * @brief End of attributes
     */
    SAI_ACL_COUNTER_ATTR_END,

} sai_acl_counter_attr_t;

/**
 * @brief Attribute data for ACL Range Type
 */
typedef enum _sai_acl_range_type_t
{
    /** L4 Source Port Range */
    SAI_ACL_RANGE_TYPE_L4_SRC_PORT_RANGE,

    /** L4 Destination Port Range */
    SAI_ACL_RANGE_TYPE_L4_DST_PORT_RANGE,

    /** Outer Vlan Range */
    SAI_ACL_RANGE_TYPE_OUTER_VLAN,

    /** Inner Vlan Range */
    SAI_ACL_RANGE_TYPE_INNER_VLAN,

    /** Packet Length Range in bytes */
    SAI_ACL_RANGE_TYPE_PACKET_LENGTH

} sai_acl_range_type_t;

/**
 * @brief Attribute Id for ACL Range Object
 */
typedef enum _sai_acl_range_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_ACL_RANGE_ATTR_START,

    /**
     * @brief Range Type
     *
     * Mandatory to pass only one of the range types
     * defined in sai_acl_range_type_t enum during ACL Range Creation.
     * Range Type cannot be changed after the range is created.
     *
     * @type sai_acl_range_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_RANGE_ATTR_TYPE = SAI_ACL_RANGE_ATTR_START,

    /**
     * @brief Start and End of ACL Range
     *
     * Range will include the start and end values.
     * Range Limit cannot be changed after the range is created.
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_ACL_RANGE_ATTR_LIMIT,

    /**
     * @brief End of attributes
     */
    SAI_ACL_RANGE_ATTR_END,

} sai_acl_range_attr_t;

/**
 * @brief Create an ACL table
 *
 * @param[out] acl_table_id The the ACL table id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_acl_table_fn)(
        _Out_ sai_object_id_t *acl_table_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL table
 *
 * @param[in] acl_table_id The ACL table id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_table_fn)(
        _In_ sai_object_id_t acl_table_id);

/**
 * @brief Set ACL table attribute
 *
 * @param[in] acl_table_id The ACL table id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_acl_table_attribute_fn)(
        _In_ sai_object_id_t acl_table_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL table attribute
 *
 * @param[in] acl_table_id ACL table id
 * @param[in] attr_count Number of attributes
 * @param[out] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_acl_table_attribute_fn)(
        _In_ sai_object_id_t acl_table_id,
        _In_ uint32_t attr_count,
        _Out_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL entry
 *
 * @param[out] acl_entry_id The ACL entry id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_acl_entry_fn)(
        _Out_ sai_object_id_t *acl_entry_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL entry
 *
 * @param[in] acl_entry_id The ACL entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_entry_fn)(
        _In_ sai_object_id_t acl_entry_id);

/**
 * @brief Set ACL entry attribute
 *
 * @param[in] acl_entry_id The ACL entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_acl_entry_attribute_fn)(
        _In_ sai_object_id_t acl_entry_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL entry attribute
 *
 * @param[in] acl_entry_id ACL entry id
 * @param[in] attr_count Number of attributes
 * @param[out] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_acl_entry_attribute_fn)(
        _In_ sai_object_id_t acl_entry_id,
        _In_ uint32_t attr_count,
        _Out_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL counter
 *
 * @param[out] acl_counter_id The ACL counter id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_acl_counter_fn)(
        _Out_ sai_object_id_t *acl_counter_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL counter
 *
 * @param[in] acl_counter_id The ACL counter id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_counter_fn)(
        _In_ sai_object_id_t acl_counter_id);

/**
 * @brief Set ACL counter attribute
 *
 * @param[in] acl_counter_id The ACL counter id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_acl_counter_attribute_fn)(
        _In_ sai_object_id_t acl_counter_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL counter attribute
 *
 * @param[in] acl_counter_id ACL counter id
 * @param[in] attr_count Number of attributes
 * @param[out] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_acl_counter_attribute_fn)(
        _In_ sai_object_id_t acl_counter_id,
        _In_ uint32_t attr_count,
        _Out_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL Range
 *
 * @param[out] acl_range_id The ACL range id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_acl_range_fn)(
        _Out_ sai_object_id_t *acl_range_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove an ACL Range
 *
 * @param[in] acl_range_id The ACL range id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_range_fn)(
        _In_ sai_object_id_t acl_range_id);

/**
 * @brief Set ACL range attribute
 *
 * @param[in] acl_range_id The ACL range id
 * @param[in] attr Attribute
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_acl_range_attribute_fn)(
        _In_ sai_object_id_t acl_range_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get ACL range attribute
 *
 * @param[in] acl_range_id ACL range id
 * @param[in] attr_count Number of attributes
 * @param[out] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_acl_range_attribute_fn)(
        _In_ sai_object_id_t acl_range_id,
        _In_ uint32_t attr_count,
        _Out_ sai_attribute_t *attr_list);

/**
 * @brief Create an ACL Table Group
 *
 * @param[out] acl_table_group_id The ACL group id 
 * @param[in] attr_count number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_acl_table_group_fn)(
        _Out_ sai_object_id_t *acl_table_group_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete an ACL Group 
 *
 * @param[in] acl_table_group_id The ACL group id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_acl_table_group_fn)(
        _In_ sai_object_id_t acl_table_group_id);

/**
 * @brief Port methods table retrieved with sai_api_query()
 */
typedef struct _sai_acl_api_t
{
    sai_create_acl_table_fn             create_acl_table;
    sai_remove_acl_table_fn             remove_acl_table;
    sai_set_acl_table_attribute_fn      set_acl_table_attribute;
    sai_get_acl_table_attribute_fn      get_acl_table_attribute;
    sai_create_acl_entry_fn             create_acl_entry;
    sai_remove_acl_entry_fn             remove_acl_entry;
    sai_set_acl_entry_attribute_fn      set_acl_entry_attribute;
    sai_get_acl_entry_attribute_fn      get_acl_entry_attribute;
    sai_create_acl_counter_fn           create_acl_counter;
    sai_remove_acl_counter_fn           remove_acl_counter;
    sai_set_acl_counter_attribute_fn    set_acl_counter_attribute;
    sai_get_acl_counter_attribute_fn    get_acl_counter_attribute;
    sai_create_acl_range_fn             create_acl_range;
    sai_remove_acl_range_fn             remove_acl_range;
    sai_set_acl_range_attribute_fn      set_acl_range_attribute;
    sai_get_acl_range_attribute_fn      get_acl_range_attribute;
    sai_create_acl_table_group_fn       create_acl_table_group;
    sai_remove_acl_table_group_fn       remove_acl_table_group;
} sai_acl_api_t;

/**
 * @}
 */
#endif /** __SAIACL_H_ */
