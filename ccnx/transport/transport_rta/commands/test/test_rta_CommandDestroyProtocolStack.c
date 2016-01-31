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

// Include the file(s) containing the functions to be tested.
// This permits internal static functions to be visible to this Test Framework.
#include "../rta_CommandDestroyProtocolStack.c"

#include <LongBow/unit-test.h>
#include <parc/algol/parc_SafeMemory.h>

LONGBOW_TEST_RUNNER(rta_CommandDestroyProtocolStack)
{
    // The following Test Fixtures will run their corresponding Test Cases.
    // Test Fixtures are run in the order specified, but all tests should be idempotent.
    // Never rely on the execution order of tests or share state between them.
    LONGBOW_RUN_TEST_FIXTURE(Global);
}

// The Test Runner calls this function once before any Test Fixtures are run.
LONGBOW_TEST_RUNNER_SETUP(rta_CommandDestroyProtocolStack)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

// The Test Runner calls this function once after all the Test Fixtures are run.
LONGBOW_TEST_RUNNER_TEARDOWN(rta_CommandDestroyProtocolStack)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE(Global)
{
    LONGBOW_RUN_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Acquire);
    LONGBOW_RUN_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Create);
    LONGBOW_RUN_TEST_CASE(Global, rtaCommandDestroyProtocolStack_GetStackId);
    LONGBOW_RUN_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Release);
}

LONGBOW_TEST_FIXTURE_SETUP(Global)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Global)
{
    uint32_t outstandingAllocations = parcSafeMemory_ReportAllocation(STDERR_FILENO);
    if (outstandingAllocations != 0) {
        printf("%s leaks memory by %d allocations\n", longBowTestCase_GetName(testCase), outstandingAllocations);
        return LONGBOW_STATUS_MEMORYLEAK;
    }
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Acquire)
{
    int stackId = 7;
    RtaCommandDestroyProtocolStack *destroyStack = rtaCommandDestroyProtocolStack_Create(stackId);
    size_t firstRefCount = parcObject_GetReferenceCount(destroyStack);

    RtaCommandDestroyProtocolStack *second = rtaCommandDestroyProtocolStack_Acquire(destroyStack);
    size_t secondRefCount = parcObject_GetReferenceCount(second);

    assertTrue(secondRefCount == firstRefCount + 1, "Wrong refcount after acquire, got %zu expected %zu", secondRefCount, firstRefCount + 1);

    rtaCommandDestroyProtocolStack_Release(&destroyStack);
    rtaCommandDestroyProtocolStack_Release(&second);
}

LONGBOW_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Create)
{
    int stackId = 7;
    RtaCommandDestroyProtocolStack *destroyStack = rtaCommandDestroyProtocolStack_Create(stackId);
    assertNotNull(destroyStack, "Got null from create");
    assertTrue(destroyStack->stackId == stackId, "Internal stackId wrong, got %d expected %d", destroyStack->stackId, stackId);
    rtaCommandDestroyProtocolStack_Release(&destroyStack);
}

LONGBOW_TEST_CASE(Global, rtaCommandDestroyProtocolStack_GetStackId)
{
    int stackId = 7;
    RtaCommandDestroyProtocolStack *destroyStack = rtaCommandDestroyProtocolStack_Create(stackId);

    int testStackId = rtaCommandDestroyProtocolStack_GetStackId(destroyStack);
    assertTrue(testStackId == stackId, "Wrong value, got %d expected %d", testStackId, stackId);

    rtaCommandDestroyProtocolStack_Release(&destroyStack);
}

LONGBOW_TEST_CASE(Global, rtaCommandDestroyProtocolStack_Release)
{
    int stackId = 7;
    RtaCommandDestroyProtocolStack *destroyStack = rtaCommandDestroyProtocolStack_Create(stackId);

    RtaCommandDestroyProtocolStack *second = rtaCommandDestroyProtocolStack_Acquire(destroyStack);
    size_t secondRefCount = parcObject_GetReferenceCount(second);

    rtaCommandDestroyProtocolStack_Release(&destroyStack);
    size_t thirdRefCount = parcObject_GetReferenceCount(second);

    assertTrue(thirdRefCount == secondRefCount - 1, "Wrong refcount after release, got %zu expected %zu", thirdRefCount, secondRefCount - 1);

    rtaCommandDestroyProtocolStack_Release(&second);
}

int
main(int argc, char *argv[])
{
    LongBowRunner *testRunner = LONGBOW_TEST_RUNNER_CREATE(rta_CommandDestroyProtocolStack);
    int exitStatus = longBowMain(argc, argv, testRunner, NULL);
    longBowTestRunner_Destroy(&testRunner);
    exit(exitStatus);
}
