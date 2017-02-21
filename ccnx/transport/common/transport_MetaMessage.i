%module (jniclassname="TransportMetaMessage") test
%{
#include "transport_MetaMessage.h"
%}

%include "stdint.i"

%include "transport_MetaMessage.h"

/* Helper Functions */
%inline %{
void ccnxMetaMessage_Release1(CCNxMetaMessage *messagePtr) {
    ccnxMetaMessage_Release(&messagePtr);
}
%}
