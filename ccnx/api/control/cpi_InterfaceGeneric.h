/*
 * Copyright (c) 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
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
/**
 * @file cpi_InterfaceGeneric.h
 * @brief A generic interface that is used as a super type for other interfaces.
 *
 * <#Detailed Description#>
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */
#ifndef libccnx_cpi_InterfaceGeneric_h
#define libccnx_cpi_InterfaceGeneric_h

#include <ccnx/api/control/cpi_InterfaceType.h>
#include <ccnx/api/control/cpi_Address.h>
#include <ccnx/api/control/cpi_AddressList.h>


struct cpi_interface_generic;
typedef struct cpi_interface_generic CPIInterfaceGeneric;

/**
 * Creates an Generic-like interface abstraction. Takes ownership of addresses.
 *
 *   <#Discussion#>
 *
 * @param <#param1#>
 * @return <#return#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CPIInterfaceGeneric *cpiInterfaceGeneric_Create(unsigned ifidx, CPIAddressList *addresses);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
CPIInterfaceGeneric *cpiInterfaceGeneric_Copy(const CPIInterfaceGeneric *generic);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
void cpiInterfaceGeneric_Destroy(CPIInterfaceGeneric **genericPtr);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
void cpiInterfaceGeneric_SetState(CPIInterfaceGeneric *generic, CPIInterfaceStateType state);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
unsigned cpiInterfaceGeneric_GetIndex(const CPIInterfaceGeneric *generic);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
const CPIAddressList *cpiInterfaceGeneric_GetAddresses(const CPIInterfaceGeneric *generic);

/**
 * <#One Line Description#>
 *
 * <#Paragraphs Of Explanation#>
 *
 * @param [<#in out in,out#>] <#name#> <#description#>
 *
 * @return <#value#> <#explanation#>
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 *
 * @see <#references#>
 */
CPIInterfaceStateType  cpiInterfaceGeneric_GetState(const CPIInterfaceGeneric *generic);

/**
 * Determine if two CPIInterfaceGeneric instances are equal.
 *
 * Two CPIInterfaceGeneric instances are equal if, and only if, the same state and index and addresses
 * are equal in the same order.
 *
 * The following equivalence relations on non-null `CPIInterfaceGeneric` instances are maintained:
 *
 *  * It is reflexive: for any non-null reference value x, `CPIInterfaceGeneric_Equals(x, x)`
 *      must return true.
 *
 *  * It is symmetric: for any non-null reference values x and y,
 *    `cpiInterfaceGeneric_Equals(x, y)` must return true if and only if
 *        `cpiInterfaceGeneric_Equals(y, x)` returns true.
 *
 *  * It is transitive: for any non-null reference values x, y, and z, if
 *        `cpiInterfaceGeneric_Equals(x, y)` returns true and
 *        `cpiInterfaceGeneric_Equals(y, z)` returns true,
 *        then  `cpiInterfaceGeneric_Equals(x, z)` must return true.
 *
 *  * It is consistent: for any non-null reference values x and y, multiple
 *      invocations of `cpiInterfaceGeneric_Equals(x, y)` consistently return true or
 *      consistently return false.
 *
 *  * For any non-null reference value x, `cpiInterfaceGeneric_Equals(x, NULL)` must
 *      return false.
 *
 * @param a A pointer to a `CPIInterfaceGeneric` instance.
 * @param b A pointer to a `CPIInterfaceGeneric` instance.
 * @return true if the two `CPIInterfaceGeneric` instances are equal.
 *
 * Example:
 * @code
 * {
 *    CPIInterfaceGeneric *a = cpiInterfaceGeneric_Create();
 *    CPIInterfaceGeneric *b = cpiInterfaceGeneric_Create();
 *
 *    if (cpiInterfaceGeneric_Equals(a, b)) {
 *        // true
 *    } else {
 *        // false
 *    }
 * }
 * @endcode
 */
bool cpiInterfaceGeneric_Equals(const CPIInterfaceGeneric *a, const CPIInterfaceGeneric *b);

/**
 * <#OneLineDescription#>
 *
 *   <#Discussion#>
 *
 * @param [in] interface
 * @param [in] composer A pointer to a PARCBufferComposer instance.
 * @return return The input parameter string.
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
PARCBufferComposer *cpiInterfaceGeneric_BuildString(const CPIInterfaceGeneric *interface, PARCBufferComposer *composer);
#endif // libccnx_cpi_InterfaceGeneric_h
