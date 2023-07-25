//*****************************************************************************
//
//! @file svc_cust.c
//!
//! @brief Customerized Service Implementation
//!
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2022, Ambiq Micro, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision release_sdk_4_3_0-0ca7d78a2b of the AmbiqSuite Development Package.
//
//*****************************************************************************
#include "wsf_types.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "att_api.h"
#include "svc_ch.h"
#include "svc_cfg.h"
#include "svc_cust.h"

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Global Variables
//
//*****************************************************************************

//*****************************************************************************
// Static Variables
//*****************************************************************************

//*****************************************************************************
// Service variables
//*****************************************************************************

/* Customized Service Declaration */
static const uint8_t    custSvcUuidData[]                       = {ATT_UUID_CUST_SERVICE};
static const uint16_t   custSvcUuidLen                          = sizeof(custSvcUuidData);

/* Write Only Sample Characteristic */
static const uint8_t    WriteOnlyChData[]                       = {ATT_PROP_WRITE_NO_RSP | ATT_PROP_WRITE, UINT16_TO_BYTES(CUSTS_HANDLE_WRITEONLY), ATT_UUID_CUSTS_WRITEONLY};
static const uint16_t   WriteOnlyCharChLen                      = sizeof(WriteOnlyChData);

/* Write Only Sample Value */
static const uint8_t    WriteOnlyValUuid[]                      = {ATT_UUID_CUSTS_WRITEONLY};
static       uint8_t    WriteOnlyValData[20]                    = {0x00};
static const uint16_t   WriteOnlyValLen                         = sizeof(WriteOnlyValData);

/* Write Only Sample Characteristic User Description. */
static const uint8_t    WriteOnlyChUsrDescrData[]               = "Write Only Sample Characteristic";
static const uint16_t   WriteOnlyChUsrDescrLen                  = sizeof(WriteOnlyChUsrDescrData) - 1u;

/* Read Only Sample Characteristic */
static const uint8_t    ReadOnlyChData[]                        = {ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_READONLY), ATT_UUID_CUSTS_READONLY};
static const uint16_t   ReadOnlyCharChLen                       = sizeof(ReadOnlyChData);

/* Read Only Sample Value */
static const uint8_t    ReadOnlyValUuid[]                       = {ATT_UUID_CUSTS_READONLY};
static       uint8_t    ReadOnlyValData[20]                     = {0x00};
static const uint16_t   ReadOnlyValLen                          = sizeof(ReadOnlyValData);

/* Read Only Sample Characteristic User Description. */
static const uint8_t    ReadOnlyChUsrDescrData[]                = "Read Only Sample Characteristic";
static const uint16_t   ReadOnlyChUsrDescrLen                   = sizeof(ReadOnlyChUsrDescrData) - 1u;

/* Notification ECG Sample Characteristic */
static const uint8_t    NotifyChData_ecg_sample[]               = {ATT_PROP_NOTIFY | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_ECG_SAMPLE), ATT_UUID_ECG_SAMPLE};
static const uint16_t   NotifyCharChLen_ecg_sample               = sizeof(NotifyChData_ecg_sample);

/* Notification ECG Sample Value */
static const uint8_t    NotifyValUuid_ecg_sample[]              = {UINT16_TO_BYTES(CUSTS_HANDLE_ECG_SAMPLE)};
static       uint8_t    NotifyValData_ecg_sample[20]            = {0x00};
static const uint16_t   NotifyValLen_ecg_sample                 = sizeof(NotifyValData_ecg_sample);

/* Notification ECG Sample Client Characteristic Configuration. */
static       uint8_t    NotifyValClientChrConfigData_ecg_sample[]          = {0x00, 0x00};
static const uint16_t   NotifyValClientChrConfigLen_ecg_sample             = sizeof(NotifyValClientChrConfigData_ecg_sample);

/* Notification ECG Sample Characteristic User Description. */
static const uint8_t    NotifyChUsrDescrData_ecg_sample[]                  = "Notification ECG Sample Characteristic";
static const uint16_t   NotifyChUsrDescrLen_ecg_sample                     = sizeof(NotifyChUsrDescrData_ecg_sample) - 1u;

