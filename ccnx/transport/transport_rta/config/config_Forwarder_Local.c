/*
 * Copyright (c) 2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Patent rights are not granted under this agreement. Patent rights are
 *       available under FRAND terms.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX or PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <config.h>
#include <stdio.h>
#include "config_Forwarder_Local.h"

#include <ccnx/transport/transport_rta/core/components.h>
#include <LongBow/runtime.h>

static const char param_FWD_LOCAL_NAME[] = "LOCAL_NAME";

CCNxStackConfig *
localForwarder_ProtocolStackConfig(CCNxStackConfig *stackConfig)
{
    PARCJSONValue *value = parcJSONValue_CreateFromNULL();
    CCNxStackConfig *result = ccnxStackConfig_Add(stackConfig, localForwarder_GetName(), value);
    parcJSONValue_Release(&value);
    return result;
}

/**
 * Generates:
 *
 * { "FWD_LOCAL" : { "path" : pipePath } }
 */
CCNxConnectionConfig *
localForwarder_ConnectionConfig(CCNxConnectionConfig *connConfig, const char *pipePath)
{
    PARCJSON *json = parcJSON_Create();
    parcJSON_AddString(json, param_FWD_LOCAL_NAME, pipePath);
    PARCJSONValue *value = parcJSONValue_CreateFromJSON(json);
    parcJSON_Release(&json);
    CCNxConnectionConfig *result = ccnxConnectionConfig_Add(connConfig, localForwarder_GetName(), value);
    parcJSONValue_Release(&value);
    return result;
}

const char *
localForwarder_GetName()
{
    return RtaComponentNames[FWD_LOCAL];
}

const char *
localForwarder_GetPath(PARCJSON *json)
{
    PARCJSONValue *value = parcJSON_GetValueByName(json, localForwarder_GetName());
    assertNotNull(value, "Got null for %s json", localForwarder_GetName());
    PARCJSON *localJson = parcJSONValue_GetJSON(value);

    value = parcJSON_GetValueByName(localJson, param_FWD_LOCAL_NAME);
    assertNotNull(value, "Must specify a path for the PF_UNIX pipe for local forwarder");
    assertTrue(parcJSONValue_IsString(value), "JSON key %s must be type STRING", localForwarder_GetName());

    PARCBuffer *sBuf = parcJSONValue_GetString(value);
    const char *path = parcBuffer_Overlay(sBuf, 0);

    return path;
}
