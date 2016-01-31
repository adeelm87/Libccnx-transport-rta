/*
 * Copyright (c) 2014-2015, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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
#ifndef Libccnx_config_CryptoCache_h
#define Libccnx_config_CryptoCache_h

#include <ccnx/transport/common/ccnx_TransportConfig.h>

/**
 * Generates:
 *
 * { "KEYS" :
 *   [
 *     { "KEYID" : base64{ keyhash },
 *       "KEY" : base64{ derEncodedKey },
 *       "PREFIXES" : [ uripath, uripath, ... uripath ]
 *     },
 *     { "KEYID" : base64{ keyhash },
 *       "KEY" : base64{ derEncodedKey },
 *       "PREFIXES" : [ uripath, uripath, ... uripath ]
 *     },
 *     ...
 *   ]
 * }
 */
CCNxConnectionConfig *cryptoCache_ConnectionConfig(CCNxConnectionConfig *connConfig, const char *filename, const char *password);

const char *cryptoCache_GetName(void);
#endif // Libccnx_config_CryptoCache_h