/* Notification ECG Sample Mask Characteristic */
static const uint8_t    NotifyChData_ecg_sample_mask[]         = {ATT_PROP_NOTIFY | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_ECG_SAMPLE_MASK), ATT_UUID_ECG_SAMPLE_MASK};
static const uint16_t   NotifyCharChLen_ecg_sample_mask        = sizeof(NotifyChData_ecg_sample_mask);

/* Notification ECG Sample Mask Value */
static const uint8_t    NotifyValUuid_ecg_sample_mask[]         = {UINT16_TO_BYTES(CUSTS_HANDLE_ECG_SAMPLE_MASK)};
static       uint8_t    NotifyValData_ecg_sample_mask[20]       = {0x00};
static const uint16_t   NotifyValLen_ecg_sample_mask            = sizeof(NotifyValData_ecg_sample_mask);

/* Notification ECG Sample Mask Client Characteristic Configuration. */
static       uint8_t    NotifyValClientChrConfigData_ecg_sample_mask[]          = {0x00, 0x00};
static const uint16_t   NotifyValClientChrConfigLen_ecg_sample_mask             = sizeof(NotifyValClientChrConfigData_ecg_sample_mask);

/* Notification ECG Sample Characteristic User Description. */
static const uint8_t    NotifyChUsrDescrData_ecg_sample_mask[]                  = "Notification ECG Sample Mask Characteristic";
static const uint16_t   NotifyChUsrDescrLen_ecg_sample_mask                     = sizeof(NotifyChUsrDescrData_ecg_sample_mask) - 1u;

/* Notification ECG Result Characteristic */
static const uint8_t    NotifyChData_ecg_result[]               = {ATT_PROP_NOTIFY | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_ECG_RESULT), ATT_UUID_ECG_RESULT};
static const uint16_t   NotifyCharChLen_ecg_result              = sizeof(NotifyChData_ecg_result);

/* Notification ECG Result Value */
static const uint8_t    NotifyValUuid_ecg_result[]              = {UINT16_TO_BYTES(CUSTS_HANDLE_ECG_RESULT)};
static       uint8_t    NotifyValData_ecg_result[20]            = {0x00};
static const uint16_t   NotifyValLen_ecg_result                 = sizeof(NotifyValData_ecg_result);

/* Notification ECG Result Client Characteristic Configuration. */
static       uint8_t    NotifyValClientChrConfigData_ecg_result[]          = {0x00, 0x00};
static const uint16_t   NotifyValClientChrConfigLen_ecg_result             = sizeof(NotifyValClientChrConfigData_ecg_result);

/* Notification ECG Result Characteristic User Description. */
static const uint8_t    NotifyChUsrDescrData_ecg_result[]                  = "Notification ECG Result Characteristic";
static const uint16_t   NotifyChUsrDescrLen_ecg_result                     = sizeof(NotifyChUsrDescrData_ecg_result) - 1u;

/* Indication Sample Characteristic */
static const uint8_t    IndicateChData[]                        = {ATT_PROP_INDICATE | ATT_PROP_READ, UINT16_TO_BYTES(CUSTS_HANDLE_INDICATEONLY), ATT_UUID_CUSTS_INDICATEONLY};
static const uint16_t   IndicateCharChLen                       = sizeof(IndicateChData);

/* Indication Sample Value */
static const uint8_t    IndicateValUuid[]                       = {UINT16_TO_BYTES(CUSTS_HANDLE_INDICATEONLY)};
static       uint8_t    IndicateValData[20]                     = {0x00};
static const uint16_t   IndicateValLen                          = sizeof(IndicateValData);

/* Indication Sample Client Characteristic Configuration. */
static       uint8_t    IndicateValClientChrConfigData[]        = {0x00, 0x00};
static const uint16_t   IndicateValClientChrConfigLen           = sizeof(IndicateValClientChrConfigData);

/* Indication Sample Characteristic User Description. */
static const uint8_t    IndicateChUsrDescrData[]                = "Indication Sample Characteristic";
static const uint16_t   IndicateChUsrDescrLen                   = sizeof(IndicateChUsrDescrData) - 1u;

static const attsAttr_t svcCustList[] =
{
    // Service Declaration
    {
        attPrimSvcUuid,
        (uint8_t *) custSvcUuidData,
        (uint16_t *) &custSvcUuidLen,
        sizeof(custSvcUuidData),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) WriteOnlyChData,
        (uint16_t *) &WriteOnlyCharChLen,
        sizeof(WriteOnlyChData),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        WriteOnlyValUuid,
        (uint8_t *) WriteOnlyValData,
        (uint16_t *) &WriteOnlyValLen,
        sizeof(WriteOnlyValUuid),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_WRITE_CBACK),
        ATTS_PERMIT_WRITE
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) WriteOnlyChUsrDescrData,
        (uint16_t *) &WriteOnlyChUsrDescrLen,
        sizeof(WriteOnlyChUsrDescrData),
        0,
        ATTS_PERMIT_READ
    },
#endif
    // Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) ReadOnlyChData,
        (uint16_t *) &ReadOnlyCharChLen,
        sizeof(ReadOnlyChData),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        ReadOnlyValUuid,
        (uint8_t *) ReadOnlyValData,
        (uint16_t *) &ReadOnlyValLen,
        sizeof(ReadOnlyValUuid),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN | ATTS_SET_READ_CBACK),
        ATTS_PERMIT_READ
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) ReadOnlyChUsrDescrData,
        (uint16_t *) &ReadOnlyChUsrDescrLen,
        sizeof(ReadOnlyChUsrDescrData),
        0,
        ATTS_PERMIT_READ
    },
#endif
    // ECG Sample Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) NotifyChData_ecg_sample,
        (uint16_t *) &NotifyCharChLen_ecg_sample,
        sizeof(NotifyChData_ecg_sample),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        NotifyValUuid_ecg_sample,
        (uint8_t *) NotifyValData_ecg_sample,
        (uint16_t *) &NotifyValLen_ecg_sample,
        sizeof(NotifyValUuid_ecg_sample),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN),
        ATTS_PERMIT_READ
    },
    // Client Characteristic Configuration
    {
        attCliChCfgUuid,
        (uint8_t *) NotifyValClientChrConfigData_ecg_sample,
        (uint16_t *) &NotifyValClientChrConfigLen_ecg_sample,
        sizeof(NotifyValClientChrConfigData_ecg_sample),
        ATTS_SET_CCC,
        ATTS_PERMIT_READ | ATTS_PERMIT_WRITE
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) NotifyChUsrDescrData_ecg_sample,
        (uint16_t *) &NotifyChUsrDescrLen_ecg_sample,
        sizeof(NotifyChUsrDescrData_ecg_sample),
        0,
        ATTS_PERMIT_READ
    },
#endif
    // ECG Sample Mask Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) NotifyChData_ecg_sample_mask,
        (uint16_t *) &NotifyCharChLen_ecg_sample_mask,
        sizeof(NotifyChData_ecg_sample_mask),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        NotifyValUuid_ecg_sample_mask,
        (uint8_t *) NotifyValData_ecg_sample_mask,
        (uint16_t *) &NotifyValLen_ecg_sample_mask,
        sizeof(NotifyValUuid_ecg_sample_mask),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN),
        ATTS_PERMIT_READ
    },
    // Client Characteristic Configuration
    {
        attCliChCfgUuid,
        (uint8_t *) NotifyValClientChrConfigData_ecg_sample_mask,
        (uint16_t *) &NotifyValClientChrConfigLen_ecg_sample_mask,
        sizeof(NotifyValClientChrConfigData_ecg_sample_mask),
        ATTS_SET_CCC,
        ATTS_PERMIT_READ | ATTS_PERMIT_WRITE
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) NotifyChUsrDescrData_ecg_sample_mask,
        (uint16_t *) &NotifyChUsrDescrLen_ecg_sample_mask,
        sizeof(NotifyChUsrDescrData_ecg_sample_mask),
        0,
        ATTS_PERMIT_READ
    },
#endif
    // ECG Result Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) NotifyChData_ecg_result,
        (uint16_t *) &NotifyCharChLen_ecg_result,
        sizeof(NotifyChData_ecg_result),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        NotifyValUuid_ecg_result,
        (uint8_t *) NotifyValData_ecg_result,
        (uint16_t *) &NotifyValLen_ecg_result,
        sizeof(NotifyValUuid_ecg_result),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN),
        ATTS_PERMIT_READ
    },
    // Client Characteristic Configuration
    {
        attCliChCfgUuid,
        (uint8_t *) NotifyValClientChrConfigData_ecg_result,
        (uint16_t *) &NotifyValClientChrConfigLen_ecg_result,
        sizeof(NotifyValClientChrConfigData_ecg_result),
        ATTS_SET_CCC,
        ATTS_PERMIT_READ | ATTS_PERMIT_WRITE
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) NotifyChUsrDescrData_ecg_result,
        (uint16_t *) &NotifyChUsrDescrLen_ecg_result,
        sizeof(NotifyChUsrDescrData_ecg_result),
        0,
        ATTS_PERMIT_READ
    },
#endif
    // Characteristic Declaration
    {
        attChUuid,
        (uint8_t *) IndicateChData,
        (uint16_t *) &IndicateCharChLen,
        sizeof(IndicateChData),
        0,
        ATTS_PERMIT_READ
    },
    // Characteristic Value
    {
        IndicateValUuid,
        (uint8_t *) IndicateValData,
        (uint16_t *) &IndicateValLen,
        sizeof(IndicateValUuid),
        (ATTS_SET_UUID_128 | ATTS_SET_VARIABLE_LEN),
        ATTS_PERMIT_READ
    },
    // Client Characteristic Configuration
    {
        attCliChCfgUuid,
        (uint8_t *) IndicateValClientChrConfigData,
        (uint16_t *) &IndicateValClientChrConfigLen,
        sizeof(IndicateValClientChrConfigData),
        ATTS_SET_CCC,
        ATTS_PERMIT_READ | ATTS_PERMIT_WRITE
    },
#ifdef INCLUDE_USER_DESCR
    /* Characteristic user description. */
    {
        attChUserDescUuid,
        (uint8_t *) IndicateChUsrDescrData,
        (uint16_t *) &IndicateChUsrDescrLen,
        sizeof(IndicateChUsrDescrData),
        0,
        ATTS_PERMIT_READ
    },
#endif
};


static attsGroup_t s_svcCustGroup =
{
    NULL,
    (attsAttr_t *) svcCustList,
    NULL,
    NULL,
    CUSTSVC_HANDLE_START,
    CUSTSVC_HANDLE_END
};


//*****************************************************************************
//
//! @brief Add the customized service to the attribute server.
//!
//! @param none
//!
//! This function adds the customized service to the attribute server.
//!
//! @return none
//
//*****************************************************************************
void SvcCustAddGroup(void)
{
    AttsAddGroup(&s_svcCustGroup);
}

//*****************************************************************************
//
//! @brief Remove the customized service from the attribute server.
//!
//! @param none
//!
//! This function removes the customized service to the attribute server.
//!
//! @return none
//
//*****************************************************************************
void SvcCustRemoveGroup(void)
{
    AttsRemoveGroup(CUSTSVC_HANDLE_START);
}

//*****************************************************************************
//
//! @brief Register callbacks for the customized service.
//!
//! @param readCback    - attribute read callback function pointer.
//! @param writeCback   - attribute write callback function pointer.
//!
//! This function registers callback functions for the customized servcie..
//!
//! @return none
//
//*****************************************************************************
void SvcCustCbackRegister(attsReadCback_t readCback, attsWriteCback_t writeCback)
{
    s_svcCustGroup.readCback    = readCback;
    s_svcCustGroup.writeCback   = writeCback;
}
